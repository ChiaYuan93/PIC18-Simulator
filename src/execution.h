#ifndef execution_H
#define execution_H

int checkCarry(int value);
int checkBorrow(int minuend, int subtrahend);
int checkDigitCarry(int value, int addend1, int addend2);
int checkDigitBorrow(int minuend, int subtrahend);
int checkZero(int value);
int checkOverflow(int value);
int checkNegative(int value);

int getFileAddress(int fileAddress, int accessType);
int readByte(int fileRegAddr, int accessType);
void writeByte(int fileRegAddr, int accessType, int value);
void writeToFileRegister(int fileAddress, int d, int accessType, int value);

int addwf (int fileRegAddr, int d, int accessType);
int addwfc (int fileRegAddr, int d, int accessType);
int addlw (int Literal);
int subwf (int fileRegAddr, int d, int accessType);
int subfwb (int fileRegAddr, int d, int accessType);
int subwfb (int fileRegAddr, int d, int accessType);
int sublw (int Literal);
int andlw (int Literal);
int andwf (int fileRegAddr, int d, int accessType);
int iorlw (int Literal);
int iorwf (int fileRegAddr, int d, int accessType);
int xorlw (int Literal);
int xorwf (int fileRegAddr, int d, int accessType);
int clrf (int fileAddress, int accessType);
int comf (int fileAddress, int d, int accessType);
int decf (int fileAddress, int d, int accessType);
int incf (int fileAddress, int d, int accessType);
int movf (int fileAddress, int d, int accessType);
int movlw (int Literal);
int movwf (int fileAddress, int accessType);


#endif // execution_H
