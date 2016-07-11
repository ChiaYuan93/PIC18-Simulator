#include "unity.h"
#include "execution.h"
#include <stdio.h>
#include <stdint.h>
#include <RegisterAddress.h>

void setUp(void){}

void tearDown(void){}

void test_addwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x23;
  memory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  int d = 0, a = 1;
  
  addwf (fileRegAddr, d, a);
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x17, memory[fileRegAddr]); 
}

void test_addwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x24;
  memory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  int d = 1, a = 1;
  
  addwf (fileRegAddr, d, a);
  
  TEST_ASSERT_EQUAL(0x37, memory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x20, WREG); 
}

// void test_add_WREG_and_carry_bit_to_file_register_and_save_into_WREG(void)
// {
  // int instructionCode = 0x20;
  // int WREG = 0x11;
  // int fileRegister = 0x12;
  // int carryBit = 1;
  
  // WREG = addwfc (instructionCode, WREG, fileRegister, carryBit);
  
  // TEST_ASSERT_EQUAL(0x24, WREG);
// }

// void test_add_WREG_and_carry_bit_to_file_register_and_save_into_file_register(void)
// {
  // int instructionCode = 0x22;
  // int WREG = 0x11;
  // int fileRegister = 0x12;
  // int carryBit = 1;
  
  // fileRegister = addwfc (instructionCode, WREG, fileRegister, carryBit);
  
  // TEST_ASSERT_EQUAL(0x24, fileRegister);
// }

// void test_AND_WREG_with_file_register_and_save_into_WREG(void)
// {
  // int instructionCode = 0x22;
  // int WREG = 0x17;
  // int fileRegister = 0xC2;
  
  // WREG = andwf (instructionCode, WREG, fileRegister);
  
  // TEST_ASSERT_EQUAL(0x02, WREG);
// }

// void test_AND_WREG_with_file_register_and_save_into_file_register(void)
// {
  // int instructionCode = 0x22;
  // int WREG = 0x43;
  // int fileRegister = 0xD7;
  
  // fileRegister = andwf (instructionCode, WREG, fileRegister);
  
  // TEST_ASSERT_EQUAL(0x43, fileRegister);
// }