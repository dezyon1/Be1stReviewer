#pragma once

#include "pch.h"
#include "MockDatabase.h"

class FixtureTestCalculator : public ::testing::Test {
protected:
	void SetUp() override {

	}

	void TearDown() override {
	}

public:
	testing::NiceMock<MockDatabase<Employee>> mockDatabase;
};