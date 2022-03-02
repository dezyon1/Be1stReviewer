#include "pch.h"
#include "../EmployeeManagementSystem/input_validation.cpp"

TEST(InputValidation, AddInputValidation) {
	
	EXPECT_EQ(true, is_valid_input("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,19050301,JONGSEOK KIM,CL3,010-1234-4321,19900101,PRO"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,20030110,JACKSON KIM,CL2,010-9999-2321,19700101,ADV"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,15050821,JM Park,CL1,010-8787-1010,20010227,EX"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,59010101,MC Donald,CL3,010-3434-0101,EX"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050301,Burger Big King,CL2,010-1234-6055,19980903,PRO"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050311,LEESU KING,CL3,010-9777-9874,19980906,PROFESSIONAL"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050350,JASON MURAZ,CL4,011-9777-1435,20010104,ADV"));
}

TEST(InputValidation, SchInputValidation) {
	EXPECT_EQ(true, is_valid_input("DEL, , , ,name,KYUMOK KIM"));
	
}

TEST(InputValidation, ModInputValidation) {
	EXPECT_EQ(true, is_valid_input("SCH, , , ,name, KYUMOK KIM"));
}

TEST(InputValidation, DelInputValidation) {
	EXPECT_EQ(true, is_valid_input("MOD, , , ,name,KYUMOK KIM,name,KYUMOK KIM"));
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}