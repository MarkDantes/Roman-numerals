#include <iostream>
#include <utility>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int roman_traslator(string str)
{
	
	string s;
	transform(str.begin(), str.end(), back_inserter(s), toupper);

	map<char, int> rom; 
	rom['I'] = 1;
	rom['V'] = 5;
	rom['X'] = 10;
	rom['L'] = 50;
	rom['C'] = 100;
	rom['D'] = 500;
	rom['M'] = 1000;

	int sum=0, i = 0;
	
	while (true)
	{

		if (rom[s[i]] >= rom[s[i + 1]])
		{
			sum += rom[s[i]];
		}
		else
			if (rom[s[i]] < rom[s[i + 1]])
			{
				sum += rom[s[i + 1]] - rom[s[i]];
				i++;
			}
			
		i++;
		if (i >= s.length())
			break;
	}
	return sum;
}

int main()
{
	setlocale(0, "");

	//MMIX = 2009, XLIII = 43, XC = 90, CD = 400, CMXCVII = 997

	const string p[] = { "I","V", "X", "L", "C", "D", "M",  "MMIX", "XLIII", "XC", "CD", "CMXCVII" };

	for (auto x : p)
		cout << "Roman number " + x + " = " << roman_traslator(x) << endl;
	std::system("pause");
	return 0;

}