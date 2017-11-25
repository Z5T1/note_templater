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

#include "template.h"

#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/** Loads the next block from a string.
  * @param string	A pointer to the string to load the block from. This
  *			pointer will be moved forwared to the character
  *			after the end ofthe block.
  * @return		A new block object. This must be freed with free_block.
  */
struct block* load_next_block(char** string) {
	struct block* b;

	b = malloc(sizeof(struct block));
	b->next = NULL;

	// Find what type this block is
	// Whitespace
	if ( isspace(*string[0]) ) {
		b->type = WHITESPACE;
		b->value = NULL;
	}
	// Variable
	else if ( *string[0] == '$' && *string[1] == '{' ) {
		int len;
		*string += 2;

		// Count the length
		for (len = 0; *string[len] != '}'; len++ ) {}

		// Copy the text
		b->value = malloc(len);
		strncpy(b->value, *string, len-1);

		// Update the string pointer
		*string += len;
	}
	// Text
	else {
		int len;
		printf("%s\n", *string);

		// Count the length
		for (len = 0;
			(*string[len] != '$' && *string[len+1] != '(')
			&& !isspace(*string[len])
		; len++ ) {}

		// Copy the text
		b->value = malloc(len+1);
		strncpy(b->value, *string, len);

		// Update the string pointer
		*string += len;
		printf("%s\n", *string);

	}

	return b;
}

/** Creates a template object from a template string.
  * @param name		The name of this template.
  * @param string	The string to load the template from.
  * @return		A new template object. This must be freed using 
  *			template_free.
  */
struct template* template_create(char* string) {
	struct template* t;

	t = malloc(sizeof(struct template));


	return t;
}
