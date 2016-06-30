#include "execution.h"
#include <stdint.h>
#include <stdio.h>


// Instruction instructionTable[256] = {
  // [0x09] = addwf,
  // [0x08] = addwfc,
// };

int addwf(instructionCode, WREG, fileRegister){
  if (instructionCode == 0x24){
    WREG = WREG + fileRegister;
    return WREG;
  }  
  if (instructionCode == 0x26){
    fileRegister = WREG + fileRegister;
    return fileRegister;
  }
  else
    return 0;
}