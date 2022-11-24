#include "Utilities.h"
#include <iostream>
using namespace std;

void CleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}