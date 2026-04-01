#pragma once
using namespace System;

public ref class User
{
public:

    String^ username;
    String^ password;
	String^ usermail;

    User(String^ username, String^ password, String^ usermail)
    {

        this->username = username;
        this->password = password;
		this->usermail = usermail;
									
    }
};
