#include "unity.h"
#include "execution.h"
#include <stdio.h>
#include <stdint.h>

void setUp(void){}

void tearDown(void){}

void test_add_WREG_to_file_register_and_save_into_WREG(void)
{
  int instructionCode = 0x24;
  int WREG = 0x17;
  int fileRegister = 0xC2;
  
  WREG = addwf (instructionCode, WREG, fileRegister);
  
  TEST_ASSERT_EQUAL(0xD9, WREG);
}

void test_add_WREG_to_file_register_and_save_into_file_register(void)
{
  int instructionCode = 0x26;
  int WREG = 0x17;
  int fileRegister = 0xC2;
  
  fileRegister = addwf (instructionCode, WREG, fileRegister);
  
  TEST_ASSERT_EQUAL(0xD9, fileRegister);
}
void test_for_fun(void){
  int a = 10 >> 2;
  printf("%d %x %o\n", 10, 10, 10); //prints "10 A 12\n"
  printf("%d\n", a); // prints "%b\n"
}
