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

int checkDigitCarry(int value, int addend1, int addend2){
  int x = (addend1 & 0x10);
  int y = (addend2 & 0x10);
  if((x ^ y) == 0x10){
    if((value & 0x10) == 0){
      STATUS = STATUS | 0x2;
    }
    else{
      STATUS = STATUS & 0xFD;
    }
  }
  else{
    if((value & 0x1F) > 0xF){
      STATUS = STATUS | 0x2;
    }
    else{
      STATUS = STATUS & 0xFD;
    }
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
  if((value & 0xFF) == 0){
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

int getFileAddress(int fileAddress, int accessType){
  int ramAddress;
  if(accessType){
    ramAddress = (BSR << 8) + (fileAddress & 0xFF);
  }
  else{
    ramAddress = fileAddress;
  }
  return ramAddress;
}

int readByte(int fileAddress, int accessType){
  int ramAddress;

	ramAddress = getFileAddress(fileAddress, accessType);
	
	return memory[ramAddress];
}

void writeByte(int fileAddress, int accessType, int value){
  int ramAddress = getFileAddress(fileAddress, accessType);
  if(accessType){
    memory[ramAddress] = value;
  }
  else{
    int accessRam = fileAddress & 0xFF;
    if(accessRam <= 0x7F){
      memory[accessRam] = value;
    }
    else{
    int accessRamHigh = 0xF00 + accessRam;
      memory[accessRamHigh] = value;
    }
  }  
}

void writeToFileRegister(int fileAddress, int d, int accessType, int value){
  if(d){
    writeByte(fileAddress, accessType, value);
  }  
  else{
    WREG = value;
  }
} 

int addwf (int fileAddress, int d, int accessType){
  int adder = readByte(fileAddress, accessType);
  int value = WREG + adder;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
  
}

int andwf (int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = WREG & data;
  
  checkZero(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int addwfc (int fileAddress, int d, int accessType){
  int adder = readByte(fileAddress, accessType);
  int value = WREG + adder + (STATUS & 0x01);
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int addlw (int Literal){
  WREG = WREG + Literal;
  int value = WREG;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, Literal);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
}

int subwf (int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = memory[fileAddress] - WREG;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int subfwb (int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = WREG - memory[fileAddress] - (~(STATUS | 0xFE));
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int subwfb (int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = memory[fileAddress] - WREG - (~(STATUS | 0xFE));
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int sublw (int Literal){
  WREG = Literal - WREG;
  int value = WREG;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, Literal);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
}

int andlw (int Literal){
  WREG = Literal & WREG;
  
  checkZero(WREG);
  checkNegative(WREG);
  
}

int iorlw(int Literal){
  WREG = (WREG) | (Literal);
  
  checkZero(WREG);
  checkNegative(WREG);
  
}

int iorwf(int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = (WREG) | data;
  
  checkZero(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int xorlw(int Literal){
  WREG = WREG ^ Literal;
  
  checkZero(WREG);
  checkNegative(WREG);
}

int xorwf(int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = WREG ^ data;
  
  checkZero(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int clrf(int fileAddress, int accessType){
  int value = 0x000;
  checkZero(value);
  
  writeToFileRegister(fileAddress, 1, accessType, value);
}

int comf(int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = ~data;
  
  checkZero(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int decf(int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = data - 1;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int incf(int fileAddress, int d, int accessType){
  int data = readByte(fileAddress, accessType);
  int value = data + 1;
  
  checkCarry(value);
  checkDigitCarry(value, WREG, memory[fileAddress]);
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int movf(int fileAddress, int d, int accessType){
  int value = readByte(fileAddress, accessType);
  
  checkZero(value);
  checkOverflow(value);
  checkNegative(value);
  
  writeToFileRegister(fileAddress, d, accessType, value);
}

int movlw(int Literal){
  WREG = Literal;
}

int movwf(int fileAddress, int accessType){
  writeToFileRegister(fileAddress, 1, accessType, WREG);
}


















