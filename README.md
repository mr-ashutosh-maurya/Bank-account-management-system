
## 🏦 Bank Account Management System

* A **C++ console-based banking application** that allows users to manage bank accounts, perform transactions, and securely log in or register.
* It demonstrates strong use of **Object-Oriented Programming (OOP)** and **Data Structure & Algorithm (DSA)** concepts in a real-world context.
* It provides all basic banking operations like **account creation, deposit, withdrawal, balance inquiry, interest addition, transaction tracking, and data export.**

## 📋 Features

### 🔐 User Management

* Secure **Login** and **Registration** system using `users.txt` for credential storage
* Prevents duplicate usernames
* Automatically loads and saves user data

### 🏦 Banking Operations

* Create and manage multiple bank accounts
* Deposit and withdraw money
* Check account balance
* Edit account holder name
* Delete (close) accounts
* View transaction history
* Add interest to all accounts
* Export all account data to a CSV file (`accounts.csv`)

### 💾 File Handling

* User data stored in **`users.txt`**
* Account data exported to **`accounts.csv`**

---

## 🧠 DSA and OOP Concepts Used

| Concept                         | Description                                                                                      | Where It’s Used                                                |
| ------------------------------- | ------------------------------------------------------------------------------------------------ | -------------------------------------------------------------- |
| **Class & Object (OOP)**        | Encapsulates data and functions in logical units                                                 | Classes `UserSystem`, `Account`, `Bank`                        |
| **Encapsulation**               | Data (like balance, username) is hidden and accessed only through member functions               | Private members with public getters/setters                    |
| **Abstraction**                 | Complex operations (like file saving or transaction history) are hidden behind simple interfaces | Functions like `deposit()`, `withdraw()`, `exportDataToFile()` |
| **Polymorphism (Compile-time)** | Same function names used for different data operations                                           | Function overloading-like behavior in account actions          |
| **File Handling**               | Stores user credentials and exports account data                                                 | `ifstream`, `ofstream` used in `users.txt` and `accounts.csv`  |
| **STL Vector**                  | Used to store multiple accounts and transaction histories dynamically                            | `vector<Account> accounts`, `vector<string> trnxhistory`       |
| **STL Map**                     | Stores username-password pairs for fast lookup                                                   | `map<string, string> users`                                    |
| **Looping & Searching**         | Finds and manages accounts efficiently                                                           | For loops used in search and transaction operations            |
| **Data Formatting**             | Uses precision control for currency values                                                       | `<iomanip>` with `setprecision(2)`                             |
| **Condition Handling**          | Prevents invalid inputs and operations                                                           | Input checks in `deposit()`, `withdraw()`, etc.                |

---

## 🧩 Code Structure

| Component         | Description                                             |
| ----------------- | ------------------------------------------------------- |
| **`UserSystem`**  | Handles login, registration, and authentication         |
| **`Account`**     | Represents a bank account (ID, name, balance, history)  |
| **`Bank`**        | Manages all accounts and performs banking operations    |
| **`loginMenu()`** | Displays and handles user login/register menu           |
| **`main_menu()`** | Displays main banking menu                              |
| **`main()`**      | Entry point – ensures secure login before system access |

---

## 🧠 How It Works

1. **Login or Register**
   Users must authenticate before using the system.
   Credentials are saved in `users.txt`.

2. **Main Menu Options**

```
--------------------------------------------------------------
|             BANK ACCOUNT MANAGEMENT SYSTEM                  |
--------------------------------------------------------------
1. Create New Account.        2. Show All Accounts.
3. Search Account.            4. Deposit Money.
5. Withdraw Money.            6. Balance Enquiry.
7. Transaction history.       8. Edit Acc. Holder Name.
9. Close Account.             10. Add Interest.
11. Export Data.              12. Clear the screen.
13. Main menu.                14. Exit.
```

3. **Transactions**

   * Each deposit or withdrawal is saved in transaction history.
   * Balances are automatically updated and shown with two decimals.

4. **Export Data**

   * All account details can be exported to `accounts.csv`.

---

## 💾 Example Outputs

### **users.txt**

```
admin admin123
john johnpass
```

### **accounts.csv**

```
Account number,Name,Balance
1001,John,12500.75
1002,Mary,10500.00
```

---

## ⚙️ Requirements

* **C++ Compiler** (e.g., g++, MinGW, or Visual Studio)
* **Windows OS** (uses `<conio.h>` and `system("cls")`)

---

## 🚀 How to Run

1. **Compile the code**

   ```bash
   g++ bms.cpp -o bankSystem
   ```

2. **Run the program**

   ```bash
   ./bankSystem
   ```

3. **Follow the menu instructions**

---

## 🧱 Future Improvements

* Store account data persistently between sessions
* Encrypt user passwords for better security
* Add admin panel for full user control
* Build a graphical interface (GUI)
* Include advanced search and filtering features

---

## 🧑‍💻 Author

* **Created by:** *Ashutosh Maurya*
* **Project:** Bank Management System (BMS)
* **Language:** C++
* **Concepts Demonstrated:** *OOP, Encapsulation, Polymorphism, STL, File Handling*

---
