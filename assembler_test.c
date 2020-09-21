/*
 * =====================================================================================
 *
 *       Filename:  assembler_test.c
 *
 *    Description: c file to test what done 
 *
 *        Version:  1.0
 *        Created:  09/15/2020 06:57:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vincenzo Petrolo
 *   Organization:  
 *
 * =====================================================================================
 */
#include "assembler.h"

int main(void)
{
	char instruction[] = "ADD   R1  , R2  , R2";
	char *instruction_bits = convert_to_binary(instruction);
	char *hex = convert_to_hex(convert_to_int_8bit(instruction_bits));
	printf("%s\n",instruction_bits);
	printf("%u",convert_to_int_8bit(instruction_bits));
	printf("%s\n",hex);
	free(hex);
	free(instruction_bits);
	return 0;
}
