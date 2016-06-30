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

void test_for_fun(void){

  int a = 10 >> 2;

  printf("%d %x %o\n", 10, 10, 10);

  printf("%d\n", a);

}
