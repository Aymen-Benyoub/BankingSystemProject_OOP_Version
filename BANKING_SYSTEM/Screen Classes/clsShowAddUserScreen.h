#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsInputValidation.h"

using namespace std;

class clsShowAddUserScreen : protected clsScreen
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

	static void _Read_Updated_User(clsBankUser& User)
	{
		cout << "Please Enter The First Name : ";
		User.FirstName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The Last Name : ";
		User.LastName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The Phone Number {10 Digits} : ";
		User.PhoneNumber = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidPhoneNumber(User.PhoneNumber))
		{
			cout << " Please Enter A Valid Phone Number In This Pattern 0{5-7} + 8 Digits : ";
			User.PhoneNumber = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The Email : ";
		User.Email = clsInputValidation::ReadTrimedString();
		cout << endl;

		while (!clsInputValidation::isValidEmail(User.Email))
		{
			cout << " Please Enter A Valid Email In This Pattern Name@Domain.extention : ";
			User.Email = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The Password {6 Digits Password} : ";
		User.Password = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValid6DigitsPassword(User.Password))
		{
			cout << " Please Enter A Valid 6 Digits Password : ";
			User.Password = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The Permissions : ";
		User.Permissions = _Read_Permissions();
		cout << endl;

	}

public:

	static void AddUser()
	{
		_DrawHeader("   ADD USER SCREEN");
		cout << "Adding New User , Please Enter Its Informations" << endl;
		cout << "==================================================" << endl;
		cout << "Please Enter The User Name : ";
		string UserName;
		UserName = clsInputValidation::ReadString();
		cout << endl;

		while (clsBankUser::IsUserExist(UserName))
		{
			cout << "Sorry , This User Name Is Occupied By Another User , Try Another : ";
			UserName = clsInputValidation::ReadString();
			cout << endl;
		}
		clsBankUser User = clsBankUser::GetNewUser(UserName);

		_Read_Updated_User(User);

		cout << "==================================================" << endl;

		clsBankUser::enSave_Result Save_Res = User.Save_Update();

		if (Save_Res == clsBankUser::enSave_Result::SuccessToAdd)
		{
			system("cls");

			cout << setw(37) << left << " " << "  =========================================\n";
			cout << setw(37) << left << " " << "  |        User Added Successfully        |\n";
			cout << setw(37) << left << " " << "  =========================================\n";

			_PrintUserRecord(User);
		}
		else
		{
			if (Save_Res == clsBankUser::enSave_Result::FaildUserName_Exist)
			{
				cout << "User Is Not Added , Its User Name Already Exist" << endl;
			}
			else if (Save_Res == clsBankUser::enSave_Result::FaildEmpty)
			{
				cout << "User Is Not Added , Its Empty !" << endl;
			}
		}


	}
};

