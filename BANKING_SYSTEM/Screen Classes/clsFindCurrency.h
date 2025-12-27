#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsCurrency.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;


class clsFindCurrency : protected clsScreen
{
private:
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(30) << left << "Country";
		cout << "| " << left << setw(15) << "Currency Code";
		cout << "| " << left << setw(40) << "Currency Name";
		cout << "| " << right << setw(15) << "Rate( Per 1$ )";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(15) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(15) << right << fixed << setprecision(2) << Currency.Rate();
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}

public:

	static void FindCurrency()
	{
		_DrawHeader("  FIND CURRENCY SCREEN");

		cout << " What Is The Finding Type  [1] : By Country / [2] : By Currency Code  : ";
		int Ans = clsInputValidation::ReadIntNumberBetween(1, 2);

		if (Ans == 1)
		{
			int Trials = 2;

			string Country;
			cout << "\nPlease Enter The Country To See Its Currency : ";
			Country = clsInputValidation::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			while (Currency.IsEmpty() && Trials != 0)
			{

				cout << " You Have " << Trials << " Trial(s) Left" << endl;
				cout << "\nCurrency Is Not Found, Choose Another Country : ";
				Country = clsInputValidation::ReadString();
				Trials--;

				Currency = clsCurrency::FindByCountry(Country);
			}

			clsCurrency CurrencyEx = clsCurrency::FindByCountry(Country);

			if (!CurrencyEx.IsEmpty())
			{
				cout << "\Currency Found  :-)\n";
				PrintCurrencyRecordLine(CurrencyEx);
			}
			else
			{
				cout << "\Currency Was not Found  :-(\n";
			}
		}
		else
		{
			int Trials = 2;

			string CurrencyCode;
			cout << "\nPlease Enter The Currency Code To See It : ";
			CurrencyCode = clsInputValidation::ReadString();

			while (!clsCurrency::IsCurrencyExist(CurrencyCode) && Trials != 0)
			{

				cout << " You Have " << Trials << " Trial(s) Left" << endl;
				cout << "\nCurrency Code Is Not Found, Choose Another One : ";
				CurrencyCode = clsInputValidation::ReadString();
				Trials--;

			}

			clsCurrency CurrencyEx = clsCurrency::FindByCode(CurrencyCode);

			if (!CurrencyEx.IsEmpty())
			{
				cout << "\Currency Found  :-)\n";
				PrintCurrencyRecordLine(CurrencyEx);
			}
			else
			{
				cout << "\Currency Was not Found  :-(\n";
			}
		}
	}
};

