#pragma once

#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Word;

	bool Have_Punc(const string& S1)
	{
		if (S1.empty()) return false;
		for (char c : S1)
		{
			if (ispunct(c)) return true;
		}
		return false;
	}

public:

	clsString()
	{
		_Word = "";
	}

	clsString(string _Word)
	{
		this->_Word = _Word;
	}

	void SetWordValue(string Word)
	{
		_Word = Word;
	}

	string GetWordValue()
	{
		return _Word;
	}

	__declspec(property(get = GetWordValue, put = SetWordValue)) string Word;

	static short Length(string S1)
	{
		return S1.length();
	};

	short Length()
	{
		return _Word.length();
	};

	static void PrintFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string: \n";
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
			{
				cout << S1[i] << endl;
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}

	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Word);
	}

	static string Upper_Letters_in_First_Of_each_word(string S1)
	{
		bool Y = true;
		for (int I = 0; I < S1.length(); I++)
		{
			if (S1[I] != ' ' && Y == true)
			{
				S1[I] = toupper(S1[I]);
			}

			Y = (S1[I] == ' ' ? true : false);
		}

		return S1;
	}

	void Upper_Letters_in_First_Of_each_word()
	{
		_Word = Upper_Letters_in_First_Of_each_word(_Word);
	}

	static string Lower_Letters_in_First_Of_each_word(string S1)
	{
		bool Y = true;
		for (int I = 0; I < S1.length(); I++)
		{
			if (S1[I] != ' ' && Y == true)
			{
				S1[I] = tolower(S1[I]);
			}

			Y = (S1[I] == ' ' ? true : false);
		}

		return S1;

	}

	void Lower_Letters_in_First_Of_each_word()
	{
		_Word = Lower_Letters_in_First_Of_each_word(_Word);
	}

	static string Lower_str(string S1)
	{
		for (int I = 0; I < S1.length(); I++)
		{
			S1[I] = tolower(S1[I]);
		}

		return S1;
	}

	static string Upper_str(string S1)
	{
		for (int I = 0; I < S1.length(); I++)
		{
			S1[I] = toupper(S1[I]);
		}

		return S1;
	}

	void Lower_str()
	{
		_Word =  Lower_str(_Word);

	}

	void  Upper_str()
	{
		_Word = Upper_str(_Word);
	}

	static string Invert_Str(string S)
	{
		for (int I = 0; I < S.length(); I++)
		{
			S[I] = (isupper(S[I]) ? tolower(S[I]) : toupper(S[I]));
		}

		return S;
	}

	void Invert_Str()
	{
		_Word =  Invert_Str(_Word);
	}

	static void Count_Capital_And_Small_Letters(string S1, int& Capital, int& Small)
	{
		Capital = 0;
		Small = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Capital++;
			}
			else if (islower(S1[i]))
			{
				Small++;
			}
		}
	}

	void Count_Capital_And_Small_Letters(int& Capital, int& Small)
	{
		Count_Capital_And_Small_Letters(_Word, Capital, Small);
	}

	static int CountLetterOcc(string S1, char Chr)
	{

		int Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] == Chr)
			{
				Count++;
			}
		}
		return Count;
	}

	int CountLetterOcc(char Chr)
	{
		return CountLetterOcc(_Word, Chr);
	}

	static int CountLetterOccMatch(string S1, char Chr)
	{

		int Count = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (toupper(S1[i]) == toupper(Chr))
			{
				Count++;
			}
		}
		return Count;
	}

	int CountLetterOccMatch(char Chr)
	{
		return CountLetterOccMatch(_Word, Chr);
	}


	static int Count_Vowels(string S1)
	{
		int Cpt = 0;
		char Chr;
		for (int I = 0; I < S1.length(); I++)
		{
			Chr = tolower(S1[I]);

			if (IsVowel(S1[I]))
			{
				Cpt++;
			}
		}
		return Cpt;
	}

	int Count_Vowels()
	{
		return Count_Vowels(_Word);
	}

	static void Print_Vowels(string S1)
	{

		char Chr;
		for (int I = 0; I < S1.length(); I++)
		{
			Chr = tolower(S1[I]);

			if ((Chr == 'a') || (Chr == 'e') || (Chr == 'i') || (Chr == 'o') || (Chr == 'u'))
			{
				cout << Chr << " ";
			}
		}

		cout << endl;
	}

	void Print_Vowels()
	{
		Print_Vowels(_Word);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " ";
		cout << " Your string wrords are : ";
		short pos = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length());

		}
		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Word);
	}

	static int CountEachWordInString(string S1)
	{
		string delim = " ";

		int pos = 0;
		short Cpt = 0;
		string sWord;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Cpt++;
			}
			S1.erase(0, pos + delim.length());

		}
		if (S1 != "")
		{
			Cpt++;
		}

		return Cpt;
	}

	int CountEachWordInString()
	{
		return CountEachWordInString(_Word);
	}

	static vector <string> Split_String(string S1, string Delimiter)
	{
		string delim = Delimiter;
		short pos = 0;
		string sWord;
		vector <string> V1;

		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				V1.push_back(sWord);
			}
			S1.erase(0, pos + delim.length());

		}
		if (S1 != "")
		{
			V1.push_back(S1);
		}

		return V1;

	}

	vector <string> Split_String( string Delimiter)
	{
		return Split_String(_Word, Delimiter);
	}

	static string Trim_Right(string S1)
	{
		bool Is_Space = true;
		int Length = S1.length() - 1;
		while (Is_Space && !S1.empty())
		{
			Length = S1.length() - 1;

			if (S1[Length] == ' ')
			{
				S1.erase(Length, 1);
			}
			else
			{
				Is_Space = false;
			}

		}

		return S1;
	}

	void Trim_Right()
	{
		_Word = Trim_Right(_Word);
	}

	static string Trim_Left(string S1)
	{
		bool Is_Space = true;
		int Length = 0;
		while (Is_Space && !S1.empty())
		{
			if (S1[Length] == ' ')
			{
				S1.erase(Length, 1);
			}
			else
			{
				Is_Space = false;
			}
		}

		return S1;
	}

	void Trim_Left()
	{
		_Word = Trim_Left(_Word);
	}

	static string Trim(string S1)
	{
		string word = Trim_Left(S1);
		return Trim_Right(word);
	}

	void Trim()
	{
		_Word = Trim_Left(_Word);
		_Word = Trim_Right(_Word);
	}

	static string ReverseWordsInString(string S1)
	{
		vector<string> vString;
		string S2 = "";
		vString = Split_String(S1, " ");
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		S2 = S2.substr(0, S2.length() - 1);
		return S2;
	}

	void ReverseWordsInString()
	{
		_Word = ReverseWordsInString(_Word);
	}


	string Remove_Punc(string S1)
	{
		int I = 0;
		while (Have_Punc(S1))
		{
			if (ispunct(S1[I]))
			{
				S1.erase(I, 1);
				I--;
			}

			I++;
		}

		return S1;
	}
	void Remove_Punc()
	{
		_Word = Remove_Punc(_Word);
	}

	static string JoinString(vector<string> vString, string Delim)
	{

		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo)
	{

		vector<string> vString = Split_String(S1, " ");

		for (string& s : vString)
		{
				if (s == StringToReplace)
				{
					s = sRepalceTo;
				}
		}

		return JoinString(vString, " ");
	}

	string ReplaceWord(string StringToReplace, string sRepalceTo)
	{
		return ReplaceWord(_Word, StringToReplace, sRepalceTo);
	}

	static bool IsVowel(char Ch1)
	{
		Ch1 = tolower(Ch1);

		return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}

	static char  InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

};

