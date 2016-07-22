#include "unity.h"
#include "execution.h"
#include <stdio.h>
#include <stdint.h>
#include "RegisterAddress.h"

void setUp(void){}

void tearDown(void){}

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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", dataMemoryAddr);
  
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

  printf("%d", WREG);
  
  TEST_ASSERT_EQUAL(0x2C, WREG); 
}





