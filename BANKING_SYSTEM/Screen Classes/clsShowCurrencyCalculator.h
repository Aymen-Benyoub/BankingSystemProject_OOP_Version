#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsCurrency.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;


class clsShowCurrencyCalculator : protected clsScreen
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
	static void CurrencyCalculator()
	{
		int Trials = 2;
		cout << "\nEnter The Currency Code Of The Desired Currency To Transform From : ";
		string CurrencyCodeFrom = clsInputValidation::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCodeFrom) && Trials != 0)
		{
			cout << " You Have " << Trials << " Trial(s) Left" << endl;
			cout << " This Currency Code Doesn't Belong To Any Currency , Retry  : ";
			CurrencyCodeFrom = clsInputValidation::ReadString();
			Trials--;
		}

		clsCurrency CurrencyFrom = clsCurrency::FindByCode(CurrencyCodeFrom);

		if (!CurrencyFrom.IsEmpty())
		{
			PrintCurrencyRecordLine(CurrencyFrom);

			Trials = 2;
			cout << "\n\nEnter The Currency Code Of The Desired Currency To Transform To : ";
			string CurrencyCodeTo = clsInputValidation::ReadString();

			while (!clsCurrency::IsCurrencyExist(CurrencyCodeTo) && Trials != 0)
			{
				cout << " You Have " << Trials << " Trial(s) Left" << endl;
				cout << " This Currency Code Doesn't Belong To Any Currency , Retry  : ";
				CurrencyCodeTo = clsInputValidation::ReadString();
				Trials--;
			}

			clsCurrency CurrencyTo = clsCurrency::FindByCode(CurrencyCodeTo);

			if (!CurrencyTo.IsEmpty())
			{
				PrintCurrencyRecordLine(CurrencyTo);

				if (CurrencyCodeFrom == CurrencyCodeTo)
				{
					cout << "Enter The Amount That You Want To Transform From " << CurrencyFrom.CurrencyName() << " To " << CurrencyTo.CurrencyName() << "  : ";
					float Amount = clsInputValidation::ReadFloatNumber();

					cout << Amount << " " << CurrencyFrom.CurrencyName() << " Is Equal To " << Amount << " " << CurrencyTo.CurrencyName() << endl;
				}
				else
				{
					cout << "Enter The Amount That You Want To Transform From " << CurrencyFrom.CurrencyName() << " To " << CurrencyTo.CurrencyName() << "  : ";
					float Amount = clsInputValidation::ReadFloatNumber();

					float AmountFrom = Amount;

					Amount = Amount / CurrencyFrom.Rate();

					Amount = Amount * CurrencyTo.Rate();

					string Str = to_string(AmountFrom) + " " + CurrencyFrom.CurrencyName() + " Is Equal To " + to_string(Amount) + " " + CurrencyTo.CurrencyName();
					cout << setw(14) << left << " " << "============================================================================================\n";
					cout << setw(14) << left << " " << "|" << setw(89) << left << Str << " | \n";
					cout << setw(14) << left << " " << "============================================================================================\n";

				}
			}
			else
			{
				cout << setw(38) << left << " " << "=============================================\n";
				cout << setw(38) << left << " " << "|       Operation Failed To Take Place      |\n";
				cout << setw(38) << left << " " << "=============================================\n";
			}

			
		}
		else
		{
			cout << setw(38) << left << " " << "=============================================\n";
			cout << setw(38) << left << " " << "|       Operation Failed To Take Place      |\n";
			cout << setw(38) << left << " " << "=============================================\n";
		}
		
	}

};

