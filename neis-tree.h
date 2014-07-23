/* Language-dependent trees for NEIS.
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

#ifndef GCC_NEIS_TREE_H
#define GCC_NEIS_TREE_H

#include "plugin-api.h"

struct GTY(()) lang_identifier
{
  struct tree_identifier base;
};

struct GTY((variable_size)) lang_decl
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

struct GTY((variable_size)) lang_type
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

struct GTY(()) language_function
{
  int dummy;  /* Added because ggc does not like empty structs.  */
};

enum neis_tree_node_structure_enum {
  TS_NEIS_GENERIC
};

union GTY((desc ("neis_tree_node_structure (&%h)"),
	  chain_next ("CODE_CONTAINS_STRUCT (TREE_CODE (&%h.generic), TS_TYPE_COMMON) ? ((union lang_tree_node *) %h.generic.type_common.next_variant) : CODE_CONTAINS_STRUCT (TREE_CODE (&%h.generic), TS_COMMON) ? ((union lang_tree_node *) %h.generic.common.chain) : NULL")))
    lang_tree_node
{
  union tree_node GTY ((tag ("TS_NEIS_GENERIC"),
			desc ("tree_node_structure (&%h)"))) generic;
};

#endif /* GCC_NEIS_TREE_H */
