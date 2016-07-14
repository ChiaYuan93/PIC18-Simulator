#include "execution.h"
#include <stdint.h>
#include <stdio.h>
#include <RegisterAddress.h>


// Instruction instructionTable[256] = {
  // [0x09] = addwf,
  // [0x08] = addwfc,
// };

// instructionTable[instructionCode << 8] (instructionCode);

int GPR (fileRegAddr, d){
  int TempReg = memory[fileRegAddr];
  fileRegAddr = (BSR << 8) + fileRegAddr;
  if(!d){
    memory[fileRegAddr] = WREG;
  }
  else{
    memory[fileRegAddr] = TempReg;
  }
  return fileRegAddr;
}

int addwf (fileRegAddr, d, a){
  if(!d){
    WREG = WREG + memory[fileRegAddr];
    if(a){      
      GPR (fileRegAddr, d);      
    }
  }
  else{
    memory[fileRegAddr] = WREG + memory[fileRegAddr];
    if(a){
      GPR (fileRegAddr, d);  
    }
  }
}

// int addwfc (fileRegAddr, d, a){
  // if(!d){
  // WREG = WREG + memory[fileRegAddr];
  // }
  // else{
  // memory[fileRegAddr] = WREG + memory[fileRegAddr]; 
  // }
// }

