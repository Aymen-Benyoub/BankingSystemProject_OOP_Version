#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsCurrency.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;

class clsUpdateCurrencyRate : protected clsScreen
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

	static void UpdateCurrencyRate()
	{
		_DrawHeader("  UPDATE CURENCY RATE SCREEN");

		int Trials = 2;

		string CurrencyCode;
		cout << "\nPlease Enter The Currency Code Of The Desired Currency To Update It : ";
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
			system("cls");
			cout << "\Currency Found  :-)\n";
			PrintCurrencyRecordLine(CurrencyEx);

			char Answer;

			do
			{
				cout << endl;
				cout << setw(38) << left << " " << "Do You Confirm Updating This Currency  Y/N \n";
				Answer = clsInputValidation::ReadChar();
				cout << endl;

			} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');

			if (tolower(Answer) == 'n')
			{
				cout << setw(38) << left << " " << "=============================================\n";
				cout << setw(38) << left << " " << "|       Operation Failed To Take Place      |\n";
				cout << setw(38) << left << " " << "=============================================\n";
			}
			else
			{
				cout << " Enter The New Rate Of This Currency ( Per 1$ ) : ";
				float RateNew = clsInputValidation::ReadFloatNumber();

				CurrencyEx.UpdateRate(RateNew);

				cout << setw(38) << left << " " << "=============================================\n";
				cout << setw(38) << left << " " << "|         Operation Done Successfully       |\n";
				cout << setw(38) << left << " " << "=============================================\n";

			}


		}
		else
		{
			cout << "\Currency Was not Found  :-(\n";
		}
	}
};

