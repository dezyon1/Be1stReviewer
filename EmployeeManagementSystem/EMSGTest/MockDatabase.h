#pragma once

#include "pch.h"
#include <stdexcept>
#include "../EmployeeManagementSystem/Database.h"
using namespace std;

template <typename record>
class MockDatabase : public IDatabase<record> {
public:
	MOCK_METHOD(bool, add, (record&), (override));
	MOCK_METHOD(vector<record>, del, (string const&, string const&, string const&), (override));
	MOCK_METHOD(vector<record>, sch, (string const&, string const&, string const&), (override));
	MOCK_METHOD(vector<record>, mod, (string const&, string const&, string const&, string const&, string const&), (override));
};