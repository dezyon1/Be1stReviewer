#pragma once

#include <vector>
#include <map>
#include <string>
#include "Common.h"

using namespace std;

template <typename record>
class IDatabase {
public:
	virtual void add(record& data) = 0;
	virtual string del(string const& column, string const& keyword) = 0;
	virtual string sch(string const& column, string const& keyword) = 0;
	virtual string mod(string const& column, string const& keyword,
		string const& tarColumn, string const& tarKeyword) = 0;
};

template <typename record>
class Database : public IDatabase<record> {
public:
	virtual void add(record& data) override {};
	virtual string del(string const& column, string const& keyword) override { return ""; };
	virtual string sch(string const& column, string const& keyword) override { return ""; };
	virtual string mod(string const& column, string const& keyword,
		string const& tarColumn, string const& tarKeyword) override {
		return "";
	};

private:
	vector<record> database;
};