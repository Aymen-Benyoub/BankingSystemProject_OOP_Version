#pragma once
#include<iostream>
#include"../Core Classes/clsBankUser.h"
#include"../Libraries/clsDate.h"
#include<fstream>
#include<string>
#include<vector>
#include"../Screen Classes/clsScreen.h"
#include<iomanip>
using namespace std;


class clsRegisterLogins : protected clsScreen
{
private:
	string _UserName;
	string _Date;
	string _Time;
	string _Password;
	int _Permissions;

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
	static string _GetSystemTime()
	{
		time_t now = time(0);
		tm* t = localtime(&now);

		return to_string(t->tm_hour) + ":" +
			to_string(t->tm_min) + ":" +
			to_string(t->tm_sec);
	}
	static string _RegisterLoginLine(clsRegisterLogins User, string Separator = " || ")
	{
		return User._UserName + Separator + _EncryptText(User._Password, 2) + Separator + to_string(User._Permissions) + Separator + User._Date + Separator + User._Time;
	}

	static  void _AddNewLineToRegisterFile(clsRegisterLogins User, string File_Name = "Data/LoginRegister.txt")
	{

		fstream MyFile;
		MyFile.open("Data/LoginRegister.txt", ios::out | ios::app);

		string DataLine;

		if (MyFile.is_open())
		{

			DataLine = _RegisterLoginLine(User);
			MyFile << DataLine << endl;
			MyFile.close();

		}

	}

	static void PrintUserRecordLine(clsRegisterLogins User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << _DecryptText(User.Password, 2);
		cout << "| " << setw(12) << left << User.Permissions;
		cout << "| " << setw(25) << left << User.Time;
		cout << "| " << setw(12) << right << fixed << setprecision(2) << User.Date;
	}

	static clsRegisterLogins _ConvertLinetoRegisterObject(string Line)
	{
		vector <string> V1 = clsString::Split_String(Line, " || ");

		return clsRegisterLogins(V1[0], V1[1], stoi(V1[2]), V1[3], V1[4]);
	}

	static  vector <clsRegisterLogins> _LoadUsersLoggedDataFromFile(string File_Name = "Data/LoginRegister.txt")
	{

		vector <clsRegisterLogins> vUsers;

		fstream MyFile;
		MyFile.open(File_Name, ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsRegisterLogins User = _ConvertLinetoRegisterObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}




public:

	clsRegisterLogins(string UserName, string Password, int Permissions)
	{
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		clsDate Date = clsDate::GetSystemDate();
		_Date = to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
		_Time = _GetSystemTime();

	}

	clsRegisterLogins(string UserName, string Password, int Permissions, string Date, string Time)
	{
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
		_Date = Date;
		_Time = Time;

	}
	void Register_Login()
	{
		_AddNewLineToRegisterFile(*this);
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

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

	static vector<clsRegisterLogins> Users_List()
	{
		return _LoadUsersLoggedDataFromFile();
	}

	static void ShowRegisterList()
	{
		vector <clsRegisterLogins> vUsers = clsRegisterLogins::Users_List();

		string Subtitle = "        There Are (" + to_string(vUsers.size()) + ") Logins";
		_DrawHeader("Login Register List", Subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(15) << left << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "| " << left << setw(25) << "Time";
		cout << "| " << right << setw(12) << "Date";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;

		if (vUsers.size() == 0)
			cout << "\t\t\t\t      No Registers Yet In the System!";
		else
			for (clsRegisterLogins User : vUsers)
			{
				PrintUserRecordLine(User);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "___________________________________________________\n" << endl;
	}
};



