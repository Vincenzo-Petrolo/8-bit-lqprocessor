/*
 * =====================================================================================
 *
 *       Filename:  macros.h
 *
 *    Description: Macros for my assembler 
 *
 *        Version:  1.0
 *        Created:  09/15/2020 01:38:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Vincenzo Petrolo
 *   Organization:  /
 *
 * =====================================================================================
 */
#ifndef __ASM_MACROS__
#define __ASM_MACROS__
//instructions
#define ADD "00"
#define SUB "01"
#define MUL "10"
#define DIV "11"

//registers
#define ZERO "00"
#define ONE  "01"
#define R1   "10"
#define R2   "11"

//delimiter of instruction
#define REG_DELIMITER "," //comma 
#define INSTR_REG_DELIMITER " " //space

//strings
#define VERSION "v3.0 hex words addressed"
#define ADDR_DELIMITER ":"
//
//
//Example of an instruction
//ADD ZERO,ONE,ONE -> 0000011

#endif
