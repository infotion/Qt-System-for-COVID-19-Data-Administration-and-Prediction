#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
	string s;
	s+='0';
	s+=".csv";
	ifstream fin(s);
	string a;
	fin>>a;
	cout<<a;
	fin>>a;
	cout<<a;
	return 0;
}
