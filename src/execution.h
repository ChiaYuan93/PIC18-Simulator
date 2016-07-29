#ifndef execution_H
#define execution_H

int checkCarry(int value);
int checkBorrow(int minuend, int subtrahend);
int checkZero(int value);
int checkNegative(int value);
int checkOverflow(int value);

int readByte(int fileRegAddr, int accessType);
void writeByte(int fileRegAddr, int accessType, int value);
void writeToFileRegister(int fileRegAddr, int d, int value);

int addwf (int fileRegAddr, int d, int accessType);
int andwf (int fileRegAddr, int d, int accessType);
int addwfc (int fileRegAddr, int d, int accessType);
int addlw (int Literal);
int subwf (int fileRegAddr, int d, int accessType);
int subfwb (int fileRegAddr, int d, int accessType);
int subwfb (int fileRegAddr, int d, int accessType);


#endif // execution_H
