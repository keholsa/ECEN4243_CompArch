/***************************************************************/
/*                                                             */
/*   RISC-V RV32 Instruction Level Simulator                   */
/*                                                             */
/*   ECEN 4243                                                 */
/*   Oklahoma State University                                 */
/*                                                             */
/***************************************************************/

#ifndef _SIM_ISA_H_
#define _SIM_ISA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

//
// MACRO: Check sign bit (sb) of (v) to see if negative
//   if no, just give number
//   if yes, sign extend (e.g., 0x80_0000 -> 0xFF80_0000)
//
#define SIGNEXT(v, sb) ((v) | (((v) & (1 << (sb))) ? ~((1 << (sb))-1) : 0))

// I Instructions
int ADDI (int Rd, int Rs1, int Imm, int Funct3) {//add imediate
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] + Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int XORI (int Rd, int Rs1, int Imm, int Funct3){ //xor immediate
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] ^ Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int ORI (int Rd, int Rs1, int Imm, int Funct3){//or immediate
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] | Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int ANDI (int Rd, int Rs1, int Imm, int Funct3){// and immediate
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] & Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SLLI (int Rd, int Rs1, int Imm, int Funct3){ //shif left logical imm
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] << Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
  }
int SRLI (int Rd, int Rs1, int Imm, int Funct3){//shift right lofical imm 
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] >> Imm;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SRAI (int Rd, int Rs1, int Imm, int Funct3){// shift right arith imm
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] >> Imm;
  cur = SIGNEXT(cur, 31-Imm);
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SLTI (int Rd, int Rs1, int Imm, int Funct3){//set less than imm
  int cur = 0;
  cur = (CURRENT_STATE.REGS[Rs1] < Imm) ?1:0;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SLTIU (int Rd, int Rs1, int Imm, int Funct3){//let less than imm (u)
  int cur = 0;
  cur = (CURRENT_STATE.REGS[Rs1] < Imm)?1:0;
  cur = SIGNEXT(cur, Imm);// zero extend
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int LB (char* i_); //load byte 
int LH (char* i_); // load half
int LW (char* i_); // load word
int LBU (char* i_);// load byte (u)
int LHU (char* i_); //load half (u)

// U Instruction
int AUIPC (int Rd , int Imm){//add upper imm to pc 
  int cur = 0;
  cur = Imm << 12;
  NEXT_STATE.REGS[Rd] = CURRENT_STATE.PC + cur; //?????
  return 0;
}
int LUI (int Rd, int Imm ){//load upper imm
  int cur = 0;
  cur = Imm << 12;
  NEXT_STATE.REGS[Rd] = cur; 
}


// S Instruction
int SB (int Rd, int Rs1, int Rs2, int Funct3){// store byte
  return 0;
}
int SH (int Rd, int Rs1, int Rs2, int Funct3){ //store half
  return 0;
}
int SW (int Rd, int Rs1, int Rs2, int Funct3){ // store word
  return 0;
}


// R instruction
int ADD (int Rd, int Rs1, int Rs2, int Funct3) { //add Rs1 to Rs2
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] + CURRENT_STATE.REGS[Rs2];
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SUB (int Rd, int Rs1, int Rs2, int Funct3){//subtraction rs1- rs2
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1]- CURRENT_STATE.REGS[Rs2];
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int XOR (int Rd, int Rs1, int Rs2, int Funct3){//xor
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] ^ CURRENT_STATE.REGS[Rs2];
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int OR (int Rd, int Rs1, int Rs2, int Funct3){//or
  int cur = 0;
  cur = CURRENT_STATE.REGS[0] | CURRENT_STATE.REGS[1];
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int AND (int Rd, int Rs1, int Rs2, int Funct3){//and 
  int cur = 0;
  cur = CURRENT_STATE.REGS[0] & CURRENT_STATE.REGS[1];
  NEXT_STATE.REGS[Rd] = cur;
} 
int SLL (int Rd, int Rs1, int Rs2, int Funct3)//shift left logical
{
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] << (CURRENT_STATE.REGS[Rs2]);
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
}
int SRL (int Rd, int Rs1, int Rs2, int Funct3){//shift right logical
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] >> (CURRENT_STATE.REGS[Rs2]);
  NEXT_STATE.REGS[Rd] = cur;
  return 0;

}
int SRA (int Rd, int Rs1, int Rs2, int Funct3){ //shift right arith*
  int cur = 0;
  cur = CURRENT_STATE.REGS[Rs1] >> (CURRENT_STATE.REGS[Rs2]);
  NEXT_STATE.REGS[Rd] = SIGNEXT(cur, 12);
  return 0;
}
int SLT (int Rd, int Rs1, int Rs2, int Funct3){//set less than 
  int cur = 0;
  cur = (CURRENT_STATE.REGS[Rs1] < (CURRENT_STATE.REGS[Rs2])) ? 1 : 0;
  NEXT_STATE.REGS[Rd] = cur;
  return 0;
} 
int SLTU (int Rd, int Rs1, int Rs2, int Funct3){//set less than (u)
  int cur = 0;
  cur = (CURRENT_STATE.REGS[Rs1] < (CURRENT_STATE.REGS[Rs2]))? 1 : 0;
  NEXT_STATE.REGS[Rd] = SIGNEXT(cur, 12);
  }


// B instructions
int BEQ (int Rs1, int Rs2, int Imm, int Funct3){ //branch ==
  int cur = 0;
  Imm = Imm << 1;
  if(CURRENT_STATE.REGS[Rs1] == CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC +4) + SIGNEXT(Imm, 13);
  return 0;
}
int BNE (int Rs1, int Rs2, int Imm, int Funct3) { //branch not equal !=
  int cur = 0;
  Imm = Imm << 1; 
  if (CURRENT_STATE.REGS[Rs1] != CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC + 4) + (SIGNEXT(Imm,13));
  return 0;
}

int BLT (int Rs1, int Rs2, int Imm, int Funct3){//branch <
  int cur = 0;
  Imm = Imm << 1;
  if(CURRENT_STATE.REGS[Rs1] < CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC + 4) + (SIGNEXT(Imm,13));
  return 0;
}

int BGE (int Rs1, int Rs2, int Imm, int Funct3){ //branch <=
  int cur = 0;
  Imm = Imm << 1;
  if(CURRENT_STATE.REGS[Rs1] <= CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC + 4) + (SIGNEXT(Imm,13));
  return 0;

}

int BLTU (int Rs1, int Rs2, int Imm, int Funct3){ // branch < u 
  int cur = 0;
  Imm = Imm << 1;
  if(CURRENT_STATE.REGS[Rs1] < CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC + 4) + (SIGNEXT(Imm,13));
  return 0;
}

int BGEU (int Rs1, int Rs2, int Imm, int Funct3){ // branch >= u
  int cur = 0;
  Imm = Imm << 1;
  if(CURRENT_STATE.REGS[Rs1] >= CURRENT_STATE.REGS[Rs2])
    NEXT_STATE.PC = (CURRENT_STATE.PC + 4) + (SIGNEXT(Imm,13));
    return 0;

}


// I instruction
int JALR (int Rd, int Rs1, int Imm, int Funct3){
  int cur = 0;
  cur = CURRENT_STATE.PC + 4;
  Rd = cur;
  NEXT_STATE.PC = Rs1 + Imm;
  return 0;
}

// J instruction
int JAL (int Rd, int Rs1, int Rs2,  int Imm, int Funct3){
  int cur = 0;
  cur = CURRENT_STATE.PC + 4;
  Rd = cur;
  NEXT_STATE.PC = Imm;
  return 0;
}


int ECALL (char* i_){return 0;}

#endif
