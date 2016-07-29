#include "unity.h"
#include "execution.h"
#include <stdio.h>
#include <stdint.h>
#include "RegisterAddress.h"

void setUp(void){}

void tearDown(void){}

void test_checkCarry_given_value_is_over_maximum_value_should_set_Carry_flag(void)
{
  int value = 0x7F + 0x87;
  
  checkCarry(value);
  
  TEST_ASSERT_EQUAL(0x1, STATUS);
}

void test_checkCarry_given_value_is_under_maximum_value_should_unset_Carry_flag(void)
{
  int value = 0xFE + 0x1;
  
  checkCarry(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkBorrow_given_minuend_is_smaller_than_subtrahend_should_unset_Carry_flag(void)
{
  int minuend = -98;
  int subtrahend = 45;
  int value = minuend - subtrahend;
  
  checkBorrow(minuend, subtrahend);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkBorrow_given_minuend_is_bigger_than_subtrahend_should_set_Carry_flag(void)
{
  int minuend = -45;
  int subtrahend = -98;
  int value = minuend - subtrahend;
  
  checkBorrow(minuend, subtrahend);
  
  TEST_ASSERT_EQUAL(0x1, STATUS);
}

void test_checkZero_given_value_is_0_should_set_zero_flag(void)
{
  int value = 0;
  STATUS = 0;
  checkZero(value);
  
  TEST_ASSERT_EQUAL(0x4, STATUS);
}

void test_checkZero_given_value_is_positive_number_should_unset_zero_flag(void)
{
  int value = 12;

  checkZero(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkZero_given_value_is_negative_value_should_unset_zero_flag(void)
{
  int value = -33;
  
  checkZero(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkOverflow_given_value_is_more_than_127_should_set_Overflow_flag(void)
{
  int value = 130;
  
  checkOverflow(value);
  
  TEST_ASSERT_EQUAL(0x8, STATUS);
}

void test_checkOverflow_given_value_is_less_than_negative_128_should_set_Overflow_flag(void)
{
  int value = -184;
  
  checkOverflow(value);
  
  TEST_ASSERT_EQUAL(0x8, STATUS);
}

void test_checkOverflow_given_value_is_124_should_unset_Overflow_flag(void)
{
  int value = 124;
  
  checkOverflow(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkOverflow_given_value_is_negative_123_should_unset_Overflow_flag(void)
{
  int value = -123;
  
  checkOverflow(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkNegative_given_value_is_positive_value_should_unset_negative_flag(void)
{
  int value = 83;
  
  checkNegative(value);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
}

void test_checkNegative_given_value_is_negative_value_should_set_negative_flag(void)
{
  int value = -107;
  
  checkNegative(value);
  
  TEST_ASSERT_EQUAL(0x10, STATUS);
}

void test_readByte_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)
{
  int fileRegAddr = 0x23;
  int accessType = 1;
  BSR = 0x2;
  
  fileRegAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x223, fileRegAddr);
}

void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int value = 0x38;
  int fileRegAddr = 0x23;
  int accessType = 1;
  BSR = 0x3;
  
  writeByte (fileRegAddr, accessType, value);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x38, memory[dataMemoryAddr]);
}

void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)
{
  int value = 0x38;
  int fileRegAddr = 0x23;
  int d = 1;
  
  writeToFileRegister(fileRegAddr, d, value);
  
  TEST_ASSERT_EQUAL(0x38, fileMemory[fileRegAddr]);  
}

void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)
{
  int value = 0x38;
  int fileRegAddr = 0x23;
  int d = 0;
  
  writeToFileRegister(fileRegAddr, d, value);
  
  TEST_ASSERT_EQUAL(0x38, WREG);  
}

void test_addwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x23;
  fileMemory[fileRegAddr] = 0x17;
  WREG  = 0x20;
  int d = 0, accessType = 0;
  
  addwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
    
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x17, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x37, memory[dataMemoryAddr]);  
}

void test_addwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x24;
  fileMemory[fileRegAddr] = 0x17;
  WREG  = 0x20;
  int d = 1, accessType = 0;
  
  addwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x37, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x20, WREG);
  TEST_ASSERT_EQUAL(0x37, memory[dataMemoryAddr]); 
}

void test_addwf_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  BSR = 0x2;
  int d = 0, accessType = 0;

  addwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x17, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x37, memory[dataMemoryAddr]); 
}

void test_addwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  BSR = 0x4;
  int d = 0, accessType = 1;

  addwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x17, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x37, memory[dataMemoryAddr]); 
}

void test_andwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  int d = 0, accessType = 0;
  BSR = 0x3;
  
  andwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x02, WREG);
  TEST_ASSERT_EQUAL(0xC2, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]); 
}

void test_andwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x27;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  int d = 1, accessType = 0;
  
  andwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0x02, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]);
}

void test_andwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x27;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  int d = 1, accessType = 1;
  
  andwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0x02, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]); 
}

void test_andwf_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x32;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  int d = 0, accessType = 0;
  
  andwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x02, WREG); 
  TEST_ASSERT_EQUAL(0xC2, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]); 
}

void test_addwfc_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x12;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  STATUS = 0x1;
  int d = 0, accessType = 0;
  
  addwfc (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0xDA, WREG); 
  TEST_ASSERT_EQUAL(0xC2, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0xDA, memory[dataMemoryAddr]); 
}

void test_addwfc_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x12;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  STATUS = 0x0;
  int d = 1, accessType = 1;
  
  addwfc (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);

  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0xD9, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0xD9, memory[dataMemoryAddr]); 
}

void test_addwfc_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x12;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x1;
  STATUS = 0x1;
  int d = 1, accessType = 0;
  
  addwfc (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0xDA, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x12, dataMemoryAddr);
  TEST_ASSERT_EQUAL(0xDA, memory[dataMemoryAddr]); 
}

void test_addwfc_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x12;
  fileMemory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  BSR = 0x1;
  STATUS = 0x0;
  int d = 0, accessType = 1;
  
  addwfc (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL(0xD9, WREG); 
  TEST_ASSERT_EQUAL(0xC2, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0xD9, memory[dataMemoryAddr]); 
  TEST_ASSERT_EQUAL(0x112, dataMemoryAddr);
}

void test_addlw_given_Literal_is_15_result_should_store_into_WREG(void)
{
  int Literal = 0x15;
  WREG = 0x17;
    
  addlw (Literal);

  
  TEST_ASSERT_EQUAL(0x2C, WREG); 
}

void test_subwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0x04;
  WREG  = 0x01;
  int d = 0, accessType = 0;
  BSR = 0x3;
  
  subwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x03, WREG);
  TEST_ASSERT_EQUAL_INT8(0x4, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0x3, memory[dataMemoryAddr]); 
}

void test_subwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x34;
  fileMemory [fileRegAddr] = 0x18;
  WREG  = 0x19;
  int d = 1, accessType = 0;
  BSR = 0x3;
  
  subwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x19, WREG);
  TEST_ASSERT_EQUAL_INT8(0xFF, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xFF, memory[dataMemoryAddr]); 
}

void test_subwf_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  BSR = 0x2;
  int d = 0, accessType = 0;

  subwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0xF7, WREG);
  TEST_ASSERT_EQUAL_INT8(0x17, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xF7, memory[dataMemoryAddr]); 
}

void test_subwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x34;
  WREG  = 0x22;
  BSR = 0x4;
  int d = 0, accessType = 1;

  subwf (fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x12, WREG);
  TEST_ASSERT_EQUAL_INT8(0x34, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0x12, memory[dataMemoryAddr]); 
}

void test_subfwb_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0x04;
  WREG  = 0x01;
  int d = 0, accessType = 0;
  STATUS = 0x0;
  BSR = 0x3;
  
  subfwb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0xFC, WREG);
  TEST_ASSERT_EQUAL_INT8(0x4, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xFC, memory[dataMemoryAddr]); 
}

void test_subfwb_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0x04;
  WREG  = 0x01;
  int d = 1, accessType = 0;
  STATUS = 0x1;
  BSR = 0x3;
  
  subfwb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x01, WREG);
  TEST_ASSERT_EQUAL_INT8(0xFD, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xFD, memory[dataMemoryAddr]); 
}

void test_subfwb_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  STATUS = 0x0;
  BSR = 0x2;
  int d = 0, accessType = 0;

  subfwb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0x8, WREG);
  TEST_ASSERT_EQUAL_INT8(0x17, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0x8, memory[dataMemoryAddr]); 
}

void test_subfwb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x14;
  WREG  = 0x33;
  STATUS = 0x1;
  BSR = 0x4;
  int d = 0, accessType = 1;

  subfwb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0x1F, WREG);
  TEST_ASSERT_EQUAL_INT8(0x14, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0x1F, memory[dataMemoryAddr]); 
}

void test_subwfb_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0x04;
  WREG  = 0x01;
  int d = 0, accessType = 0;
  STATUS = 0x0;
  BSR = 0x3;
  
  subwfb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x2, WREG);
  TEST_ASSERT_EQUAL_INT8(0x4, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0x2, memory[dataMemoryAddr]); 
}

void test_subwfb_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x25;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x63;
  int d = 1, accessType = 0;
  STATUS = 0x1;
  BSR = 0x3;
  
  subwfb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x63, WREG);
  TEST_ASSERT_EQUAL_INT8(0xB4, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xB4, memory[dataMemoryAddr]); 
}

void test_subwfb_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  STATUS = 0x0;
  BSR = 0x2;
  int d = 1, accessType = 0;

  subwfb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0x20, WREG);
  TEST_ASSERT_EQUAL_INT8(0xF6, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xF6, memory[dataMemoryAddr]); 
}

void test_subwfb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x23;
  fileMemory [fileRegAddr] = 0x14;
  WREG  = 0x33;
  STATUS = 0x1;
  BSR = 0x4;
  int d = 0, accessType = 1;

  subwfb(fileRegAddr, d, accessType);
  int dataMemoryAddr = readByte (fileRegAddr, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0xE1, WREG);
  TEST_ASSERT_EQUAL_INT8(0x14, fileMemory[fileRegAddr]);
  TEST_ASSERT_EQUAL_INT8(0xE1, memory[dataMemoryAddr]); 
}
