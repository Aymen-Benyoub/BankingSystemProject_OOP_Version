#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;


class clsShowClientsBalanceMood : protected clsScreen
{
private:
	static void _PrintClientRecordLineBalanceMood(clsBankClient Client)
	{
		cout << setw(32) << left << "" << "| " << setw(15) << left << Client.CCP_Number();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << right << fixed << setprecision(2) << Client.Balance;
	}

public:
	static void ShowClientsListBalanceMood()
	{
		vector <clsBankClient> vClients = clsBankClient::Clients_List();

		cout << setw(32) << left << "" << "\t\tClient List (" << vClients.size() << ") Client(s).\n";
		cout << setw(32) << left << "" << "_______________________________________________________";
		cout << "\n" << endl;

		cout << setw(32) << left << "" << "| " << left << setw(15) << "CCP Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << right << setw(12) << "Balance\n";
		cout << setw(32) << left << "" << "_______________________________________________________";
		cout << endl;

		if (vClients.size() == 0)
			cout << setw(32) << left << "" << "\t\tNo Clients Available In the System!";
		else
		{
			cout << endl;
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLineBalanceMood(Client);
				cout << endl;
			}
		}
		cout << setw(32) << left << "" << "_______________________________________________________";
		cout << "\n" << endl;
		double TotalBalances = clsBankClient::TotalBalances();
		cout << setw(32) << left << "" << "\t\tTotal Balances Is : " << TotalBalances << endl << endl;
		cout << setw(32) << left << "" << "=====================================================================" << endl;
		cout << setw(32) << left << "" << "|       ( " << clsInputValidation::NumberToText(TotalBalances) << ")      |" << endl;
		cout << setw(32) << left << "" << "=====================================================================" << endl;
		cout << endl << endl;



	}
};




