#include "execution.h"
#include <stdint.h>
#include <stdio.h>
#include "RegisterAddress.h"

int readByte(int fileRegAddr, int accessType){
  if(accessType){
    fileRegAddr = (BSR << 8) + fileRegAddr;
  }
  else{
    fileRegAddr = fileRegAddr;
  }
  return fileRegAddr;
}

void writeByte(int fileRegAddr, int accessType, int value){
  int dataMemoryAddr = readByte(fileRegAddr, accessType);
  memory[dataMemoryAddr] = value;
}

void writeToFileRegister(int fileRegAddr, int d, int value){
  if(d){
    fileMemory[fileRegAddr] = value;
  }  
  else{
    WREG = value;
  }
} 

int addwf (int fileRegAddr, int d, int accessType){
  int value = WREG + fileMemory[fileRegAddr];
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int andwf (int fileRegAddr, int d, int accessType){
  int value = WREG & fileMemory[fileRegAddr];
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int addwfc (int fileRegAddr, int d, int accessType){
  int value = WREG + fileMemory[fileRegAddr] + (STATUS && 0x01);
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int addlw (int Literal){
  WREG = WREG + Literal;
}

