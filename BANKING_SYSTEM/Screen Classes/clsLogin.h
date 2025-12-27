#pragma once
#include"iostream"
#include"../Menu Classes/clsMainMenu.h"
#include"../Core Classes/clsBankUser.h"
#include"../Core Classes/clsGlobal.h"
#include"../Libraries/clsInputValidation.h"
#include"../Screen Classes/clsScreen.h"
#include"../Screen Classes/clsRegisterLogins.h"

using namespace std;

class clsLogin : protected clsScreen
{
private:

	static bool Admin_Exist()
	{
		return clsBankUser::IsUserExist("Admin");
	}
	static void _Login()
	{
		cout << endl;
		cout << " Enter Your User Name  : ";
		string UserName = clsInputValidation::ReadString();
		cout << endl;
		cout << " Enter Your Password  : ";
		string Password = clsInputValidation::ReadString();
		cout << endl;

		CurrentUser = clsBankUser::Find(UserName, Password);

		while (CurrentUser.IsEmpty() && Trials != 0)
		{
			Trials--;



			if (Trials != 0)
			{
				cout << " Wrong Parameters , You Have " << Trials << " More Trial(s) " << endl << endl;
				cout << " Enter Your User Name  : ";
				UserName = clsInputValidation::ReadString();
				cout << endl;
				cout << " Enter Your Password  : ";
				Password = clsInputValidation::ReadString();
				cout << endl;
			}
			else
			{
				cout << " You Are Blocked After 3 Failed Logins " << endl;
				CurrentUser = clsBankUser::Find(UserName, Password);
			}

			CurrentUser = clsBankUser::Find(UserName, Password);

		}
		if (!CurrentUser.IsEmpty())
		{
			clsRegisterLogins User_Logged(CurrentUser.UserName, CurrentUser.Password, CurrentUser.Permissions);
			User_Logged.Register_Login();

			system("cls");
			Run = true;
			clsMainMenu::ShowMainMenu();

		}

	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		if (!Admin_Exist())
		{
			clsBankUser Admin = clsBankUser::GetAdmin();
			Admin.Save_Update();
		}
		_Algerian_Bank_Banner();
		_DrawHeader(" LOGIN TO THE SYSTEM");
		_Login();

	}
};



