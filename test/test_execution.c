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
  int d = 0, a = 0;
  
  addwf (fileRegAddr, d, a);
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x17, memory[fileRegAddr]); 
}

void test_addwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x24;
  memory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  int d = 1, a = 0;
  
  addwf (fileRegAddr, d, a);
  
  TEST_ASSERT_EQUAL(0x37, memory[fileRegAddr]);
  TEST_ASSERT_EQUAL(0x20, WREG); 
}

void test_addwf_given_a_is_1_result_should_store_into_general_purpose_register(void)
{
  int fileRegAddr = 0x23;
  memory [fileRegAddr] = 0x17;
  WREG  = 0x20;
  BSR = 0x2;
  int d = 0, a = 1;

  addwf (fileRegAddr, d, a);
  fileRegAddr = GPR (fileRegAddr, d);
  printf("%d", memory[fileRegAddr]);
  
  TEST_ASSERT_EQUAL(0x37, WREG);
  TEST_ASSERT_EQUAL(0x37, memory[fileRegAddr]); 
}

void test_andwf_given_d_is_0_result_should_store_into_WREG(void)
{
  int fileRegAddr = 0x25;
  memory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  int d = 0, a = 0;
  
  andwf (fileRegAddr, d, a);
  printf("%d", WREG);
  
  TEST_ASSERT_EQUAL(0x02, WREG);
  TEST_ASSERT_EQUAL(0xC2, memory[fileRegAddr]); 
}

void test_andwf_given_d_is_1_result_should_store_into_file_register(void)
{
  int fileRegAddr = 0x27;
  memory [fileRegAddr] = 0xC2;
  WREG  = 0x17;
  int d = 1, a = 0;
  
  andwf (fileRegAddr, d, a);
  
  TEST_ASSERT_EQUAL(0x17, WREG); 
  TEST_ASSERT_EQUAL(0x02, memory[fileRegAddr]);
}

