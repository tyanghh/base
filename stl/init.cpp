#include <iostream>
#include <string>
#include <map>
#include <stdio.h>
#include "time_cost.h"

using namespace std;
using namespace bruce::util;

class CBaseCon {
public:
	CBaseCon():m_i(0),m_baseStr("m_baseStr"){}
#if 0	
	CBaseCon(const CBaseCon &oIn)
	{
		if (&oIn == this)
		{
			return ;
		}
		m_i = oIn.m_i;
		LOG_DBG("CBaseCon call over");
	}
#endif

public:
	int m_i;
	string m_baseStr;
	char * m_point;
};

class CConCombination {
public:
	int m_c;
	string m_str;
	CBaseCon m_oBaseCon;
};

int main(int argc, char **argv)
{
	CConCombination oCombination;

	oCombination.m_c = 1;
	oCombination.m_oBaseCon.m_i = 2;
	oCombination.m_oBaseCon.m_baseStr = "m_baseInit";
	oCombination.m_str = "string";
	oCombination.m_oBaseCon.m_point = new char[100];
	
	CConCombination oCombinationInit(oCombination);

	LOG_DBG("oCombination:%d,%d,%s,%s,%p",
			oCombination.m_c,oCombination.m_oBaseCon.m_i,
			oCombination.m_oBaseCon.m_baseStr.c_str(),oCombination.m_str.c_str(),
			oCombination.m_oBaseCon.m_point);
	LOG_DBG("oCombinationInit:%d,%d,%s,%s,%p",
			oCombinationInit.m_c,oCombinationInit.m_oBaseCon.m_i,
			oCombinationInit.m_oBaseCon.m_baseStr.c_str(),oCombinationInit.m_str.c_str(),
			oCombinationInit.m_oBaseCon.m_point);
	
}
