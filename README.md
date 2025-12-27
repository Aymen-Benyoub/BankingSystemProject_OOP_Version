# Algerian National Bank Management System

A comprehensive desktop banking application developed in **C++** using **Object-Oriented Programming (OOP)** principles.

---

## 🎯 Key Features

### Core Banking Operations
- **Client Management**: Add, view, update, and delete client accounts
- **Deposit & Withdrawal**: Process deposits and withdrawals with balance validation
- **Money Transfer**: Transfer funds between client accounts
- **Balance Inquiry**: View client balances and account details

### User Management
- **User Accounts**: Create and manage bank staff accounts with secure password encryption
- **Role-Based Access Control**: 8 different permission types:
  - List Clients
  - Add New Clients
  - Delete Clients
  - Update Clients
  - Find Clients
  - Process Transactions
  - Manage Users
  - View Login Register

### Currency Exchange
- **Multi-Currency Support**: View exchange rates for multiple currencies
- **Currency Conversion**: Calculate conversions between different currencies
- **Rate Management**: Update exchange rates

### Transaction History & Logging
- **Login Register**: Track all user login activities
- **Transfer Register**: Record all money transfers between accounts

---

## 📸 Project Screenshots

### Login Screen
![Login Screen](Screenshots/Login.png)
*Enter with default credentials: Admin / 1111*

### Main Menu
![Main Menu](Screenshots/Menu.png)

### Client Management

![Clients List](Screenshots/ClientList.png)

### Transaction Operations
![Deposit Screen](Screenshots/Deposit.png)

![Withdraw Screen](Screenshots/Withdraw.png)

### User Management
![Users Screen](Screenshots/Users.png)

![Users List](Screenshots/UsersList.png)

### Currency Exchange
![Currency Menu](Screenshots/CurrencyExchange.png)

---

## 🚀 Quick Start Guide

### First Login
```
Username: Admin
Password: 1111
```

The Admin account has **full permissions** and can access all features:
- ✅ Manage all clients
- ✅ Process all transactions
- ✅ Manage all users
- ✅ View activity logs
- ✅ Manage currency exchange

### Main Menu Options
1. Show All Clients
2. Add New Client
3. Delete Client
4. Update Client
5. Find Client
6. Transactions
7. Manage Users
8. Login Register
9. Logout
10. Currency Exchange
11. Exit

### Create Your Own Admin Account
1. Login as Admin
2. Go to "Manage Users" → "Add New User"
3. Create a new account
4. Give it full access
5. Use this account for future logins

---

## 🔐 Default Credentials

### Admin Account
```
Username: Admin
Password: 1111
Permissions: Full Access
```

### Creating New Users

**Permission Flags:**
- `pListClients = 1` - View client list
- `pAddNewClient = 2` - Create new clients
- `pDeleteClient = 4` - Delete clients
- `pUpdateClients = 8` - Modify client information
- `pFindClient = 16` - Search for clients
- `pTransactions = 32` - Process deposits/withdrawals/transfers
- `pManageUsers = 64` - Create/edit/delete users
- `pShowLoginReg = 128` - View login history

**Example Combinations:**
- Full Access: `-1` (Admin)
- Transaction Officer: `1 + 2 + 8 + 16 + 32 = 59`
- Customer Service: `1 + 16 = 17`

---

## 🏗️ Architecture

### Core Classes
- `clsBankClient` - Client data management
- `clsBankUser` - User accounts and permissions
- `clsCurrency` - Currency data and rates
- `clsRegisterLogins` - Login tracking
- `clsRegisterTransfer` - Transfer logging

### Screen Classes
- `clsScreen` - Base UI class
- `clsAddNewClientScreen` - Add clients
- `clsShowAllClientsScreen` - View clients
- `clsDepositScreen` - Deposit transactions
- `clsWithdrawScreen` - Withdrawal transactions
- `clsTransferScreen` - Money transfers
- `clsMainMenu` - Main navigation
- `clsManageUsersMenu` - User management
- `clsCurrencyExchangeMenu` - Currency operations

### Supporting Libraries
- `clsInputValidation` - Input validation with regex
- `clsString` - String utilities
- `clsDate` - Date operations
- `clsPerson` - Base person class

---

## 🔐 Security Features

### Authentication
- Username and password verification
- 3-attempt login limit
- Password encryption (XOR key=3)
- PIN encryption (XOR key=4)

### Data Protection
- Encrypted data storage
- File-based persistence
- Confirmation dialogs for critical operations

---

## 💾 Data Storage

Files used for data persistence:
- `Data/Clients.txt` - Client accounts
- `Data/Users.txt` - User accounts
- `Data/Currencies.txt` - Currency data
- `Data/LoginRegister.txt` - Login logs
- `Data/TransferRegister.txt` - Transfer logs

---

## ✅ Input Validation

Comprehensive validation using Regular Expressions:

```
CCP Number:  00799999[0-9]{12}
Phone:       0[4-7][0-9]{8} (Algerian format)
Email:       standard email format
PIN Code:    [0-9]{4}
Password:    [A-Za-z0-9._%+-]{6}
```

---

## 📋 Technical Stack

- **Language**: C++
- **Paradigm**: Object-Oriented Programming
- **Storage**: File-based (Text files)
- **UI**: Console-based
- **Validation**: Regular Expressions

---

## 🚀 System Requirements

- C++ Compiler (C++11 or later)
- Windows, Linux, or macOS
- 512 MB RAM
- 10 MB disk space

---

## 📥 Installation & Compilation

### Clone the Repository
```bash
git clone https://github.com/YOUR_USERNAME/algerian-bank-system.git
cd algerian-bank-system
```

### Compile

**Linux/macOS:**
```bash
g++ -std=c++11 -o bank_system main.cpp
```

**Windows (MinGW):**
```bash
g++ -std=c++11 -o bank_system.exe main.cpp
```

**Windows (MSVC):**
```bash
cl /std:latest main.cpp
```

### Run
```bash
./bank_system          # Linux/macOS
bank_system.exe        # Windows
```

### First Login
```
Username: Admin
Password: 1111
```

---

## 📊 Example Usage

### Add a New Client
1. Login as Admin
2. Main Menu → Option 2 (Add New Client)
3. Enter CCP Number, name, phone, email, PIN, balance
4. System validates and saves client

### Process a Deposit
1. Main Menu → Option 6 (Transactions)
2. Transactions Menu → Option 1 (Deposit)
3. Enter client CCP number
4. Confirm amount
5. Balance updated

### Create a User Account
1. Main Menu → Option 7 (Manage Users)
2. Users Menu → Option 2 (Add New User)
3. Enter username and personal details
4. Set permissions
5. User created and ready to login

---

## 📝 Future Enhancements

- Database backend (SQL/MySQL)
- GUI interface (Qt/Windows Forms)
- Advanced encryption (AES, RSA)
- Transaction reports and analytics
- Mobile app integration
- REST API
- Loan management
- Interest calculations
- PDF reports

---

## 📄 License

Open-source for educational purposes.

---

## 👨‍💻 Author

**Aymen Benyoub**

---
