#pragma once

#include<iostream>
#include"clsDate.h"
#include"clsString.h"
#include<regex>

using namespace std;


class clsInputValidation
{

public:

	static bool IsNumberBetween(int Number, int From, int To)
	{
		if (From == To)
		{
			if (Number == To) 
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (From < To)
				return (Number > To || Number < From) ? false : true;
			else
				return (Number > From || Number < To) ? false : true;
		}
		return false;
		
	}
	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (From == To)
		{
			if (Number == To)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (From < To)
				return (Number > To || Number < From) ? false : true;
			else
				return (Number > From || Number < To) ? false : true;
		}

		return false;
	}
	static bool IsDateBetween(clsDate DateToCheck, clsDate Date1, clsDate Date2)
	{
		if (clsDate::CompareDates(Date1, Date2) == clsDate::Equal)
		{
			if (clsDate::CompareDates(DateToCheck, Date2) == clsDate::Equal)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (clsDate::CompareDates(Date1, Date2) == clsDate::Before)
			{
				return (clsDate::CompareDates(DateToCheck, Date1) == clsDate::Before || clsDate::CompareDates(DateToCheck, Date2) == clsDate::After) ? false : true;
			}
			else
			{
				return (clsDate::CompareDates(DateToCheck, Date2) == clsDate::Before || clsDate::CompareDates(DateToCheck, Date1) == clsDate::After) ? false : true;
			}
		}

		return false;
		
	}
	static int ReadIntNumber(string ErrorMsg = "You Did Not Enter An Integer , Try Again : ")
	{
		int Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();           
			cin.ignore(1000, '\n');
			cout << ErrorMsg;
			cin >> Number;
			cout << endl;
		}
		return Number;
	}
	static float ReadFloatNumber(string ErrorMsg = "You Did Not Enter A Float , Try Again : ")
	{
		float Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << ErrorMsg;
			cin >> Number;
			cout << endl;
		}
		return Number;
	}
	static double ReadDoubleNumber(string ErrorMsg = "You Did Not Enter A Double , Try Again : ")
	{
		double Number;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << ErrorMsg;
			cin >> Number;
			cout << endl;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMsg = "Number is not within range, Enter again : ")
	{
		int Number;
		Number = ReadIntNumber(" You Did Not Enter An Integer , Retry : ");
		while (!IsNumberBetween(Number, From, To))
		{
			cin.clear();
			cout << ErrorMsg;
			Number = ReadIntNumber(" You Did Not Enter An Integer , Retry : ");
			cout << endl;
		}
		return Number;
	}
	static double ReadDoubleNumberBetween(double From, double To, string ErrorMsg = "Number is not within range, Enter again : ")
	{
		double Number;
		Number = ReadDoubleNumber(" You Did Not Enter A Double , Retry : ");
		while (!IsNumberBetween(Number, From, To))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << ErrorMsg;
			cin >> Number;
			cout << endl;
		}
		return Number;
	}
	static string ReadString()
	{
		string St;
		getline(cin >> ws, St);
		return St;
	}

	static string ReadTrimedString()
	{
		string St;
		getline(cin >> ws, St);
		return clsString::Trim(St);
	}

	static char ReadChar(string errormsg = " Failed To Enter A character , Retry : ")
	{
		char St;
		cin >> St;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << errormsg;
			cin >> St;
			cout << endl;
		}
		return St;
	}
	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

	static bool isValidEmail(string email)
	{
		const regex pattern(
			R"(^[a-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)"
		);
		return (regex_match(email, pattern) ? true : false) ;
	}

	static bool isValidPhoneNumber(string PhoneNumber)
	{
		const regex pattern(
			R"(^0[5-7][0-9]{8}$)"
		);
		return (regex_match(PhoneNumber, pattern) ? true : false);
	}

	static bool isValidPinCode(string PinCode)
	{
		const regex pattern(
			R"(^[0-9]{4}$)"
		);
		return (regex_match(PinCode, pattern) ? true : false);
	}

	static bool isValid6DigitsPassword(string Password)
	{
		const regex pattern(
			R"(^[A-Za-z0-9._%+-]{6}$)"
		);
		return (regex_match(Password, pattern) ? true : false);
	}

	static bool isValidCcp_Number(string Password)
	{
		const regex pattern(
			R"(^00799999[0-9]{12}$)"
		);
		return (regex_match(Password, pattern) ? true : false);
	}
};

