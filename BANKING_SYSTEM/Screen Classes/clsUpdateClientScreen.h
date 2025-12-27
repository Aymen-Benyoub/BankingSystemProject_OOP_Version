#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________________________\n" << endl;

		cout << "| " << setw(25) << left << "CCP Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << right << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________________________\n" << endl;
		cout << "| " << setw(25) << left << Client.CCP_Number();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << Client.Balance;
		cout << "\n_______________________________________________________";
		cout << "_______________________________________________________________\n" << endl;
	}
	static void _Read_Updated_Client(clsBankClient& Client)
	{
		cout << "Please Enter The New First Name : ";
		Client.FirstName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The New Last Name : ";
		Client.LastName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The New Phone Number {10 Digits} : ";
		Client.PhoneNumber = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidPhoneNumber(Client.PhoneNumber))
		{
			cout << " Please Enter A Valid Phone Number In This Pattern 0{4-7} + 8 Digits : ";
			Client.PhoneNumber = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The New Email : ";
		Client.Email = clsInputValidation::ReadTrimedString();
		cout << endl;

		while (!clsInputValidation::isValidEmail(Client.Email))
		{
			cout << " Please Enter A Valid Email In This Pattern Name@Domain.extention : ";
			Client.Email = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The New 4-Digit PinCode : ";
		Client.PinCode = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidPinCode(Client.PinCode))
		{
			cout << " Please Enter A Valid 4-Digit PinCode : ";
			Client.PinCode = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The New Account Balance : ";
		Client.Balance = clsInputValidation::ReadDoubleNumber();
		cout << endl;

	}



public:
	static void UpdateClient()
	{
		_DrawHeader("Update Client Screen");
		string CCP_Number;
		cout << " Please Enter The CCP Number Of The Desired Client To Modify  : ";
		CCP_Number = clsInputValidation::ReadString();
		cout << endl;

		while (!clsBankClient::IsClientExist(CCP_Number))
		{
			cout << " No Client Matches The CCP Number Entered , Retry : ";
			CCP_Number = clsInputValidation::ReadString();
			cout << endl;
		}

		clsBankClient ClientToUpdate = clsBankClient::Find(CCP_Number);

		system("cls");

		_PrintClientRecord(ClientToUpdate);
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
			cout << "|      Enter The New Client Informations     |" << endl;
			cout << "==============================================\n";
			_Read_Updated_Client(ClientToUpdate);

			bool Save_Res = ClientToUpdate.Save_Update();

			if (Save_Res)
			{
				cout << "==============================================\n";
				cout << "|     Your Client Is Successfully Updated    |" << endl;
				cout << "==============================================\n";
			}
			else
			{
				cout << "=====================================================================================\n";
				cout << "|  An Error Occured , Your Client Might Be An Empty Object , Updating Client Broke  |" << endl;
				cout << "=====================================================================================\n";
			}
		}



	}
};



