#pragma once 
#include<iomanip> 
#include<iostream>
#include"../Core Classes/clsGlobal.h"

using namespace std;
class clsScreen
{
protected:
    static void _DrawHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t=====================================";
        cout << "\n\t\t\t\t\t\t" << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t" << SubTitle;
        }
        cout << "\n\t\t\t\t\t=====================================\n";


    }

    static void _Access_Denied()
    {
        system("cls");
        _DrawHeader("ALGERIAN NATIONAL BANK");
        cout << setw(25) << left << " " << "=========================================================================\n";
        cout << setw(25) << left << " " << "[*] You Do Not Have The Access To Do This Choice , Contact Your Admin ... \n";
        cout << setw(25) << left << " " << "=========================================================================\n";
    }
    static void _Algerian_Bank_Banner()
    {
        clsDate Today = clsDate::GetSystemDate();
        string TodayDate = to_string(Today.Day) + "/" + to_string(Today.Month) + "/" + to_string(Today.Year);

        cout << endl;
        cout << setw(37) << left << " " << "=============================================";
        cout << endl;
        cout << setw(37) << left << " " << "          A L G E R I A N   B A N K";
        cout << endl;
        cout << setw(37) << left << " " << "---------------------------------------------";
        cout << endl;
        cout << setw(37) << left << " " << " User : " << CurrentUser.UserName << "       |    Date : " << TodayDate;
        cout << endl;
        cout << setw(37) << left << " " << "=============================================\n\n";
    }

};
