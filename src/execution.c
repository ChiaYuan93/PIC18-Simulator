#include "execution.h"
#include <stdint.h>
#include <stdio.h>
#include <RegisterAddress.h>


// Instruction instructionTable[256] = {
  // [0x09] = addwf,
  // [0x08] = addwfc,
// };

// instructionTable[instructionCode << 8] (instructionCode);

int addwf (fileRegAddr, d, a){
  if(!d){ 
  WREG = WREG + memory[fileRegAddr];
  }
  else{
  memory[fileRegAddr] = WREG + memory[fileRegAddr]; 
  }
}

int addwfc (fileRegAddr, d, a){
  if(!d){
  WREG = WREG + memory[fileRegAddr];
  }
  else{
  memory[fileRegAddr] = WREG + memory[fileRegAddr]; 
  }
}

// int andwf(int instructionCode, int WREG, int fileRegister){
  // int Checkbit2 = (instructionCode >> 1) & 1;
  // if (!Checkbit2){
    // WREG = WREG & fileRegister;
    // return WREG;
  // }
  // else{
    // fileRegister = WREG & fileRegister;
    // return fileRegister;
  // }
// }

// int addlw(int instructionCode, int)