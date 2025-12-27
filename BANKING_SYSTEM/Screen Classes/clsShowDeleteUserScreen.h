#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;

class clsShowDeleteUserScreen : protected clsScreen
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

	static void DeleteUser()
	{
		_DrawHeader("  DELETE USER SCREEN");
		cout << setw(28) << left << "" << " Please Enter The User Name For The Desired User To Delete : ";

		string UserName;
		UserName = clsInputValidation::ReadString();
		cout << endl;

		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << setw(28) << left << "" << "Sorry , This User Name Is Not Occupied By Any User , Try Another : ";
			UserName = clsInputValidation::ReadString();
			cout << endl;
		}
		clsBankUser UserToDelete = clsBankUser::Find(UserName);
		char Answer;

		if (UserToDelete.UserName == "Admin")
		{
			cout << setw(28) << left << "" << "Sorry , This User Can't Be Deleted Because Its The Administrator  \n";
			Answer = 'N';
		}
		else
		{
			_PrintUserRecord(UserToDelete);
			do
			{
				cout << endl;
				cout << setw(28) << left << "" << "          Do You Confirm Deleting This Account  Y/N \n";
				Answer = clsInputValidation::ReadChar();
				cout << endl;

			} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');
		}


		if (tolower(Answer) == 'n')
		{
			cout << setw(37) << left << "" << "==============================================\n";
			cout << setw(37) << left << "" << "|       Operation Failed To Take Place       |\n";
			cout << setw(37) << left << "" << "==============================================\n";
		}
		else
		{
			clsBankUser::MakeDeleteState(UserToDelete);
			UserToDelete.Delete();

			cout << setw(37) << left << "" << "==============================================\n";
			cout << setw(37) << left << "" << "|         Operation Done Successfully        |\n";
			cout << setw(37) << left << "" << "==============================================\n";

		}

	}
};




