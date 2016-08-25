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

  int addend1 = 0xEE;

  int addend2 = 0x12;

  int value = addend1 + addend2;



  checkDigitCarry(value, addend1, addend2);



  UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)60, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitCarry_given_value_is_more_than_maximum_value_should_set_Digit_Carry_flag(void)

{

  memory[0xFD8] = 0;

  int addend1 = 0xEF;

  int addend2 = 0x1;

  int value = addend1 + addend2;



  checkDigitCarry(value, addend1, addend2);



  UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)72, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitBorrow_given_minuend_is_bigger_than_subtrahend_should_set_Carry_flag(void)

{

  int minuend = 0x98;

  int subtrahend = 0x45;

  int value = minuend - subtrahend;



  checkDigitBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x2)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_checkDigitBorrow_given_minuend_is_smaller_than_subtrahend_should_unset_Carry_flag(void)

{

  int minuend = -45;

  int subtrahend = -56;

  int value = minuend - subtrahend;



  checkDigitBorrow(minuend, subtrahend);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_0_should_set_zero_flag(void)

{

  int value = 0;

  memory[0xFD8] = 0;

  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x4)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_positive_number_should_unset_zero_flag(void)

{

  int value = 12;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_negative_value_should_unset_zero_flag(void)

{

  int value = -33;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)121, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_more_than_127_should_set_Overflow_flag(void)

{

  int value = 130;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)130, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_less_than_negative_128_should_set_Overflow_flag(void)

{

  int value = -184;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_124_should_unset_Overflow_flag(void)

{

  int value = 124;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)148, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_negative_123_should_unset_Overflow_flag(void)

{

  int value = -123;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)157, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_positive_value_should_unset_negative_flag(void)

{

  int value = 83;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)166, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_negative_value_should_set_negative_flag(void)

{

  int value = -107;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

}



void test_getFileAddress_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)

{

  int fileAddress = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x2;



  fileAddress = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x223)), (_U_SINT)((fileAddress)), (((void *)0)), (_U_UINT)186, UNITY_DISPLAY_STYLE_INT);

}



void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int value = 0x38;

  int fileAddress = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x3;



  writeByte (fileAddress, accessType, value);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)

{

  int value = 0xF3;

  int fileAddress = 0xE8;

  int d = 1;

  int accessType = 1;

  memory[0xFE0] = 4;



  writeToFileRegister(fileAddress, d, accessType, value);

  fileAddress = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xF3)), (_U_SINT)((memory[fileAddress])), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileAddress = 0x23;

  int d = 0;

  int accessType = 0;



  writeToFileRegister(fileAddress, d, accessType, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

}



void test_readByte_should_read_data_from_address(void)

{

  int fileAddress = 0x23;

  memory[fileAddress] = 0x45;

  int accessType = 0;

  int data = readByte(fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x45)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

}



void test_readByte_should_read_data_from_Bank_address(void)

{

  int fileAddress = 0x423;

  memory[fileAddress] = 0x55;

  memory[0xFE0] = 0x4;

  int accessType = 0;

  int data = readByte(fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x55)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT);

}



void test_readByte_should_read_different_data_from_Bank_address(void)

{

  int fileAddress = 0x413;

  memory[fileAddress] = 0x55;

  memory[0xFE0] = 0x2;

  int accessType = 1;

  int data = readByte(fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((data)), (((void *)0)), (_U_UINT)257, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x23;

  memory[fileAddress] = 0xEE;

  memory[0xFE8] = 0x12;

  int d = 0, accessType = 0;



  addwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)((0xEE)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)272, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x0F)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)273, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x80;

  memory[fileAddress] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, accessType = 0;



  addwf (fileAddress, d, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)285, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xF80])), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x423;

  memory [fileAddress] = 0x17;

  memory[0xFE8] = 0x20;

  memory[0xFE0] = 0x4;

  int d = 1, accessType = 1;



  addwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;



  andwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)314, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x27;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 1, accessType = 0;



  andwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)329, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x327;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  andwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)343, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x93;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFD8] = 0x1;

  int d = 0, accessType = 0;



  addwfc (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)359, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x312;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  memory[0xFD8] = 0x0;

  int d = 1, accessType = 1;



  addwfc (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);





  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)375, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_INT);

}



void test_addwfc_given_accessType_is_0_result_should_store_into_access_bank(void)

{

  int fileAddress = 0x12;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFD8] = 0x1;

  int d = 1, accessType = 0;



  addwfc (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

}



void test_addlw_given_Literal_is_15_result_should_store_into_WREG(void)

{

  int Literal = 0x15;

  memory[0xFE8] = 0x17;



  addlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x2C)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)401, UNITY_DISPLAY_STYLE_INT);

}



void test_subwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;



  subwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x03)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)414, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x04)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)415, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x34;

  memory [fileAddress] = 0x18;

  memory[0xFE8] = 0x19;

  int d = 1, accessType = 0;



  subwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x19)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)428, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)429, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x423;

  memory [fileAddress] = 0x34;

  memory[0xFE8] = 0x22;

  memory[0xFE0] = 0x4;

  int d = 1, accessType = 1;



  subwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x22)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)443, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;

  memory[0xFD8] = 0x0;



  subfwb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFC)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)458, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x04)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)459, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 1, accessType = 0;

  memory[0xFD8] = 0x1;



  subfwb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)473, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFD)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)474, UNITY_DISPLAY_STYLE_INT8);

}



void test_subfwb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x323;

  memory [fileAddress] = 0x14;

  memory[0xFE8] = 0x33;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  subfwb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x33)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)489, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1F)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)490, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0x04;

  memory[0xFE8] = 0x01;

  int d = 0, accessType = 0;

  memory[0xFD8] = 0x0;



  subwfb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x2)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)504, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x04)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)505, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0x17;

  memory[0xFE8] = 0x63;

  int d = 1, accessType = 0;

  memory[0xFD8] = 0x1;



  subwfb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x63)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)519, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB4)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)520, UNITY_DISPLAY_STYLE_INT8);

}



void test_subwfb_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x123;

  memory [fileAddress] = 0x14;

  memory[0xFE8] = 0x33;

  memory[0xFD8] = 0x1;

  memory[0xFE0] = 0x1;

  int d = 1, accessType = 1;



  subwfb(fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x33)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)535, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE1)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)536, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_is_34_result_should_store_into_WREG(void)

{

  int Literal = 0x34;

  memory[0xFE8] = 0x21;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x13)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)546, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_is_smaller_than_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x17;

  memory[0xFE8] = 0x21;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)556, UNITY_DISPLAY_STYLE_INT8);

}



void test_sublw_given_Literal_and_WREG_are_negative_value_result_should_store_into_WREG(void)

{

  int Literal = 0x90;

  memory[0xFE8] = 0xED;



  sublw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xA3)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)566, UNITY_DISPLAY_STYLE_INT8);

}



void test_andlw_given_eight_bit_Literal_AND_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x73;

  memory[0xFE8] = 0xB5;



  andlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x31)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)576, UNITY_DISPLAY_STYLE_INT);

}



void test_iorlw_given_eight_bit_Literal_OR_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0xAA;

  memory[0xFE8] = 0x55;



  iorlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0xFF)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)586, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;



  iorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)599, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)600, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x27;

  memory [fileAddress] = 0xF1;

  memory[0xFE8] = 0x14;

  int d = 1, accessType = 0;



  iorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)613, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xF5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)614, UNITY_DISPLAY_STYLE_INT);

}



void test_iorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x527;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x5;

  int d = 1, accessType = 1;



  iorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)628, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD7)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)629, UNITY_DISPLAY_STYLE_INT);

}



void test_xorlw_given_eight_bit_Literal_XOR_with_WREG_result_should_store_into_WREG(void)

{

  int Literal = 0x6D;

  memory[0xFE8] = 0x29;



  xorlw (Literal);



  UnityAssertEqualNumber((_U_SINT)((0x44)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)639, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x25;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 0, accessType = 0;



  xorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)652, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)653, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x27;

  memory [fileAddress] = 0xF1;

  memory[0xFE8] = 0x14;

  int d = 1, accessType = 0;



  xorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x14)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)666, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xE5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)667, UNITY_DISPLAY_STYLE_INT);

}



void test_xorwf_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x327;

  memory [fileAddress] = 0xC2;

  memory[0xFE8] = 0x17;

  memory[0xFE0] = 0x3;

  int d = 1, accessType = 1;



  xorwf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)681, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD5)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)682, UNITY_DISPLAY_STYLE_INT);

}



void test_clrf_given_accessType_is_1_should_clear_the_content_of_general_purpose_register(void)

{

  int fileAddress = 153;

  memory [fileAddress] = 0xC2;

  memory[0xFE0] = 0x1;

  int accessType = 1;



  clrf (fileAddress, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)695, UNITY_DISPLAY_STYLE_INT);

}



void test_clrf_given_accessType_is_0_should_clear_the_content_of_access_RAM(void)

{

  int fileAddress = 0xF93;

  memory [fileAddress] = 0xC2;

  int accessType = 1;



  clrf (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((memory[0xF94])), (((void *)0)), (_U_UINT)706, UNITY_DISPLAY_STYLE_INT);

}



void test_comf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x27;

  memory [fileAddress] = 0x13;

  int d = 0, accessType = 0;



  comf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xEC)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)718, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)((0x13)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)719, UNITY_DISPLAY_STYLE_INT);

}



void test_comf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileAddress = 0x49;

  memory [fileAddress] = 0x95;

  int d = 1, accessType = 0;



  comf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x6A)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)731, UNITY_DISPLAY_STYLE_INT8);

}



void test_comf_given_a_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x149;

  memory [fileAddress] = 0x48;

  memory[0xFE0] = 0x1;

  int d = 1, accessType = 1;



  comf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB7)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)744, UNITY_DISPLAY_STYLE_INT8);

}



void test_decf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x49;

  memory [fileAddress] = 0x48;

  int d = 0, accessType = 0;



  decf (fileAddress, d, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x47)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)755, UNITY_DISPLAY_STYLE_INT8);

}



void test_decf_given_d_is_1_result_should_store_into_WREG(void)

{

  int fileAddress = 0x51;

  memory [fileAddress] = 0;

  int d = 1, accessType = 0;



  decf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)767, UNITY_DISPLAY_STYLE_INT8);

}



void test_decf_given_a_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x251;

  memory [fileAddress] = 0x10;

  memory[0xFE0] = 0x2;

  int d = 1, accessType = 1;



  decf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x0F)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)780, UNITY_DISPLAY_STYLE_INT8);

}



void test_incf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileAddress = 0x49;

  memory [fileAddress] = 0x48;

  int d = 0, accessType = 0;



  incf (fileAddress, d, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x49)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)791, UNITY_DISPLAY_STYLE_INT8);

}



void test_incf_given_d_is_1_result_should_store_into_WREG(void)

{

  int fileAddress = 0x51;

  memory [fileAddress] = 0xFF;

  int d = 1, accessType = 0;



  incf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)803, UNITY_DISPLAY_STYLE_INT8);

}



void test_incf_given_a_is_1_result_should_store_into_general_purpose_register(void)

{

  int fileAddress = 0x251;

  memory [fileAddress] = 0x0F;

  memory[0xFE0] = 0x2;

  int d = 1, accessType = 1;



  incf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x10)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)816, UNITY_DISPLAY_STYLE_INT8);

}



void test_movf_given_d_is_0_data_should_read_from_file_register_and_store_into_WREG(void)

{

  int fileAddress = 0x51;

  memory [fileAddress] = 0x78;

  int d = 0, accessType = 0;



  movf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x78)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)828, UNITY_DISPLAY_STYLE_INT8);

}



void test_movf_given_d_is_1_data_should_read_from_file_register_and_store_back_into_file_register(void)

{

  int fileAddress = 0x251;

  memory [fileAddress] = 0x78;

  int d = 1, accessType = 0;



  movf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x78)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)840, UNITY_DISPLAY_STYLE_INT8);

}



void test_movf_given_a_is_1_data_should_read_from_file_register_and_store_back_into_file_register_with_BSR(void)

{

  int fileAddress = 0x151;

  memory [fileAddress] = 0x11;

  memory[0xFE0] = 1;

  int d = 1, accessType = 1;



  movf (fileAddress, d, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x11)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)853, UNITY_DISPLAY_STYLE_INT8);

}



void test_movlw_data_should_store_into_WREG(void)

{

  int Literal = 0xF0;



  movlw (Literal);



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF0)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)862, UNITY_DISPLAY_STYLE_INT8);

}



void test_movwf_should_read_data_from_WREG_and_store_into_file_register(void)

{

  int fileAddress = 0x70;

  memory[0xFE8] = 0x39;

  int accessType = 0;



  movwf (fileAddress, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x39)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)875, UNITY_DISPLAY_STYLE_INT8);

}



void test_movwf_given_a_is_1_should_read_data_from_WREG_and_store_into_file_register_with_BSR(void)

{

  int fileAddress = 0x570;

  memory[0xFE8] = 0x67;

  memory[0xFE0] = 5;

  int accessType = 1;



  movwf (fileAddress, accessType);

  int dataMemoryAddr = getFileAddress (fileAddress, accessType);





  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x67)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)889, UNITY_DISPLAY_STYLE_INT8);

}
