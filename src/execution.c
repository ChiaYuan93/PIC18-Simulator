#include "execution.h"
#include <stdint.h>
#include <stdio.h>
#include <RegisterAddress.h>


// Instruction instructionTable[256] = {
  // [0x09] = addwf,
  // [0x08] = addwfc,
// };

// instructionTable[instructionCode << 8] (instructionCode);

int readByte(int fileRegAddr, int accessType){
  if(accessType)
    fileRegAddr = (BSR << 8) + fileRegAddr;
  
  return fileRegAddr;
}

void writeByte(int fileRegAddr, int accessType, int value){
  fileRegAddr = readByte(int fileRegAddr, int accessType);
  memory[fileRegAddr] = value;
}

void writeToFileRegister(int fileRegAddr, d, int value){
  if(d)
    memory[fileRegAddr] = value;
  else
    WREG = value;
} 

// int addwf (fileRegAddr, d, a){
  // int result = WREG + memory[fileRegAddr];
// }

// int andwf (fileRegAddr, d, a){
  // if(!d){
    // WREG = WREG & memory[fileRegAddr];
    // if(a){      
      // GPR (fileRegAddr, d);      
    // }
  // }
  // else{
    // memory[fileRegAddr] = WREG & memory[fileRegAddr];
    // if(a){
      // GPR (fileRegAddr, d);  
    // }
  // }
// }

// int addwfc (fileRegAddr, d, a){
  // if(!d){
  // WREG = WREG + memory[fileRegAddr];
  // }
  // else{
  // memory[fileRegAddr] = WREG + memory[fileRegAddr]; 
  // }
// }

