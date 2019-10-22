#include "MyForm.h"
#include "Mysql.h"
#include <iostream>
#include <Windows.h>

using namespace ConvenienceStore;



[STAThreadAttribute]
int main() {
	SetConsoleOutputCP(CP_UTF8);//コンソールのUTF8表示

	Mysql* sql = new Mysql();

	//フォームの作成
	MyForm^ fm = gcnew MyForm();
	fm->ShowDialog();
	return 0;
	
}