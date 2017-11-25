/*****************************************************************************\
Copyright 2017 Scott Court

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
\*****************************************************************************/

#pragma once

/* The valid block types. */
enum block_type {
	TEXT,
	VARIABLE,
	WHITESPACE
};

/* Holds a block of a template. */
struct block {
	enum block_type type;	/* The type of this block. */
	char* value;		/* The value (text/variable name) of this
				   block. */
	struct block* next;	/* A pointer to the next block of this
				   template, or NULL if this the last block in
				   this template. */
};

/* Holds a template. */
struct template {
	char* name;			/* The name of this template */
	struct block* first_block;	/* The first block of this template. */
};

/** Loads the next block from a string.
  * @param string	A pointer to the string to load the block from. This
  *			pointer will be moved forwared to the character
  *			after the end ofthe block.
  * @return		A new block object. This must be freed with free_block.
  */
struct block* load_next_block(char** string);

/** Creates a template object from a template string.
  * @param string	The string to load the template from.
  * @return		A new template object. This must be freed by the caller
  *			using template_free.
  */
struct template* template_create(char* string);

