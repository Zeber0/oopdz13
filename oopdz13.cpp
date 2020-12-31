﻿// oopdz13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DB.h"
int main()
{
	{
		srand(time(NULL));
		DB db1, db2, db3;
		DBMAP db4;
		for (int i = 0; i < 1 + rand() % 20; i++) {
			db1.add(new Base(1+rand() % 100));
			db1.add(new Derived(1+rand() % 100));
		}
		db1.print();
		std::cout << std::endl;
		bool sw = 0;
		db2.copy(db1, sw);
		db2.print();
		sw++;
		std::cout << std::endl;
		db3.copy(db1, sw);
		db3.print();
		db4.copydb(db3);
	}
	_CrtDumpMemoryLeaks();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
