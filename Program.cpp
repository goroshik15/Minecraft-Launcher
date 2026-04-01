#include "LoginForm.h"
#include "User.h"
#include "RegisterForm.h"
#include "MainForm.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    while (true) {


		Diwersus::LoginForm loginform;
        loginform.ShowDialog();

        if (loginform.user != nullptr) {


            if (loginform.switchtomainform) {
                Diwersus::MainForm mainform(loginform.user);
                mainform.ShowDialog();
                break;
            }


        }

        else if (loginform.switchtoregisterform) {


            Diwersus::RegisterForm registerform;
            registerform.ShowDialog();


            if (registerform.user != nullptr) {
                if (registerform.switchtomainform) {
                    Diwersus::MainForm mainform(registerform.user);
                    mainform.ShowDialog();
                    break;
                }
            }


            else if (registerform.switchtologinform) {
                continue;
            }
            else {
                return 0;
            }


        }
        else {
            return 0;
        }


    }
    return 0;
}