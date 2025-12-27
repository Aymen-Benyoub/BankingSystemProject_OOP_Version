#pragma once
#include<iostream>
#include"../Libraries/clsDate.h"
#include<fstream>
#include<string>
#include<vector>
#include"../Screen Classes/clsScreen.h"
#include<iomanip>
using namespace std;


class clsRegisterTransfer : protected clsScreen
{
private:
	string _Sender;
	string _Date;
	string _Time;
	string _Receiver;
	float _Amount;

	static string _GetSystemTime()
	{
		time_t now = time(0);
		tm* t = localtime(&now);

		return to_string(t->tm_hour) + ":" +
			to_string(t->tm_min) + ":" +
			to_string(t->tm_sec);
	}
	static string _RegisterTransferLine(clsRegisterTransfer User, string Separator = " || ")
	{
		return User._Sender + Separator + User._Receiver + Separator + to_string(User._Amount) + Separator + User._Date + Separator + User._Time;
	}

	static  void _AddNewLineToRegisterFile(clsRegisterTransfer User, string File_Name = "Data/TransferRegister.txt")
	{

		fstream MyFile;
		MyFile.open("Data/TransferRegister.txt", ios::out | ios::app);

		string DataLine;

		if (MyFile.is_open())
		{

			DataLine = _RegisterTransferLine(User);
			MyFile << DataLine << endl;
			MyFile.close();

		}

	}

	static void PrintTransferRecordLine(clsRegisterTransfer User)
	{
		cout << setw(8) << left << "" << "| " << setw(20) << left << User.Sender;
		cout << "| " << setw(20) << left << User.Receiver;
		cout << "| " << setw(12) << left << User.Amount;
		cout << "| " << setw(20) << left << User.Time;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << User.Date;
	}

	static clsRegisterTransfer _ConvertLinetoRegisterObject(string Line)
	{
		vector <string> V1 = clsString::Split_String(Line, " || ");

		return clsRegisterTransfer(V1[0], V1[1], stoi(V1[2]), V1[3], V1[4]);
	}

	static  vector <clsRegisterTransfer> _LoadUsersBankTransferDataFromFile(string File_Name = "Data/TransferRegister.txt")
	{

		vector <clsRegisterTransfer> vUsers;

		fstream MyFile;
		MyFile.open(File_Name, ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsRegisterTransfer User = _ConvertLinetoRegisterObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}




public:

	clsRegisterTransfer(string Sender, string Receiver, int Amount)
	{
		_Sender = Sender;
		_Receiver = Receiver;
		_Amount = Amount;
		clsDate Date = clsDate::GetSystemDate();
		_Date = to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
		_Time = _GetSystemTime();

	}

	clsRegisterTransfer(string Sender, string Receiver, int Amount, string Date, string Time)
	{
		_Sender = Sender;
		_Receiver = Receiver;
		_Amount = Amount;
		_Date = Date;
		_Time = Time;

	}
	void Register_Transfer()
	{
		_AddNewLineToRegisterFile(*this);
	}

	string GetSender()
	{
		return _Sender;
	}

	void SetUserName(string Sender)
	{
		_Sender = Sender;
	}

	__declspec(property(get = GetSender, put = SetSender)) string Sender;

	string GetReceiver()
	{
		return _Receiver;
	}

	void SetReceiver(string Receiver)
	{
		_Receiver = Receiver;
	}

	__declspec(property(get = GetReceiver, put = SetReceiver)) string Receiver;

	float GetAmount()
	{
		return _Amount;
	}

	void SetAmount(float Amount)
	{
		_Amount = Amount;
	}

	__declspec(property(get = GetAmount, put = SetAmount)) float Amount;

	string GetDate()
	{
		return _Date;
	}

	void SetDate(string Date)
	{
		_Date = Date;
	}

	__declspec(property(get = GetDate, put = SetDate)) string Date;

	string GetTime()
	{
		return _Time;
	}

	void SetTime(string Time)
	{
		_Time = Time;
	}

	__declspec(property(get = GetTime, put = SetTime)) string Time;

	static vector<clsRegisterTransfer> Transfer_List()
	{
		return _LoadUsersBankTransferDataFromFile();
	}

	static void ShowTransfersList()
	{
		vector <clsRegisterTransfer> vUsers = clsRegisterTransfer::Transfer_List();

		string Subtitle = "       There Are (" + to_string(vUsers.size()) + ") Transfer";
		_DrawHeader("Transfer Register List", Subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(20) << left << "Sender";
		cout << "| " << left << setw(20) << "Receiver";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(20) << "Time";
		cout << "| " << right << setw(12) << "Date";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\t      No Registers Yet In the System!";
		else
			for (clsRegisterTransfer User : vUsers)
			{
				PrintTransferRecordLine(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}
};




