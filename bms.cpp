#include <iostream> //for input output
#include <vector>   //for vector implementation
#include <string>   //for string implementation
#include <fstream>  //for file handling
#include <iomanip>  //for prcision of the double value
#include <map>      //for storing user name and password together
#include <limits>   //to find miinimum and maximum value
#include<conio.h>   // for the use of direct input using getch()
using namespace std;
class UserSystem {
private:
    map<string, string> users; // Store username-password pairs

    void loadUsers() {
        ifstream file("users.txt");
        if (!file) {
            return; // No file exists yet
        }
        string username, password;
        while (file >> username >> password) {
            users[username] = password;
        }
        file.close();
    }

    void saveUsers() {
        ofstream file("users.txt");
        if (!file) {
            cout << "Failed to save user data.\n";
            return;
        }
        for (auto &user : users) {
            file << user.first << " " << user.second << "\n";
        }
        file.close();
    }

public:
    UserSystem() {
        loadUsers();
    }

    bool login() {
        string username, password;
        cout << "\t\tEnter username: ";
        cin >> username;
        cout << "\t\tEnter password: ";
        cin >> password;

        if (users.find(username) != users.end() && users[username] == password) {
            cout << "\t\tLogin successful! Welcome " << username << ".\n";
            return true;
        } else {
            cout << "\t\tInvalid username or password. Try again.\n";
            return false;
        }
    }

    void registerUser() {
        string username, password;
        cout << "\t\tEnter a new username: ";
        cin >> username;

        if (users.find(username) != users.end()) {
            cout << "\t\tUsername already exists. Please try another.\n";
            return;
        }

        cout << "\t\tEnter a password: ";
        cin >> password;
        users[username] = password;
        saveUsers();
        cout << "\t\tRegistration successful! You can now login.\n";
    }
};

void loginMenu(UserSystem &userSystem) {
    char choice;
    do {
        cout << "\t\t------------------------------------------------\n";  
        cout << "\t\t|                   LOGIN SYSTEM               |\n";
        cout << "\t\t------------------------------------------------\n"; 
        cout << "\t\t| 1. Login                                     |\n";
        cout << "\t\t| 2. Register                                  |\n";
        cout << "\t\t| 3. Exit                                      |\n";
        cout << "\t\t------------------------------------------------\n"; 
        cout << "\t\tEnter your choice: ";
        cout<<(choice=getch())<<endl;
        

        switch (choice) {
            case '1':
                if (userSystem.login()) {
                    return; // Login successful, exit login menu
                }
                break;
            case '2':
                userSystem.registerUser();
                break;
            case '3':
                exit(0); // Exit the program
            default:
                cout << "\t\tInvalid choice. Try again.\n";
        }
    } while (true);
}

class Account {
private:
    int accNumber;
    string name;
    double balance;
    vector<string>trnxhistory;

public:
    Account(int accNo, string accName, double initialBalance) {
        accNumber = accNo;
        name = accName;
        balance = initialBalance;
        trnxhistory.push_back("\nAccount created with initial balance :" + to_string(initialBalance));
    }

    int getAccountNumber() {
        return accNumber;
    }

    std::string getName() {
        return name;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Invalid amount. Deposit failed!\n";
            return;
        }
        balance += amount;
        std::cout << "Deposit successful. New Balance: " <<std::fixed<<std::setprecision(2)<< balance << std::endl;
        trnxhistory.push_back("deposited :" + std::to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            std::cout << "Invalid or Insufficient Funds. Withdrawal failed.\n";
            return;
        }
        balance -= amount;
        std::cout << "Withdrawal successful. New Balance: " <<std::fixed<<std::setprecision(2)<< balance << std::endl;
        trnxhistory.push_back("Withdrawal :" + std::to_string(amount));
    }
    void Newname(string newname){
        name=newname;
    }
    void display() {
        std::cout << "\nAccount Number: " << accNumber;
        std::cout << "\nName: " << name;
        std::cout << "\nBalance: " <<std::fixed<<std::setprecision(2)<< balance << std::endl;
    }
    void DisplayTrnx(){
        std::cout<<"\nTransaction history for account Number :"<<accNumber;
        for(auto&trnx:trnxhistory){
            std::cout<<trnx<<std::endl;
        }
    }
    void addInterest(double rate){
        double intrest=balance*rate/100;
        balance+=intrest;
        std::cout<<"Interest of "<<std::fixed<<std::setprecision(2)<<intrest<<" added. New balance :"
        <<std::fixed<<std::setprecision(2)<<balance<<std::endl;
    }
    std::string toCSV(){
       return std::to_string(accNumber) + "," + name + "," + std::to_string(balance);
    }
};

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNumber;

public:
    Bank() {
        nextAccountNumber = 1001;
    }

    void createAccount() {
        std::string na;
        double initialBalance;
        std::cout << "Enter Account Holder Name: ";
        std::cin >> na;
        std::cout << "Enter Initial Balance: ";
        std::cin >> initialBalance;

        Account newAccount(nextAccountNumber, na, initialBalance);
        accounts.push_back(newAccount);
        std::cout << "Account created successfully. Your account number is: " << nextAccountNumber << std::endl;
        nextAccountNumber++;
    }

    void showAcc() {
        if (accounts.empty()) {
            std::cout << "Account list empty.\n";
            return;
        }
        for ( auto& acc : accounts) {
            acc.display();
            std::cout << "________________\n";
        }
    }

    void searchAccount() {
        int acc;
        std::cout << "Enter account number: ";
        std::cin >> acc;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == acc) {
                std::cout << "Account found!\n";
                account.display();
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void depositMoney() {
        int acc;
        double amount;
        std::cout << "Enter Account Number: ";
        std::cin >> acc;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == acc) {
                std::cout << "Enter the amount to deposit: ";
                std::cin >> amount;
                account.deposit(amount);
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void withdrawMoney() {
        int acc;
        double amount;
        std::cout << "Enter Account Number: ";
        std::cin >> acc;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == acc) {
                std::cout << "Enter the amount to withdraw: ";
                std::cin >> amount;
                account.withdraw(amount);
                return;
            }
        }
        std::cout << "Account not found.\n";
    }

    void balanceEnquiry() {
        int acc;
        std::cout << "Enter Account Number: ";
        std::cin >> acc;

        for (auto& account : accounts) {
            if (account.getAccountNumber() == acc) {
                std::cout << "Current Balance: " <<std::fixed<<std::setprecision(2)<< account.getBalance() << std::endl;
                return;
            }
        }
        std::cout << "Account not found.\n";
    }
   void showTrnx(){
    int acc;
    std::cout<<"enter the account number :";
    std::cin>>acc;
    for(auto&account:accounts){
        if(account.getAccountNumber()==acc){
            account.DisplayTrnx();
            return;
        }
    }
    std::cout<<"Account not Found!\n";
   } 
   void editdetail(){
    int acc;
    std::cout<<"enter the account number :";
    std::cin>>acc;
    for(auto&account:accounts){
        if(account.getAccountNumber()==acc){
           string NewName;
            std::cout<<"Enter New Account holder Name : ";
            std::cin>>NewName;
            account.Newname(NewName);
            cout<<"Account Name updated successfully!\n";
            return;
        }
    }
     cout<<"Account not Found!\n";
   }  
   void DeleteAcc(){
       int acc;
     cout<<"enter the account number :";
     cin>>acc;
    for(int i=0;i<accounts.size();i++){
        if(accounts[i].getAccountNumber()==acc){
           accounts.erase(accounts.begin() + i);
             cout<<"Account deleted successfully!\n";
            return;
        }
    }
     cout<<"Account not Found!\n";
   }   
   void addIntrestToAll(double rate){
    for(auto&acc:accounts){
        acc.addInterest(rate);
    }
   }
   void exportDataToFile(){
    ofstream file("accounts.csv");
    if(!file){
        std::cout<<"Failed to open file for writting.\n";
        return;
    }
    file<<"Account number,Name,Balance\n";
    for(auto&acc:accounts){
        file<<acc.toCSV()<<endl;
    }
    file.close();
    std::cout<<"Data expoted successfully to account.csv\n";
   }
};
void main_menu(){
        cout<<"--------------------------------------------------------------\n";
        cout<<"|             BANK ACCOUNT MANAGEMENT SYSTEM                  |\n";
        cout<<"--------------------------------------------------------------\n";
        cout << "1. Create New Account.\t\t";
        cout << "2. Show All Accounts.\n";
        cout << "3. Search Account.\t\t";
        cout << "4. Deposit Money.\n";
        cout << "5. Withdraw Money.\t\t";
        cout << "6. Balance Enquiry.\n";
        cout << "7. Transcation history.\t\t";
        cout << "8. Edit Acc. Holder Name.\n";
        cout << "9. Close Account.\t\t";
        cout << "10. Add Intrest.\n";
        cout << "11. Export Data.\t\t";
        cout << "12. Clear the screen.\n";
        cout << "13. Main menu.\t\t\t";
        cout << "14. Exit.\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

// Your existing Bank and Account class implementation here...

int main() {
    UserSystem userSystem;

    // Ensure the user logs in before accessing the main system
    loginMenu(userSystem);

    Bank bank;
    int choice;
    char op;
    system("cls");
    cout << "Welcome to our bank account management system! We are happy to assist you!\n";
    main_menu();

    do {
        cout << "______________________________________________________________\n";
        cout << "Enter your choice or enter 13 for main menu: ";
        cin>>choice;
        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.showAcc();
                break;
            case 3:
                bank.searchAccount();
                break;
            case 4:
                bank.depositMoney();
                break;
            case 5:
                bank.withdrawMoney();
                break;
            case 6:
                bank.balanceEnquiry();
                break;
            case 7:
                bank.showTrnx();
                break;
            case 8:
                bank.editdetail();
                break;
            case 9:
                bank.DeleteAcc();
                break;
            case 10: {
                double rate;
                cout << "Enter the Rate of Interest (%): ";
                cin >> rate;
                bank.addIntrestToAll(rate);
                break;
            }
            case 11:
                bank.exportDataToFile();
                break;
            case 12:
                system("cls");
                break;
            case 13:
                system("cls");
                main_menu();
                break;
            case 14:
                cout << "Thank you for using Bank Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 14);

    return 0;
}
