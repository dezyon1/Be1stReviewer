#include "pch.h"
#include "test.h"
#include "TestUtil.h"

#include "../EmployeeManagementSystem/InputValidation.cpp"
#include "../EmployeeManagementSystem/OutputValidation.cpp"
#include "../EmployeeManagementSystem/EmployeeManagementSystem.cpp"
#include "../EmployeeManagementSystem/Employee.cpp"
#include "../EmployeeManagementSystem/Employee.h"
#include "../EmployeeManagementSystem/Database.cpp"
#include "../EmployeeManagementSystem/Common.cpp"

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

/*
TEST_F(FixtureTestCalculator, SuccessToAdd) {
	FEATURE("Manage는 Employee에 사원 정보를 추가할 수 있다.");
	SCENARIO("Employee에 주어진 사원 정보를 저장한다.");

	GIVEN("주어진 사원 정보");
	// Employee employee(0, NULL, NULL, NULL, NULL, NULL);

	WHEN("사원 정보가 추가되었을 때");

	THEN("정상적으로 추가가 되어야하고");
	string sample = "Mock is working";
	// EXPECT_CALL(manage_, testMock()).Times(1).WillOnce(Return(sample));

	AND("추가된 사원 정보를 확인할 수 있어야 한다.");
	// EXPECT_EQ("Mock is working", result);
}
*/

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

	EXPECT_EQ(true, isValidInput("ADD, , , ,18050301,KYUMOK KIM,CL2,010-9777-6055,19980906,PRO"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,19050301,JONGSEOK KIM,CL3,010-1234-4321,19900101,PRO"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,20030110,JACKSON KIM,CL2,010-9999-2321,19700101,ADV"));
	EXPECT_EQ(true, isValidInput("ADD, , , ,15050821,JM PARK,CL1,010-8787-1010,20010227,EX"));

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

	EXPECT_EQ(true, isValidInput("MOD, ,-l, ,name,KIM,phoneNum,010-2321-4584"));
	EXPECT_EQ(true, isValidInput("MOD, ,-f, ,name,KYUMOK,name,KYUMOK KING"));
	EXPECT_EQ(true, isValidInput("MOD, ,-y, ,birthday,1999,cl,CL4"));

	EXPECT_EQ(false, isValidInput("MOD, , , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, isValidInput("MOD,-p, , ,name,KYUMOK KIM"));
	EXPECT_EQ(false, isValidInput("MOD,-p,-m, ,phoneNum,1234"));
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

TEST(OutputValidation, IsSameAsAnswer) {
	EXPECT_EQ(true, IsValidOutput());
}

TEST(EmployeeTest, MatchTest) {
	Employee e("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV");
	EXPECT_EQ(true, e.isMatch("name", "JHOP", "-l"));
	EXPECT_EQ(true, e.isMatch("name", "VXIHXOTH", "-f"));
	EXPECT_EQ(false, e.isMatch("name", "JHOP", "-f"));
	EXPECT_EQ(false, e.isMatch("name", "VXIHXOTH", "-l"));

	EXPECT_EQ(true, e.isMatch("phoneNum", "3112", "-m"));
	EXPECT_EQ(true, e.isMatch("phoneNum", "2609", "-l"));
	EXPECT_EQ(false, e.isMatch("phoneNum", "3112", "-l"));
	EXPECT_EQ(false, e.isMatch("phoneNum", "2609", "-m"));

	EXPECT_EQ(true, e.isMatch("birthday", "1977", "-y"));
	EXPECT_EQ(false, e.isMatch("birthday", "1978", "-y"));

	EXPECT_EQ(false, e.isMatch("birthday", "1977", "-m"));
	EXPECT_EQ(false, e.isMatch("birthday", "1978", "-d"));

	EXPECT_EQ(true, e.isMatch("birthday", "12", "-m"));
	EXPECT_EQ(true, e.isMatch("birthday", "11", "-d"));
}

TEST(ResultStrValidation, TestCase1) {
	VectorDatabase<Employee> vDB;
	EmployeeManagementSystem employeeMng(vDB);
	employeeMng.runCommand("ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV");
	employeeMng.runCommand("ADD, , , ,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO");
	employeeMng.runCommand("ADD, , , ,18115040,TTETHU HBO,CL3,010-4581-2050,20080718,ADV");
	employeeMng.runCommand("ADD, , , ,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO");
	employeeMng.runCommand("ADD, , , ,19129568,SRERLALH HMEF,CL2,010-3091-9521,19640910,PRO");
	employeeMng.runCommand("ADD, , , ,17111236,VSID TVO,CL1,010-3669-1077,20120718,PRO");
	employeeMng.runCommand("ADD, , , ,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO");
	employeeMng.runCommand("ADD, , , ,08123556,WN XV,CL1,010-7986-5047,20100614,PRO");
	employeeMng.runCommand("ADD, , , ,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV");
	employeeMng.runCommand("ADD, , , ,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO");
	employeeMng.runCommand("ADD, , , ,14130827,RPO JK,CL4,010-3231-1698,20090201,ADV");
	employeeMng.runCommand("ADD, , , ,01122329,DN WD,CL4,010-7174-5680,20071117,PRO");
	employeeMng.runCommand("ADD, , , ,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV");
	employeeMng.runCommand("ADD, , , ,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV");
	employeeMng.runCommand("ADD, , , ,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV");
	employeeMng.runCommand("ADD, , , ,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV");
	employeeMng.runCommand("ADD, , , ,12117017,LFIS JJIVL,CL1,010-7914-4067,20120812,PRO");
	employeeMng.runCommand("ADD, , , ,11125777,TKOQKIS HC,CL1,010-6734-2289,19991001,PRO");
	employeeMng.runCommand("ADD, , , ,11109136,QKAHCEX LTODDO,CL4,010-2627-8566,19640130,PRO");
	employeeMng.runCommand("ADD, , , ,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO");

	EXPECT_EQ("SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV", employeeMng.runCommand("SCH,-p, , ,birthday,19950704"));
	EXPECT_EQ("SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV", employeeMng.runCommand("SCH,-p,-d, ,birthday,04"));

	EXPECT_EQ("MOD,17112609,FB NTAWR,CL4,010-5645-6122,19861203,PRO", employeeMng.runCommand("MOD,-p, , ,name,FB NTAWR,birthday,20050520"));

	EXPECT_EQ("SCH,NONE", employeeMng.runCommand("SCH, , , ,employeeNum,79110836"));

	EXPECT_EQ("DEL,1", employeeMng.runCommand("DEL, , , ,employeeNum,18115040"));

	EXPECT_EQ("DEL,08117441,BMU MPOSXU,CL3,010-2703-3153,20010215,ADV", employeeMng.runCommand("DEL,-p,-l, ,name,MPOSXU"));

	string newLine = "\n";
	string expectResult = "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO" + newLine +
		"SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO" + newLine +
		"SCH,03113260,HH LTUPF,CL2,010-5798-5383,19791018,PRO" + newLine +
		"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO" + newLine +
		"SCH,08123556,WN XV,CL1,010-7986-5047,20100614,PRO";
	EXPECT_EQ(expectResult, employeeMng.runCommand("SCH,-p, , ,certi,PRO"));

	EXPECT_EQ("SCH,6", employeeMng.runCommand("SCH, , , ,certi,ADV"));

	expectResult = "SCH,88114052,NQ LVARW,CL4,010-4528-3059,19911021,PRO" + newLine +
		"SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO" + newLine +
		"SCH,02117175,SBILHUT LDEXRI,CL4,010-2814-1699,19950704,ADV" + newLine +
		"SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO" + newLine +
		"SCH,08108827,RTAH VNUP,CL4,010-9031-2726,19780417,ADV";
	EXPECT_EQ(expectResult, employeeMng.runCommand("SCH,-p, , ,cl,CL4"));

	EXPECT_EQ("SCH,1", employeeMng.runCommand("SCH, ,-m, ,birthday,09"));

	EXPECT_EQ("MOD,17112609,FB NTAWR,CL4,010-5645-6122,20050520,PRO", employeeMng.runCommand("MOD,-p, , ,name,FB NTAWR,cl,CL3"));

	EXPECT_EQ("MOD,08123556,WN XV,CL1,010-7986-5047,20100614,PRO", employeeMng.runCommand("MOD,-p, , ,employeeNum,08123556,birthday,20110706"));

	expectResult = "SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO" + newLine +
		"SCH,18117906,TWU QSOLT,CL4,010-6672-7186,20030413,PRO";
	EXPECT_EQ(expectResult, employeeMng.runCommand("SCH,-p,-y, ,birthday,2003"));

	EXPECT_EQ("SCH,05101762,VCUHLE HMU,CL4,010-3988-9289,20030819,PRO", employeeMng.runCommand("SCH,-p, , ,employeeNum,05101762"));

	EXPECT_EQ("SCH,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV", employeeMng.runCommand("SCH,-p,-m, ,phoneNum,3112"));

	EXPECT_EQ("SCH,NONE", employeeMng.runCommand("SCH,-p,-l, ,phoneNum,4605"));

	EXPECT_EQ("SCH,10127115,KBU MHU,CL3,010-3284-4054,19660814,ADV", employeeMng.runCommand("SCH,-p, , ,employeeNum,10127115"));

	EXPECT_EQ("MOD,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV", employeeMng.runCommand("MOD,-p, , ,phoneNum,010-8900-1478,certi,PRO"));

	EXPECT_EQ("SCH,NONE", employeeMng.runCommand("SCH, ,-f, ,name,LDEXRI"));

	EXPECT_EQ("MOD,1", employeeMng.runCommand("MOD, , , ,name,VCUHLE HMU,birthday,19910808"));

	EXPECT_EQ("SCH,1", employeeMng.runCommand("SCH, , , ,name,FB NTAWR"));
}

TEST(ResultStrValidation, ModifyNameTest) {
	VectorDatabase<Employee> vDB;
	EmployeeManagementSystem employeeMng(vDB);
	employeeMng.runCommand("ADD, , , ,21119688,WSICW FJASW,CL4,010-2463-9215,19870613,ADV");
	employeeMng.runCommand("MOD,-p, , ,name,WSICW FJASW,name,TJENQ VH");
	EXPECT_EQ("SCH,NONE", employeeMng.runCommand("SCH,-p,-f, ,name,WSICW"));
}

TEST(DatabaseTest, SimpleTest) {
	VectorDatabase<Employee> vDatabase;
	IDatabase<Employee>& iDatabase = vDatabase;

	vector<Employee> result = iDatabase.sch("employeeNum", "15123099", " ");
	EXPECT_EQ(0, result.size());

	iDatabase.add(Employee("15123099", "VXIHXOTH JHOP", "CL3", "010-3112-2609", "19771211", "ADV"));
	
	result = iDatabase.sch("employeeNum", "15123099", " ");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("name", "VXIHXOTH JHOP", " ");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("cl", "CL3", " ");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("phoneNum", "010-3112-2609", " ");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("birthday", "19771211", " ");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("certi", "ADV", " ");
	EXPECT_EQ(1, result.size());

	result = iDatabase.sch("name", "VXIHXOTH", "-f");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("name", "JHOP", "-l");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("phoneNum", "3112", "-m");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("phoneNum", "2609", "-l");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("birthday", "1977", "-y");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("birthday", "12", "-m");
	EXPECT_EQ(1, result.size());
	result = iDatabase.sch("birthday", "11", "-d");
	EXPECT_EQ(1, result.size());

	iDatabase.mod("employeeNum", "15123099"," ", "name", "KA NG");
	result = iDatabase.sch("name", "VXIHXOTH JHOP", " ");
	EXPECT_EQ(0, result.size());
	result = iDatabase.sch("name", "KA NG", " ");
	EXPECT_EQ(1, result.size());

	iDatabase.del("employeeNum", "15123099", " ");
	result = iDatabase.sch("employeeNum", "15123099", " ");
	EXPECT_EQ(0, result.size());
}

TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
