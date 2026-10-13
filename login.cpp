#include <iostream>
#include <fstream>
using namespace std;

class Login
{
    string username, email, pass;
    string searchname, searchemail, searchpass;
    fstream file;

public:
    void login();
    void signup();
    void forgetpassword();
};

void Login::signup()
{
    cout << "Enter Your User Name :: " << endl;
    getline(cin, username);

    cout << "Enter your Email Address :: " << endl;
    getline(cin, email);

    cout << "Enter Your Password :: " << endl;
    getline(cin, pass);

    file.open("login.txt", ios::out | ios::app);

    file << username << "\t*\t" << email << "\t*\t" << pass << "\t\n";

    file.close();

    cout << "Account Created Successfully !!" << endl;
}

void Login::login()
{
    cout << "------------------------LOGIN------------------------" << endl;

    cout << "Enter Your User Name :: " << endl;
    getline(cin, searchname);

    cout << "Enter Your Password :: " << endl;
    getline(cin, searchpass);

    file.open("login.txt", ios::in);

    bool found = false;

    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, pass, '\n'))
    {
        if (username == searchname)
        {
            found = true;
            // cout<<"User Found !!"<<endl;

            if (pass == searchpass)
            {
                cout << "Account Login Successfully !!" << endl;
                cout << "Username :: " << username << endl;
                cout << "Email :: " << email << endl;
            }
            else
            {
                cout << "Password is Incorrect | Please try again !!" << endl;
            }

            break;
        }
    }

    if (!found)
    {
        cout << "Username Not Found !!" << endl;
    }

    file.close();
}

void Login::forgetpassword()
{
    cout << "Enter Your Username :: " << endl;
    getline(cin, searchname);

    cout << "Enter Your Email Address :: " << endl;
    getline(cin, searchemail);

    file.open("login.txt", ios::in);

    bool found = false;

    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, pass, '\n'))
    {
        if (username == searchname && email == searchemail)
        {
            found = true;

            cout << "Account Found !!" << endl;
            cout << "Your Old Password :: " << pass << endl;

            break;
        }
    }

    if (!found)
    {
        cout << "Username or Email is Incorrect !!" << endl;
    }

    file.close();
}

int main()
{
    Login a;
    int choice;

    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "3. Forget Password" << endl;
    cout << "4. Exit" << endl;

    cout << "Enter Your Choice = ";
    cin >> choice;

    cin.ignore();

    switch (choice)
    {
    case 1:
        a.login();
        break;

    case 2:
        a.signup();
        break;

    case 3:
        a.forgetpassword();
        break;

    case 4:
        cout << "Thank You !!" << endl;
        return 0;

    default:
        cout << "Invalid Choice !!" << endl;
    }

    return 0;
}