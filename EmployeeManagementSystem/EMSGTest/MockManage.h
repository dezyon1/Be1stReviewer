#pragma once

#include "pch.h"
#include <stdexcept>
#include "../EmployeeManagementSystem/employee.h"
#include "../EmployeeManagementSystem/EmployeeManagementSystem.h"
using namespace std;

class MockManage : public IEmployeeManagementSystem {
public:
	MOCK_METHOD(string, testMock, (), (override));
};