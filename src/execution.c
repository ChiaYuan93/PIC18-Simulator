#include "execution.h"
#include <stdint.h>
#include <stdio.h>


// Instruction instructionTable[256] = {
  // [0x09] = addwf,
  // [0x08] = addwfc,
// };

// instructionTable[instructionCode << 8] (instructionCode);

int addwf(int instructionCode, int WREG, int fileRegister){
  int Checkbit2 = (instructionCode >> 1) & 1;
  if (!Checkbit2){
    WREG = WREG + fileRegister;
    return WREG;
  }  
  else{
    fileRegister = WREG + fileRegister;
    return fileRegister;
  }
}

int addwfc(int instructionCode, int WREG, int fileRegister, int CFlag){
  int Checkbit2 = (instructionCode >> 1) & 1;
  if (!Checkbit2){
    WREG = WREG + fileRegister + CFlag;
    return WREG;
  }
  else{
    fileRegister = WREG + fileRegister + CFlag;
    return fileRegister;
  }
}

int andwf(int instructionCode, int WREG, int fileRegister){
  int Checkbit2 = (instructionCode >> 1) & 1;
  if (!Checkbit2){
    WREG = WREG & fileRegister;
    return WREG;
  }
  else{
    fileRegister = WREG & fileRegister;
    return fileRegister;
  }
}