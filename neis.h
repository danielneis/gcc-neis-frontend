/* NEIS declarations.
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

#ifndef NEIS_H
#define NEIS_H

#include "hashtab.h"
#include "vec.h"

/* A file.  */
typedef struct neis_file_struct
{
  /* The name of the file.  */
  const char *filename;
  /* The offset for the object inside an ar archive file (or zero).  */
  off_t offset;
} neis_file;

/* In neis-lang.c  */
extern const char *resolution_file_name;

/* In neis.c  */
extern tree neis_eh_personality (void);
extern void neis_main (void);
extern void neis_read_all_file_options (void);

/* In neis-elf.c or neis-coff.c  */
extern neis_file *neis_obj_file_open (const char *filename, bool writable);
extern void neis_obj_file_close (neis_file *file);
struct neis_section_list;
extern htab_t neis_obj_build_section_table (neis_file *file, struct neis_section_list *list);
extern htab_t neis_obj_create_section_hash_table (void);
extern void neis_obj_begin_section (const char *name);
extern void neis_obj_append_data (const void *data, size_t len, void *block);
extern void neis_obj_end_section (void);
extern neis_file *neis_set_current_out_file (neis_file *file);
extern neis_file *neis_get_current_out_file (void);

/* Hash table entry to hold the start offset and length of an NEIS
   section in a .o file.  */
struct neis_section_slot
{
  const char *name;
  intptr_t start;
  size_t len;
  struct neis_section_slot *next;
};

/* A list of section slots */
struct neis_section_list
{
  struct neis_section_slot *first, *last;
};

#endif /* NEIS_H */
