#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int main()
{
	unordered_map<string ,string> um_test;

	char str[16];
	int i = 0;
	for (; i < 100000; i ++)
	{
		sprintf(str, "%d", i);
		um_test[str] = string(str) + "test";
	}
	int j = 100000;
	for (; j > 0; j --)
	{
		sprintf(str, "%d", j);
		if (um_test.find(str) != um_test.end())
			continue;
	}
	return 0;
}
