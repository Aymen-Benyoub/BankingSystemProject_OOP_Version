#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
#include"../Core Classes/clsGlobal.h"
using namespace std;


class clsShowAllClientsScreen : protected clsScreen
{
private:
	static void PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(0) << left << "" << "| " << setw(25) << left << Client.CCP_Number();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << Client.Balance;
	}

public:

	static void ShowClientsList()
	{
		vector <clsBankClient> vClients = clsBankClient::Clients_List();

		string Subtitle = "        There Are (" + to_string(vClients.size()) + ") Clients";
		clsScreen::_DrawHeader("     Clients List", Subtitle);
		cout << "\n___________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		cout << "| " << setw(25) << left << "CCP Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << right << setw(12) << "Balance";
		cout << "\n___________________________________________________";
		cout << "___________________________________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\t      No Clients Available In the System!";
		else
			for (clsBankClient Client : vClients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}

		cout << "\n___________________________________________________";
		cout << "___________________________________________________________________\n" << endl;
	}
};




