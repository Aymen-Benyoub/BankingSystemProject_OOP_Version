#pragma once
#include<iostream>
#include"..\Libraries\clsPerson.h"
#include"../Libraries/clsString.h"
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>


class clsBankClient : public clsPerson
{

private:

	enum enObjectMode { EmptyMode, UpdateMode, AddNewMode, DeleteMode };

	enObjectMode _Mode;
	string _CCP_Number;
	string _PinCode;
	float _Balance;

	static string  _EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  _DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}

	static clsBankClient _GetEmptyClient()
	{
		return clsBankClient(enObjectMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static clsBankClient _ConvertLinetoClientObject(string Line)
	{
		vector <string> V1 = clsString::Split_String(Line, " || ");

		return clsBankClient(enObjectMode::UpdateMode, V1[0], V1[1], V1[2], V1[3], V1[4], _DecryptText(V1[5], 4), stod(V1[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = " || ")
	{

		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.PhoneNumber + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.CCP_Number() + Seperator;
		stClientRecord += _EncryptText(Client.PinCode, 4) + Seperator;
		stClientRecord += to_string(Client.Balance);

		return stClientRecord;

	}

	static  vector <clsBankClient> _LoadClientsDataFromFile(string File_Name = "Data/Clients.txt")
	{

		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open(File_Name, ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankClient Client = _ConvertLinetoClientObject(Line);

				vClients.push_back(Client);
			}

			MyFile.close();

		}

		return vClients;

	}

	static  void _SaveClientsDataToFile(vector<clsBankClient> V1, string File_Name = "Data/Clients.txt")
	{

		fstream MyFile;
		MyFile.open("Data/Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankClient C : V1)
			{
				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Updating_Clients_File()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& Client : vClients)
		{
			if (Client.CCP_Number() == CCP_Number())
			{
				Client = *this;
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
	}

	static  void _AddNewLineToClientsFile(clsBankClient Client, string File_Name = "Data/Clients.txt")
	{

		fstream MyFile;
		MyFile.open("Data/Clients.txt", ios::out | ios::app);

		string DataLine;

		if (MyFile.is_open())
		{

			DataLine = _ConvertClientObjectToLine(Client);
			MyFile << DataLine << endl;
			MyFile.close();

		}

	}

	static void _DeleteClientFromFile(clsBankClient Client, string File_Name = "Data/Clients.txt")
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (int i = 0; i < vClients.size(); i++)
		{
			if (vClients[i].CCP_Number() == Client.CCP_Number())
			{
				vClients.erase(vClients.begin() + i);
				break;
			}
		}

		_SaveClientsDataToFile(vClients);
	}


public:

	clsBankClient(enObjectMode Mode, string FirstName, string LastName, string PhoneNumber, string Email
		, string CCP_Number, string PinCode, float Balance) : clsPerson(FirstName, LastName, PhoneNumber, Email)
	{
		_Mode = Mode;
		_CCP_Number = CCP_Number;
		_PinCode = PinCode;
		_Balance = Balance;
	}

	bool IsEmpty()
	{
		return (_Mode == enObjectMode::EmptyMode);
	}

	string CCP_Number()
	{
		return _CCP_Number;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	float GetBalance()
	{
		return _Balance;
	}

	void SetBalance(float Balance)
	{
		_Balance = Balance;
	}

	__declspec(property(get = GetBalance, put = SetBalance)) float Balance;

	void Print()
	{
		cout << endl;
		cout << setw(33) << left << "" << "Client Card :";
		cout << endl;
		cout << setw(33) << left << "" << "___________________";
		cout << endl;
		cout << setw(33) << left << "" << "FirstName   : " << FirstName;
		cout << endl;
		cout << setw(33) << left << "" << "LastName    : " << LastName;
		cout << endl;
		cout << setw(33) << left << "" << "Full Name   : " << FullName();
		cout << endl;
		cout << setw(33) << left << "" << "Email       : " << Email;
		cout << endl;
		cout << setw(33) << left << "" << "Phone       : " << PhoneNumber;
		cout << endl;
		cout << setw(33) << left << "" << "CCP Number : " << _CCP_Number;
		cout << endl;
		cout << setw(33) << left << "" << "Password    : " << _PinCode;
		cout << endl;
		cout << setw(33) << left << "" << "Balance     : " << _Balance;
		cout << endl;
		cout << setw(33) << left << "" << "___________________\n";
	}

	static clsBankClient Find(string CCP_Number)
	{


		fstream MyFile;
		MyFile.open("Data/Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.CCP_Number() == CCP_Number)
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClient();
	}

	static clsBankClient Find(string CCP_Number, string PinCode)
	{

		fstream MyFile;
		MyFile.open("Data/Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if ((Client.CCP_Number() == CCP_Number) && (Client.PinCode == PinCode))
				{
					MyFile.close();
					return Client;
				}

			}

			MyFile.close();

		}

		return _GetEmptyClient();
	}

	static bool IsClientExist(string AccountNumber)
	{

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

	enum enSave_Result {
		SuccessToAdd, SuccessToModify,
		FaildEmpty, FaildCCP_Exist
	};

	enSave_Result Save_Update()
	{

		enObjectMode Mode = this->_Mode;

		switch (Mode)
		{
		case clsBankClient::EmptyMode:
			return enSave_Result::FaildEmpty;
			break;
		case clsBankClient::UpdateMode:
			_Updating_Clients_File();
			return enSave_Result::SuccessToModify;
			break;
		case clsBankClient::AddNewMode:
			if (IsClientExist(this->CCP_Number()))
			{
				return enSave_Result::FaildCCP_Exist;
				break;
			}
			else
			{
				_AddNewLineToClientsFile(*this);

				_Mode = enObjectMode::UpdateMode;
				return enSave_Result::SuccessToAdd;
				break;
			}
		default:
			return enSave_Result::FaildEmpty;
			break;
		}

	}

	static clsBankClient GetNewClient(string CCP_Number1)
	{
		clsBankClient Client(enObjectMode::AddNewMode, "", "", "", "", CCP_Number1, "", 0);
		return Client;
	}

	static void MakeDeleteState(clsBankClient& Client)
	{
		Client._Mode = enObjectMode::DeleteMode;
	}

	void Delete()
	{
		_DeleteClientFromFile(*this);
		*this = _GetEmptyClient();
	}

	static vector<clsBankClient> Clients_List(string FileName = "Data/Clients.txt")
	{
		return _LoadClientsDataFromFile(FileName);
	}

	static int TotalBalances()
	{
		vector<clsBankClient> Vclients = _LoadClientsDataFromFile();

		float TotBal = 0;
		for (clsBankClient Client : Vclients)
		{
			TotBal += Client.Balance;
		}

		return TotBal;
	}
};




