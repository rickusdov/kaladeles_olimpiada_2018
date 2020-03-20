// olimpiada2018_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

using namespace std;

const int riba = 10000;

void skaitymas(int& n, char simbolis[]);
void rusiavimas(int n, char simbolis[], bool& salyga);
void isvedimas(int n, char simbolis[], bool salyga);

int main()
{
	char simbolis[riba];
	int n;
	bool salyga;
		skaitymas(n, simbolis);
		rusiavimas(n, simbolis, salyga);
		isvedimas(n, simbolis, salyga);

	return 0;
}
void skaitymas(int& n, char simbolis[])
{
	ifstream fd("duom.txt");
	fd >> n;
	for (int i = 1; i <= n; i++)
	{
		fd >> simbolis[i];

	}

}
void rusiavimas(int n, char simbolis[], bool& salyga)
{
	int k = 0;
	int m;
	char laikinas[riba];
	bool rikiuote = true;
	m = n / 2;
	for (int i = 1; i <= n; i++)
	{
		laikinas[i] = simbolis[i];
	}
	while (rikiuote)
	{
		rikiuote = false;
		for (int i = 1; i <= n-1; i++)
		{
			if (laikinas[i] > laikinas[i + 1])
			{
				swap(laikinas[i], laikinas[i + 1]);
				rikiuote = true;
			}
		}
	}
	rikiuote = true;
	for (int i = 1; i <= n; i++)
	{
		k = 0;
		for (int j = 1; j <= n; j++)
		{
			if (laikinas[i] == laikinas[j])
			{
				++k;
			}
		}
		if (k > m)
		{
			salyga = false;
			break;
		}
	}
	//cout << salyga << endl;
	if (salyga != false)
	{
		while (rikiuote)
		{
			rikiuote = false;
			for (int i = 1; i <= n - 1; i++)
			{
				if (simbolis[i] == simbolis[i + 1])
				{
					swap(simbolis[i - 1], simbolis[i]);
					rikiuote = true;
				}
			}
		}
	}

	
}
void isvedimas(int n, char simbolis[], bool salyga)
{
	ofstream out("rez.txt");
	if (salyga != false)
	{
		for (int i = 1; i <= n; i++)
		{
			out << simbolis[i] << " ";
		}
	}
	else
		out << "NE" << endl;
}


