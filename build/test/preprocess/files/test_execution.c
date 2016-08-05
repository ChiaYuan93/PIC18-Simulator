#include "RegisterAddress.h"
#include "execution.h"
#include "unity.h"






void setUp(void){}



void tearDown(void){}



void test_checkCarry_given_value_is_over_maximum_value_should_set_Carry_flag(void)

{

  int value = 0x7F + 0x87;



  checkCarry(value);



  UnityAssertEqualNumber((_U_SINT)((0x1)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

}



void test_checkCarry_given_value_is_under_maximum_value_should_unset_Carry_flag(void)

{

  int value = 0xFE + 0x1;



  checkCarry(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

}



void test_checkBorrow_given_minuend_is_smaller_than_subtrahend_should_unset_Carry_flag(void)

{

  int minuend = -98;

  int subtrahend = 45;

  int value = minuend - subtrahend;



  checkBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)37, UNITY_DISPLAY_STYLE_INT);

}



void test_checkBorrow_given_minuend_is_bigger_than_subtrahend_should_set_Carry_flag(void)

{

  int minuend = -45;

  int subtrahend = -98;

  int value = minuend - subtrahend;



  checkBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x1)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitCarry_given_value_is_over_maximum_value_should_set_Digit_Carry_flag(void)

{

  memory[0xFD8] = 0;

  int value = 0x8F + 0x1;



  checkDigitCarry(value);



  UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)58, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitCarry_given_value_is_under_maximum_value_should_unset_Digit_Carry_flag(void)

{

  memory[0xFD8] = 0;

  int value = 0x8E + 0x1;



  checkDigitCarry(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)68, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitBorrow_given_minuend_is_bigger_than_subtrahend_should_set_Carry_flag(void)

{

  int minuend = 0x98;

  int subtrahend = 0x45;

  int value = minuend - subtrahend;



  checkDigitBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)79, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitBorrow_given_minuend_is_smaller_than_subtrahend_should_unset_Carry_flag(void)

{

  int minuend = -45;

  int subtrahend = -56;

  int value = minuend - subtrahend;



  checkDigitBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)90, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_0_should_set_zero_flag(void)

{

  int value = 0;

  memory[0xFD8] = 0;

  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x4)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_positive_number_should_unset_zero_flag(void)

{

  int value = 12;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)108, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_negative_value_should_unset_zero_flag(void)

{

  int value = -33;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)117, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_more_than_127_should_set_Overflow_flag(void)

{

  int value = 130;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_less_than_negative_128_should_set_Overflow_flag(void)

{

  int value = -184;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_124_should_unset_Overflow_flag(void)

{

  int value = 124;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_negative_123_should_unset_Overflow_flag(void)

{

  int value = -123;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_positive_value_should_unset_negative_flag(void)

{

  int value = 83;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)162, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_negative_value_should_set_negative_flag(void)

{

  int value = -107;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

}



void test_readByte_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)

{

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x2;



  fileRegAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x223)), (_U_SINT)((fileRegAddr)), (((void *)0)), (_U_UINT)182, UNITY_DISPLAY_STYLE_INT);

}



void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x3;



  writeByte (fileRegAddr, accessType, value);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 1;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 0;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)217, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x23;

  fileMemory[fileRegAddr] = 0xEE;

  memory[0xFE8] = 0x12;

  int d = 0, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)230, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)231, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)((0x0F)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)233, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x24;

  fileMemory[fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)248, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)278, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)294, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)296, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 1, accessType = 0;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)309, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)311, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)326, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)342, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)360, UNITY_DISPLAY_STYLE_INT);

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





  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)377, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)378, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)393, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)394, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x12)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)395, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)396, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)411, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)412, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)413, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x112)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)414, UNITY_DISPLAY_STYLE_INT);

}



void test_addlw_given_Literal_is_15_result_should_store_into_WREG(void)

{

  int Literal = 0x15;

  memory[0xFE8] = 0x17;



  addlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x2C)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)424, UNITY_DISPLAY_STYLE_INT);

}



void test_subwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;

  memory[0xFE0] = 0x3;



  subwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x03)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)438, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)439, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x3)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x34;

  fileMemory [fileRegAddr] = 0x18;

  memory[0xFE8] = 0x19;

  int d = 1, accessType = 0;

  memory[0xFE0] = 0x3;



  subwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x19)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)454, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)455, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)456, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwf_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFE0] = 0x2;

  int d = 0, accessType = 0;



  subwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF7)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)470, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x17)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)471, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF7)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)472, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x34;

  memory[0xFE8] = 0x22;

  memory[0xFE0] = 0x4;

  int d = 0, accessType = 1;



  subwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x34)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)487, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)488, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;

  memory[0xFD8] = 0x0;

  memory[0xFE0] = 0x3;



  subfwb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFC)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)503, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)504, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFC)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 1, accessType = 0;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x3;



  subfwb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)520, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFD)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFD)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)522, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFD8] = 0x0;

  memory[0xFE0] = 0x2;

  int d = 0, accessType = 0;



  subfwb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x8)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)537, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x17)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)538, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x8)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)539, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x14;

  memory[0xFE8] = 0x33;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x4;

  int d = 0, accessType = 1;



  subfwb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1F)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)554, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)555, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1F)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)556, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;

  memory[0xFD8] = 0x0;

  memory[0xFE0] = 0x3;



  subwfb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x2)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)571, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)572, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x2)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)573, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x63;

  int d = 1, accessType = 0;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x3;



  subwfb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x63)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)588, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)589, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB4)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)590, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFD8] = 0x0;

  memory[0xFE0] = 0x2;

  int d = 1, accessType = 0;



  subwfb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x20)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)605, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)606, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)607, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x23;

  fileMemory [fileRegAddr] = 0x14;

  memory[0xFE8] = 0x33;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x4;

  int d = 0, accessType = 1;



  subwfb(fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE1)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)622, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)623, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE1)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)624, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_is_34_result_should_store_into_WREG(void)

{

  int Literal = 0x34;

  memory[0xFE8] = 0x21;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x13)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)634, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_is_smaller_than_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x17;

  memory[0xFE8] = 0x21;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)644, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_and_WREG_are_negative_value_result_should_store_into_WREG(void)

{

  int Literal = 0x90;

  memory[0xFE8] = 0xED;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA3)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)654, UNITY_DISPLAY_STYLE_INT8);

}



void test_andlw_given_eight_bit_Literal_AND_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x73;

  memory[0xFE8] = 0xB5;



  andlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x31)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)664, UNITY_DISPLAY_STYLE_INT);

}



void test_iorlw_given_eight_bit_Literal_OR_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0xAA;

  memory[0xFE8] = 0x55;



  iorlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0xFF)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)674, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;

  memory[0xFE0] = 0x3;



  iorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)688, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)689, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)690, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xF1;

  memory[0xFE8] = 0x14;

  int d = 1, accessType = 0;



  iorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)703, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xF5)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)704, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xF5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)705, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  iorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)719, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)720, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)721, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x32;

  fileMemory [fileRegAddr] = 0x83;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 0, accessType = 0;



  iorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x97)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)735, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x83)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)736, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x97)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)737, UNITY_DISPLAY_STYLE_INT);

}



void test_xorlw_given_eight_bit_Literal_XOR_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x6D;

  memory[0xFE8] = 0x29;



  xorlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x44)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)747, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x25;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;

  memory[0xFE0] = 0x3;



  xorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)761, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)762, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)763, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xF1;

  memory[0xFE8] = 0x14;

  int d = 1, accessType = 0;



  xorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)776, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xE5)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)777, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xE5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)778, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  xorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)792, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)793, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)794, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileRegAddr = 0x32;

  fileMemory [fileRegAddr] = 0x83;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 0, accessType = 0;



  xorwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x94)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)808, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x83)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)809, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x94)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)810, UNITY_DISPLAY_STYLE_INT);

}
