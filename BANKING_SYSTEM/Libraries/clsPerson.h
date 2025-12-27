#pragma once

#include<iostream>
using namespace std;

class clsPerson
{
private:

    string _FirstName;
    string _LastName;
    string _PhoneNumber;
    string _Email;

public:

    clsPerson(string FirstName, string LastName, string PhoneNumber, string Email)
    {
        _FirstName = FirstName;
        _LastName = LastName;
        _PhoneNumber = PhoneNumber;
        _Email = Email;
    }

    string GetFirstName()
    {
        return _FirstName;
    }

    string GetLastName()
    {
        return _LastName;
    }

    string GetPhoneNumber()
    {
        return _PhoneNumber;
    }

    string GetEmail()
    {
        return _Email;
    }

    void SetFirstName(string FirstName)
    {
        _FirstName = FirstName;
    }

    void SetLastName(string LastName)
    {
        _LastName = LastName;
    }

    void SetPhoneNumber(string PhoneNumber)
    {
        _PhoneNumber = PhoneNumber;
    }

    void SetEmail(string Email)
    {
        _Email = Email;
    }

    __declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

    __declspec(property(get = GetLastName, put = SetLastName)) string LastName;

    __declspec(property(get = GetPhoneNumber, put = SetPhoneNumber)) string PhoneNumber;

    __declspec(property(get = GetEmail, put = SetEmail)) string Email;

    string FullName()
    {
        return _FirstName + " " + _LastName;
    }

    void Print()
    {
        cout << "===================================" << endl;
        cout << " First Name  : " << _FirstName << endl;
        cout << " Last Name  : " << _LastName << endl;
        cout << " Phone Number  : " << _PhoneNumber << endl;
        cout << " Email  : " << _Email << endl;
        cout << "===================================" << endl;
    }

    void SendSMS(string Message)
    {
        cout << "===========================================" << endl;
        cout << " Sending SMS To Phone : " << _PhoneNumber << endl;
        cout << "===========================================" << endl;

        cout << " The Message [ " << Message << " ] Is Successfully Sent As An SMS To The Above Phone Number" << endl;

    }

    void SendEmail(string Subject, string Message)
    {
        cout << "====================================================" << endl;
        cout << " Sending Mail To The Email  : " << _Email << endl;
        cout << "====================================================" << endl;

        cout << " The Mail Subject Is : " << Subject << endl;

        cout << " The Message [ " << Message << " ] Is Successfully Sent As An Mail To The Above Email" << endl;
    }
};


