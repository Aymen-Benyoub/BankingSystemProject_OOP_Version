#pragma once
#include<iomanip> 
#include<iostream>
#include"../Screen Classes/clsScreen.h"
#include"../Core Classes/clsBankClient.h"
#include"../Libraries/clsInputValidation.h"
using namespace std;

class clsWithdrawScreen : protected clsScreen
{
private:
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(15) << left << "CCP Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(25) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << right << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << setw(15) << left << Client.CCP_Number();
		cout << "| " << setw(20) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.PhoneNumber;
		cout << "| " << setw(25) << left << Client.Email;
		cout << "| " << setw(10) << left << Client.PinCode;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << Client.Balance;
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}


public:
	static void Withdraw(string File_Name = "Data/Clients.txt")
	{
		_DrawHeader("  WITHDRAW SCREEN");
		int Trials = 2;
		cout << " Please Enter The CCP Number Of The Desired Client To Withdraw In His Account  : ";
		string CCP_Number = clsInputValidation::ReadString();

		while (!clsBankClient::IsClientExist(CCP_Number) && Trials != 0)
		{
			cout << " You Have " << Trials << " Trial(s) Left" << endl;
			cout << " No Client Matches The CCP Number Entered , Retry : ";
			CCP_Number = clsInputValidation::ReadString();
			cout << endl;
			Trials--;
		}

		
		vector <clsBankClient> V1 = clsBankClient::Clients_List();
		char Answer;
		bool Found = false;
		for (clsBankClient Client : V1)
		{

			if (Client.CCP_Number() == CCP_Number)
			{
				Found = true;


				system("cls");

				_PrintClientRecord(Client);
				char Answer;

				do
				{
					cout << endl;

					cout << setw(37) << left << "" << "Do You Confirm Withdrawing In This Account  Y/N \n";
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
					cout << "\nPlease Enter The Amount You Want To Withdraw In This Account  : \n";

					int Amount_To_Sub = clsInputValidation::ReadIntNumber();

					if (Client.Balance >= Amount_To_Sub)
					{
						Client.Balance = Client.Balance - Amount_To_Sub;

						clsBankClient::enSave_Result SaveRes = Client.Save_Update();

						switch (SaveRes)
						{
						case clsBankClient::SuccessToModify:
							cout << "\n=========================================\n";
							cout << "|       Amount Successfully Withdrawed       |\n";
							cout << "=========================================\n";
							break;
						default:
							cout << "\n================================================\n";
							cout << "|       Transaction Failed To Take Place       |\n";
							cout << "================================================\n";
							break;
						}
					}
					else
					{
						cout << "\n=====================================================================================\n";
						cout << "|       You Can't Take That Amount From This Account As It Exceeds Its Balance      |\n";
						cout << "=====================================================================================\n";
					}

				}


			}
		}

	}
};



