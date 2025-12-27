#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;


class clsShowUsersListScreen : protected clsScreen
{
private:
	static void PrintUserRecordLine(clsBankUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.PhoneNumber;
		cout << "| " << setw(25) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << User.Permissions;
	}

public:

	static void ShowUsersList()
	{
		_DrawHeader("     SHOW CLIENTS", "         ( BALANCE MOOD )");
		vector <clsBankUser> vUsers = clsBankUser::Users_List();

		string Subtitle = "       There Are (" + to_string(vUsers.size()) + ") Users";
		clsScreen::_DrawHeader("      Users List", Subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(15) << left << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << right << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\t     No Users Available In the System!";
		else
			for (clsBankUser User : vUsers)
			{
				PrintUserRecordLine(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}
};





