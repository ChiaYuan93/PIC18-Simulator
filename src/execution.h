#ifndef execution_H
#define execution_H

int readByte(int fileRegAddr, int accessType);
void writeByte(int fileRegAddr, int accessType, int value);
void writeToFileRegister(int fileRegAddr, int d, int value);

int addwf (int fileRegAddr, int d, int accessType);
int andwf (int fileRegAddr, int d, int accessType);
int addwfc (int fileRegAddr, int d, int accessType);
int addlw (int Literal);

#endif // execution_H
