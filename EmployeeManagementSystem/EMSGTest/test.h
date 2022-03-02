#pragma once

#include "pch.h"
#include "MockManage.h"

class FixtureTestCalculator : public ::testing::Test {
protected:
	void SetUp() override {

	}

	void TearDown() override {
	}

public:
	testing::NiceMock<MockManage> manage_;
};