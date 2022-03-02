#pragma once
#include "Employee.h"
using namespace std;

class IEmployeeManagementSystem
{
public:
	virtual ~IEmployeeManagementSystem() {};
	virtual string testMock() = 0;
};