#include "RegisterAddress.h"
#include "execution.h"
#include "unity.h"






void setUp(void){}



void tearDown(void){}



void test_readByte_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)

{

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x2;



  fileRegAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x223)), (_U_SINT)((fileRegAddr)), (((void *)0)), (_U_UINT)19, UNITY_DISPLAY_STYLE_INT);

}



void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x3;



  writeByte (fileRegAddr, accessType, value);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)32, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 1;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 0;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x23;

  fileMemory[fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 0, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)69, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x24;

  fileMemory[fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFE0] = 0x2;

  int d = 0, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)98, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)100, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFE0] = 0x4;

  int d = 0, accessType = 1;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;

  memory[0xFE0] = 0x3;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)132, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 1, accessType = 0;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)145, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)165, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x32;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 0, accessType = 0;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)183, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x12;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  memory[0xFD8] = 0x1;

  int d = 0, accessType = 0;



  addwfc (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)200, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)201, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)202, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x12;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  memory[0xFD8] = 0x0;

  int d = 1, accessType = 1;



  addwfc (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x12;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x1;

  memory[0xFD8] = 0x1;

  int d = 1, accessType = 0;



  addwfc (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)239, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x12)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x12;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x1;

  memory[0xFD8] = 0x0;

  int d = 0, accessType = 1;



  addwfc (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  printf("%d", dataMemoryAddr);



  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)260, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x112)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)261, UNITY_DISPLAY_STYLE_INT);

}



void test_addlw_given_Literal_is_15_result_should_store_into_WREG(void)

{

  int Literal = 0x15;

  memory[0xFE8] = 0x17;



  addlw (Literal);



  printf("%d", memory[0xFE8]);



  UnityAssertEqualNumber((_U_SINT)((0x2C)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);

}
