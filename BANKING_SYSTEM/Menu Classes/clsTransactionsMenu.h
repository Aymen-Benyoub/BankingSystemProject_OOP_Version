#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"
#include"../Screen Classes/clsDepositScreen.h"
#include"../Screen Classes/clsWithdrawScreen.h"
#include"../Screen Classes/clsShowClientsBalanceMood.h"
#include"../Screen Classes/clsTransferScreen.h"
#include"../Screen Classes/clsRegisterTransfer.h"

using namespace std;

class clsTransactionsMenu : protected clsScreen
{
private:

	enum enTransMenuChoice {
		enDeposit = 1, enWithdraw = 2, enClientListBalanceMood = 3, enTransfer = 4, enShowTransferList = 5,
		enReurnMainMenu = 6
	};

	static void _GoBackToTransactionsMenue()
	{
		cout << setw(37) << left << "" << "Press any key to go back to Transactions Menu...\n";
		system("pause>0");
		system("cls");
		_Algerian_Bank_Banner();
		ShowTransactionsMenue();
	}
	static enTransMenuChoice _ReadChoiceTrans()
	{
		cout << setw(37) << left << "" << "   Enter Your Choice From 1 To 6 : ";
		int Choice = clsInputValidation::ReadIntNumberBetween(1, 6);
		cout << endl;
		return static_cast<enTransMenuChoice>(Choice);
	}
	static void _PerformDeposit()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsDepositScreen::Deposit();

	}
	static void _PerformWithdraw()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsWithdrawScreen::Withdraw();
	}
	static void _PerformShowClentsListBalanceMood()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsShowClientsBalanceMood::ShowClientsListBalanceMood();
	}
	static void _PerformTransfer()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsTransferScreen::Transfer();
	}
	static void _PerformShowTransferList()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsRegisterTransfer::ShowTransfersList();
	}
	static void _PerfromTransMenueOption(enTransMenuChoice MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enDeposit:
			system("cls");
			_PerformDeposit();
			_GoBackToTransactionsMenue();
			break;
		case enWithdraw:
		{
			system("cls");
			_PerformWithdraw();
			_GoBackToTransactionsMenue();
			break;
		}
		case enClientListBalanceMood:
			system("cls");
			_PerformShowClentsListBalanceMood();
			_GoBackToTransactionsMenue();
			break;
		case enTransfer:
			system("cls");
			_PerformTransfer();
			_GoBackToTransactionsMenue();
			break;
		case enShowTransferList:
			system("cls");
			_PerformShowTransferList();
			_GoBackToTransactionsMenue();
		case enReurnMainMenu:
			break;
		}
	}

public:
	static void ShowTransactionsMenue()
	{
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |          TRANSACTIONS SCREEN         |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |  1. Deposit                          |\n";
		cout << setw(37) << left << " " << "  |  2. Withdraw                         |\n";
		cout << setw(37) << left << " " << "  |  3. Show Clients List (Balance Mood) |\n";
		cout << setw(37) << left << " " << "  |  4. Transfer                         |\n";
		cout << setw(37) << left << " " << "  |  5. Show Transfer List               |\n";
		cout << setw(37) << left << " " << "  |  6. Return To Main Menu              |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		enTransMenuChoice Choice = _ReadChoiceTrans();
		_PerfromTransMenueOption(Choice);
	}

};





