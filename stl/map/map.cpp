#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include "time_cost.h"

using namespace std;
using namespace com::bruce::util;

int main()
{
	map<string ,string> map_test;

	TIME_COST_START(map_insert); 
	char str[16];
	int i = 0;
	for (; i < 100000; i ++)
	{
		sprintf(str, "%d", i);
		map_test[str] = string(str) + "test";
	}
	TIME_COST_STOP(map_insert); 


	TIME_COST_START(map_find); 
	int j = 100000;
	for (; j > 0; j --)
	{
		sprintf(str, "%d", j);
		if (map_test.find(str) != map_test.end())
			continue;
	}
	TIME_COST_STOP(map_find); 
	return 0;
}
