#include "execution.h"
#include <stdint.h>
#include <stdio.h>
#include "RegisterAddress.h"

int checkCarry(int value){
  if(value > 0xFF){
    STATUS = STATUS | 0x1;
  }
  else{
    STATUS = STATUS & 0xFE;
  }
}

int checkBorrow(int minuend, int subtrahend){
  if(minuend < subtrahend){
    STATUS = STATUS & 0xFE;
  }
  else{
    STATUS = STATUS | 0x1;
  }
}

int checkDigitCarry(int value){
  if((value & 0x1F) > 0xF){
    STATUS = STATUS | 0x2;
  }
  else{
    STATUS = STATUS & 0xFD;
  }
}

int checkDigitBorrow(int minuend, int subtrahend){
  if((minuend & 0xF) < (subtrahend & 0xF)){
    STATUS = STATUS & 0xFD;
  }
  else{
    STATUS = STATUS | 0x2;
  }
}

int checkZero(int value){
  if(value == 0){
    STATUS = STATUS | 0x04;
  }
  else{
    STATUS = STATUS & 0xFB; 
  }
}

int checkOverflow(int value){
  if((value < -128) || (value > 127)){
    STATUS = STATUS | 0x8;
  }
  else{
    STATUS = STATUS & 0xF7;
  }
}

int checkNegative(int value){
  value = value & 0xFF;
  if(value >> 7 == 1){
    STATUS = STATUS | 0x10;
  }
  else{
    STATUS = STATUS & 0xEF;
  }
}



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
  checkCarry(value);
  checkDigitCarry(value);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
}

int andwf (int fileRegAddr, int d, int accessType){
  int value = WREG & fileMemory[fileRegAddr];
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int addwfc (int fileRegAddr, int d, int accessType){
  int value = WREG + fileMemory[fileRegAddr] + (STATUS & 0x01);
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int addlw (int Literal){
  WREG = WREG + Literal;
}

int subwf (int fileRegAddr, int d, int accessType){
  int value = fileMemory[fileRegAddr] - WREG;
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int subfwb (int fileRegAddr, int d, int accessType){
  int value = WREG - fileMemory[fileRegAddr] - (~(STATUS | 0xFE));
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int subwfb (int fileRegAddr, int d, int accessType){
  int value = fileMemory[fileRegAddr] - WREG - (~(STATUS | 0xFE));
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int sublw (int Literal){
  WREG = Literal - WREG;
}

int andlw (int Literal){
  WREG = Literal & WREG;
}

int iorlw(int Literal){
  WREG = (WREG) | (Literal);
}

int iorwf(int fileRegAddr, int d, int accessType){
  int value = (WREG) | (fileMemory[fileRegAddr]);
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

int xorlw(int Literal){
  WREG = ((~WREG) & Literal) | (WREG & (~Literal));
}

int xorwf(int fileRegAddr, int d, int accessType){
  int value = ((~WREG) & (fileMemory[fileRegAddr]))| (WREG & (~fileMemory[fileRegAddr]));
  writeToFileRegister(fileRegAddr, d, value);
  writeByte(fileRegAddr, accessType, value);
}

























