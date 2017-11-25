#include "template.h"

#include <stdio.h>

void print_block (struct block* b) {
	printf("Type: %d\nValue: %s\nNext: %p\n", b->type, b->value, b->next);
}

int main (int argc, char** argv) {
	char* string = "---------- ${Item Name} ----------";
	struct block* b;

	b = load_next_block(&string);
	printf("foo\n");
	print_block(b);

	return 0;
}
