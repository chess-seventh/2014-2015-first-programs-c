#include "stack.h"

s_Element* stack_init()
{
	return NULL;
}

s_Element* stack_init(char value)
{
	s_Element *e = (s_Element*) malloc(sizeof(s_Element));
	e->value = value
	e->next = NULL;
	return e;
}

void stack_add(s_Element *stack, char value)
{
	s_Element *tmp = stack;
	while(tmp != NULL)
		tmp = tmp->next;

	s_Element *e = stack_init(value);
	tmp = e;
}

void stack_remove(s_Element *stack)
{
	s_Element *tmp = stack;
	while(tmp->next != NULL)
		tmp = tmp->next;

	tmp = NULL; 
}

char stack_getFirst(s_Element *stack)
{
	s_Element *tmp = stack;
	while(tmp->next != NULL)
		tmp = tmp->next;

	return tmp->value; 
}

bool stack_isEmpty(s_Element *stack)
{
	return (stack == NULL) ? true : false;
}

void stack_getSize(s_Element *stack)
{
	int counter = 0;
	s_Element *tmp = stack;

	while(tmp != NULL)
	{
		tmp = tmp->next;
		counter++;
	}

	return counter; 
}