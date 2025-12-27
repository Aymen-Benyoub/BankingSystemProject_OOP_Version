#pragma once 
#include<iomanip> 
#include<iostream>
#include"../Libraries/clsInputValidation.h"
#include"../Screen Classes/clsScreen.h" 
#include"../Screen Classes/clsShowAllClientsScreen.h"
#include"../Screen Classes/clsAddNewClientScreen.h"
#include"../Screen Classes/clsDeleteClientScreen.h"
#include"../Screen Classes/clsUpdateClientScreen.h"
#include"../Screen Classes/clsFindClientScreen.h"
#include"../Menu Classes/clsTransactionsMenu.h"
#include"../Menu Classes/clsManageUsersMenu.h"
#include"../Core Classes/clsGlobal.h"
#include"../Screen Classes/clsRegisterLogins.h"
#include"../Menu Classes/clsCurrencyExchangeMenu.h"


using namespace std;

class clsMainMenu : protected clsScreen
{
private:

	static bool _Check_Access(clsBankUser::enPermissions Permission, clsBankUser User = CurrentUser)
	{
		if ((User.Permissions & Permission) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	enum enMainMenuChoice {
		enListClients = 1, enAddClient = 2, enDeleteClient = 3,
		enUpdateClient = 4, enFindClient = 5, enTransactions = 6, enManageUsers = 7, enLogout = 9, enShowLoginRegister = 8,
		enCurrencyExchange = 10,enExit = 11
	};
	static void _GoBackToMainMenu()
	{
		cout << setw(37) << left << " " << "  ===========================================\n";
		cout << setw(37) << left << " " << "  | Press any key to go back to Main Menu.. |\n";
		cout << setw(37) << left << " " << "  ===========================================\n";
		system("pause>0");
		system("cls");
		ShowMainMenu();
	}
	static enMainMenuChoice _ReadChoice()
	{
		cout << setw(37) << left << "" << "   Enter Your Choice From 1 To 11  : ";
		int Choice = clsInputValidation::ReadIntNumberBetween(1, 11);
		cout << endl;
		return static_cast<enMainMenuChoice> (Choice);
	}
	static void _PerformShowClientList()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsShowAllClientsScreen::ShowClientsList();
	}
	static void _PerformAddNewClient()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsAddNewClientScreen::AddClient();
	}
	static void _PerformDeleteClient()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsDeleteClientScreen::DeleteClient();
	}
	static void _PerformModifyClient()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsUpdateClientScreen::UpdateClient();
	}
	static void _PerformFindClient()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _PerformTransactions()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsTransactionsMenu::ShowTransactionsMenue();
	}
	static void _PerformManageUsers()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsManageUsersMenu::ShowUsersMenu();
	}

	static void _PerformLogout()
	{

		CurrentUser = clsBankUser::Find("", "");
	}
	static void _PerformShowLoginRegister()
	{
		_Algerian_Bank_Banner();
		clsRegisterLogins::ShowRegisterList();
	}
	static void _PerformExit()
	{
		_Algerian_Bank_Banner();
		Run = false;
	}

	static void _PerformCurrencyExchange()
	{
		system("cls");
		_Algerian_Bank_Banner();
		clsCurrencyExchangeMenu::ShowCurrencyMenu();
		
	}

	static void _PerfromMainMenueOption(enMainMenuChoice MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enListClients:
			if (_Check_Access(clsBankUser::pListClients))
			{
				system("cls");
				_PerformShowClientList();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enAddClient:
		{
			if (_Check_Access(clsBankUser::enPermissions::pAddNewClient))
			{
				system("cls");
				_PerformAddNewClient();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		}
		case enDeleteClient:
			if (_Check_Access(clsBankUser::enPermissions::pDeleteClient))
			{
				system("cls");
				_PerformDeleteClient();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enUpdateClient:
			if (_Check_Access(clsBankUser::enPermissions::pUpdateClients))
			{
				system("cls");
				_PerformModifyClient();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enFindClient:
			if (_Check_Access(clsBankUser::enPermissions::pFindClient))
			{
				system("cls");
				_PerformFindClient();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enTransactions:
			if (_Check_Access(clsBankUser::enPermissions::pTranactions))
			{
				system("cls");
				_PerformTransactions();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enManageUsers:
			if (_Check_Access(clsBankUser::enPermissions::pManageUsers))
			{
				system("cls");
				_PerformManageUsers();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}
		case enShowLoginRegister:
			if ((_Check_Access(clsBankUser::enPermissions::pShowLoginReg)))
			{
				system("cls");
				_PerformShowLoginRegister();
				_GoBackToMainMenu();
				break;
			}
			else
			{
				_Access_Denied();
				_GoBackToMainMenu();
				break;
			}

		case enLogout:
			system("cls");
			_PerformLogout();
			break;
		case enCurrencyExchange:
			system("cls");
			_PerformCurrencyExchange();
			_GoBackToMainMenu();
			break;
		case enExit:
			system("cls");
			_PerformExit();
			break;
		}
	}
public:
	static void ShowMainMenu()
	{
		_Algerian_Bank_Banner();
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |           MAIN MENU SCREEN           |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |  1. Show All Clients Data            |\n";
		cout << setw(37) << left << " " << "  |  2. Add New Client                   |\n";
		cout << setw(37) << left << " " << "  |  3. Delete Client Using CCP Num      |\n";
		cout << setw(37) << left << " " << "  |  4. Modify Client Using CCP Num      |\n";
		cout << setw(37) << left << " " << "  |  5. Find Client Using CCP Num        |\n";
		cout << setw(37) << left << " " << "  |  6. Transactions                     |\n";
		cout << setw(37) << left << " " << "  |  7. Manage Users                     |\n";
		cout << setw(37) << left << " " << "  |  8. Show Login Register              |\n";
		cout << setw(37) << left << " " << "  |  9. Logout                           |\n";
		cout << setw(37) << left << " " << "  |  10. Currency Exchange               |\n";
		cout << setw(37) << left << " " << "  |  11. Exit                            |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		enMainMenuChoice Choice = _ReadChoice();
		_PerfromMainMenueOption(Choice);
	}
};


