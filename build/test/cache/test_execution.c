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



void test_checkZero_given_value_is_0_should_set_zero_flag(void)

{

  int value = 0;

  memory[0xFD8] = 0;

  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x4)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)57, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_positive_number_should_unset_zero_flag(void)

{

  int value = 12;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

}



void test_checkZero_given_value_is_negative_value_should_unset_zero_flag(void)

{

  int value = -33;



  checkZero(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_more_than_127_should_set_Overflow_flag(void)

{

  int value = 130;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_less_than_negative_128_should_set_Overflow_flag(void)

{

  int value = -184;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x8)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_124_should_unset_Overflow_flag(void)

{

  int value = 124;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

}



void test_checkOverflow_given_value_is_negative_123_should_unset_Overflow_flag(void)

{

  int value = -123;



  checkOverflow(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_positive_value_should_unset_negative_flag(void)

{

  int value = 83;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x0)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)120, UNITY_DISPLAY_STYLE_INT);

}



void test_checkNegative_given_value_is_negative_value_should_set_negative_flag(void)

{

  int value = -107;



  checkNegative(value);



  UnityAssertEqualNumber((_U_SINT)((0x10)), (_U_SINT)((memory[0xFD8])), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

}



void test_readByte_given_accessType_is_1_result_should_return_as_general_purpose_register_address(void)

{

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x2;



  fileRegAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x223)), (_U_SINT)((fileRegAddr)), (((void *)0)), (_U_UINT)140, UNITY_DISPLAY_STYLE_INT);

}



void test_writeByte_given_accessType_is_1_result_should_store_into_general_purpose_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int accessType = 1;

  memory[0xFE0] = 0x3;



  writeByte (fileRegAddr, accessType, value);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)153, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_1_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 1;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)164, UNITY_DISPLAY_STYLE_INT);

}



void test_writeToFileRegister_given_d_is_0_result_should_store_into_file_register(void)

{

  int value = 0x38;

  int fileRegAddr = 0x23;

  int d = 0;



  writeToFileRegister(fileRegAddr, d, value);



  UnityAssertEqualNumber((_U_SINT)((0x38)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)175, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_0_result_should_store_into_WREG(void)

{

  int fileRegAddr = 0x23;

  fileMemory[fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 0, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)188, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)189, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT);

}



void test_addwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x24;

  fileMemory[fileRegAddr] = 0x17;

  memory[0xFE8] = 0x20;

  int d = 1, accessType = 0;



  addwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)203, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x20)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)204, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)205, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)221, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x37)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)237, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)251, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)252, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

}



void test_andwf_given_d_is_1_result_should_store_into_file_register(void)

{

  int fileRegAddr = 0x27;

  fileMemory [fileRegAddr] = 0xC2;

  memory[0xFE8] = 0x17;

  int d = 1, accessType = 0;



  andwf (fileRegAddr, d, accessType);

  int dataMemoryAddr = readByte (fileRegAddr, accessType);



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)267, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)282, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)283, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)298, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x02)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)300, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)315, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)316, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)317, UNITY_DISPLAY_STYLE_INT);

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





  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)333, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0x17)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)350, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)351, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x12)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xDA)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)353, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)368, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xC2)), (_U_SINT)((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)369, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0xD9)), (_U_SINT)((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((_U_SINT)((0x112)), (_U_SINT)((dataMemoryAddr)), (((void *)0)), (_U_UINT)371, UNITY_DISPLAY_STYLE_INT);

}



void test_addlw_given_Literal_is_15_result_should_store_into_WREG(void)

{

  int Literal = 0x15;

  memory[0xFE8] = 0x17;



  addlw (Literal);





  UnityAssertEqualNumber((_U_SINT)((0x2C)), (_U_SINT)((memory[0xFE8])), (((void *)0)), (_U_UINT)382, UNITY_DISPLAY_STYLE_INT);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x03)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)396, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x3)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)398, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x19)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)412, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)413, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)414, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF7)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)428, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x17)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)429, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF7)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)430, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)444, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x34)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)445, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x12)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)446, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFC)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)461, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)462, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFC)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)463, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x01)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)478, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFD)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)479, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFD)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)480, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x8)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)495, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x17)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)496, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x8)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)497, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1F)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)512, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)513, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x1F)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)514, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x2)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)529, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)530, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x2)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)531, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x63)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)546, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB4)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)547, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xB4)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)548, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x20)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)563, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)564, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF6)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)565, UNITY_DISPLAY_STYLE_INT8);

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



  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE1)), (_U_SINT)(_US8 )((memory[0xFE8])), (((void *)0)), (_U_UINT)580, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0x14)), (_U_SINT)(_US8 )((fileMemory[fileRegAddr])), (((void *)0)), (_U_UINT)581, UNITY_DISPLAY_STYLE_INT8);

  UnityAssertEqualNumber((_U_SINT)(_US8 )((0xE1)), (_U_SINT)(_US8 )((memory[dataMemoryAddr])), (((void *)0)), (_U_UINT)582, UNITY_DISPLAY_STYLE_INT8);

}
