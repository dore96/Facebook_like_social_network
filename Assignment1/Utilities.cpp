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

void makeDoubleSpace(void** arr, int sizeOfElement, int& size)//need to check if works
{
	int oldSize = size;
	size *= 2;
	unsigned char* tmpArr = new unsigned char[size * sizeOfElement];
	for(int i = 0;i < oldSize;i++)
	{
		tmpArr[i * sizeOfElement] = (unsigned char)*arr + (i * sizeOfElement);
	}
	delete []arr;
	*arr = tmpArr;
}
