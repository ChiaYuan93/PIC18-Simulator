#include "execution.h"
#include "unity.h"






void setUp(void){}



void tearDown(void){}



void test_add_WREG_to_file_register_and_save_into_WREG(void)

{

  int instructionCode = 0x24;

  int WREG = 0x17;

  int fileRegister = 0xC2;



  WREG = addwf (instructionCode, WREG, fileRegister);



  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((WREG)), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



void test_add_WREG_to_file_register_and_save_into_file_register(void)

{

  int instructionCode = 0x26;

  int WREG = 0x17;

  int fileRegister = 0xC2;



  fileRegister = addwf (instructionCode, WREG, fileRegister);



  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((fileRegister)), (((void *)0)), (_U_UINT)29, UNITY_DISPLAY_STYLE_INT);

}



void test_add_WREG_and_carry_bit_to_file_register_and_save_into_WREG(void)

{

  int instructionCode = 0x20;

  int WREG = 0x11;

  int fileRegister = 0x12;

  int carryBit = 1;



  WREG = addwfc (instructionCode, WREG, fileRegister, carryBit);



  UnityAssertEqualNumber((_U_SINT)((0x24)), (_U_SINT)((WREG)), (((void *)0)), (_U_UINT)41, UNITY_DISPLAY_STYLE_INT);

}



void test_add_WREG_and_carry_bit_to_file_register_and_save_into_file_register(void)

{

  int instructionCode = 0x22;

  int WREG = 0x11;

  int fileRegister = 0x12;

  int carryBit = 1;



  fileRegister = addwfc (instructionCode, WREG, fileRegister, carryBit);



  UnityAssertEqualNumber((_U_SINT)((0x24)), (_U_SINT)((fileRegister)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

}



void test_AND_WREG_with_file_register_and_save_into_WREG(void)

{

  int instructionCode = 0x22;

  int WREG = 0x17;

  int fileRegister = 0xC2;



  WREG = andwf (instructionCode, WREG, fileRegister);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((WREG)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

}



void test_AND_WREG_with_file_register_and_save_into_file_register(void)

{

  int instructionCode = 0x22;

  int WREG = 0x43;

  int fileRegister = 0xD7;



  fileRegister = andwf (instructionCode, WREG, fileRegister);



  UnityAssertEqualNumber((_U_SINT)((0x43)), (_U_SINT)((fileRegister)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}
