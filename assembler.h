/*
 * =====================================================================================
 *
 *       Filename:  assembler.h
 *
 *    Description: Header hosting functions 
 *
 *        Version:  1.0
 *        Created:  09/15/2020 01:45:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vincenzo Petrolo
 *   Organization:  /
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "macros.h"

#define INSTRUCTION_LENGTH 8
#define COLUMNS 52
#define ROW 16
#define FILENAME "MEM"

char *convert_to_binary(char *instruction);
u_int8_t convert_to_int_8bit(char *bits); //using 8 bit type
char *convert_to_hex(u_int8_t n);
