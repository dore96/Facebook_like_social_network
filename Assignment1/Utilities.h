#ifndef __UTILITIES_H
#define __UTILITIES_H
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG
#include <iostream>
using namespace std;
#pragma warning (disable: 4996)
#pragma warning (disable: 4267)

void CleanBuffer();
#endif