#ifndef execution_H
#define execution_H

int addwf(int instructionCode, int WREG, int fileRegister);
int addwfc(int instructionCode, int WREG, int fileRegister, int CFlag);
int andwf(int instructionCode, int WREG, int fileRegister);

#endif // execution_H
