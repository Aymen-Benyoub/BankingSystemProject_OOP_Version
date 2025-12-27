#pragma once 
#include<iomanip> 
#include<iostream>
#include"../Libraries/clsInputValidation.h"
#include"../Screen Classes/clsShowCurrencyList.h"
#include"../Screen Classes/clsFindCurrency.h"
#include"../Screen Classes/clsUpdateCurrencyRate.h"
#include"../Screen Classes/clsShowCurrencyCalculator.h"

using namespace std;

class clsCurrencyExchangeMenu : protected clsScreen
{
private:

	enum enCurrencyMenuChoice {
		enListCurrency = 1, enFindCurrency = 2, enUpdateRate = 3,
		enCurrencyCalculator = 4, enReturnToMainMenu = 5
	};

	static void _GoBackToCurrencyMenu()
	{
		cout << setw(35) << left << " " << "=======================================================\n";
		cout << setw(35) << left << " " << "| Press any key to go back to Currency Exchange Menu.. |\n";
		cout << setw(35) << left << " " << "=======================================================\n";
		system("pause>0");
		system("cls");
		_Algerian_Bank_Banner();
		ShowCurrencyMenu();
	}



	static enCurrencyMenuChoice _ReadCurrencyChoice()
	{
		cout << setw(37) << left << "" << "   Enter Your Choice From 1 To 5  : ";
		int Choice = clsInputValidation::ReadIntNumberBetween(1, 5);
		cout << endl;
		return static_cast<enCurrencyMenuChoice>(Choice);
	}

	static void _PerformListCurrency()
	{
		_Algerian_Bank_Banner();
		clsShowCurrencyList::ShowCurrencyList();
	}
	static void _PerformFindCurrency()
	{
		_Algerian_Bank_Banner();
		clsFindCurrency::FindCurrency();
	}
	static void _PerformUpdateRate()
	{
		_Algerian_Bank_Banner();
		clsUpdateCurrencyRate::UpdateCurrencyRate();
	}
	static void _PerformCurrencyCalculator()
	{
		_Algerian_Bank_Banner();
		clsShowCurrencyCalculator::CurrencyCalculator();
	}

	static void _PerfromCurrencyMenuChoice(enCurrencyMenuChoice MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case clsCurrencyExchangeMenu::enListCurrency:
			system("cls");
			_PerformListCurrency();
			_GoBackToCurrencyMenu();
			break;
		case clsCurrencyExchangeMenu::enFindCurrency:
			system("cls");
			_PerformFindCurrency();
			_GoBackToCurrencyMenu();
			break;
		case clsCurrencyExchangeMenu::enUpdateRate:
			system("cls");
			_PerformUpdateRate();
			_GoBackToCurrencyMenu();
			break;
		case clsCurrencyExchangeMenu::enCurrencyCalculator:
			system("cls");
			_PerformCurrencyCalculator();
			_GoBackToCurrencyMenu();
			break;
		case clsCurrencyExchangeMenu::enReturnToMainMenu:
			break;
		}
	}

public:
	static void ShowCurrencyMenu()
	{
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |        CURRENCY EXCHANGE SCREEN      |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |  1. Show All Currencies Data         |\n";
		cout << setw(37) << left << " " << "  |  2. Find Currency                    |\n";
		cout << setw(37) << left << " " << "  |  3. Update Rate                      |\n";
		cout << setw(37) << left << " " << "  |  4. Currency Calculator              |\n";
		cout << setw(37) << left << " " << "  |  5. Return To Main Menu              |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		enCurrencyMenuChoice Choice = _ReadCurrencyChoice();
		_PerfromCurrencyMenuChoice(Choice);
	}
	

};



