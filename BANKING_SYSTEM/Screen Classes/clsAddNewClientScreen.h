#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Core Classes/clsGlobal.h"
#include"../Libraries/clsInputValidation.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
{

private:

	static void _PrintClientRecord(clsBankClient Client)
	{
		cout <<"\n_______________________________________________________";
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
		cout << "Please Enter The First Name : ";
		Client.FirstName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The Last Name : ";
		Client.LastName = clsInputValidation::ReadTrimedString();
		cout << endl;

		cout << "Please Enter The Phone Number {10 Digits} : ";
		Client.PhoneNumber = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidPhoneNumber(Client.PhoneNumber))
		{
			cout << " Please Enter A Valid Phone Number In This Pattern 0{5-7} + 8 Digits : ";
			Client.PhoneNumber = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The Email : ";
		Client.Email = clsInputValidation::ReadTrimedString();
		cout << endl;

		while (!clsInputValidation::isValidEmail(Client.Email))
		{
			cout << " Please Enter A Valid Email In This Pattern Name@Domain.extention : ";
			Client.Email = clsInputValidation::ReadTrimedString();
			cout << endl;
           
		}

		cout << "Please Enter 4-Digit PinCode : ";
		Client.PinCode = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidPinCode(Client.PinCode))
		{
			cout << " Please Enter A Valid 4-Digit PinCode : ";
			Client.PinCode = clsInputValidation::ReadTrimedString();
			cout << endl;

		}

		cout << "Please Enter The Account Balance : ";
		Client.Balance = clsInputValidation::ReadDoubleNumber();
		cout << endl;

	}

public:

	static void AddClient()
	{
		_DrawHeader(" ADD CLIENT SCREEN");
		cout << "Adding New Client , Please Enter Its Informations" << endl;
		cout << "___________________________________________________" << endl;
		cout << "Please Enter The CCP Number : ";
		string CCP_Number1;
		CCP_Number1 = clsInputValidation::ReadString();
		cout << endl;

		while (!clsInputValidation::isValidCcp_Number(CCP_Number1))
		{
			cout << " Please Enter A Valid CCP Number in The Pattern [ 00799999 ] + 12 Digits : ";
			CCP_Number1 = clsInputValidation::ReadTrimedString();
			cout << endl;
		}

		while (clsBankClient::IsClientExist(CCP_Number1))
		{
			cout << "Sorry , This CCP Bank Number Is Occupied By Another Client , Try Another : ";
			CCP_Number1 = clsInputValidation::ReadString();
			cout << endl;
		}
		clsBankClient Client = clsBankClient::GetNewClient(CCP_Number1);

		_Read_Updated_Client(Client);

		cout << "___________________________________________________" << endl;

		clsBankClient::enSave_Result Save_Res = Client.Save_Update();

		if (Save_Res == clsBankClient::enSave_Result::SuccessToAdd)
		{
			system("cls");

			cout << setw(37) << left << " " << "  ===========================================\n";
			cout << setw(37) << left << " " << "  |        Client Added Successfully        |\n";
			cout << setw(37) << left << " " << "  ===========================================\n";

			_PrintClientRecord(Client);
		}
		else
		{
			if (Save_Res == clsBankClient::enSave_Result::FaildCCP_Exist)
			{
				cout << "Client Is Not Added , Its CCP Bank Number Already Exist" << endl;
			}
			else if (Save_Res == clsBankClient::enSave_Result::FaildEmpty)
			{
				cout << "Client Is Not Added , Its Empty !" << endl;
			}
		}


	}
};




