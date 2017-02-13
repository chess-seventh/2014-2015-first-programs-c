#include <stdio.h>
#include <stdbool.h>

struct Element{
	char value;
	struct Element next;
};

typedef struct Element s_Element;

s_Element* stack_init();

void stack_add(s_Element *stack, char value);
void stack_remove(s_Element *stack);
void stack_getFirst(s_Element *stack);
void stack_isEmpty(s_Element *stack);
void stack_getSize(s_Element *stack);