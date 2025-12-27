#pragma once 
#include<iomanip> 
#include<iostream>
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"
#include"../Screen Classes/clsScreen.h" 
#include"../Screen Classes/clsShowUsersListScreen.h"
#include"../Screen Classes/clsShowAddUserScreen.h"
#include"../Screen Classes/clsShowDeleteUserScreen.h"
#include"../Screen Classes/clsShowUpdateUserScreen.h"
#include"../Screen Classes/clsShowFindUserScreen.h"

using namespace std;

class clsManageUsersMenu : protected clsScreen
{
private:
	enum enUsersMenuChoice {
		enListUsers = 1, enAddUser = 2, enDeleteUser = 3,
		enUpdateUser = 4, enFindUser = 5, enReturnMainMenu = 6
	};
	static void _GoBackToUsersMenu()
	{
		cout << setw(35) << left << " " << "===================================================\n";
		cout << setw(35) << left << " " << "| Press any key to go back to Manage Users Menu.. |\n";
		cout << setw(35) << left << " " << "===================================================\n";
		system("pause>0");
		system("cls");
		_Algerian_Bank_Banner();
		ShowUsersMenu();
	}
	static enUsersMenuChoice _ReadUsersChoice()
	{
		cout << setw(37) << left << "" << "   Enter Your Choice From 1 To 6  : ";
		int Choice = clsInputValidation::ReadIntNumberBetween(1, 6);
		cout << endl;
		return static_cast<enUsersMenuChoice>(Choice);
	}

	static void _PerformShowUsersList()
	{
		clsShowUsersListScreen::ShowUsersList();
	}
	static void _PerformAddNewUser()
	{
		_Algerian_Bank_Banner();
		clsShowAddUserScreen::AddUser();
	}
	static void _PerformDeleteUser()
	{
		_Algerian_Bank_Banner();
		clsShowDeleteUserScreen::DeleteUser();
	}
	static void _PerformModifyUser()
	{
		_Algerian_Bank_Banner();
		clsShowUpdateUserScreen::UpdateUser();
	}
	static void _PerformFindUser()
	{
		_Algerian_Bank_Banner();
		clsShowFindUserScreen::ShowFindUserScreen();

	}

	static void _PerfromUsersMenuOption(enUsersMenuChoice MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enListUsers:
			system("cls");
			_PerformShowUsersList();
			_GoBackToUsersMenu();
			break;
		case enAddUser:
		{
			system("cls");
			_PerformAddNewUser();
			_GoBackToUsersMenu();
			break;
		}
		case enDeleteUser:
			system("cls");
			_PerformDeleteUser();
			_GoBackToUsersMenu();
			break;
		case enUpdateUser:
			system("cls");
			_PerformModifyUser();
			_GoBackToUsersMenu();
			break;
		case enFindUser:
			system("cls");
			_PerformFindUser();
			_GoBackToUsersMenu();
			break;
		case enReturnMainMenu:
			break;
		}
	}

public:
	static void ShowUsersMenu()
	{
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |          MANAGE USERS SCREEN         |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		cout << setw(37) << left << " " << "  |  1. Show All Users Data              |\n";
		cout << setw(37) << left << " " << "  |  2. Add New Users                    |\n";
		cout << setw(37) << left << " " << "  |  3. Delete A User                    |\n";
		cout << setw(37) << left << " " << "  |  4. Modify A User                    |\n";
		cout << setw(37) << left << " " << "  |  5. Find A User                      |\n";
		cout << setw(37) << left << " " << "  |  6. Return To Main Menu              |\n";
		cout << setw(37) << left << " " << "  ========================================\n";
		enUsersMenuChoice Choice = _ReadUsersChoice();
		_PerfromUsersMenuOption(Choice);
	}

};



