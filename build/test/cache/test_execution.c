#include "RegisterAddress.h"
#include "execution.h"
#include "unity.h"






void setUp(void){}



void tearDown(void){}



void test_addwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x23;

  memory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 0, a = 1;



  addwf (fileRegAddr, d, a);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x24;

  memory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, a = 1;



  addwf (fileRegAddr, d, a);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

}
