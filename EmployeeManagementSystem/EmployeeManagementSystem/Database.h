#pragma once

#include <vector>
#include <map>
#include <string>
#include "Common.h"
#include <iostream>

using namespace std;

template <typename record>
class IDatabase {
public:
	virtual void add(record& data) = 0;
	virtual vector<record> del(string const& column, string const& keyword) = 0;
	virtual vector<record> sch(string const& column, string const& keyword) = 0;
	virtual vector<record> mod(string const& column, string const& keyword,
		string const& tarColumn, string const& tarKeyword) = 0;
	virtual int getSize() = 0;
};

template <typename record>
class VectorDatabase : public IDatabase<record> {
public:
	virtual int getSize() override {
		return database.size();
	};

	virtual void add(record& data) override	{
		database.push_back(data);
	};
	virtual vector<record> del(string const& column, string const& keyword) override {
		vector<record> temp;
		return temp;
	};
	virtual vector<record> sch(string const& column, string const& keyword) override {
		vector<record> temp;
		return temp;
	};
	virtual vector<record> mod(string const& column, string const& keyword,
		string const& tarColumn, string const& tarKeyword) override {
		vector<record> temp;
		return temp;
	};

private:
	vector<record> database;
};