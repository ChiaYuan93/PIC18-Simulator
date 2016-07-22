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

  int d = 0, a = 0;



  addwf (fileRegAddr, d, a);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)20, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x24;

  memory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, a = 0;



  addwf (fileRegAddr, d, a);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_a_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x23;

  memory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFE0] = 0x2;

  int d = 0, a = 1;



  addwf (fileRegAddr, d, a);

  fileRegAddr = GPR (fileRegAddr, d);

  printf("%d", fileRegAddr);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)49, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  memory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, a = 0;



  andwf (fileRegAddr, d, a);

  printf("%d", memory[0xFE8]);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  memory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 1, a = 0;



  andwf (fileRegAddr, d, a);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_a_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x27;

  memory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 3;

  int d = 1, a = 0;



  andwf (fileRegAddr, d, a);

  fileRegAddr = GPR (fileRegAddr, d);

  printf("%d", fileRegAddr);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[fileRegAddr])), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

}
