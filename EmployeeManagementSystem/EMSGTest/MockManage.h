#pragma once

#include "pch.h"
#include <stdexcept>
#include "../EmployeeManagementSystem/Employee.h"
#include "../EmployeeManagementSystem/EmployeeManagementSystem.h"
using namespace std;

class MockManage : public IEmployeeManagementSystem {
public:
	MOCK_METHOD(void, testMock, (), (override));
};