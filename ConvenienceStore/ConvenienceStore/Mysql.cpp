#include "Mysql.h"

#define HOST "localhost"
#define USER "rk221"
#define PW "1192"

using namespace::mysqlx;

Mysql::Mysql() {
	try {



		/* 例
		Row row = myResult.fetchOne();
		std::cout << row.get(0);

		auto myResult = sess.sql("SELECT name FROM product WHERE price >= 150").execute();
		for (auto r : myResult) {
			std::cout << r.get(0);
		}
		*/



	}
	catch (const mysqlx::Error& err) {
		std::cout << err << std::endl;
	}

}

/*
void Mysql::sql(std::vector<System::String>& data) {
	Session sess("localhost", "name", "pass");
	sess.sql("USE store").execute();
	auto myResult = sess.sql("SELECT name FROM product WHERE >= 150").execute();
	for (auto r : myResult) {
		data.push_back(encodeString((std::string)r.get(0)));
	}
}

*/
void Mysql::getSqlString(std::vector<std::string>& data, std::string sqlCommand) {
	Session sess(HOST, USER, PW);
	sess.sql("USE store").execute();
	auto myResult = sess.sql(sqlCommand).execute();
	for (auto r : myResult) {
		data.push_back((std::string)r.get(0));
	}
	sess.close();
}

void Mysql::getSqlIntger(std::vector<int>& data, std::string sqlCommand) {
	Session sess(HOST, USER, PW);
	sess.sql("USE store").execute();
	auto myResult = sess.sql(sqlCommand).execute();
	for (auto r : myResult) {
		data.push_back((int)r.get(0));
	}
	sess.close();
}

System::String^ Mysql::encodeString(std::string str) {
	std::string cpp_string = str;

	// 型の変換
	array<unsigned char>^ c_array = gcnew array<unsigned char>(cpp_string.length());
	for (int i = 0; i < cpp_string.length(); i++)
	{
		c_array[i] = cpp_string[i];
	}

	// .NETのライブラリでバイト配列(
	System::Text::Encoding^ u8enc = System::Text::Encoding::UTF8;
	System::String^ u8_array = u8enc->GetString(c_array);
	return u8_array;
}

/*

	std::list<Schema> schemaList = sess.getSchemas();
	std::cout << "Available schemas in this session:" << std::endl;
	for (Schema schema : schemaList) {
		std::cout << schema.getName() << std::endl;
	}
	*/