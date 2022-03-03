#include "pch.h"
#include "test.h"
#include "TestUtil.h"
#include "../EmployeeManagementSystem/input_validation.cpp"
#include "../EmployeeManagementSystem/outputValidation.cpp"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

TEST_F(FixtureTestCalculator, SuccessToAdd) {
	FEATURE("Manage는 Employee에 사원 정보를 추가할 수 있다.");
	SCENARIO("Employee에 주어진 사원 정보를 저장한다.");

	GIVEN("주어진 사원 정보");
	Employee employee(0, NULL, NULL, NULL, NULL, NULL);

	WHEN("사원 정보가 추가되었을 때");

	THEN("정상적으로 추가가 되어야하고");
	string sample = "Mock is working";
	EXPECT_CALL(manage_, testMock()).Times(1).WillOnce(Return(sample));

	AND("추가된 사원 정보를 확인할 수 있어야 한다.");
	// EXPECT_EQ("Mock is working", result);
}

TEST(InputValidation, TypeValidation) {
	EXPECT_EQ(true, isValidBirthday("20120101"));
	EXPECT_EQ(true, isValidBirthday("19990228"));
	EXPECT_EQ(true, isValidBirthday("20101231"));
	EXPECT_EQ(false, isValidBirthday("20010229"));
	EXPECT_EQ(false, isValidBirthday("199902282"));
	EXPECT_EQ(false, isValidBirthday("201012A1"));


	EXPECT_EQ(true, isValidCerti("ADV"));
	EXPECT_EQ(true, isValidCerti("PRO"));
	EXPECT_EQ(true, isValidCerti("EX"));
	EXPECT_EQ(false, isValidCerti("ADVance"));

	EXPECT_EQ(true, isValidCL("CL1"));
	EXPECT_EQ(true, isValidCL("CL2"));
	EXPECT_EQ(true, isValidCL("CL3"));
	EXPECT_EQ(true, isValidCL("CL4"));
	EXPECT_EQ(false, isValidCL("CL0"));
	EXPECT_EQ(false, isValidCL("CL5"));
	EXPECT_EQ(false, isValidCL("CL2 "));
	EXPECT_EQ(false, isValidCL("CL22"));

	EXPECT_EQ(true, isValidPhoneNum("010-1234-3210"));
	EXPECT_EQ(true, isValidPhoneNum("010-9999-0000"));
	EXPECT_EQ(false, isValidPhoneNum("011-1234-3210"));
	EXPECT_EQ(false, isValidPhoneNum("012-1234-3210"));
	EXPECT_EQ(false, isValidPhoneNum("010-1998-32210"));
	EXPECT_EQ(false, isValidPhoneNum("010-123-43210"));
	EXPECT_EQ(false, isValidPhoneNum("010--23143210"));

	EXPECT_EQ(true, isValidEmployeeNum("69123456"));
	EXPECT_EQ(true, isValidEmployeeNum("21123456"));
	EXPECT_EQ(false, isValidEmployeeNum("69123a56"));
	EXPECT_EQ(false, isValidEmployeeNum("691023456"));
	EXPECT_EQ(false, isValidEmployeeNum("68123456"));
	EXPECT_EQ(false, isValidEmployeeNum("22123456"));
	EXPECT_EQ(false, isValidEmployeeNum("2112345a"));

	EXPECT_EQ(true, isValidName("A B"));
	EXPECT_EQ(true, isValidName("AMILY BARK"));
	EXPECT_EQ(true, isValidName("ABCDEFG BILLYAB"));
	EXPECT_EQ(false, isValidName("ABCDEFG BILL YAB"));
	EXPECT_EQ(false, isValidName("Amily Bark"));
	EXPECT_EQ(false, isValidName("Am1ly Bark"));
}

TEST(InputValidation, AddInputValidation) {
	
	EXPECT_EQ(true, is_valid_input("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,19050301,JONGSEOK KIM,CL3,010-1234-4321,19900101,PRO"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,20030110,JACKSON KIM,CL2,010-9999-2321,19700101,ADV"));
	EXPECT_EQ(true, is_valid_input("ADD, , , ,15050821,JM PARK,CL1,010-8787-1010,20010227,EX"));

	EXPECT_EQ(false, is_valid_input("ADD, , , ,59010101,MC Donald,CL3,010-3434-0101,EX"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050301,Burger Big King,CL2,010-1234-6055,19980903,PRO"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050311,LEESU KING,CL3,010-9777-9874,19980906,PROFESSIONAL"));
	EXPECT_EQ(false, is_valid_input("ADD, , , ,18050350,JASON MURAZ,CL4,011-9777-1435,20010104,ADV"));
}

TEST(InputValidation, SchInputValidation) {
	EXPECT_EQ(true, is_valid_input("SCH, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, is_valid_input("SCH,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, is_valid_input("SCH,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(true, is_valid_input("SCH, ,-l, ,name,KIM"));
	EXPECT_EQ(true, is_valid_input("SCH, ,-f, ,name,KYUMOK"));
	EXPECT_EQ(true, is_valid_input("SCH, ,-y, ,birthday,1999"));

	EXPECT_EQ(false, is_valid_input("Sch, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, is_valid_input("SCH,-p,-l, ,birthday,19970102"));
	EXPECT_EQ(false, is_valid_input("SCH,-p,-m, ,phonenum,1234"));
	EXPECT_EQ(false, is_valid_input("SCH, ,-l, ,cl,CL3"));
	EXPECT_EQ(false, is_valid_input("SCH, , , ,phoneNum,010-1234-"));
	EXPECT_EQ(false, is_valid_input("SCH, ,-y, ,birthday,01"));
}

TEST(InputValidation, ModInputValidation) {

	EXPECT_EQ(true, is_valid_input("MOD, ,-l, ,name,KIM,phoneNum,010-2321-4584"));
	EXPECT_EQ(true, is_valid_input("MOD, ,-f, ,name,KYUMOK,name,KYUMOK KING"));
	EXPECT_EQ(true, is_valid_input("MOD, ,-y, ,birthday,1999,cl,CL4"));

	EXPECT_EQ(false, is_valid_input("MOD, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, is_valid_input("MOD,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, is_valid_input("MOD,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(false, is_valid_input("Mod, , , ,name,KYUMOK KIM,name,KYUMOK IM"));
	EXPECT_EQ(false, is_valid_input("MOD,-p,-l, ,birthday,19970102,birthday,19970103"));
	EXPECT_EQ(false, is_valid_input("MOD,-p,-m, ,phonenum,1234,phoneNum,010-2321-2324"));
	EXPECT_EQ(false, is_valid_input("MOD, ,-l, ,cl,CL3,cl,CL4"));
	EXPECT_EQ(false, is_valid_input("MOD, , , ,phoneNum,010-1234-,phoneNum,010-1234-4321"));
	EXPECT_EQ(false, is_valid_input("MOD, ,-y, ,birthday,01,birthday,19991231"));
}

TEST(InputValidation, DelInputValidation) {
	EXPECT_EQ(true, is_valid_input("DEL, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, is_valid_input("DEL,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(true, is_valid_input("DEL,-p,-m, ,phoneNum,1234"));
	EXPECT_EQ(true, is_valid_input("DEL, ,-l, ,name,KIM"));
	EXPECT_EQ(true, is_valid_input("DEL, ,-f, ,name,KYUMOK"));
	EXPECT_EQ(true, is_valid_input("DEL, ,-y, ,birthday,1999"));

	EXPECT_EQ(false, is_valid_input("Del, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, is_valid_input("DEL,-p,-l, ,birthday,19970102"));
	EXPECT_EQ(false, is_valid_input("DEL,-p,-m, ,phonenum,1234"));
	EXPECT_EQ(false, is_valid_input("DEL, ,-l, ,cl,CL3"));
	EXPECT_EQ(false, is_valid_input("DEL, , , ,phoneNum,010-1234-"));
	EXPECT_EQ(false, is_valid_input("DEL, ,-y, ,birthday,01"));
}

TEST(OutputValidation, IsSameAsAnswer) {
	EXPECT_EQ(true, IsValidOutput());
}

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}