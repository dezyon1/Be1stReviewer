#include "Database.h"
#include "Employee.h"
#include <iostream>

void VectorDatabase<Employee>::add(Employee& data)
{
	database.push_back(data);
};