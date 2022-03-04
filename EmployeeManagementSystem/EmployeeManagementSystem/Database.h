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
	virtual vector<record> del(string const& column, string const& keyword) = 0;
	virtual vector<record> sch(string const& column, string const& keyword) = 0;
	virtual vector<record> mod(string const& column, string const& keyword,
		string const& tarColumn, string const& tarKeyword) = 0;
};

template <typename record>
class VectorDatabase : public IDatabase<record> {
public:
	virtual void add(record& data) override {};
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
		vector<record> schResult;
		for (auto& it : database) {
			if (it.isMatch(column, keyword)) {
				schResult.push_back(it);
				it.setData(tarColumn, tarKeyword);
			}
		}
		return schResult;
	};

private:
	vector<record> database;
};