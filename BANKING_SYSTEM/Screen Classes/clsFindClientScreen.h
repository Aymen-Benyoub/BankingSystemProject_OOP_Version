#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"

using namespace std;

class clsFindClientScreen : protected clsScreen
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

public:
	static void ShowFindClientScreen()
	{

		_DrawHeader(" FIND CLIENT SCREEN");

		int Trials = 2;

		string AccountNumber;
		cout << "\nPlease Enter CCP Number : ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber) && Trials != 0)
		{
			

			cout << " You Have " << Trials << " Trial(s) Left" << endl;
			cout << "\nCCP Number is not found, choose another one : ";
			AccountNumber = clsInputValidation::ReadString();
			Trials--;
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found  :-)\n";
			_PrintClientRecord(Client1);
		}
		else
		{
			cout << "\nClient Was not Found  :-(\n";
		}



	}
};




