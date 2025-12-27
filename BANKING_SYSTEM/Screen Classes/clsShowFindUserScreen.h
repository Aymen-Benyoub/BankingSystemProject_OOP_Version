#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsInputValidation.h"

using namespace std;


class clsShowFindUserScreen : protected clsScreen
{
private:
	static void _PrintUserRecord(clsBankUser User)
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(15) << left << "UserName";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << right << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.PhoneNumber;
		cout << "| " << setw(25) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << User.Permissions;
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}

public:
	static void ShowFindUserScreen()
	{

		_DrawHeader("  FIND USER SCREEN");

		string UserName;
		cout << "\nPlease Enter User Name : ";
		UserName = clsInputValidation::ReadString();
		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found, choose another one : ";
			UserName = clsInputValidation::ReadString();
		}

		clsBankUser User = clsBankUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << endl;
			_DrawHeader("     USER FOUND :)");
			_PrintUserRecord(User);
		}
		else
		{
			cout << endl;
			_DrawHeader("  USER NOT FOUND :(");
		}



	}
};

