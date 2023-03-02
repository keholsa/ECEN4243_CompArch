/***************************************************************/
/*                                                             */
/*   RISC-V RV32 Instruction Level Simulator                   */
/*                                                             */
/*   ECEN 4243                                                 */
/*   Oklahoma State University                                 */
/*                                                             */
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "isa.h"

char *byte_to_binary(int x) {

  static char b[9];
  b[0] = '\0';

  int z;
  for (z = 128; z > 0; z >>= 1) {
    strcat(b, ((x & z) == z) ? "1" : "0");
  }

  return b;
}

char *byte_to_binary32(int x) {

  static char b[33];
  b[0] = '\0';

  unsigned int z;
  for (z = 2147483648; z > 0; z >>= 1) {
    strcat(b, ((x & z) == z) ? "1" : "0");
  }

  return b;
}

int bchar_to_int(char* rsa) {

  int i = 0;
  int result = 0;
  int t = 0;
  while(rsa[i] != '\0')i++;
  while(i>0)
    {
      --i;
      // printf("%d\n", (rsa[i]-'0')<<t);
      result += (rsa[i] - '0')<<t;
      t++;
    }
  return result;
}

int r_process(char* i_) {

  char d_opcode[8];
  d_opcode[0] = i_[31-6]; 
  d_opcode[1] = i_[31-5]; 
  d_opcode[2] = i_[31-4]; 
  d_opcode[3] = i_[31-3];
  d_opcode[4] = i_[31-2]; 
  d_opcode[5] = i_[31-1]; 
  d_opcode[6] = i_[31-0];
  d_opcode[7] = '\0';
  char rs1[6]; rs1[5] = '\0';		   
  char rs2[6]; rs2[5] = '\0'; // create rs2 that stores 6 chars iniciess 0 to 5
  char rd[6]; rd[5] = '\0';
  char funct3[4]; funct3[3] = '\0';
  char funct7[8]; funct7[7] = '\0';
  
  for(int i = 0; i < 5; i++) {
    rs1[i] = i_[31-19+i];
    rs2[i] = i_[31-24+i];            
    rd[i] = i_[31-11+i];
  }
  for(int i = 0; i < 3; i++) {
    funct3[i] = i_[31-14+i];
  }
   for(int i = 0; i < 7; i++) {
    funct7[i] = i_[i]; // now we got it :D
  }
  int Rs1 = bchar_to_int(rs1);
  int Rs2 = bchar_to_int(rs2);		   
  int Rd = bchar_to_int(rd);
  int Funct3 = bchar_to_int(funct3);
  //int Funct7 = bchar_to_int(funct7);
  printf ("Opcode = %s\n Rs1 = %d\n Rs2 = %d\n Rd = %d\n Funct3 = %d\n\n",
	  d_opcode, Rs1, Rs2, Rd, Funct3);
  printf("\n");

  /* Example - use and replicate */
  if(!strcmp(d_opcode,"0110011")) {
    switch (Funct3)
    {
    case 0x0 /*add */:
      if(!strcmp(funct7,"0100000")){
        printf("this is the sub instruction\n");
        SUB(Rd, Rs1, Rs2, Funct3);
        break;
      }
      else if(!strcmp(funct7,"0000000")){
        printf("--- This is an ADD instruction. \n");
        ADD(Rd, Rs1, Rs2, Funct3);
        break;
      }
    case 0x1 /* shift left logical */:
      printf("--- This is a SLL instruction. \n");
      SLL(Rd, Rs1, Rs2, Funct3);
      break;
    case 0x2 /* set less than */:
      printf("--- This is a Set less than instruction. \n");
      SLT(Rd, Rs1, Rs2, Funct3);      
      break;
      
    case 0x3 /* set less than (u) */:
      printf("--- This is a Set less than (u) instruction. \n");
      SLTU(Rd, Rs1, Rs2, Funct3);    
      break;
    case 0x4 /* XOR */:
      printf("--- This is a XOR instruction. \n");
      XOR(Rd, Rs1, Rs2, Funct3);
      break;
    case 0x5 /* shift right logical */:
      if(!strcmp(funct7, "0100000")){
      printf("--- This is a Shift Right Arith instruction. \n");
      SRL(Rd, Rs1, Rs2, Funct3);
      break;
      }
      else{
        printf("--- This is an Shift right logical instruction. \n");
        SRL(Rd, Rs1, Rs2, Funct3);
        break;
      } 
    case 0x6 /* OR */:
      printf("--- This is a OR instruction. \n");
      OR(Rd, Rs1, Rs2, Funct3);
      break;
    case 0x7 /* AND */:
      printf("--- This is a AND instruction. \n");
      AND(Rd, Rs1, Rs2, Funct3);

    default:
      printf("--- This is an unknown instruction. \n");
      break;
    }
   
  }

}

int i_process(char* i_) {

  char d_opcode[8];
  d_opcode[0] = i_[31-6]; 
  d_opcode[1] = i_[31-5]; 
  d_opcode[2] = i_[31-4]; 
  d_opcode[3] = i_[31-3];
  d_opcode[4] = i_[31-2]; 
  d_opcode[5] = i_[31-1]; 
  d_opcode[6] = i_[31-0]; 
  d_opcode[7] = '\0';
  char rs1[6]; rs1[5] = '\0';		   
  char rd[6]; rd[5] = '\0';
  char funct3[4]; funct3[3] = '\0';
  char imm[13]; imm[12] = '\0';
  for(int i = 0; i < 5; i++) {
    rs1[i] = i_[31-19+i];
    rd[i] = i_[31-11+i];
  }
  for(int i = 0; i < 12; i++) {
    imm[i] = i_[31-31+i];
  }
  for(int i = 0; i < 3; i++) {
    funct3[i] = i_[31-14+i];
  }
  int Rs1 = bchar_to_int(rs1);
  int Rd = bchar_to_int(rd);
  int Funct3 = bchar_to_int(funct3);
  int Imm = bchar_to_int(imm);
  printf ("Opcode = %s\n Rs1 = %d\n Imm = %d\n Rd = %d\n Funct3 = %d\n\n",
	  d_opcode, Rs1, Imm, Rd, Funct3);
  printf("\n");

  /* Add other imm instructions here */ 

  /* This is an Add Immediate Instruciton */
  if(!strcmp(d_opcode,"0010011")) {
    switch (Funct3)
    {
    case 0X0 /* ADD Imm */:
      printf("--- This is an ADD Immediate instruction. \n");
      ADDI(Rd, Rs1, Imm, Funct3);
      break;

    case 0X1 /* shift left logical Imm */:
      if(Imm ==0000000){
        printf("--- This is a Load half instruction. \n");
       // LH(Rd, Rs1, Imm, Funct3);
        break;
      }
      else{
        printf("--- This is a shift left logical immediate instruction. \n");
        SLLI(Rd, Rs1, Imm, Funct3); 
        break;
      }

    case 0X2 /* set less than Imm */:
      printf("--- This is a set less than immediate instruction. \n");
      SLTI(Rd,Rs1,Imm,Funct3);
      break;
    case 0X3 /* set less than Imm (u) */:
      printf("--- This is a set less than immediate (u) instruction. \n");
      SLTIU(Rd,Rs1,Imm,Funct3);
      break;
    case 0x4 /* XOR Imm */:
      printf("--- This is a XOR immediate instruction. \n");
      XORI(Rd,Rs1,Imm,Funct3);
      break;
    case 0X5 /* Shift right logical */:
      if(Imm == 0000000){
        printf("--- This is a shift right Arith immediate instruction. \n");
        SRAI(Rd,Rs1,Imm,Funct3);
        break;
      }
      else{
        printf("--- This is a shift right logical immediate instruction. \n");
        SRLI(Rd,Rs1,Imm,Funct3);
        break;
      }
    case 0x6 /*xOR Immediate*/:
      printf("--- This is an XOR immediate instruction. \n");
      XORI(Rd,Rs1,Imm,Funct3);
      break;
    case 0X7 /* AND Imm */:
      printf("--- This is an AND immediate instruction. \n");
      ANDI(Rd,Rs1,Imm,Funct3);
      break;
    default:
      printf("--- This is an invalid instruction. R-type error \n");
      break;
    }
  }	  
  return 1;	
}

int b_process(char* i_) {
  
  /* This function execute branch instruction */

  char d_opcode[8];
  d_opcode[0] = i_[31-6]; 
  d_opcode[1] = i_[31-5]; 
  d_opcode[2] = i_[31-4]; 
  d_opcode[3] = i_[31-3];
  d_opcode[4] = i_[31-2]; 
  d_opcode[5] = i_[31-1]; 
  d_opcode[6] = i_[31-0]; 
  d_opcode[7] = '\0';
  char rs1[6]; rs1[5] = '\0';
  char rs2[6]; rs2[5] = '\0';		     
  char funct3[4]; funct3[3] = '\0';
  char imm[13]; 
  for(int i = 0; i < 5; i++) {
    rs1[i] = i_[31-19+i];
    rs2[i] = i_[31-24+i];                
  }
  // Old-fashioned method but works :)
  imm[0] = i_[31-31]; 
  imm[1] = i_[31-7]; 
  imm[2] = i_[31-30]; 
  imm[3] = i_[31-29];
  imm[4] = i_[31-28]; 
  imm[5] = i_[31-27]; 
  imm[6] = i_[31-26];
  imm[7] = i_[31-25];
  imm[8] = i_[31-11];
  imm[9] = i_[31-10];
  imm[10] = i_[31-9];
  imm[11] = i_[31-8];
  imm[12] = '\0';  

  for(int i = 0; i < 3; i++) {
    funct3[i] = i_[31-14+i];
  }
  int Rs1 = bchar_to_int(rs1);
  int Rs2 = bchar_to_int(rs2);  
  int Funct3 = bchar_to_int(funct3);
  int Imm = bchar_to_int(imm);
  printf ("Opcode = %s\n Rs1 = %d\n Rs2 = %d\n Imm = %d\n Funct3 = %d\n\n",
	  d_opcode, Rs1, Rs2, Imm, Funct3);
  printf("\n");    

  /* Add branch instructions here */
  if(!strcmp(d_opcode,"1100011")) { // B-type branch
    switch (Funct3)
    {
    case 0x0 /* Banch if = */:
      printf("--- This is a BRANCH IF = instruction. \n");
      BEQ(Rs1,Rs2,Imm,Funct3);
      break;
    case 0x1 /* Banch != */:
      printf("--- This is a BRANCH != instruction. \n");
      BNE(Rs1,Rs2,Imm,Funct3);
      break;
    case 0x4 /* Banch if less than */:
      printf("--- This is a BRANCH less than instruction. \n");
      BLT(Rs1,Rs2,Imm,Funct3);
      break;
    case 0x5 /* Banch if greater than or = */:
      printf("--- This is a BRANCH greater than instruction. \n");
      BGE(Rs1,Rs2,Imm,Funct3);
      break;
    case 0x6 /* Banch if less than (u) */:
      printf("--- This is a BRANCH less than or equal instruction. \n");
      BLTU(Rs1,Rs2,Imm,Funct3);
      break;
      case 0x7 /* Banch if greater than or equal (u) */:
      printf("--- This is a BRANCH greater than or equal (u) instruction. \n");
      BGEU(Rs1,Rs2,Imm,Funct3);
      break;
    default:
      printf("--- Unknown instruction. \n");
      break;
    }
    printf("--- This is an BNE instruction. B-type error \n");
    BNE(Rs1, Rs2, Imm, Funct3);
    return 0;
  }	    
  
  return 1;

}

int s_process(char* i_) {

  /* This function execute S type instructions */
  char d_opcode[8];
  d_opcode[0] = i_[31-6]; 
  d_opcode[1] = i_[31-5]; 
  d_opcode[2] = i_[31-4]; 
  d_opcode[3] = i_[31-3];
  d_opcode[4] = i_[31-2]; 
  d_opcode[5] = i_[31-1]; 
  d_opcode[6] = i_[31-0];
  d_opcode[7] = '\0';
  char rs1[6]; rs1[5] = '\0';		   
  char rs2[6]; rs2[5] = '\0';
  char rd[6]; rd[5] = '\0';
  char funct3[4]; funct3[3] = '\0';
  char imm[7]; imm[6] = '\0';
  
  for(int i = 0; i < 5; i++) {
    rs1[i] = i_[31-19+i];
    rs2[i] = i_[31-24+i];            
    rd[i] = i_[31-11+i];
  }

  for(int i = 0; i < 3; i++) {
    funct3[i] = i_[31-14+i];
  }

  for(int i = 0; i < 7; i++) {
    imm[i] = i_[i]; 
  }

  int Rs1 = bchar_to_int(rs1);
  int Rs2 = bchar_to_int(rs2);		   
  int Rd = bchar_to_int(rd);
  int Funct3 = bchar_to_int(funct3);
  int Imm = bchar_to_int(imm);
  printf ("Opcode = %s\n Rs1 = %d\n Rs2 = %d\n Rd = %d\n Funct3 = %d\n\n", d_opcode, Rs1, Rs2, Rd, Funct3);
  printf("\n");

  if(!strcmp(d_opcode,"0100011")) {
    switch(Funct3) {
      case 0x0 :
        printf("--- This is an SB instruction. \n");
        SB(Rd, Rs1, Rs2, Imm);
        break;
      case 0x1 :
        printf("--- This is an SH instruction. \n");
        SH(Rd, Rs1, Rs2, Imm);
        break;
      case 0x2 :
        printf("--- This is an SW instruction. \n");
        SW(Rd, Rs1, Rs2, Imm);
        break;
    }
  }
  return 1;
}

int j_process(char* i_) {

  /* This function execute Jump instructions */

  /* Add jump instructions here */ 

  /* Add store instructions here */ 
    char d_opcode[8];
    d_opcode[0] = i_[31-6];
    d_opcode[1] = i_[31-5];
    d_opcode[2] = i_[31-4];
    d_opcode[3] = i_[31-3];
    d_opcode[4] = i_[31-2];
    d_opcode[5] = i_[31-1];
    d_opcode[6] = i_[31-0];
    d_opcode[7] = '\0';


    char imm[21];
    char rd[6];
    rd[5] = '\0';

    imm[0] = i_[31-31];
    imm[1] = i_[31-30];
    imm[2] = i_[31-29];
    imm[3] = i_[31-28];
    imm[4] = i_[31-27];
    imm[5] = i_[31-26];
    imm[6] = i_[31-25];
    imm[7] = i_[31-24];
    imm[8] = i_[31-23];
    imm[9] = i_[31-22];
    imm[10] = i_[31-21];
    imm[11] = i_[31-20];
    imm[12] = i_[31-19];
    imm[13] = i_[31-18];
    imm[14] = i_[31-17];
    imm[15] = i_[31-16];
    imm[16] = i_[31-15];
    imm[17] = i_[31-14];
    imm[18] = i_[31-13];
    imm[19] = i_[31-12];
    imm[20] = '\0';

    for(int i = 0; i < 3; i++) {
        rd[i] = i_[31-11+i];
    }

    int Rd = bchar_to_int(rd);
    int Imm = bchar_to_int(imm);

    /* Example - use and replicate */
    if(!strcmp(d_opcode,"0010111")) {
        printf("--- This is an AUIPC instruction. \n");
        AUIPC(Rd, Imm);
    }else if(!strcmp(d_opcode,"0110111")){
        printf("--- This is an LUI instruciton. \n");
        LUI(Rd, Imm);
    }

}


int u_process(char* i_) {

  /* This function execute U type instructions */

    char d_opcode[8];
    d_opcode[0] = i_[31-6];
    d_opcode[1] = i_[31-5];
    d_opcode[2] = i_[31-4];
    d_opcode[3] = i_[31-3];
    d_opcode[4] = i_[31-2];
    d_opcode[5] = i_[31-1];
    d_opcode[6] = i_[31-0];
    d_opcode[7] = '\0';


    char imm[21];
    char rd[6];
    rd[5] = '\0';

    imm[0] = i_[31-31];
    imm[1] = i_[31-30];
    imm[2] = i_[31-29];
    imm[3] = i_[31-28];
    imm[4] = i_[31-27];
    imm[5] = i_[31-26];
    imm[6] = i_[31-25];
    imm[7] = i_[31-24];
    imm[8] = i_[31-23];
    imm[9] = i_[31-22];
    imm[10] = i_[31-21];
    imm[11] = i_[31-20];
    imm[12] = i_[31-19];
    imm[13] = i_[31-18];
    imm[14] = i_[31-17];
    imm[15] = i_[31-16];
    imm[16] = i_[31-15];
    imm[17] = i_[31-14];
    imm[18] = i_[31-13];
    imm[19] = i_[31-12];
    imm[20] = '\0';

    for(int i = 0; i < 3; i++) {
        rd[i] = i_[31-11+i];
    }

    int Rd = bchar_to_int(rd);
    int Imm = bchar_to_int(imm);

    /* Example - use and replicate */
    if(!strcmp(d_opcode,"0010111")) {
        printf("--- This is an AUIPC instruction. \n");
        AUIPC(Rd, Imm);
    }else if(!strcmp(d_opcode,"0110111")){
        printf("--- This is an LUI instruciton. \n");
        LUI(Rd, Imm);
    }

  return 1;

}

int interruption_process(char* i_) {

  ECALL(i_);
  RUN_BIT = 0;
  return 0;

}

int decode_and_execute(char* i_) {

  /* 
     This function decode the instruction and update 
     CPU_State (NEXT_STATE)
  */

  if((i_[25] == '0') && (i_[26] == '0') &&
     (i_[27] == '1') && (i_[28] == '0') &&
     (i_[29] == '0') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is an Immediate Type Instruction. \n");
    i_process(i_);
    return 1;
  }
  if((i_[25] == '0') && (i_[26] == '1') &&
     (i_[27] == '1') && (i_[28] == '0') &&
     (i_[29] == '0') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is an R Type Instruction. \n");
    r_process(i_);
    return 2;
  }    
  if((i_[25] == '1') && (i_[26] == '1') &&
     (i_[27] == '0') && (i_[28] == '0') &&
     (i_[29] == '0') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is a B Type Instruction. \n");
    b_process(i_);
    return 3;
  }
  if((i_[25] == '0') && (i_[26] == '1') &&
     (i_[27] == '0') && (i_[28] == '0') &&
     (i_[29] == '0') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is a S Type Instruction. \n");
    s_process(i_);
    return 4;
  }  
  if((i_[25] == '1') && (i_[26] == '1') &&
     (i_[27] == '0') && (i_[28] == '1') &&
     (i_[29] == '1') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is a J Type Instruction. \n");
    j_process(i_);
    return 5;
  }
  if((i_[25] == '0') && (i_[26] == '0') &&
     (i_[27] == '1') && (i_[28] == '0') &&
     (i_[29] == '1') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is a U Type Instruction. \n");
    u_process(i_);
    return 6;
  }  
  if((i_[25] == '1') && (i_[26] == '1') &&
     (i_[27] == '1') && (i_[28] == '0') &&
     (i_[29] == '0') && (i_[30] == '1') && (i_[31] == '1')) {
    printf("- This is a Software Interruption Instruction. \n");
    interruption_process(i_);
    return 7;
  }

  return 0;

}

unsigned int OPCODE (unsigned int i_word) {

  return ((i_word<<27)>>27);

}

void process_instruction() {

  /* 
     execute one instruction here. You should use CURRENT_STATE and modify
     values in NEXT_STATE. You can call mem_read_32() and mem_write_32() to
     access memory. 
  */   

  unsigned int inst_word = mem_read_32(CURRENT_STATE.PC);
  printf("The instruction is: %x \n", inst_word);
  printf("33222222222211111111110000000000\n");
  printf("10987654321098765432109876543210\n");
  printf("--------------------------------\n");
  printf("%s \n", byte_to_binary32(inst_word));
  printf("\n");
  decode_and_execute(byte_to_binary32(inst_word));

  NEXT_STATE.PC += 4;

}
