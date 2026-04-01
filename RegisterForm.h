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
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
	bool switchtologinform;
	bool switchtomainform;
	private: System::Windows::Forms::Label^ lbRegister;
	private: System::Windows::Forms::Button^ btCloseForm;
	private: System::Windows::Forms::Button^ btMinimizeWindow;
	public:
		User^ user;
		RegisterForm(void)
		{
			InitializeComponent();
			user = nullptr;
			switchtologinform = false;
			switchtomainform = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
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
	private: System::Windows::Forms::Label^ EnterUsernameLabel;
	protected:
	private: System::Windows::Forms::Label^ EnterEmailLabel;
	private: System::Windows::Forms::Label^ EnterPasswordLabel;
	private: System::Windows::Forms::Label^ ConfirmPasswordLabel;
	private: System::Windows::Forms::LinkLabel^ LinkSwitchToLogin;
	private: System::Windows::Forms::Button^ btCancel;
	private: System::Windows::Forms::TextBox^ tbusername;
	private: System::Windows::Forms::TextBox^ tbEmail;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::TextBox^ tbConfirmPassword;
	private: System::Windows::Forms::Button^ btRegister;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->EnterUsernameLabel = (gcnew System::Windows::Forms::Label());
			this->EnterEmailLabel = (gcnew System::Windows::Forms::Label());
			this->EnterPasswordLabel = (gcnew System::Windows::Forms::Label());
			this->ConfirmPasswordLabel = (gcnew System::Windows::Forms::Label());
			this->LinkSwitchToLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->btCancel = (gcnew System::Windows::Forms::Button());
			this->tbusername = (gcnew System::Windows::Forms::TextBox());
			this->tbEmail = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->tbConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->btRegister = (gcnew System::Windows::Forms::Button());
			this->lbRegister = (gcnew System::Windows::Forms::Label());
			this->btCloseForm = (gcnew System::Windows::Forms::Button());
			this->btMinimizeWindow = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// EnterUsernameLabel
			// 
			this->EnterUsernameLabel->AutoSize = true;
			this->EnterUsernameLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnterUsernameLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->EnterUsernameLabel->Location = System::Drawing::Point(38, 75);
			this->EnterUsernameLabel->Name = L"EnterUsernameLabel";
			this->EnterUsernameLabel->Size = System::Drawing::Size(198, 25);
			this->EnterUsernameLabel->TabIndex = 1;
			this->EnterUsernameLabel->Text = L"Enter username";
			// 
			// EnterEmailLabel
			// 
			this->EnterEmailLabel->AutoSize = true;
			this->EnterEmailLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnterEmailLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->EnterEmailLabel->Location = System::Drawing::Point(38, 126);
			this->EnterEmailLabel->Name = L"EnterEmailLabel";
			this->EnterEmailLabel->Size = System::Drawing::Size(156, 25);
			this->EnterEmailLabel->TabIndex = 2;
			this->EnterEmailLabel->Text = L"Enter e-mail";
			// 
			// EnterPasswordLabel
			// 
			this->EnterPasswordLabel->AutoSize = true;
			this->EnterPasswordLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->EnterPasswordLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->EnterPasswordLabel->Location = System::Drawing::Point(38, 179);
			this->EnterPasswordLabel->Name = L"EnterPasswordLabel";
			this->EnterPasswordLabel->Size = System::Drawing::Size(195, 25);
			this->EnterPasswordLabel->TabIndex = 3;
			this->EnterPasswordLabel->Text = L"Enter password";
			// 
			// ConfirmPasswordLabel
			// 
			this->ConfirmPasswordLabel->AutoSize = true;
			this->ConfirmPasswordLabel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ConfirmPasswordLabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->ConfirmPasswordLabel->Location = System::Drawing::Point(38, 231);
			this->ConfirmPasswordLabel->Name = L"ConfirmPasswordLabel";
			this->ConfirmPasswordLabel->Size = System::Drawing::Size(224, 25);
			this->ConfirmPasswordLabel->TabIndex = 4;
			this->ConfirmPasswordLabel->Text = L"Confirm password";
			// 
			// LinkSwitchToLogin
			// 
			this->LinkSwitchToLogin->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToLogin->AutoSize = true;
			this->LinkSwitchToLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LinkSwitchToLogin->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->LinkSwitchToLogin->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToLogin->Location = System::Drawing::Point(267, 268);
			this->LinkSwitchToLogin->Name = L"LinkSwitchToLogin";
			this->LinkSwitchToLogin->Size = System::Drawing::Size(76, 25);
			this->LinkSwitchToLogin->TabIndex = 9;
			this->LinkSwitchToLogin->TabStop = true;
			this->LinkSwitchToLogin->Text = L"Login";
			this->LinkSwitchToLogin->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->LinkSwitchToLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::LinkSwitchToLogin_LinkClicked);
			// 
			// btCancel
			// 
			this->btCancel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->btCancel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btCancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCancel->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btCancel->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->btCancel->Location = System::Drawing::Point(436, 311);
			this->btCancel->Name = L"btCancel";
			this->btCancel->Size = System::Drawing::Size(139, 49);
			this->btCancel->TabIndex = 11;
			this->btCancel->Text = L"Cancel";
			this->btCancel->UseVisualStyleBackColor = false;
			this->btCancel->Click += gcnew System::EventHandler(this, &RegisterForm::btCancel_Click);
			// 
			// tbusername
			// 
			this->tbusername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbusername->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbusername->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbusername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbusername->Location = System::Drawing::Point(272, 76);
			this->tbusername->MaxLength = 24;
			this->tbusername->Name = L"tbusername";
			this->tbusername->Size = System::Drawing::Size(303, 29);
			this->tbusername->TabIndex = 12;
			this->tbusername->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbusername_TextChanged_1);
			// 
			// tbEmail
			// 
			this->tbEmail->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbEmail->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbEmail->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbEmail->Location = System::Drawing::Point(272, 127);
			this->tbEmail->MaxLength = 24;
			this->tbEmail->Name = L"tbEmail";
			this->tbEmail->Size = System::Drawing::Size(303, 29);
			this->tbEmail->TabIndex = 13;
			this->tbEmail->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbEmail_TextChanged);
			// 
			// tbPassword
			// 
			this->tbPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbPassword->Location = System::Drawing::Point(272, 175);
			this->tbPassword->MaxLength = 24;
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(303, 29);
			this->tbPassword->TabIndex = 14;
			this->tbPassword->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbPassword_TextChanged);
			// 
			// tbConfirmPassword
			// 
			this->tbConfirmPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->tbConfirmPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbConfirmPassword->Font = (gcnew System::Drawing::Font(L"Verdana", 13.25F, System::Drawing::FontStyle::Bold));
			this->tbConfirmPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->tbConfirmPassword->Location = System::Drawing::Point(272, 227);
			this->tbConfirmPassword->MaxLength = 24;
			this->tbConfirmPassword->Name = L"tbConfirmPassword";
			this->tbConfirmPassword->Size = System::Drawing::Size(303, 29);
			this->tbConfirmPassword->TabIndex = 15;
			this->tbConfirmPassword->TextChanged += gcnew System::EventHandler(this, &RegisterForm::tbConfirmPassword_TextChanged);
			// 
			// btRegister
			// 
			this->btRegister->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->btRegister->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btRegister->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btRegister->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btRegister->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold));
			this->btRegister->Location = System::Drawing::Point(272, 311);
			this->btRegister->Name = L"btRegister";
			this->btRegister->Size = System::Drawing::Size(139, 49);
			this->btRegister->TabIndex = 16;
			this->btRegister->Text = L"Register";
			this->btRegister->UseVisualStyleBackColor = false;
			this->btRegister->Click += gcnew System::EventHandler(this, &RegisterForm::btRegister_Click_1);
			// 
			// lbRegister
			// 
			this->lbRegister->AutoSize = true;
			this->lbRegister->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegister->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->lbRegister->Location = System::Drawing::Point(233, 19);
			this->lbRegister->Name = L"lbRegister";
			this->lbRegister->Size = System::Drawing::Size(219, 25);
			this->lbRegister->TabIndex = 17;
			this->lbRegister->Text = L"Diwersus register";
			// 
			// btCloseForm
			// 
			this->btCloseForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btCloseForm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCloseForm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btCloseForm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btCloseForm->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btCloseForm->Location = System::Drawing::Point(633, 2);
			this->btCloseForm->Name = L"btCloseForm";
			this->btCloseForm->Size = System::Drawing::Size(40, 25);
			this->btCloseForm->TabIndex = 18;
			this->btCloseForm->Text = L"X";
			this->btCloseForm->UseVisualStyleBackColor = true;
			this->btCloseForm->Click += gcnew System::EventHandler(this, &RegisterForm::btCloseForm_Click_1);
			// 
			// btMinimizeWindow
			// 
			this->btMinimizeWindow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btMinimizeWindow->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMinimizeWindow->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btMinimizeWindow->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btMinimizeWindow->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btMinimizeWindow->Location = System::Drawing::Point(582, 1);
			this->btMinimizeWindow->Name = L"btMinimizeWindow";
			this->btMinimizeWindow->Size = System::Drawing::Size(45, 25);
			this->btMinimizeWindow->TabIndex = 19;
			this->btMinimizeWindow->Text = L"—";
			this->btMinimizeWindow->UseVisualStyleBackColor = true;
			this->btMinimizeWindow->Click += gcnew System::EventHandler(this, &RegisterForm::btMinimizeWindow_Click);
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->ClientSize = System::Drawing::Size(674, 408);
			this->Controls->Add(this->btMinimizeWindow);
			this->Controls->Add(this->btCloseForm);
			this->Controls->Add(this->lbRegister);
			this->Controls->Add(this->btRegister);
			this->Controls->Add(this->tbConfirmPassword);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbEmail);
			this->Controls->Add(this->tbusername);
			this->Controls->Add(this->btCancel);
			this->Controls->Add(this->LinkSwitchToLogin);
			this->Controls->Add(this->ConfirmPasswordLabel);
			this->Controls->Add(this->EnterPasswordLabel);
			this->Controls->Add(this->EnterEmailLabel);
			this->Controls->Add(this->EnterUsernameLabel);
			this->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(57)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegisterForm";
			this->Load += gcnew System::EventHandler(this, &RegisterForm::RegisterForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btRegister_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void LinkSwitchToLogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		switchtologinform = true;
		this->Close();
}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbusername_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbConfirmPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbPassword_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbEmail_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tbusername_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btRegister_Click_1(System::Object^ sender, System::EventArgs^ e) {
	String^ username = this->tbusername->Text;
	String^ usermail = this->tbEmail->Text;
	String^ password = this->tbPassword->Text;
	String^ confirmpassword = this->tbConfirmPassword->Text;

	if (username->Length == 0 || usermail->Length == 0
		|| password->Length == 0 || confirmpassword->Length == 0)
	{
		MessageBox::Show("Please fill all the fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	if (username->Length < 5 || username->Length > 10)
	{
		MessageBox::Show("Username must be between 5 and 10 characters long", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	for each(char c in username)
	{
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')))
		{
			MessageBox::Show("Username can only contain English symbols", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	if (!usermail->Contains("@") || !usermail->Contains("."))
	{
		MessageBox::Show("Invalid email", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	for each(char c in usermail)
	{
		if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') 
			&& (c < '0' || c > '9')
			&& c != '@' && c != '.' 
			&& c != '-' && c != '_')
		{
			MessageBox::Show("Email can only contain English symbols and the characters @, ., -, _", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}

	if (password->Length < 8)
	{
		MessageBox::Show("Password must be at least 8 characters long", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	for each(char c in password)
	{
		if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
		{
			MessageBox::Show("Password can only contain English symbols", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}
	if (password != confirmpassword)
	{
		MessageBox::Show("Passwords do not match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	for each(char c in password)
	{
		if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*'
			|| c == '(' || c == ')' || c == '-' || c == '+' || c == '_' || c == '=' || c == '{' || c == '}'
			|| c == '[' || c == ']' || c == ':' || c == ';' || c == '"' || c == '\'' || c == '<' || c == '>'
			|| c == ',' || c == '.' || c == '?' || c == '/' || c == '\\' || c == '|' || c == '`' || c == '~')
		{
			MessageBox::Show("Password cannot contain special symbols", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
	}

	// Hash the password using SHA-256
	array<Byte>^ passwordBytes = Encoding::UTF8->GetBytes(password);
	array<Byte>^ hashBytes = SHA256::Create()->ComputeHash(passwordBytes);
	String^ hashedPassword = BitConverter::ToString(hashBytes)->Replace("-", "");

	try
	{
		String^ connString = "Data Source=DESKTOP-FE1F9LO;Initial Catalog=dle_users;Integrated Security=True;Encrypt=False";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ checkQuery = "SELECT 1 FROM dle_users WHERE usermail = @usermail OR username = @username";
		SqlCommand checkCommand(checkQuery, % sqlConn);
		checkCommand.Parameters->AddWithValue("@usermail", usermail);
		checkCommand.Parameters->AddWithValue("@username", username);

		Object^ result = checkCommand.ExecuteScalar();
		if (result != nullptr)
		{
			MessageBox::Show("Username or email already exists", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ sqlQuery = "INSERT INTO dle_users (username, usermail, password) VALUES (@username, @usermail, @password)";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@username", username);
		command.Parameters->AddWithValue("@usermail", usermail);
		command.Parameters->AddWithValue("@password", hashedPassword);

		command.ExecuteNonQuery();

		MessageBox::Show("User registered successfully!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

		// Close RegisterForm and open LoginForm
		switchtologinform = true;
		this->Close();
	}
	catch (SqlException^ ex)
	{
		if (ex->Number == 2627)
		{
			MessageBox::Show("Username or email already exists", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			MessageBox::Show(ex->Message, "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Unexpected error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void RegisterForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e) {
	this->WindowState = FormWindowState::Minimized;
}
private: System::Void btCloseForm_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

