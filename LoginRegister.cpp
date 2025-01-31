#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void display(){

    cout << endl;
    cout << "\t\t\t WELCOME TO LOGIN AND REGISTRATION PAGE\n\n\n";
    cout << "\t\t1- Login" << endl;
    cout << "\t\t2- Register" << endl;
    cout << "\t\t3- Forgot password" << endl;
    cout << "\t\t4- Exit" << endl;
    cout << endl;
    cout << "\t\tPlease select a valid option: ";
}

void loginUser(){

    system("clear");
    int userPassword, password;
    string userEmail, email;
    bool loggedIn =false;

    fstream file;
    
    cout << "\t\t\tLOGIN PAGE\n\n\n" << endl;
    cout << "\t\tEmail: ";
    cin >> email;
    cout << "\t\tPassword: ";
    cin >> password;
    cout << endl;

    file.open("User Info.txt", ios::in);
    if (file.is_open()) {
        bool isLoggedIn = false;
        while (file >> userEmail >> userPassword) {
            if (email == userEmail && password == userPassword) {
                cout << "\t\tYou have successfully logged in!\n\n\n";
                isLoggedIn = true;
                break;
            }
        }
        if (!isLoggedIn) {
            cout << "\t\tEmail or password is wrong, or user does not exist.\n\n\n";
        }
        file.close();
    }
    else{
        cout << "File does not exist." << endl;
    }
}

void registerUser(){

    int userPassword;
    string userEmail;
    fstream file;

    cout << "\t\t\tREGISTRATION PAGE\n\n\n";
    cout << "\t\tYour email: ";
    cin >> userEmail;
    cout << "\t\tYour password: ";
    cin >> userPassword;

    file.open("User Info.txt", ios::app);
    if(file.is_open()){
        file << "\n" <<userEmail << " " << userPassword << endl;
        file.close();
        cout << "registration successful\n\n\n";
    }
    else{
        cout << "File does not exist." << endl;
    }
}

void forgotPassword(){
    
    int userPassword, password;
    string userEmail, email;
    bool userExist = false;
    fstream file;

    cout << "\t\t\tPASSWORD RESET PAGE\n\n\n";
    cout << "\t\tWhat is your email?: ";
    cin >> email;

    file.open("User Info.txt",ios::in);
    if(file.is_open()){
        while (file>>userEmail>>userPassword)
        {
            if(email == userEmail){
                cout << "\t\tYour password is: " << userPassword << endl;
                userExist = true;
                break;
            }
        }
        if (!userExist) {
            cout << "\t\tUser does not exist.\n\n\n";
        }
        file.close();
    }
    else{
        cout << "File does not exist." << endl;
    }
}

int main() {

    fstream file;
    file.open("User Info.txt");
    display();
    int choice;
    cin >> choice;
    cout << endl;
    
    switch (choice)
    {
    case 1:
        loginUser();
        break;
    case 2:
        registerUser();
        break;
    case 3:
        forgotPassword();
        break;
    case 4:
        cout << "\t\tPROGRAM ENDED" << endl;
        break;
    default:
        system("clear");
        cout << "\t\tINVALID VALUE!" << endl;
        main();
        break;  
    }
    return 0;
}