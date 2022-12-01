// text formater module for hex_file_handler.c
// NOT FINISHED YET
// MADE BY ALEXEY POPOV
// GNU GPLv3

#include <stdio.h>
#include <stdlib.h>
#include "cut_text.h"

static enum {
	A_LETTER = 'A',
	B_LETTER = 'B',
	C_LETTER = 'C',
	D_LETTER = 'D',
	E_LETTER = 'E',
	F_LETTER = 'F',
	A_DECIMAL_CODE = 10,
	B_DECIMAL_CODE = 11,
	C_DECIMAL_CODE = 12,
	D_DECIMAL_CODE = 13,
	E_DECIMAL_CODE = 14,
	F_DECIMAL_CODE = 15,
	ZERO_CODE_NUMBER = '0',
	THE_BASE_OF_HEX_NUMBER_SYSTEM = 16
};

static enum {
	START_INDEX__COUNT_OF_BYTES = 1,
	END_INDEX__COUNT_OF_BYTES = 2,
	START_INDEX__START_ADRESS = 3,
	END_INDEX__START_ADRESS = 4
};

int index_out_of_buffer_length(struct text_unit text, int index)
{
	return (text.length - 1) < index;
}

int get_decimal_by_char(char *hex_char)
{
	switch(hex_char) {
	case A_LETTER:
		return A_DECIMAL_CODE;
	case B_LETTER:
		return B_DECIMAL_CODE;
	case C_LETTER:
		return C_DECIMAL_CODE;
	case D_LETTER:
		return D_DECIMAL_CODE;
	case E_LETTER:
		return E_DECIMAL_CODE;
	case F_LETTER:
		return F_DECIMAL_CODE;
	else:
		return hex_char - ZERO_CODE_NUMBER;
	}
}

int translate_hex_to_decimal(const char *hex, int start, int end)
{
	int temp = 0;
	int i;
	for(hex += start, i = 0; i < end; i++)
	{
		temp = temp * THE_BASE_OF_HEX_NUMBER_SYSTEM;
		temp = temp + get_decimal_by_char(hex[i]);
	}
	return temp;
}

int get_count_of_bytes(struct text_unit text)
{
	int res = -1;
	if(!index_out_of_buffer_length(text, START_INDEX__COUNT_OF_BYTES) &&
		!index_out_of_buffer(text, END_INDEX__COUNT_OF_BYTES))
	{
		char *str = malloc(sizeof(2*char));
		str[0] = text[COUNT_OF_BYTES_START_INDEX];
		str[1] = text[COUNT_OF_BYTES_END_INDEX];
		res =  translate_hex_to_decimal(
			str,
			START_INDEX__COUNT_OF_BYTES,
			END_INDEX__COUNT_OF_BYTES);
	}
	return res;
}

int get_code_adress(struct text_unit text)
{}

int get_record_type(struct text_unit text)
{}

int *get_code_bytes(struct text_unit text)
{}

int *get_check_sum(struct text_unit text)
{}
