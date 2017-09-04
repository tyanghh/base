#include <iostream>
#include <string>
#include <ext/hash_map>
#include <stdio.h>

using namespace std;
using namespace __gnu_cxx;

struct hash_string 
{
	size_t operator()(const string& str) const
	{
		return __stl_hash_string(str.c_str());
	}
};

int main()
{
	hash_map<string, string, hash_string> hm_test;

	char str[16];
	int i = 0;
	for (; i < 100000; i ++)
	{
		sprintf(str, "%d", i);
		hm_test[str] = string(str) + "test";
	}
	int j = 100000;
	for (; j > 0; j --)
	{
		sprintf(str, "%d", j);
		if (hm_test.find(str) != hm_test.end())
			continue;
	}
	return 0;
}
