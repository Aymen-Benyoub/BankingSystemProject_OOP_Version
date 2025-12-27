#pragma once
#include<iostream>
#include"../Libraries/clsPerson.h"
#include"../Libraries/clsString.h"
#include<fstream>
#include<string>
#include<vector>
#include<iomanip>



class clsBankUser : public clsPerson
{

private:

	enum enObjectMode { EmptyMode, UpdateMode, AddNewMode, DeleteMode };

	string _UserName;
	enObjectMode _Mode;
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

	static clsBankUser _GetAdmin()
	{
		return clsBankUser(enObjectMode::AddNewMode, " ", " ", " ", " ", "Admin", "1111", -1);
	}

	static clsBankUser _ConvertLinetoUserObject(string Line)
	{
		vector <string> V1 = clsString::Split_String(Line, " || ");

		return clsBankUser(enObjectMode::UpdateMode, V1[0], V1[1], V1[2], V1[3], V1[4], _DecryptText(V1[5], 3), stoi(V1[6]));
	}

	static string _ConvertUserObjectToLine(clsBankUser User, string Seperator = " || ")
	{

		string stUserRecord = "";
		stUserRecord += User.FirstName + Seperator;
		stUserRecord += User.LastName + Seperator;
		stUserRecord += User.PhoneNumber + Seperator;
		stUserRecord += User.Email + Seperator;
		stUserRecord += User.UserName + Seperator;
		stUserRecord += _EncryptText(User.Password, 3) + Seperator;
		stUserRecord += to_string(User.Permissions);

		return stUserRecord;

	}

	static clsBankUser _GetEmptyUser()
	{
		return clsBankUser(enObjectMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static  vector <clsBankUser> _LoadUsersDataFromFile(string File_Name = "Data/Users.txt")
	{

		vector <clsBankUser> vUsers;

		fstream MyFile;
		MyFile.open(File_Name, ios::in);

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBankUser User = _ConvertLinetoUserObject(Line);

				vUsers.push_back(User);
			}

			MyFile.close();

		}

		return vUsers;

	}

	static  void _SaveUsersDataToFile(vector<clsBankUser> V1, string File_Name = "Data/Users.txt")
	{

		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsBankUser C : V1)
			{
				DataLine = _ConvertUserObjectToLine(C);
				MyFile << DataLine << endl;

			}

			MyFile.close();

		}

	}

	void _Updating_Users_File()
	{
		vector <clsBankUser> vUsers = _LoadUsersDataFromFile();

		for (clsBankUser& User : vUsers)
		{
			if (User.UserName == UserName)
			{
				User = *this;
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}

	static  void _AddNewLineToUsersFile(clsBankUser User, string File_Name = "Data/Users.txt")
	{

		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::out | ios::app);

		string DataLine;

		if (MyFile.is_open())
		{

			DataLine = _ConvertUserObjectToLine(User);
			MyFile << DataLine << endl;
			MyFile.close();

		}

	}

	static void _DeleteUserFromFile(clsBankUser User, string File_Name = "Data/Users.txt")
	{
		vector <clsBankUser> vUsers = _LoadUsersDataFromFile();

		for (int i = 0; i < vUsers.size(); i++)
		{
			if (vUsers[i].UserName == User.UserName)
			{
				vUsers.erase(vUsers.begin() + i);
				break;
			}
		}

		_SaveUsersDataToFile(vUsers);
	}


public:

	enum enPermissions {
		pAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pShowLoginReg = 128
	};

	clsBankUser(enObjectMode Mode, string FirstName, string LastName, string PhoneNumber, string Email
		, string UserName, string Password, int Permissions) : clsPerson(FirstName, LastName, PhoneNumber, Email)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	bool IsEmpty()
	{
		return (_Mode == enObjectMode::EmptyMode);
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

	void Print()
	{
		cout << endl;
		cout << setw(33) << left << "" << "User Card :";
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
		cout << setw(33) << left << "" << "UserName    : " << _UserName;
		cout << endl;
		cout << setw(33) << left << "" << "Password    : " << _Password;
		cout << endl;
		cout << setw(33) << left << "" << "Permissions : " << _Permissions;
		cout << endl;
		cout << setw(33) << left << "" << "___________________\n";
	}

	static clsBankUser Find(string UserName)
	{


		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUser User = _ConvertLinetoUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUser();
	}

	static clsBankUser Find(string UserName, string Password)
	{

		fstream MyFile;
		MyFile.open("Data/Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankUser User = _ConvertLinetoUserObject(Line);
				if ((User.UserName == UserName) && (User.Password == Password))
				{
					MyFile.close();
					return User;
				}

			}

			MyFile.close();

		}

		return _GetEmptyUser();
	}

	static bool IsUserExist(string UserName)
	{

		clsBankUser User1 = clsBankUser::Find(UserName);

		return (!User1.IsEmpty());
	}

	enum enSave_Result {
		SuccessToAdd, SuccessToModify,
		FaildEmpty, FaildUserName_Exist
	};

	enSave_Result Save_Update()
	{

		enObjectMode Mode = this->_Mode;

		switch (Mode)
		{
		case clsBankUser::EmptyMode:
			return enSave_Result::FaildEmpty;
			break;
		case clsBankUser::UpdateMode:
			_Updating_Users_File();
			return enSave_Result::SuccessToModify;
			break;
		case clsBankUser::AddNewMode:
			if (IsUserExist(this->UserName))
			{
				return enSave_Result::FaildUserName_Exist;
				break;
			}
			else
			{
				_AddNewLineToUsersFile(*this);

				_Mode = enObjectMode::UpdateMode;
				return enSave_Result::SuccessToAdd;
				break;
			}
		default:
			return enSave_Result::FaildEmpty;
			break;
		}

	}

	static clsBankUser GetNewUser(string UserName1)
	{
		clsBankUser User(enObjectMode::AddNewMode, "", "", "", "", UserName1, "", 0);
		return User;
	}

	static void MakeDeleteState(clsBankUser& User)
	{
		User._Mode = enObjectMode::DeleteMode;
	}

	void Delete()
	{
		_DeleteUserFromFile(*this);
		*this = _GetEmptyUser();
	}

	static vector<clsBankUser> Users_List(string FileName = "Data/Users.txt")
	{
		return _LoadUsersDataFromFile(FileName);
	}

	static clsBankUser GetAdmin()
	{
		return _GetAdmin();
	}

};






