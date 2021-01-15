#include <iostream>
#include <clocale>
#include "DB.h"
#include "Derived.h"
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
