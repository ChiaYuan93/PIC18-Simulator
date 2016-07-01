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

void test_add_WREG_and_carry_bit_to_file_register_and_save_into_WREG(void)
{
  int instructionCode = 0x20;
  int WREG = 0x11;
  int fileRegister = 0x12;
  int carryBit = 1;
  
  WREG = addwfc (instructionCode, WREG, fileRegister, carryBit);
  
  TEST_ASSERT_EQUAL(0x24, WREG);
}

void test_add_WREG_and_carry_bit_to_file_register_and_save_into_file_register(void)
{
  int instructionCode = 0x22;
  int WREG = 0x11;
  int fileRegister = 0x12;
  int carryBit = 1;
  
  fileRegister = addwfc (instructionCode, WREG, fileRegister, carryBit);
  
  TEST_ASSERT_EQUAL(0x24, fileRegister);
}

void test_AND_WREG_with_file_register_and_save_into_WREG(void)
{
  int instructionCode = 0x22;
  int WREG = 0x17;
  int fileRegister = 0xC2;
  
  WREG = andwf (instructionCode, WREG, fileRegister);
  
  TEST_ASSERT_EQUAL(0x02, WREG);
}

void test_AND_WREG_with_file_register_and_save_into_file_register(void)
{
  int instructionCode = 0x22;
  int WREG = 0x43;
  int fileRegister = 0xD7;
  
  fileRegister = andwf (instructionCode, WREG, fileRegister);
  
  TEST_ASSERT_EQUAL(0x43, fileRegister);
}