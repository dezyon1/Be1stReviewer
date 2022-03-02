#include "pch.h"
#include "../EmployeeManagementSystem/input_validation.cpp"

TEST(InputValidation, AddInputValidation) {
	
	EXPECT_EQ(true, isValidInput("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,19050301,JONGSEOK KIM,CL3,010-1234-4321,19900101,PRO"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,20030110,JACKSON KIM,CL2,010-9999-2321,19700101,ADV"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,15050821,JM Park,CL1,010-8787-1010,20010227,EX"));

	EXPECT_EQ(false, isValidInput("ADD, , , ,59010101,MC Donald,CL3,010-3434-0101,EX"));
	EXPECT_EQ(false, isValidInput("ADD, , , ,18050301,Burger Big King,CL2,010-1234-6055,19980903,PRO"));
	EXPECT_EQ(false, isValidInput("ADD, , , ,18050311,LEESU KING,CL3,010-9777-9874,19980906,PROFESSIONAL"));
	EXPECT_EQ(false, isValidInput("ADD, , , ,18050350,JASON MURAZ,CL4,011-9777-1435,20010104,ADV"));
}

TEST(InputValidation, SchInputValidation) {
	EXPECT_EQ(true, isValidInput("SCH, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("SCH,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("SCH,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(true, isValidInput("SCH, ,-l, ,name,KIM"));
	EXPECT_EQ(true, isValidInput("SCH, ,-f, ,name,KYUMOK"));
	EXPECT_EQ(true, isValidInput("SCH, ,-y, ,birthday,1999"));

	EXPECT_EQ(false, isValidInput("Sch, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, isValidInput("SCH,-p,-l, ,birthday,19970102"));
	EXPECT_EQ(false, isValidInput("SCH,-p,-m, ,phonenum,1234"));
	EXPECT_EQ(false, isValidInput("SCH, ,-l, ,cl,CL3"));
	EXPECT_EQ(false, isValidInput("SCH, , , ,phoneNum,010-1234-"));
	EXPECT_EQ(false, isValidInput("SCH, ,-y, ,birthday,01"));
}

TEST(InputValidation, ModInputValidation) {
	EXPECT_EQ(true, isValidInput("MOD, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("MOD,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("MOD,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(true, isValidInput("MOD, ,-l, ,name,KIM,phoneNum,010-2321-4584"));
	EXPECT_EQ(true, isValidInput("MOD, ,-f, ,name,KYUMOK,name,KYUMOK KING"));
	EXPECT_EQ(true, isValidInput("MOD, ,-y, ,birthday,1999,cl,CL4"));

	EXPECT_EQ(false, isValidInput("Mod, , , ,name,KYUMOK KIM,name,KYUMOK IM"));
	EXPECT_EQ(false, isValidInput("MOD,-p,-l, ,birthday,19970102,birthday,19970103"));
	EXPECT_EQ(false, isValidInput("MOD,-p,-m, ,phonenum,1234,phoneNum,010-2321-2324"));
	EXPECT_EQ(false, isValidInput("MOD, ,-l, ,cl,CL3,cl,CL4"));
	EXPECT_EQ(false, isValidInput("MOD, , , ,phoneNum,010-1234-,phoneNum,010-1234-4321"));
	EXPECT_EQ(false, isValidInput("MOD, ,-y, ,birthday,01,birthday,19991231"));
}

TEST(InputValidation, DelInputValidation) {
	EXPECT_EQ(true, isValidInput("DEL, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("DEL,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, isValidInput("DEL,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(true, isValidInput("DEL, ,-l, ,name,KIM"));
	EXPECT_EQ(true, isValidInput("DEL, ,-f, ,name,KYUMOK"));
	EXPECT_EQ(true, isValidInput("DEL, ,-y, ,birthday,1999"));

	EXPECT_EQ(false, isValidInput("Del, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, isValidInput("DEL,-p,-l, ,birthday,19970102"));
	EXPECT_EQ(false, isValidInput("DEL,-p,-m, ,phonenum,1234"));
	EXPECT_EQ(false, isValidInput("DEL, ,-l, ,cl,CL3"));
	EXPECT_EQ(false, isValidInput("DEL, , , ,phoneNum,010-1234-"));
	EXPECT_EQ(false, isValidInput("DEL, ,-y, ,birthday,01"));
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}