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
	virtual vector<record> del(string const& column, string const& keyword, string const& option) = 0;
	virtual vector<record> sch(string const& column, string const& keyword, string const& option) = 0;
	virtual vector<record> mod(string const& column, string const& keyword, string const& option,
		string const& tarColumn, string const& tarKeyword) = 0;
};

template <typename record>
class VectorDatabase : public IDatabase<record> {
public:
	virtual void add(record& data) override {
		database.push_back(data);
	};

	virtual vector<record> del(string const& column, string const& keyword, string const& option) override {
		vector<record> temp;
		for (int i = 0; i < database.size(); ) {
			auto &r = database[i];

			if (!r.isMatch(column, keyword, option)) {
				i++;
				continue;
			}
			temp.push_back(r);
			database.erase(database.begin() + i);
		}
		return temp;
	};
	
	virtual vector<record> sch(string const& column, string const& keyword, string const& option) override {
		vector<record> temp;
		for (auto & r : database) {
			if (r.isMatch(column, keyword, option)) {
				temp.push_back(r);
			}
		}
		return temp;
	};
	
	virtual vector<record> mod(string const& column, string const& keyword, string const& option,
		string const& tarColumn, string const& tarKeyword) override {
		vector<record> temp = sch(column, keyword, option);
		
		for (auto & r:database) {
			if (keyword == r.getValue(column)) {
				r.setValue(tarColumn, tarKeyword);
			}
		}	
		return temp;
	};

private:
	vector<record> database;
};
