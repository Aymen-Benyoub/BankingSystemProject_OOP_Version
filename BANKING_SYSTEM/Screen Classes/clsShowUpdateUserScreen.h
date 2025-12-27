#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;

class clsShowUpdateUserScreen : protected clsScreen
{
private:

	static char _GetAnswer(string Str = "Do You Want To Give This User Access To This Choice")
	{
		char Answer;
		do
		{
			cout << endl;
			cout << setw(28) << left << "" << Str << " Y/N \n";
			Answer = clsInputValidation::ReadChar();
			cout << endl;

		} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');

		return Answer;
	}
	static int _Read_Permissions()
	{
		int Perm = 0;
		cout << endl;
		char Answer;
		Answer = _GetAnswer("Do You Want To Give This User The Full Access To The Program");
		if (toupper(Answer) == 'Y')
		{
			return clsBankUser::enPermissions::pAll;
		}
		else
		{
			cout << setw(37) << left << " " << "  =========================================\n";
			cout << setw(37) << left << " " << "  |         Permissions Selection         |\n";
			cout << setw(37) << left << " " << "  =========================================\n";

			cout << setw(35) << left << "" << "First Permission [Showing The List Of All Client]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pListClients;
			}
			cout << setw(35) << left << "" << "Second Permission [Adding Clients]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pAddNewClient;
			}
			cout << setw(35) << left << "" << "Third Permission [Deleting Clients]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pDeleteClient;
			}
			cout << setw(35) << left << "" << "Fourth Permission [Updating Client]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pUpdateClients;
			}
			cout << setw(35) << left << "" << "Fifth Permission [Searching For Client]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pFindClient;
			}
			cout << setw(35) << left << "" << "Sixth Permission [Transactions]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pTranactions;
			}
			cout << setw(35) << left << "" << "Seventh Permission [Manage Users]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pManageUsers;
			}

			cout << setw(35) << left << "" << "Eighth Permission [Show Login Register]" << endl;
			Answer = _GetAnswer();
			if (toupper(Answer) == 'Y')
			{
				Perm += clsBankUser::enPermissions::pShowLoginReg;
			}

		}

		return Perm;

	}
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

	static void _Read_Updated_User(clsBankUser& User)
	{
		cout << "Please Enter The First Name : ";
		User.FirstName = clsInputValidation::ReadString();
		cout << endl;

		cout << "Please Enter The Last Name : ";
		User.LastName = clsInputValidation::ReadString();
		cout << endl;

		cout << "Please Enter The Phone Number : ";
		User.PhoneNumber = clsInputValidation::ReadString();
		cout << endl;

		cout << "Please Enter The Email : ";
		User.Email = clsInputValidation::ReadString();
		cout << endl;

		cout << "Please Enter The Password : ";
		User.Password = clsInputValidation::ReadString();
		cout << endl;

		cout << "Please Enter The New Permissions : ";
		User.Permissions = _Read_Permissions();
		cout << endl;

	}



public:
	static void UpdateUser()
	{
		_DrawHeader("   UPDATE USER SCREEN");
		string UserName;
		cout << " Please Enter User Name Of The Desired User To Modify  : ";
		UserName = clsInputValidation::ReadString();
		cout << endl;

		while (!clsBankUser::IsUserExist(UserName))
		{
			cout << " No User Matches The User Name Entered , Retry : ";
			UserName = clsInputValidation::ReadString();
			cout << endl;
		}

		clsBankUser UserToUpdate = clsBankUser::Find(UserName);

		system("cls");

		_PrintUserRecord(UserToUpdate);
		char Answer;

		do
		{
			cout << endl;

			cout << setw(37) << left << "" << "Do You Confirm Updating This Account  Y/N \n";
			Answer = clsInputValidation::ReadChar();
			cout << endl;

		} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');

		if (tolower(Answer) == 'n')
		{
			cout << setw(37) << left << "" << "==============================================\n";
			cout << setw(37) << left << "" << "|       Operation Failed To Take Place       |\n";
			cout << setw(37) << left << "" << "==============================================\n";
		}
		else
		{
			cout << "==============================================\n";
			cout << "|       Enter The New User Informations      |" << endl;
			cout << "==============================================\n";
			_Read_Updated_User(UserToUpdate);

			bool Save_Res = UserToUpdate.Save_Update();

			if (Save_Res)
			{
				cout << setw(35) << left << " " << "===================================================\n";
				cout << setw(35) << left << " " << "|         Your User Is Successfully Updated       |" << endl;
				cout << setw(35) << left << " " << "===================================================\n";
			}
			else
			{
				cout << setw(28) << left << " " << "=====================================================================================\n";
				cout << setw(28) << left << " " << "|    An Error Occured , Your User Might Be An Empty Object , Updating User Broke    |" << endl;
				cout << setw(28) << left << " " << "=====================================================================================\n";
			}
		}



	}
};



