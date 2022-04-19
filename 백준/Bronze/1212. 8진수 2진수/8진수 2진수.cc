#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>


using namespace std;

string oc;
string bi="";

string f1= "1";
string f2 = "10";
string f3= "11";
string c0 = "000";
string c1 = "001";
string c2= "010";
string c3 = "011";
string c4 = "100";
string c5 = "101";
string c6 = "110";
string c7 = "111";

int main(void)
{
	cin >> oc;
	if (oc[0] == '0')
	{
		cout << 0 << '\n';
		return 0;
	}
	int len = oc.size();
	for (int i = 0; i < len; i++)
	{
		switch (oc[i])
		{
		case '0':
			bi += c0;
			break;

		case '1':
			if (i == 0)
				bi += f1;
			else
				bi += c1;
			break;

		case '2':
			if (i == 0)
				bi += f2;
			else
				bi += c2;
			break;

		case '3':
			if (i == 0)
				bi += f3;
			else
				bi += c3;
			break;

		case '4':
			bi += c4;
			break;

		case '5':
			bi += c5;
			break;

		case '6':
			bi += c6;
			break;
		default:
			bi += c7;
		}
	}
	cout << bi << '\n';
	return 0;
}