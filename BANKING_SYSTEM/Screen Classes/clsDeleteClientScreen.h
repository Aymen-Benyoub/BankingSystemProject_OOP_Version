#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen
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

	static void DeleteClient()
	{
		_DrawHeader(" DELETE CLIENT SCREEN");
		cout << setw(28) << left << "" << " Please Enter The CCP Bank Number For The Desired Client To Delete : ";

		int Trials = 2;

		string CCP_Number1;
		CCP_Number1 = clsInputValidation::ReadString();
		cout << endl;

		while (!clsBankClient::IsClientExist(CCP_Number1) && Trials != 0)
		{

			cout << setw(28) << left << "" << " You Have " << Trials << " Trial(s) Left" << endl;

			cout << setw(28) << left << "" << "Sorry , This CCP Bank Number Is Not Occupied By Any Client , Try Another : ";
			CCP_Number1 = clsInputValidation::ReadString();
			cout << endl;

			Trials--;
		}
		clsBankClient ClientToDelete = clsBankClient::Find(CCP_Number1);

		if (!ClientToDelete.IsEmpty())
		{
			_PrintClientRecord(ClientToDelete);

			char Answer;

			do
			{
				cout << endl;
				cout << setw(38) << left << " " << "Do You Confirm Deleting This Account  Y/N \n";
				Answer = clsInputValidation::ReadChar();
				cout << endl;

			} while (Answer != 'y' && Answer != 'Y' && Answer != 'n' && Answer != 'N');

			if (tolower(Answer) == 'n')
			{
				cout << setw(38) << left << " " << "=============================================\n";
				cout << setw(38) << left << " " << "|       Operation Failed To Take Place      |\n";
				cout << setw(38) << left << " " << "=============================================\n";
			}
			else
			{
				clsBankClient::MakeDeleteState(ClientToDelete);
				ClientToDelete.Delete();

				_PrintClientRecord(ClientToDelete);

			}
		}
		else
		{
			cout << setw(38) << left << " " << "=============================================\n";
			cout << setw(38) << left << " " << "|       Operation Failed To Take Place      |\n";
			cout << setw(38) << left << " " << "=============================================\n";
		}

	}
};



