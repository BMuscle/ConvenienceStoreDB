#pragma once
#include "mysqlx/xdevapi.h"
#include <iostream>
#include <stdio.h>

class Mysql {
public:
	Mysql();
	~Mysql();
	/*
	void sql(std::vector<System::String>& data);
	*/
	void getSqlString(std::vector<std::string>& data, std::string sqlCommand);
	void getSqlIntger(std::vector<int>& data, std::string sqlCommand);
	System::String^ encodeString(std::string str);
	
};