/*
 * =====================================================================================
 *
 *       Filename:  assembler.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/15/2020 06:22:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Vincenzo Petrolo 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "assembler.h"
#include <string.h>

char *convert_to_binary(char *instruction)
{
	char *bit_strings = (char *) malloc(sizeof(char) * INSTRUCTION_LENGTH);
	
	if (strstr(instruction,"ADD")) {
		bit_strings[0] = '0';
		bit_strings[1] = '0';
	} else if (strstr(instruction,"SUB")) {
		bit_strings[0] = '0';
		bit_strings[1] = '1';
	} else if (strstr(instruction,"MUL")) {
		bit_strings[0] = '1';
		bit_strings[1] = '0';
	}  else if (strstr(instruction,"DIV")) {
		bit_strings[0] = '1';
		bit_strings[1] = '1';
	}  else if (strstr(instruction,"MOV")) {
		bit_strings[0] = '0';
		bit_strings[1] = '0';
	}
	
	
	char *token = strtok(instruction,REG_DELIMITER);
	int i = 0;
	while (token != NULL) {

		if (strstr(token,"ZERO")) {
			bit_strings[2 + i] = '0';
			bit_strings[3 + i] = '0';
		} else if (strstr(token,"ONE")) {
			bit_strings[2 + i] = '0';
			bit_strings[3 + i] = '1';
		} else if (strstr(token,"R1")) {
			bit_strings[2 + i] = '1';
			bit_strings[3 + i] = '0';
		} else if (strstr(token,"R2")) {
			bit_strings[2 + i] = '1';
			bit_strings[3 + i] = '1';
		}
		i += 2;	
		token = strtok(NULL,REG_DELIMITER);
	}

	return bit_strings;
}

u_int8_t  convert_to_int_8bit(char *bits)
{
	u_int8_t  tot = 0x0;
	for (int i = 0; i < INSTRUCTION_LENGTH; i++) {
		if (bits[i] == '1') {
			u_int8_t cur = 0x1;
			cur = cur << (-i + INSTRUCTION_LENGTH -1);
			tot += cur;
		}
	}
	return tot;
}

char *convert_to_hex(u_int8_t n)
{
	char *hex_str = (char *) malloc(sizeof(char) * 2);
	sprintf(hex_str, "%x",n);
	return hex_str;
}
