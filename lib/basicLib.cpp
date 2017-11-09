#include "basicLib.h"
#include "libPrivate.h"

#include <iostream>
using std::cout;
using std::endl;


void sayHelloBasic()
{
	cout << "Basic" << endl;
	sayHelloPrivate();
}
