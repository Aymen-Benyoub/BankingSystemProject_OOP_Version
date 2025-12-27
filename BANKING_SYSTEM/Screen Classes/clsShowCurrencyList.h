#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsCurrency.h"
using namespace std;


class clsShowCurrencyList : protected clsScreen
{
private:
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(15) << right << fixed << setprecision(2) << Currency.Rate();
	}

public:

	static void ShowCurrencyList()
	{
		vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

		string Subtitle = "        There Are (" + to_string(vCurrency.size()) + ") Currencies";
		clsScreen::_DrawHeader("     Currencies List", Subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(15) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << right << setw(15) << "Rate( Per 1$ )";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

			for (clsCurrency Currency : vCurrency)
			{
				PrintCurrencyRecordLine(Currency);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}
};



