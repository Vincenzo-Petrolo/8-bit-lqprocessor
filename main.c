/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description: Main of the assembler 
 *
 *        Version:  1.0
 *        Created:  09/15/2020 08:13:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vincenzo Petrolo
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "assembler.h"

int main(int argc, char* argv[])
{
	FILE *fp = fopen(argv[1],"r");
	FILE *fp1 = fopen(FILENAME,"w");
	char* instruction = NULL;
	size_t len = 0;
	int addr_len = 0x0;	//each 16 group of data gets incremented by 16
	int instr = 0;		// max is 16x16 = 256
	int result = 0;

	if (fp == NULL || fp1 == NULL) exit(EXIT_FAILURE);

	fprintf(fp1,"%s\n",VERSION);	//printing version in the file


	while (instr < 256) {
		fprintf(fp1,"%02x:",addr_len);	
		for (int i = 0; i < 16; i++){
			result = getline(&instruction,&len,fp);;		
			if (result != -1) {
				char *bin_string = convert_to_binary(instruction);
				char *hex = convert_to_hex(convert_to_int_8bit(bin_string));
				free(bin_string);
				fprintf(fp1," %s",hex);
				free(hex);
			} else {
				fprintf(fp1," 00");
			}
		}

		addr_len += 16;
		fprintf(fp1,"\n");
		instr += 16;
	}

	fclose(fp);
	fclose(fp1);

	return 0;
}

