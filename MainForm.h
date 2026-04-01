#pragma once
#include "User.h"

namespace Diwersus {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Data::SqlClient;
	using namespace System::Threading;
	using namespace System::Diagnostics;



	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		User^ user;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	public:


	public:
		String^ username;
		// Constructor
		MainForm(User^ user) : user(user) {
			InitializeComponent();
			// Check if user is not null
			if (user == nullptr) {
				throw gcnew ArgumentNullException("user");
			}

			// Initialize username
			username = user->username;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}

		// Override WndProc to allow dragging the form
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

	private:
		System::Windows::Forms::Button^ btCloseForm;
		System::Windows::Forms::Button^ btMinimizeWindow;
	private: System::Windows::Forms::Label^ lbTechnoSphere;


	protected:
	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btCloseForm = (gcnew System::Windows::Forms::Button());
			this->btMinimizeWindow = (gcnew System::Windows::Forms::Button());
			this->lbTechnoSphere = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// btCloseForm
			// 
			this->btCloseForm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btCloseForm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btCloseForm->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btCloseForm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btCloseForm->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btCloseForm->Location = System::Drawing::Point(966, 3);
			this->btCloseForm->Name = L"btCloseForm";
			this->btCloseForm->Size = System::Drawing::Size(40, 25);
			this->btCloseForm->TabIndex = 0;
			this->btCloseForm->Text = L"X";
			this->btCloseForm->UseVisualStyleBackColor = true;
			this->btCloseForm->Click += gcnew System::EventHandler(this, &MainForm::btCloseForm_Click);
			// 
			// btMinimizeWindow
			// 
			this->btMinimizeWindow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btMinimizeWindow->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btMinimizeWindow->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btMinimizeWindow->Font = (gcnew System::Drawing::Font(L"Unispace", 12, System::Drawing::FontStyle::Bold));
			this->btMinimizeWindow->ForeColor = System::Drawing::SystemColors::ControlText;
			this->btMinimizeWindow->Location = System::Drawing::Point(915, 3);
			this->btMinimizeWindow->Name = L"btMinimizeWindow";
			this->btMinimizeWindow->Size = System::Drawing::Size(45, 25);
			this->btMinimizeWindow->TabIndex = 1;
			this->btMinimizeWindow->Text = L"—";
			this->btMinimizeWindow->UseVisualStyleBackColor = true;
			this->btMinimizeWindow->Click += gcnew System::EventHandler(this, &MainForm::btMinimizeWindow_Click);
			// 
			// lbTechnoSphere
			// 
			this->lbTechnoSphere->AutoSize = true;
			this->lbTechnoSphere->Cursor = System::Windows::Forms::Cursors::Hand;
			this->lbTechnoSphere->Font = (gcnew System::Drawing::Font(L"Verdana", 12.75F, System::Drawing::FontStyle::Bold));
			this->lbTechnoSphere->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(165)), static_cast<System::Int32>(static_cast<System::Byte>(165)),
				static_cast<System::Int32>(static_cast<System::Byte>(165)));
			this->lbTechnoSphere->Location = System::Drawing::Point(429, 173);
			this->lbTechnoSphere->Name = L"lbTechnoSphere";
			this->lbTechnoSphere->Size = System::Drawing::Size(144, 20);
			this->lbTechnoSphere->TabIndex = 2;
			this->lbTechnoSphere->Text = L"TechnoSphere";
			this->lbTechnoSphere->Click += gcnew System::EventHandler(this, &MainForm::lbTechnoSphere_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(78)), static_cast<System::Int32>(static_cast<System::Byte>(78)),
				static_cast<System::Int32>(static_cast<System::Byte>(78)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 12.75F, System::Drawing::FontStyle::Bold));
			this->richTextBox1->Location = System::Drawing::Point(724, 60);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(282, 454);
			this->richTextBox1->TabIndex = 3;
			this->richTextBox1->Text = L"TechnoSphere";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(42)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1008, 569);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->lbTechnoSphere);
			this->Controls->Add(this->btMinimizeWindow);
			this->Controls->Add(this->btCloseForm);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Diwersus";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
			// Handle form load event
		}
System::Void btCloseForm_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
System::Void btMinimizeWindow_Click(System::Object^ sender, System::EventArgs^ e) {
			this->WindowState = FormWindowState::Minimized;
		}  
System::Void lbTechnoSphere_Click(System::Object^ sender, System::EventArgs^ e) {
	lbTechnoSphere->Enabled = false; // Disable the button

	// Start a new thread to handle the process
	Thread^ processThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::LaunchGame));
	processThread->IsBackground = true; // Ensure the thread is a background thread
	processThread->Start();
}

System::Void LaunchGame() {
	try {
		String^ AppDataPath = Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData), "Diwersus");
		String^ basePath = AppDataPath + "\\modpacks\\1.7.10\\TechnoSphere";
		String^ javaPath = basePath + "\\java\\bin\\java.exe";
		String^ nativesPath = basePath + "\\versions\\Forge_1.7.10\\natives";
		String^ librariesPath = basePath + "\\libraries";
		String^ assetsPath = basePath + "\\assets";
		String^ versionPath = basePath + "\\versions\\Forge_1.7.10\\Forge_1.7.10.jar";
		String^ logConfigPath = assetsPath + "\\log_configs\\client-1.7.xml";
		String^ modPath = basePath + "\\mods";

		//Let's check if all mods exist in folder "mods"



		// Construct the command
		String^ command = ConstructCommand(javaPath, nativesPath, librariesPath, versionPath, logConfigPath, basePath, username);

		// Launch game
		ProcessStartInfo^ psi = gcnew ProcessStartInfo();
		psi->FileName = "cmd.exe";
		psi->Arguments = "/C " + command;
		psi->CreateNoWindow = true;
		psi->UseShellExecute = false;

		Process^ process = Process::Start(psi);
		process->WaitForExit(); // Wait for the process to exit
		process->Close(); // Ensure the process is properly disposed of

		// Ensure UI updates are done on the main thread
		if (!this->IsDisposed && this->IsHandleCreated) {
			this->Invoke(gcnew Action(this, &MainForm::EnableTechnoSphereButton));
		}
	}
	catch (Exception^ ex) {
		// Ensure UI updates are done on the main thread
		if (!this->IsDisposed && this->IsHandleCreated) {
			this->Invoke(gcnew Action(this, &MainForm::EnableTechnoSphereButton));
		}
		MessageBox::Show("An error occurred: " + ex->Message, 
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		// Ensure UI updates are done on the main thread
		if (!this->IsDisposed && this->IsHandleCreated) {
			this->Invoke(gcnew Action(this, &MainForm::EnableTechnoSphereButton));
		}
	}
}

System::Void EnableTechnoSphereButton() {
	lbTechnoSphere->Enabled = true; // Enable the button back
}
		// Construct the command
		String^ ConstructCommand(String^ javaPath, String^ nativesPath, String^ librariesPath, String^ versionPath, String^ logConfigPath, String^ basePath, String^ username) {
			return String::Format("{0} -Djava.library.path={1} -cp {2}\\net\\minecraftforge\\forge\\1.7.10-10.13.4.1614-1.7.10\\forge-1.7.10-10.13.4.1614-1.7.10.jar;" +
				"{2}\\net\\minecraft\\launchwrapper\\1.12\\launchwrapper-1.12.jar;" +
				"{2}\\org\\ow2\\asm\\asm-all\\5.0.3\\asm-all-5.0.3.jar;" +
				"{2}\\com\\typesafe\\akka\\akka-actor_2.11\\2.3.3\\akka-actor_2.11-2.3.3.jar;" +
				"{2}\\com\\typesafe\\config\\1.2.1\\config-1.2.1.jar;" +
				"{2}\\org\\scala-lang\\scala-actors-migration_2.11\\1.1.0\\scala-actors-migration_2.11-1.1.0.jar;" +
				"{2}\\org\\scala-lang\\scala-compiler\\2.11.1\\scala-compiler-2.11.1.jar;" +
				"{2}\\org\\scala-lang\\plugins\\scala-continuations-library_2.11\\1.0.2\\scala-continuations-library_2.11-1.0.2.jar;" +
				"{2}\\org\\scala-lang\\plugins\\scala-continuations-plugin_2.11.1\\1.0.2\\scala-continuations-plugin_2.11.1-1.0.2.jar;" +
				"{2}\\org\\scala-lang\\scala-library\\2.11.1\\scala-library-2.11.1.jar;" +
				"{2}\\org\\scala-lang\\scala-parser-combinators_2.11\\1.0.1\\scala-parser-combinators_2.11-1.0.1.jar;" +
				"{2}\\org\\scala-lang\\scala-reflect\\2.11.1\\scala-reflect-2.11.1.jar;" +
				"{2}\\org\\scala-lang\\scala-swing_2.11\\1.0.1\\scala-swing_2.11-1.0.1.jar;" +
				"{2}\\org\\scala-lang\\scala-xml_2.11\\1.0.2\\scala-xml_2.11-1.0.2.jar;" +
				"{2}\\lzma\\lzma\\0.0.1\\lzma-0.0.1.jar;" +
				"{2}\\com\\google\\guava\\guava\\17.0\\guava-17.0.jar;" +
				"{2}\\org\\tlauncher\\netty\\1.6\\netty-1.6.jar;" +
				"{2}\\com\\mojang\\realms\\1.3.5\\realms-1.3.5.jar;" +
				"{2}\\org\\apache\\commons\\commons-compress\\1.8.1\\commons-compress-1.8.1.jar;" +
				"{2}\\org\\apache\\httpcomponents\\httpclient\\4.3.3\\httpclient-4.3.3.jar;" +
				"{2}\\commons-logging\\commons-logging\\1.1.3\\commons-logging-1.1.3.jar;" +
				"{2}\\org\\apache\\httpcomponents\\httpcore\\4.3.2\\httpcore-4.3.2.jar;" +
				"{2}\\java3d\\vecmath\\1.3.1\\vecmath-1.3.1.jar;" +
				"{2}\\net\\sf\\trove4j\\trove4j\\3.0.3\\trove4j-3.0.3.jar;" +
				"{2}\\com\\ibm\\icu\\icu4j-core-mojang\\51.2\\icu4j-core-mojang-51.2.jar;" +
				"{2}\\net\\sf\\jopt-simple\\jopt-simple\\4.5\\jopt-simple-4.5.jar;" +
				"{2}\\com\\paulscode\\codecjorbis\\20101023\\codecjorbis-20101023.jar;" +
				"{2}\\com\\paulscode\\codecwav\\20101023\\codecwav-20101023.jar;" +
				"{2}\\com\\paulscode\\libraryjavasound\\20101123\\libraryjavasound-20101123.jar;" +
				"{2}\\com\\paulscode\\librarylwjglopenal\\20100824\\librarylwjglopenal-20100824.jar;" +
				"{2}\\com\\paulscode\\soundsystem\\20120107\\soundsystem-20120107.jar;" +
				"{2}\\io\\netty\\netty-all\\4.0.10.Final\\netty-all-4.0.10.Final.jar;" +
				"{2}\\org\\apache\\commons\\commons-lang3\\3.3.2\\commons-lang3-3.3.2.jar;" +
				"{2}\\commons-io\\commons-io\\2.4\\commons-io-2.4.jar;" +
				"{2}\\commons-codec\\commons-codec\\1.9\\commons-codec-1.9.jar;" +
				"{2}\\net\\java\\jinput\\jinput\\2.0.5\\jinput-2.0.5.jar;" +
				"{2}\\net\\java\\jutils\\jutils\\1.0.0\\jutils-1.0.0.jar;" +
				"{2}\\com\\google\\code\\gson\\gson\\2.2.4\\gson-2.2.4.jar;" +
				"{2}\\org\\tlauncher\\authlib\\1.7.211\\authlib-1.7.211.jar;" +
				"{2}\\org\\apache\\logging\\log4j\\log4j-api\\2.0-beta9\\log4j-api-2.0-beta9.jar;" +
				"{2}\\org\\apache\\logging\\log4j\\log4j-core\\2.0-beta9\\log4j-core-2.0-beta9.jar;" +
				"{2}\\org\\lwjgl\\lwjgl\\lwjgl\\2.9.1\\lwjgl-2.9.1.jar;" +
				"{2}\\org\\lwjgl\\lwjgl\\lwjgl_util\\2.9.1\\lwjgl_util-2.9.1.jar;" +
				"{2}\\tv\\twitch\\twitch\\5.16\\twitch-5.16.jar;" +
				"{3} -Xmx13360M -XX:+UnlockExperimentalVMOptions -XX:+UseG1GC -XX:G1NewSizePercent=20 -XX:G1ReservePercent=20 -XX:MaxGCPauseMillis=50 -XX:G1HeapRegionSize=32M -Dfml.ignoreInvalidMinecraftCertificates=true -Dfml.ignorePatchDiscrepancies=true -Djava.net.preferIPv4Stack=true -Dminecraft.applet.TargetDirectory={4} -DlibraryDirectory={2} -Dlog4j.configurationFile={5} net.minecraft.launchwrapper.Launch --username {6} --version Forge_1.7.10 --gameDir {4} --assetsDir {4}\\assets --assetIndex 1.7.10 --uuid a392f2d99d144a6a803f0a025912b8cc --accessToken null --userProperties {{}} --userType mojang --tweakClass cpw.mods.fml.common.launcher.FMLTweaker --width 925 --height 530",
				javaPath, nativesPath, librariesPath, versionPath, basePath, logConfigPath, username);
		}

};
}
		