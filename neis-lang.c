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
#include "langhooks.h"
#include "langhooks-def.h"
#include "debug.h"
#include "neis-tree.h"

/* Tables of information about tree codes.  */

#define DEFTREECODE(SYM, NAME, TYPE, LENGTH) TYPE,
const enum tree_code_class tree_code_type[] = {
#include "tree.def"
};
#undef DEFTREECODE

#define DEFTREECODE(SYM, NAME, TYPE, LENGTH) LENGTH,
const unsigned char tree_code_length[] = {
#include "tree.def"
};
#undef DEFTREECODE

#define DEFTREECODE(SYM, NAME, TYPE, LEN) NAME,
const char *const tree_code_name[] = {
#include "tree.def"
};
#undef DEFTREECODE

/* Language hooks.  */

static bool
neis_mark_addressable (tree t ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static tree
neis_type_for_mode (enum machine_mode mode ATTRIBUTE_UNUSED,
                  int unsigned_p ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static tree
neis_type_for_size (unsigned precision ATTRIBUTE_UNUSED,
                  int unsigned_p ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static tree
neis_unsigned_type (tree type ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static tree
neis_signed_type (tree type ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static tree
neis_signed_or_unsigned_type (int unsigned_p ATTRIBUTE_UNUSED,
                            tree type ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

static int
neis_global_bindings_p (void)
{
  gcc_unreachable ();
}

static void
neis_insert_block (tree block ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
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

static void
neis_write_globals (void)
{
  gcc_unreachable ();
}

static tree
neis_builtin_function (const char *name ATTRIBUTE_UNUSED,
                     tree type ATTRIBUTE_UNUSED,
                     int function_code ATTRIBUTE_UNUSED,
                     enum built_in_class bt_class ATTRIBUTE_UNUSED,
                     const char *library_name ATTRIBUTE_UNUSED,
                     tree attrs ATTRIBUTE_UNUSED)
{
  gcc_unreachable ();
}

#define LANG_HOOKS_MARK_ADDRESSABLE neis_mark_addressable
#define LANG_HOOKS_TYPE_FOR_MODE neis_type_for_mode
#define LANG_HOOKS_TYPE_FOR_SIZE neis_type_for_size
#define LANG_HOOKS_UNSIGNED_TYPE neis_unsigned_type
#define LANG_HOOKS_SIGNED_TYPE neis_signed_type
#define LANG_HOOKS_SIGNED_OR_UNSIGNED_TYPE neis_signed_or_unsigned_type
#undef LANG_HOOKS_GLOBAL_BINDINGS_P
#define LANG_HOOKS_GLOBAL_BINDINGS_P neis_global_bindings_p
#undef LANG_HOOKS_INSERT_BLOCK
#define LANG_HOOKS_INSERT_BLOCK neis_insert_block
#undef LANG_HOOKS_PUSHDECL
#define LANG_HOOKS_PUSHDECL neis_pushdecl
#undef LANG_HOOKS_GETDECLS
#define LANG_HOOKS_GETDECLS neis_getdecls
#undef LANG_HOOKS_WRITE_GLOBALS
#define LANG_HOOKS_WRITE_GLOBALS neis_write_globals
#undef LANG_HOOKS_BUILTIN_FUNCTION
#define LANG_HOOKS_BUILTIN_FUNCTION neis_builtin_function

const struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

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
  return TS_LTO_GENERIC;
}

#include "ggc.h"
#include "gtype-neis.h"
