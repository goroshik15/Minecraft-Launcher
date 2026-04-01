#pragma once
#include "User.h"
#include <openssl/sha.h>
#include <iomanip>

namespace Diwersus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Security::Cryptography;
	using namespace System::Text;
	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		bool switchtoregisterform;
		bool switchtomainform;
	private: System::Windows::Forms::Button^ btCloseForm;
	private: System::Windows::Forms::Button^ btMinimizeWindow;
	private: System::Windows::Forms::Label^ lbLogin;
	public:
		User^ user;
		LoginForm(void)
		{
			InitializeComponent();
			user = nullptr;
			switchtoregisterform = false;
			switchtomainform = false;

		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
		virtual void WndProc(Message% m) override
		{
			const int WM_NCHITTEST = 0x84;
			const int HTCAPTION = 2;

			if (m.Msg == WM_NCHITTEST)
			{
				m.Result = (System::IntPtr)HTCAPTION; // Allow dragging
				return;
			}

			Form::WndProc(m);
		}
	private: System::Windows::Forms::Label^ usernameLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ tbusername;


	private: System::Windows::Forms::Button^ btPlay;
	private: System::Windows::Forms::Button^ btCancel;
	private: System::Windows::Forms::LinkLabel^ LinkSwitchToRegister;
	private: System::Windows::Forms::TextBox^ tbpassword;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->usernameLabel = (gcnew System::Windows::Forms::Label());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->tbusername = (gcnew System::Windows::Forms::TextBox());
			this->btPlay = (gcnew System::Windows::Forms::Button());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->LinkSwitchToRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->tbpassword = (gcnew System::Windows::Forms::TextBox());
			this->btCloseForm = (gcnew System::Windows::Forms::Button());
			this->btMinimizeWindow = (gcnew System::Windows::Forms::Button());
			this->lbLogin = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// usernameLabel
			// 
			this->usernameLabel->AutoSize = true;
			this->usernameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->usernameLabel->Location = System::Drawing::Point(42, 114);
			this->usernameLabel->Name = L"usernameLabel";
			this->usernameLabel->Size = System::Drawing::Size(242, 25);
			this->usernameLabel->TabIndex = 0;
			this->usernameLabel->Text = L"Username or e-mail";
			this->usernameLabel->Click += gcnew System::EventHandler(this, &LoginForm::usernameLabel_Click);
			// 
			// passwordLabel
			// 
			this->passwordLabel->AutoSize = true;
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->passwordLabel->Location = System::Drawing::Point(42, 187);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(195, 25);
			this->passwordLabel->TabIndex = 1;
			this->passwordLabel->Text = L"Enter password";
			this->passwordLabel->Click += gcnew System::EventHandler(this, &LoginForm::passwordLabel_Click);
			// 
			// tbusername
			// 
			this->tbusername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbusername->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbusername->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbusername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbusername->Location = System::Drawing::Point(300, 115);
			this->tbusername->MaxLength = 24;
			this->tbusername->Name = L"tbusername";
			this->tbusername->Size = System::Drawing::Size(303, 29);
			this->tbusername->TabIndex = 2;
			this->tbusername->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbUsername_TextChanged);
			// 
			// btPlay
			// 
			this->btPlay->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->btPlay->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btPlay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btPlay->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btPlay->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->btPlay->Location = System::Drawing::Point(300, 268);
			this->btPlay->Name = L"btPlay";
			this->btPlay->Size = System::Drawing::Size(140, 49);
			this->btPlay->TabIndex = 4;
			this->btPlay->Text = L"Play";
			this->btPlay->UseVisualStyleBackColor = false;
			this->btPlay->Click += gcnew System::EventHandler(this, &LoginForm::btPlay_Click);
			// 
			// btCancel
			// 
			this->btCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->btCancel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btCancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCancel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btCancel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->btCancel->Location = System::Drawing::Point(464, 268);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(139, 49);
			this->btCancel->TabIndex = 5;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = false;
			this->btCancel->Click += gcnew System::EventHandler(this, &LoginForm::btCancel_Click);
			// 
			// LinkSwitchToRegister
			// 
			this->LinkSwitchToRegister->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToRegister->AutoSize = true;
			this->LinkSwitchToRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LinkSwitchToRegister->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->LinkSwitchToRegister->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToRegister->Location = System::Drawing::Point(295, 229);
			this->LinkSwitchToRegister->Name = L"LinkSwitchToRegister";
			this->LinkSwitchToRegister->Size = System::Drawing::Size(110, 25);
			this->LinkSwitchToRegister->TabIndex = 6;
			this->LinkSwitchToRegister->TabStop = true;
			this->LinkSwitchToRegister->Text = L"Register";
			this->LinkSwitchToRegister->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkSwitchToRegister_LinkClicked);
			// 
			// tbpassword
			// 
			this->tbpassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbpassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbpassword->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbpassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbpassword->Location = System::Drawing::Point(300, 188);
			this->tbpassword->MaxLength = 24;
			this->tbpassword->Name = L"tbpassword";
			this->tbpassword->PasswordChar = '$';
			this->tbpassword->Size = System::Drawing::Size(303, 29);
			this->tbpassword->TabIndex = 7;
			this->tbpassword->TextChanged += gcnew System::EventHandler(this, &LoginForm::tbpassword_TextChanged);
			// 
			// btCloseForm
			// 
			this->btCloseForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btCloseForm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCloseForm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btCloseForm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btCloseForm->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btCloseForm->Location = System::Drawing::Point(633, 3);
			this->btCloseForm->Name = L"btCloseForm";
			this->btCloseForm->Size = System::Drawing::Size(40, 25);
			this->btCloseForm->TabIndex = 19;
			this->btCloseForm->Text = L"X";
			this->btCloseForm->UseVisualStyleBackColor = true;
			this->btCloseForm->Click += gcnew System::EventHandler(this, &LoginForm::btCloseForm_Click);
			// 
			// btMinimizeWindow
			// 
			this->btMinimizeWindow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btMinimizeWindow->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMinimizeWindow->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btMinimizeWindow->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btMinimizeWindow->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btMinimizeWindow->Location = System::Drawing::Point(582, 3);
			this->btMinimizeWindow->Name = L"btMinimizeWindow";
			this->btMinimizeWindow->Size = System::Drawing::Size(45, 25);
			this->btMinimizeWindow->TabIndex = 20;
			this->btMinimizeWindow->Text = L"—";
			this->btMinimizeWindow->UseVisualStyleBackColor = true;
			this->btMinimizeWindow->Click += gcnew System::EventHandler(this, &LoginForm::btMinimizeWindow_Click);
			// 
			// lbLogin
			// 
			this->lbLogin->AutoSize = true;
			this->lbLogin->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->lbLogin->Location = System::Drawing::Point(246, 18);
			this->lbLogin->Name = L"lbLogin";
			this->lbLogin->Size = System::Drawing::Size(185, 25);
			this->lbLogin->TabIndex = 21;
			this->lbLogin->Text = L"Diwersus login";
			this->lbLogin->Click += gcnew System::EventHandler(this, &LoginForm::lbLogin_Click);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->ClientSize = System::Drawing::Size(674, 408);
			this->Controls->Add(this->lbLogin);
			this->Controls->Add(this->btMinimizeWindow);
			this->Controls->Add(this->btCloseForm);
			this->Controls->Add(this->tbpassword);
			this->Controls->Add(this->LinkSwitchToRegister);
			this->Controls->Add(this->btCancel);
			this->Controls->Add(this->btPlay);
			this->Controls->Add(this->tbusername);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->usernameLabel);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btPlay_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ input = this->tbusername->Text;
	String^ password = this->tbpassword->Text;

	// Basic checks
	if (input->Length == 0 || password->Length == 0) {
		MessageBox::Show("Please enter email/username and password",
			"Email/Username or password fields are empty", MessageBoxButtons::OK);
		return;
	}
	if (input->Length < 5) {
		MessageBox::Show("Username length should be more than 5 symbols",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (password->Length < 8) {
		MessageBox::Show("Password must be at least 8 characters long",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	bool isusermail = input->Contains("@") && input->Contains(".");

	// Email validation
	if (isusermail) {
		System::Text::RegularExpressions::Regex^ emailRegex =
			gcnew System::Text::RegularExpressions::Regex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
		if (!emailRegex->IsMatch(input)) {
			MessageBox::Show("Invalid email", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	else {
		// Username validation
		for each(char c in input) {
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
				MessageBox::Show("Username can only contain English symbols",
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
	}

	// Password validation
	for each(char c in password) {
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))) {
			MessageBox::Show("Password can only contain English symbols",
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}

	// Hash the input password using SHA-256
	array<Byte>^ passwordBytes = System::Text::Encoding::UTF8->GetBytes(password);
	array<Byte>^ hashedBytes;
	{
		pin_ptr<Byte> pinnedPasswordBytes = &passwordBytes[0];
		unsigned char hash[SHA256_DIGEST_LENGTH];
		::SHA256(pinnedPasswordBytes, passwordBytes->Length, hash);
		hashedBytes = gcnew array<Byte>(SHA256_DIGEST_LENGTH);
		System::Runtime::InteropServices::Marshal::Copy((IntPtr)hash, hashedBytes, 0, SHA256_DIGEST_LENGTH);
	}
	String^ hashedPassword = BitConverter::ToString(hashedBytes)->Replace("-", "");

	try {
		String^ connString = "Data Source=DESKTOP-FE1F9LO;Initial Catalog=dle_users;Integrated Security=True;Encrypt=False";
		SqlConnection^ sqlConn = gcnew SqlConnection(connString);
		sqlConn->Open();

		String^ sqlQuery = isusermail ?
			"SELECT * FROM dle_users WHERE usermail = @input AND password = @password" :
			"SELECT * FROM dle_users WHERE username = @input AND password = @password";

		SqlCommand^ command = gcnew SqlCommand(sqlQuery, sqlConn);
		command->Parameters->AddWithValue("@input", input);
		command->Parameters->AddWithValue("@password", hashedPassword);

		SqlDataReader^ reader = command->ExecuteReader();

		if (reader->Read()) {
			String^ username = reader["username"]->ToString();
			String^ usermail = reader["usermail"]->ToString();
			String^ password = reader["password"]->ToString();
			user = gcnew User(username, password, usermail);
		}
		else {
			MessageBox::Show("Email/Username or password is incorrect",
				"Auth error", MessageBoxButtons::OK);
			return;
		}
		reader->Close();
		sqlConn->Close();
	}
	catch (Exception^ exception) {
		MessageBox::Show(exception->Message, "Database connection error", MessageBoxButtons::OK);
		return;
	}

	switchtomainform = true;
	this->Close();
}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void usernameLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void passwordLabel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void tbUsername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void linkSwitchToRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		switchtoregisterform = true;
		this->Close();
	}
	private: System::Void tbpassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;
	}
	private: System::Void btCloseForm_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
	private: System::Void lbLogin_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}