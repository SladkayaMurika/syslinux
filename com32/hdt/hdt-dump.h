/* ----------------------------------------------------------------------- *
 *
 *   Copyright 20011 Erwan Velu - All Rights Reserved
 *
 *   Permission is hereby granted, free of charge, to any person
 *   obtaining a copy of this software and associated documentation
 *   files (the "Software"), to deal in the Software without
 *   restriction, including without limitation the rights to use,
 *   copy, modify, merge, publish, distribute, sublicense, and/or
 *   sell copies of the Software, and to permit persons to whom
 *   the Software is furnished to do so, subject to the following
 *   conditions:
 *
 *   The above copyright notice and this permission notice shall
 *   be included in all copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *   NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *   HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *   WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *   OTHER DEALINGS IN THE SOFTWARE.
 *
 * -----------------------------------------------------------------------
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <bufprintf.h>
#include <zzjson/zzjson.h>
#include "hdt-common.h"

#define add_i(name,value) *item = zzjson_object_append(config, *item, name, zzjson_create_number_i(config, value))
#define add_s(name,value) *item = zzjson_object_append(config, *item, name, zzjson_create_string(config, value))
#define add_bool_true(name) *item = zzjson_object_append(config, *item, name, zzjson_create_true(config))
#define add_bool_false(name) *item = zzjson_object_append(config, *item, name, zzjson_create_false(config))
#define add_hi(value) add_i(#value,hardware->value)
#define add_hs(value) add_s(#value,(char *)hardware->value)
#define add_b(name,value) if (value==true) {add_bool_true((char *)name);} else {add_bool_false((char *)name);}
#define add_hb(value) add_b(#value,hardware->value)

extern struct print_buf p_buf;

void print_and_flush(ZZJSON_CONFIG *config, ZZJSON **item);
int dumpprintf(FILE *p, const char *format, ...);
void flush (char *filename, ZZJSON_CONFIG *config, ZZJSON ** item);

void dump_cpu(struct s_hardware *hardware, ZZJSON_CONFIG *config, ZZJSON **item);
void dump_pxe(struct s_hardware *hardware, ZZJSON_CONFIG *config, ZZJSON **item);
void dump_syslinux(struct s_hardware *hardware, ZZJSON_CONFIG *config, ZZJSON **item);
void dump_vpd(struct s_hardware *hardware, ZZJSON_CONFIG *config, ZZJSON **item);
