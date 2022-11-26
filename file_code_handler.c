// Made by Alexey Popov, GNU GPLv3
// UNFINISHED YET

#include <stdio.h>
#include <stdlib.h>
#include "hex_file_handler.c"

enum {EEPROM_SEGMENT=0x0}; //EEPROM record-type of code_unit; IS_NOT_CORRECT

struct text_unit {
	char *str;
	struct text_unit *next;
};

struct text_type {
	struct text_unit *first, *last; 
};

struct code_unit {
	int byte_count;
	int start_adress;
	int record_type;
	char *bytes;
	int control_sum;
	struct code_unit *next;
};

struct code_type {
	struct code_unit *first, *last;
};

void init_text_var(struct text_type *list)
{
	list->first = NULL;
	list->last = NULL;
}

void init_code_var(struct code_type *code)
{
	code->first = NULL;
	code->last = NULL;
}	

void add_text(struct text_type *list, char* str)
{
	struct text_unit item = malloc(sizeof(struct text_unit));
	item->str = str;
	item->next = NULL;
	if(!(list->first))
	{
		list->first = item;
		list->last = item;
	}
	else
	{
		list->last->next = item;
		list->last = item;
	}
}


static struct code_unit *format_text(struct text_unit text)
{
	struct code_unit *result = malloc(sizeof(struct code_unit));
}

static void add_code_unit(struct code_type *list, struct code_unit item)
{
	if(!(list->first))
	{
		list->first = item;
		list->last = item;
	}
	else
	{
		list->last->next = item;
		list->last = item;
	}
}

void translate_text(struct text_type text, struct code_type *code)
{
	struct text_unit *current = text.first;
	for(;current;current = current->next)
	{
		struct code_unit temp = format_text(current);
		add_code_unit(code, temp);
	}
}
