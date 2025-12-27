#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Screen Classes/clsRegisterTransfer.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{

private:
	static void _PrintClientRecordLineBalanceMood(clsBankClient Client)
	{
		cout << setw(32) << left << "" << "_______________________________________________________";
		cout << "\n" << endl;

		cout << setw(32) << left << "" << "| " << left << setw(15) << "CCP Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << right << setw(12) << "Balance\n";
		cout << setw(32) << left << "" << "_______________________________________________________";
		cout << endl << endl;
		cout << setw(32) << left << "" << "| " << setw(15) << left << Client.CCP_Number();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << right << fixed << setprecision(2) << Client.Balance;
		cout << endl;
		cout << setw(32) << left << "" << "_______________________________________________________";
	}
public:
	static void Transfer()
	{

		cout << "\nEnter The CCP Bank Number Of The Desired Account To Transfer From : ";
		string CCP_Number_From = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(CCP_Number_From))
		{
			cout << " This CCP Bank Number Doesn't Belong To Any Client , Retry  : ";
			CCP_Number_From = clsInputValidation::ReadString();
		}

		clsBankClient Client_From = clsBankClient::Find(CCP_Number_From);

		_PrintClientRecordLineBalanceMood(Client_From);

		cout << "\n\nEnter The CCP Bank Number Of The Desired Account To Transfer To : ";
		string CCP_Number_To = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(CCP_Number_To))
		{
			cout << " This CCP Bank Number Doesn't Belong To Any Client , Retry  : ";
			CCP_Number_To = clsInputValidation::ReadString();
		}

		clsBankClient Client_To = clsBankClient::Find(CCP_Number_To);

		if (CCP_Number_To == CCP_Number_From)
		{
			cout << " You Cant Transfer Money Between The Same Acount " << endl;
		}
		else
		{
			_PrintClientRecordLineBalanceMood(Client_To);

			cout << "\n\n Enter The Amount Of Money That You Want To Transfer From " << Client_From.FullName() << " To " << Client_To.FullName() << " : ";

			string Msg = "\n The Amount Excceeds The Balance Of The Client " + Client_From.FullName() + " , Re Enter The Amount : ";
			float Amount = clsInputValidation::ReadDoubleNumberBetween(0, Client_From.Balance, Msg);

			Client_From.Balance = Client_From.Balance - Amount;
			Client_To.Balance = Client_To.Balance + Amount;

			Client_From.Save_Update();
			Client_To.Save_Update();

			clsRegisterTransfer Transfer(Client_From.FullName(), Client_To.FullName(), Amount);

			Transfer.Register_Transfer();

			cout << " Operation Done Successfully " << endl;

		}

		




	}
};



