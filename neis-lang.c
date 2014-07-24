/* Language-dependent hooks for NEIS.
   Copyright (C) 2009-2014 Free Software Foundation, Inc.
   Contributed by CodeSourcery, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 3, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tree.h"
#include "flags.h"
#include "stor-layout.h"
#include "langhooks.h"
#include "langhooks-def.h"
#include "debug.h"
#include "neis-tree.h"
#include "function.h"
#include "toplev.h"
#include "expr.h"
#include "stmt.h"
#include "name-lookup.h"

/* Tables of information about tree codes.  */

#define DEFTREECODE(SYM, NAME, TYPE, LEN) NAME,
const char *const tree_code_name[] = {
#include "tree.def"
};
#undef DEFTREECODE

/* Language hooks.  */

static GTY(()) tree registered_builtin_types;

/* Initialize tree structures required by the LTO front end.  */

static void neis_init_ts (void)
{
  tree_contains_struct[NAMESPACE_DECL][TS_DECL_MINIMAL] = 1;
}

/* Return a data type that has machine mode MODE.
   If the mode is an integer,
   then UNSIGNEDP selects between signed and unsigned types.
   If the mode is a fixed-point mode,
   then UNSIGNEDP selects between saturating and nonsaturating types.  */

static tree
neis_type_for_mode (enum machine_mode mode, int unsigned_p)
{
  tree t;

  if (mode == TYPE_MODE (integer_type_node))
    return unsigned_p ? unsigned_type_node : integer_type_node;

  if (mode == TYPE_MODE (signed_char_type_node))
    return unsigned_p ? unsigned_char_type_node : signed_char_type_node;

  if (mode == TYPE_MODE (short_integer_type_node))
    return unsigned_p ? short_unsigned_type_node : short_integer_type_node;

  if (mode == TYPE_MODE (long_integer_type_node))
    return unsigned_p ? long_unsigned_type_node : long_integer_type_node;

  if (mode == TYPE_MODE (long_long_integer_type_node))
    return unsigned_p ? long_long_unsigned_type_node : long_long_integer_type_node;

  if (mode == QImode)
    return unsigned_p ? unsigned_intQI_type_node : intQI_type_node;

  if (mode == HImode)
    return unsigned_p ? unsigned_intHI_type_node : intHI_type_node;

  if (mode == SImode)
    return unsigned_p ? unsigned_intSI_type_node : intSI_type_node;

  if (mode == DImode)
    return unsigned_p ? unsigned_intDI_type_node : intDI_type_node;

#if HOST_BITS_PER_WIDE_INT >= 64
  if (mode == TYPE_MODE (intTI_type_node))
    return unsigned_p ? unsigned_intTI_type_node : intTI_type_node;
#endif

  if (mode == TYPE_MODE (float_type_node))
    return float_type_node;

  if (mode == TYPE_MODE (double_type_node))
    return double_type_node;

  if (mode == TYPE_MODE (long_double_type_node))
    return long_double_type_node;

  if (mode == TYPE_MODE (void_type_node))
    return void_type_node;

  if (mode == TYPE_MODE (build_pointer_type (char_type_node)))
    return (unsigned_p
	    ? make_unsigned_type (GET_MODE_PRECISION (mode))
	    : make_signed_type (GET_MODE_PRECISION (mode)));

  if (mode == TYPE_MODE (build_pointer_type (integer_type_node)))
    return (unsigned_p
	    ? make_unsigned_type (GET_MODE_PRECISION (mode))
	    : make_signed_type (GET_MODE_PRECISION (mode)));

  if (COMPLEX_MODE_P (mode))
    {
      enum machine_mode inner_mode;
      tree inner_type;

      if (mode == TYPE_MODE (complex_float_type_node))
	return complex_float_type_node;
      if (mode == TYPE_MODE (complex_double_type_node))
	return complex_double_type_node;
      if (mode == TYPE_MODE (complex_long_double_type_node))
	return complex_long_double_type_node;

      if (mode == TYPE_MODE (complex_integer_type_node) && !unsigned_p)
	return complex_integer_type_node;

      inner_mode = GET_MODE_INNER (mode);
      inner_type = neis_type_for_mode (inner_mode, unsigned_p);
      if (inner_type != NULL_TREE)
	return build_complex_type (inner_type);
    }
  else if (VECTOR_MODE_P (mode))
    {
      enum machine_mode inner_mode = GET_MODE_INNER (mode);
      tree inner_type = neis_type_for_mode (inner_mode, unsigned_p);
      if (inner_type != NULL_TREE)
	return build_vector_type_for_mode (inner_type, mode);
    }

  if (mode == TYPE_MODE (dfloat32_type_node))
    return dfloat32_type_node;
  if (mode == TYPE_MODE (dfloat64_type_node))
    return dfloat64_type_node;
  if (mode == TYPE_MODE (dfloat128_type_node))
    return dfloat128_type_node;

  if (ALL_SCALAR_FIXED_POINT_MODE_P (mode))
    {
      if (mode == TYPE_MODE (short_fract_type_node))
	return unsigned_p ? sat_short_fract_type_node : short_fract_type_node;
      if (mode == TYPE_MODE (fract_type_node))
	return unsigned_p ? sat_fract_type_node : fract_type_node;
      if (mode == TYPE_MODE (long_fract_type_node))
	return unsigned_p ? sat_long_fract_type_node : long_fract_type_node;
      if (mode == TYPE_MODE (long_long_fract_type_node))
	return unsigned_p ? sat_long_long_fract_type_node
			 : long_long_fract_type_node;

      if (mode == TYPE_MODE (unsigned_short_fract_type_node))
	return unsigned_p ? sat_unsigned_short_fract_type_node
			 : unsigned_short_fract_type_node;
      if (mode == TYPE_MODE (unsigned_fract_type_node))
	return unsigned_p ? sat_unsigned_fract_type_node
			 : unsigned_fract_type_node;
      if (mode == TYPE_MODE (unsigned_long_fract_type_node))
	return unsigned_p ? sat_unsigned_long_fract_type_node
			 : unsigned_long_fract_type_node;
      if (mode == TYPE_MODE (unsigned_long_long_fract_type_node))
	return unsigned_p ? sat_unsigned_long_long_fract_type_node
			 : unsigned_long_long_fract_type_node;

      if (mode == TYPE_MODE (short_accum_type_node))
	return unsigned_p ? sat_short_accum_type_node : short_accum_type_node;
      if (mode == TYPE_MODE (accum_type_node))
	return unsigned_p ? sat_accum_type_node : accum_type_node;
      if (mode == TYPE_MODE (long_accum_type_node))
	return unsigned_p ? sat_long_accum_type_node : long_accum_type_node;
      if (mode == TYPE_MODE (long_long_accum_type_node))
	return unsigned_p ? sat_long_long_accum_type_node
			 : long_long_accum_type_node;

      if (mode == TYPE_MODE (unsigned_short_accum_type_node))
	return unsigned_p ? sat_unsigned_short_accum_type_node
			 : unsigned_short_accum_type_node;
      if (mode == TYPE_MODE (unsigned_accum_type_node))
	return unsigned_p ? sat_unsigned_accum_type_node
			 : unsigned_accum_type_node;
      if (mode == TYPE_MODE (unsigned_long_accum_type_node))
	return unsigned_p ? sat_unsigned_long_accum_type_node
			 : unsigned_long_accum_type_node;
      if (mode == TYPE_MODE (unsigned_long_long_accum_type_node))
	return unsigned_p ? sat_unsigned_long_long_accum_type_node
			 : unsigned_long_long_accum_type_node;

      if (mode == QQmode)
	return unsigned_p ? sat_qq_type_node : qq_type_node;
      if (mode == HQmode)
	return unsigned_p ? sat_hq_type_node : hq_type_node;
      if (mode == SQmode)
	return unsigned_p ? sat_sq_type_node : sq_type_node;
      if (mode == DQmode)
	return unsigned_p ? sat_dq_type_node : dq_type_node;
      if (mode == TQmode)
	return unsigned_p ? sat_tq_type_node : tq_type_node;

      if (mode == UQQmode)
	return unsigned_p ? sat_uqq_type_node : uqq_type_node;
      if (mode == UHQmode)
	return unsigned_p ? sat_uhq_type_node : uhq_type_node;
      if (mode == USQmode)
	return unsigned_p ? sat_usq_type_node : usq_type_node;
      if (mode == UDQmode)
	return unsigned_p ? sat_udq_type_node : udq_type_node;
      if (mode == UTQmode)
	return unsigned_p ? sat_utq_type_node : utq_type_node;

      if (mode == HAmode)
	return unsigned_p ? sat_ha_type_node : ha_type_node;
      if (mode == SAmode)
	return unsigned_p ? sat_sa_type_node : sa_type_node;
      if (mode == DAmode)
	return unsigned_p ? sat_da_type_node : da_type_node;
      if (mode == TAmode)
	return unsigned_p ? sat_ta_type_node : ta_type_node;

      if (mode == UHAmode)
	return unsigned_p ? sat_uha_type_node : uha_type_node;
      if (mode == USAmode)
	return unsigned_p ? sat_usa_type_node : usa_type_node;
      if (mode == UDAmode)
	return unsigned_p ? sat_uda_type_node : uda_type_node;
      if (mode == UTAmode)
	return unsigned_p ? sat_uta_type_node : uta_type_node;
    }

  for (t = registered_builtin_types; t; t = TREE_CHAIN (t))
    if (TYPE_MODE (TREE_VALUE (t)) == mode)
      return TREE_VALUE (t);

  return NULL_TREE;
}

/* Return an integer type with PRECISION bits of precision,
   that is unsigned if UNSIGNEDP is nonzero, otherwise signed.  */

static tree
neis_type_for_size (unsigned precision, int unsignedp)
{
  if (precision == TYPE_PRECISION (integer_type_node))
    return unsignedp ? unsigned_type_node : integer_type_node;

  if (precision == TYPE_PRECISION (signed_char_type_node))
    return unsignedp ? unsigned_char_type_node : signed_char_type_node;

  if (precision == TYPE_PRECISION (short_integer_type_node))
    return unsignedp ? short_unsigned_type_node : short_integer_type_node;

  if (precision == TYPE_PRECISION (long_integer_type_node))
    return unsignedp ? long_unsigned_type_node : long_integer_type_node;

  if (precision == TYPE_PRECISION (long_long_integer_type_node))
    return unsignedp
	   ? long_long_unsigned_type_node
	   : long_long_integer_type_node;

  if (precision <= TYPE_PRECISION (intQI_type_node))
    return unsignedp ? unsigned_intQI_type_node : intQI_type_node;

  if (precision <= TYPE_PRECISION (intHI_type_node))
    return unsignedp ? unsigned_intHI_type_node : intHI_type_node;

  if (precision <= TYPE_PRECISION (intSI_type_node))
    return unsignedp ? unsigned_intSI_type_node : intSI_type_node;

  if (precision <= TYPE_PRECISION (intDI_type_node))
    return unsignedp ? unsigned_intDI_type_node : intDI_type_node;

  if (precision <= TYPE_PRECISION (intTI_type_node))
    return unsignedp ? unsigned_intTI_type_node : intTI_type_node;

  return NULL_TREE;
}

static tree
neis_pushdecl (tree t ATTRIBUTE_UNUSED)
{
    gcc_unreachable ();
}

static tree
neis_getdecls (void)
{
    gcc_unreachable ();
}

static bool
neis_global_bindings_p (void)
{
    gcc_unreachable ();
}

void neis_parse_file(void)
{
    yyin = fopen(in_fnames[0], "r");

    if (yyin == NULL)
        fatal_error("cannot open %s: %m", filename);

    if(!yyparse())
        printf("\nParsing complete\n");
    else
        printf("\nParsing failed\n");

    fclose(yyin);
}

#undef LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "Neis"

#undef LANG_HOOKS_TYPE_FOR_MODE
#define LANG_HOOKS_TYPE_FOR_MODE neis_type_for_mode
#undef LANG_HOOKS_TYPE_FOR_SIZE
#define LANG_HOOKS_TYPE_FOR_SIZE neis_type_for_size

#undef LANG_HOOKS_PUSHDECL
#define LANG_HOOKS_PUSHDECL neis_pushdecl

#undef LANG_HOOKS_GETDECLS
#define LANG_HOOKS_GETDECLS neis_getdecls

#undef LANG_HOOKS_GLOBAL_BINDINGS_P
#define LANG_HOOKS_GLOBAL_BINDINGS_P neis_global_bindings_p

#undef LANG_HOOKS_INIT_TS
#define LANG_HOOKS_INIT_TS neis_init_ts

#undef LANG_HOOKS_PARSE_FILE
#define LANG_HOOKS_PARSE_FILE neis_parse_file

struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

/* Language hooks that are not part of lang_hooks.  */

tree
convert (tree type ATTRIBUTE_UNUSED, tree expr ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

/* Tree walking support.  */

static enum neis_tree_node_structure_enum
neis_tree_node_structure (union lang_tree_node *t ATTRIBUTE_UNUSED)
{
  return TS_NEIS_GENERIC;
}


#include "ggc.h"
#include "gtype-neis.h"
