#include<pch.h>
#include <iostream>
#include <string>
using namespace std;

struct computer
{
	string mnfact;
	int volum;
	int date[3];
	int price;

	void output(int p)
	{
		if (p == -1)
			cout << " IS not found ";
		else
		{
			cout << "Manufacturer:\t" << mnfact << endl;
			cout << "Volum:\t" << volum << endl;
			cout << "Date:\t" << date[0] << "." << date[1] << "." << date[2] << endl;
			cout << "Price:\t" << price << endl;
		}
	}
};

void input(computer*RAM, int m)
{
	for (size_t i = 0; i < m; i++)
	{
		cout << "Enter manufacturer ";
		cin >> RAM[i].mnfact;

		do {
			cout << "Enter volume of memory (4GB, 8GB, 16GB or 32GB) ";
			cin >> RAM[i].volum;
		} while (!(RAM[i].volum == 4 || RAM[i].volum == 8 || RAM[i].volum == 16 || RAM[i].volum == 32));

		do {
			cout << "Enter day of creating ";
			cin >> RAM[i].date[0];
		} while (!(RAM[i].date[0] > 0 && RAM[i].date[0] <= 31));

		do {
			cout << "Enter month of creating ";
			cin >> RAM[i].date[1];
		} while (!(RAM[i].date[1] > 0 && RAM[i].date[1] <= 12));

		do {
			cout << "Enter year of creating ";
			cin >> RAM[i].date[2];
		} while (!(RAM[i].date[2] > 1991 && RAM[i].date[2] <= 2019));

		do {
			cout << "Enter price ";
			cin >> RAM[i].price;
		} while (!(RAM[i].price > 0));
		system("cls");
	}
};

int main()
{
	int kol = 0, index = -1, max = 0;
	string AMD = "AMD";
	for (;;)
	{
		cout << "Enter number of products  ";
		cin >> kol;
		if (kol >= 1)
		{
			break;
		}
		else
		{
			cout << "THE END";
			break;
		}
	}

	system("cls");

	computer *RAM = new computer[kol];
	input(RAM, kol);

	for (size_t i = 0; i < kol; i++)
	{
		if (RAM[i].price > max)
		{
			max = RAM[i].price;
		}
	}

	for (size_t i = 0; i < kol; i++)
	{
		if (RAM[i].mnfact._Equal(AMD) && RAM[i].price < max)
		{
			max = RAM[i].price;
			index = i;
		}
	}
	RAM[index].output(index);
}
