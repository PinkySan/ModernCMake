#include <iostream>
using std::cout;
using std::endl;

#include "basicLib.h"

int main()
{
	cout << "Main" << endl;
	sayHelloBasic();
	sayHelloBasicPublic();
	std::cin.get();
	return 0;
}