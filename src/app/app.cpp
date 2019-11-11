#include "app.h"

#include <iostream>
#include <string>
#include "../encryption/simplersa.h"

using namespace RsaEncrypter;
using namespace std;

const string TITLE = "8888888b.  .d8888b.        d88888888888888                                       888                       \n"
                     "888   Y88bd88P  Y88b      d88888888                                              888                       \n"
                     "888    888Y88b.          d88P888888                                              888                       \n"
                     "888   d88P \"Y888b.      d88P 8888888888   88888b.  .d8888b888d888888  88888888b. 888888 .d88b. 888d888    \n"
                     "8888888P\"     \"Y88b.   d88P  888888       888 \"88bd88P\"   888P\"  888  888888 \"88b888   d8P  Y8b888P\"\n"
                     "888 T88b        \"888  d88P   888888       888  888888     888    888  888888  888888   88888888888        \n"
                     "888  T88b Y88b  d88P d8888888888888       888  888Y88b.   888    Y88b 888888 d88PY88b. Y8b.    888         \n"
                     "888   T88b \"Y8888P\" d88P     8888888888888888  888 \"Y8888P888     \"Y8888888888P\"  \"Y888 \"Y8888 888  \n"
                     "                                                                    888888                                 \n"
                     "                                                                     Y8b d88P888                           \n"
                     "                                                                     \"Y88P\" 888                          \n";

const string DIVISOR = "-------------------------------------------------------------------------------------------------------\n";

const string MAIN_MENU = "Main Menu\n"
                         "   1 - Simple RSA\n"
                         "   2 - RSA 4096\n"
                         "   3 - EXIT\n"
                         "\n";

const string SIMPLE_RSA= "Simple RSA\n"
                         "   1 - Generate Key Pair\n"
                         "   2 - Encrypt\n"
                         "   3 - Decrypt\n"
                         "   4 - Return to Main Menu\n"
                         "   5 - Exit\n"
                         "\n";

App::App() { }

void App::bootstrap()
{
    title();
    main_menu();
}

void App::title()
{
    //system("CLS");
    cout << endl;
    cout << TITLE << endl;    
    cout << DIVISOR << endl;    
}

void App::main_menu()
{
    cout << MAIN_MENU;
    while(true)
    {
        int x;
        cout << ">_ ";
        cin >> x;
        switch (x)
        {
        case 1:
            simple_rsa();
            system("cls");
            title();
            cout << MAIN_MENU;
            break;
        case 2:
            cout << "You tried RSA 4096" << endl;
            break;
        case 3:
            system("cls");
            exit(0);
        default:
            system("cls");
            title();
            cout << "Error" << endl << endl;
            cout << MAIN_MENU;
            break;
        }
    }
}

void App::simple_rsa()
{
    RSA::KeyPair key;
    string k;
    string m;

    system("cls");
    title();
    cout << SIMPLE_RSA;
    while(true)
    {
        int x;
        cout << ">_ ";
        cin >> x;
        switch (x)
        {
        case 1:
            cout << endl << "Please enter two prime numbers greater than 19 and lesser than 2000000" << endl << endl;
            int x, y;
            cin >> x >> y;
            cout << endl;
            key = RSA::generate_simple_keypair(x, y);
            cout << "===== PRIVATE KEY =====" << endl;
            cout << key.private_key << endl << endl;
            cout << "===== PUBLIC  KEY =====" << endl;
            cout << key.public_key << endl << endl;
            break;
        case 2:
            cout << endl << "Please enter the public key" << endl << endl;
            cin >> k;
            cout << endl << "Please enter the message" << endl << endl;
            cin.ignore();
            getline(cin, m);
            cout << endl << RSA::encrypt_simple(k, m) << endl << endl;
            break;
        case 3:
            cout << endl << "Please enter the private key" << endl << endl;
            cin >> k;
            cout << endl << "Please enter the encrypted message" << endl << endl;
            cin.ignore();
            getline(cin, m);
            cout << endl << RSA::decrypt_simple(k, m) << endl << endl;
            break;
        case 4:
            return;
        case 5:
            system("cls");
            exit(0);
            break;
        default:
            system("cls");
            title();
            cout << "Error" << endl << endl;
            cout << SIMPLE_RSA;
            break;
        }
    }
}