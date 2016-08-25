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

void test_checkDigitCarry_given_value_is_over_maximum_value_should_set_Digit_Carry_flag(void)
{
  STATUS = 0;
  int addend1 = 0xEE;
  int addend2 = 0x12;
  int value = addend1 + addend2;
  
  checkDigitCarry(value, addend1, addend2);
  
  TEST_ASSERT_EQUAL(0x2, STATUS);
}

void test_checkDigitCarry_given_value_is_more_than_maximum_value_should_set_Digit_Carry_flag(void)
{
  STATUS = 0;
  int addend1 = 0xEF;
  int addend2 = 0x1;
  int value = addend1 + addend2;
  
  checkDigitCarry(value, addend1, addend2);
  
  TEST_ASSERT_EQUAL(0x2, STATUS);
}

void test_checkDigitBorrow_given_minuend_is_bigger_than_subtrahend_should_set_Carry_flag(void)
{
  int minuend = 0x98;
  int subtrahend = 0x45;
  int value = minuend - subtrahend;
  
  checkDigitBorrow(minuend, subtrahend);
  
  TEST_ASSERT_EQUAL(0x2, STATUS);
}

void test_checkDigitBorrow_given_minuend_is_smaller_than_subtrahend_should_unset_Carry_flag(void)
{
  int minuend = -45;
  int subtrahend = -56;
  int value = minuend - subtrahend;
  
  checkDigitBorrow(minuend, subtrahend);
  
  TEST_ASSERT_EQUAL(0x0, STATUS);
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

void test_getFileAddress_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)
{
  int fileAddress = 0x23;
  int accessType = BankRAM;
  BSR = 0x2;
  
  fileAddress = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x223, fileAddress);
}

void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int value = 0x38;
  int fileAddress = 0x23;
  int accessType = BankRAM;
  BSR = 0x3;
  
  writeByte (fileAddress, accessType, value);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x38, memory[dataMemoryAddr]);
}

void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)
{
  int value = 0xF3;
  int fileAddress = 0xE8;
  int d = DIR_fileRegister;
  int accessType = BankRAM;
  BSR = 4;
  
  writeToFileRegister(fileAddress, d, accessType, value);
  fileAddress = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0xF3, memory[fileAddress]);  
}

void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)
{
  int value = 0x38;
  int fileAddress = 0x23;
  int d = DIR_WREG;
  int accessType = AccessRAM;
  
  writeToFileRegister(fileAddress, d, accessType, value);
  
  TEST_ASSERT_EQUAL(0x38, WREG);  
}

void test_readByte_should_read_data_from_address(void)
{
  int fileAddress = 0x23;
  memory[fileAddress] = 0x45;
  int accessType = AccessRAM;
  int data = readByte(fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x45, data);  
}

void test_readByte_should_read_data_from_Bank_address(void)
{
  int fileAddress = 0x423;
  memory[fileAddress] = 0x55;
  BSR = 0x4;
  int accessType = AccessRAM;
  int data = readByte(fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x55, data);  
}

void test_readByte_should_read_different_data_from_Bank_address(void)
{
  int fileAddress = 0x413;
  memory[fileAddress] = 0x55;
  BSR = 0x2;
  int accessType = BankRAM;
  int data = readByte(fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0, data);  
}

void test_addwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x23;
  memory[fileAddress] = 0xEE;
  WREG = 0x12;
  int d = DIR_WREG, accessType = AccessRAM;
  
  addwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
    
    
  TEST_ASSERT_EQUAL_INT8(0x00, WREG);
  TEST_ASSERT_EQUAL(0xEE, memory[dataMemoryAddr]);
  TEST_ASSERT_EQUAL(0x0F, STATUS);  
}

void test_addwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x80;
  memory[fileAddress] = 0x17;
  WREG  = 0x20;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  addwf (fileAddress, d, accessType);
  
  TEST_ASSERT_EQUAL(0x20, WREG);
  TEST_ASSERT_EQUAL(0x37, PORTA); 
}

void test_addwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x423;
  memory [fileAddress] = 0x17;
  WREG  = 0x20;
  BSR = 0x4;
  int d = DIR_fileRegister, accessType = BankRAM;

  addwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x20, WREG);
  TEST_ASSERT_EQUAL(0x37, memory[dataMemoryAddr]); 
}

void test_andwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  int d = DIR_WREG, accessType = AccessRAM;
  
  andwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x02, WREG);
  TEST_ASSERT_EQUAL(0xC2, memory[dataMemoryAddr]); 
}

void test_andwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x27;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  andwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]);
}

void test_andwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x327;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  andwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0x02, memory[dataMemoryAddr]); 
}

void test_addwfc_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x93;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  STATUS = 0x1;
  int d = DIR_WREG, accessType = AccessRAM;
  
  addwfc (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0xDA, WREG); 
  TEST_ASSERT_EQUAL(0xC2, memory[dataMemoryAddr]); 
}

void test_addwfc_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x312;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  STATUS = 0x0;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  addwfc (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);

  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0xD9, memory[dataMemoryAddr]); 
}

void test_addwfc_given_accessType_is_0_result_should_store_into_access_bank(void)
{
  int fileAddress = 0x12;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  STATUS = 0x1;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  addwfc (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0xDA, memory[dataMemoryAddr]); 
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
  int fileAddress = 0x25;
  memory [fileAddress] = 0x04;
  WREG  = 0x01;
  int d = DIR_WREG, accessType = AccessRAM;
  
  subwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x03, WREG);
  TEST_ASSERT_EQUAL_INT8(0x04, memory[dataMemoryAddr]); 
}

void test_subwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x34;
  memory [fileAddress] = 0x18;
  WREG  = 0x19;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  subwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x19, WREG);
  TEST_ASSERT_EQUAL_INT8(0xFF, memory[dataMemoryAddr]); 
}

void test_subwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x423;
  memory [fileAddress] = 0x34;
  WREG  = 0x22;
  BSR = 0x4;
  int d = DIR_fileRegister, accessType = BankRAM;

  subwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x22, WREG);
  TEST_ASSERT_EQUAL_INT8(0x12, memory[dataMemoryAddr]); 
}

void test_subfwb_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0x04;
  WREG  = 0x01;
  int d = DIR_WREG, accessType = AccessRAM;
  STATUS = 0x0;
  
  subfwb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0xFC, WREG);
  TEST_ASSERT_EQUAL_INT8(0x04, memory[dataMemoryAddr]); 
}

void test_subfwb_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0x04;
  WREG  = 0x01;
  int d = DIR_fileRegister, accessType = AccessRAM;
  STATUS = 0x1;
  
  subfwb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x01, WREG);
  TEST_ASSERT_EQUAL_INT8(0xFD, memory[dataMemoryAddr]); 
}

void test_subfwb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x323;
  memory [fileAddress] = 0x14;
  WREG  = 0x33;
  STATUS = 0x1;
  BSR = 0x3;
  int d = DIR_fileRegister, accessType = BankRAM;

  subfwb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0x33, WREG);
  TEST_ASSERT_EQUAL_INT8(0x1F, memory[dataMemoryAddr]); 
}

void test_subwfb_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0x04;
  WREG  = 0x01;
  int d = DIR_WREG, accessType = AccessRAM;
  STATUS = 0x0;
  
  subwfb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x2, WREG);
  TEST_ASSERT_EQUAL_INT8(0x04, memory[dataMemoryAddr]); 
}

void test_subwfb_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0x17;
  WREG  = 0x63;
  int d = DIR_fileRegister, accessType = AccessRAM;
  STATUS = 0x1;
  
  subwfb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x63, WREG);
  TEST_ASSERT_EQUAL_INT8(0xB4, memory[dataMemoryAddr]); 
}

void test_subwfb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x123;
  memory [fileAddress] = 0x14;
  WREG  = 0x33;
  STATUS = 0x1;
  BSR = 0x1;
  int d = DIR_fileRegister, accessType = BankRAM;

  subwfb(fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
   
  TEST_ASSERT_EQUAL_INT8(0x33, WREG);
  TEST_ASSERT_EQUAL_INT8(0xE1, memory[dataMemoryAddr]); 
}

void test_sublw_given_Literal_is_34_result_should_store_into_WREG(void)
{
  int Literal = 0x34;
  WREG = 0x21;
    
  sublw (Literal);

  TEST_ASSERT_EQUAL_INT8(0x13, WREG); 
}

void test_sublw_given_Literal_is_smaller_than_WREG_result_should_store_into_WREG(void)
{
  int Literal = 0x17;
  WREG = 0x21;
   
  sublw (Literal);
  
  TEST_ASSERT_EQUAL_INT8(0xF6, WREG); 
}

void test_sublw_given_Literal_and_WREG_are_negative_value_result_should_store_into_WREG(void)
{
  int Literal = 0x90;
  WREG = 0xED;
   
  sublw (Literal);
  
  TEST_ASSERT_EQUAL_INT8(0xA3, WREG); 
}

void test_andlw_given_eight_bit_Literal_AND_with_WREG_result_should_store_into_WREG(void)
{
  int Literal = 0x73;
  WREG = 0xB5;
   
  andlw (Literal);
  
  TEST_ASSERT_EQUAL(0x31, WREG); 
}

void test_iorlw_given_eight_bit_Literal_OR_with_WREG_result_should_store_into_WREG(void)
{
  int Literal = 0xAA;
  WREG = 0x55;
   
  iorlw (Literal);
  
  TEST_ASSERT_EQUAL(0xFF, WREG); 
}

void test_iorwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  int d = DIR_WREG, accessType = AccessRAM;
  
  iorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0xD7, WREG);
  TEST_ASSERT_EQUAL(0xC2, memory[dataMemoryAddr]); 
}

void test_iorwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x27;
  memory [fileAddress] = 0xF1;
  WREG  = 0x14;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  iorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x14, WREG); 
  TEST_ASSERT_EQUAL(0xF5, memory[dataMemoryAddr]);
}

void test_iorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x527;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  BSR = 0x5;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  iorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG);
  TEST_ASSERT_EQUAL(0xD7, memory[dataMemoryAddr]); 
}

void test_xorlw_given_eight_bit_Literal_XOR_with_WREG_result_should_store_into_WREG(void)
{
  int Literal = 0x6D;
  WREG = 0x29;
   
  xorlw (Literal);
  
  TEST_ASSERT_EQUAL(0x44, WREG); 
}

void test_xorwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x25;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  int d = DIR_WREG, accessType = AccessRAM;
  
  xorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0xD5, WREG);
  TEST_ASSERT_EQUAL(0xC2, memory[dataMemoryAddr]); 
}

void test_xorwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x27;
  memory [fileAddress] = 0xF1;
  WREG  = 0x14;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  xorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x14, WREG);
  TEST_ASSERT_EQUAL(0xE5, memory[dataMemoryAddr]);
}

void test_xorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x327;
  memory [fileAddress] = 0xC2;
  WREG  = 0x17;
  BSR = 0x3;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  xorwf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0xD5, memory[dataMemoryAddr]); 
}

void test_clrf_given_accessType_is_1_should_clear_the_content_of_general_purpose_register(void)
{
  int fileAddress = 153;
  memory [fileAddress] = 0xC2;
  BSR = 0x1;
  int accessType = BankRAM;
  
  clrf (fileAddress, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0, memory[dataMemoryAddr]); 
}

void test_clrf_given_accessType_is_0_should_clear_the_content_of_access_RAM(void)
{
  int fileAddress = 0xF93;
  memory [fileAddress] = 0xC2;
  int accessType = BankRAM;
  
  clrf (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL(0, TRISC); 
}

void test_comf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x27;
  memory [fileAddress] = 0x13;
  int d = DIR_WREG, accessType = AccessRAM;
  
  comf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0xEC, WREG); 
  TEST_ASSERT_EQUAL(0x13, memory[dataMemoryAddr]); 
}

void test_comf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileAddress = 0x49;
  memory [fileAddress] = 0x95;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  comf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x6A, memory[dataMemoryAddr]); 
}

void test_comf_given_a_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x149;
  memory [fileAddress] = 0x48;
  BSR = 0x1;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  comf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0xB7, memory[dataMemoryAddr]); 
}

void test_decf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x49;
  memory [fileAddress] = 0x48;
  int d = DIR_WREG, accessType = AccessRAM;
  
  decf (fileAddress, d, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x47, WREG); 
}

void test_decf_given_d_is_1_result_should_store_into_WREG(void)
{
  int fileAddress = 0x51;
  memory [fileAddress] = 0;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  decf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0xFF, memory[dataMemoryAddr]); 
}

void test_decf_given_a_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x251;
  memory [fileAddress] = 0x10;
  BSR = 0x2;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  decf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x0F, memory[dataMemoryAddr]); 
}

void test_incf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileAddress = 0x49;
  memory [fileAddress] = 0x48;
  int d = DIR_WREG, accessType = AccessRAM;
  
  incf (fileAddress, d, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x49, WREG); 
}

void test_incf_given_d_is_1_result_should_store_into_WREG(void)
{
  int fileAddress = 0x51;
  memory [fileAddress] = 0xFF;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  incf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x00, memory[dataMemoryAddr]); 
}

void test_incf_given_a_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileAddress = 0x251;
  memory [fileAddress] = 0x0F;
  BSR = 0x2;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  incf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x10, memory[dataMemoryAddr]); 
}

void test_movf_given_d_is_0_data_should_read_from_file_register_and_store_into_WREG(void)
{
  int fileAddress = 0x51;
  memory [fileAddress] = 0x78;
  int d = DIR_WREG, accessType = AccessRAM;
  
  movf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x78, WREG); 
}

void test_movf_given_d_is_1_data_should_read_from_file_register_and_store_back_into_file_register(void)
{
  int fileAddress = 0x251;
  memory [fileAddress] = 0x78;
  int d = DIR_fileRegister, accessType = AccessRAM;
  
  movf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x78, memory[dataMemoryAddr]); 
}

void test_movf_given_a_is_1_data_should_read_from_file_register_and_store_back_into_file_register_with_BSR(void)
{
  int fileAddress = 0x151;
  memory [fileAddress] = 0x11;
  BSR = 1;
  int d = DIR_fileRegister, accessType = BankRAM;
  
  movf (fileAddress, d, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  TEST_ASSERT_EQUAL_INT8(0x11, memory[dataMemoryAddr]); 
}

void test_movlw_data_should_store_into_WREG(void)
{
  int Literal = 0xF0;
  
  movlw (Literal);
  
  TEST_ASSERT_EQUAL_INT8(0xF0, WREG); 
}

void test_movwf_should_read_data_from_WREG_and_store_into_file_register(void)
{
  int fileAddress = 0x70;
  WREG = 0x39;
  int accessType = AccessRAM;
  
  movwf (fileAddress, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  
  TEST_ASSERT_EQUAL_INT8(0x39, memory[dataMemoryAddr]); 
}

void test_movwf_given_a_is_1_should_read_data_from_WREG_and_store_into_file_register_with_BSR(void)
{
  int fileAddress = 0x570;
  WREG = 0x67;
  BSR = 5;
  int accessType = BankRAM;
  
  movwf (fileAddress, accessType);
  int dataMemoryAddr = getFileAddress (fileAddress, accessType);
  
  
  TEST_ASSERT_EQUAL_INT8(0x67, memory[dataMemoryAddr]); 
}


