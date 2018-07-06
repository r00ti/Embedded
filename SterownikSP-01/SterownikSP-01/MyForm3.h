#pragma once
#include <iostream>
#include "common.h"
using namespace System::IO::Ports;
#include <windows.h>

namespace SterownikSP01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace IO;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		String ^message;
		array<Object^>^ portname;
		int numbytes;
		int configureOk;
		int szablonOk;
		int licznikDanych;
		int ck;
		int flaga;
		bool ready_to_read = true;
		array<Byte>^ encodedBytes;
		array<Int32> ^ tabYMSB;
		array<Int32> ^ tabYLSB;
		array<Int32> ^ tabZMSB;
		array<Int32> ^ tabZLSB;
		array<Int32> ^ tabZ;
		array<Int32> ^ tabY;
		String ^bouds2;
		String^ data1;
		byte hams;
		String^ marian;
		String ^portnames2;
	private: System::Windows::Forms::TabControl^  as;
	public:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button4;



	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  label23;
	private: System::Windows::Forms::Label^  label24;
	private: System::Windows::Forms::Label^  label25;
	private: System::Windows::Forms::Label^  label26;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label21;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Panel^  panel15;
	private: System::Windows::Forms::Panel^  panel14;
	private: System::Windows::Forms::Panel^  panel13;
	private: System::Windows::Forms::Panel^  panel12;
	private: System::Windows::Forms::Panel^  panel11;
	private: System::Windows::Forms::Panel^  panel10;
	private: System::Windows::Forms::Panel^  panel9;
	private: System::Windows::Forms::Panel^  panel8;
	private: System::Windows::Forms::Panel^  panel7;
	private: System::Windows::Forms::Panel^  panel6;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Label^  label27;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::TextBox^  textBox10;
	public: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripProgressBar^  toolStripProgressBar1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripLabel^  toolStripLabel2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	public:
		Byte receivs;

		MyForm3(void)
		{
			InitializeComponent();
			findPorts();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm3()
		{
			//close serialPort
			this->serialPort1->Close();
			// update progress bar
			this->progressBar1->Value = 0;
			// Enable read button
			this->button4->Enabled = true;
			// Enable the init button
			this->button1->Enabled = true;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm3::typeid));
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
				 this->as = (gcnew System::Windows::Forms::TabControl());
				 this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
				 this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
				 this->toolStripProgressBar1 = (gcnew System::Windows::Forms::ToolStripProgressBar());
				 this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->toolStripLabel1 = (gcnew System::Windows::Forms::ToolStripLabel());
				 this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
				 this->toolStripLabel2 = (gcnew System::Windows::Forms::ToolStripLabel());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->textBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
				 this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->panel3 = (gcnew System::Windows::Forms::Panel());
				 this->label27 = (gcnew System::Windows::Forms::Label());
				 this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->label22 = (gcnew System::Windows::Forms::Label());
				 this->label23 = (gcnew System::Windows::Forms::Label());
				 this->label24 = (gcnew System::Windows::Forms::Label());
				 this->label25 = (gcnew System::Windows::Forms::Label());
				 this->label26 = (gcnew System::Windows::Forms::Label());
				 this->label20 = (gcnew System::Windows::Forms::Label());
				 this->label21 = (gcnew System::Windows::Forms::Label());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->panel15 = (gcnew System::Windows::Forms::Panel());
				 this->panel14 = (gcnew System::Windows::Forms::Panel());
				 this->panel13 = (gcnew System::Windows::Forms::Panel());
				 this->panel12 = (gcnew System::Windows::Forms::Panel());
				 this->panel11 = (gcnew System::Windows::Forms::Panel());
				 this->panel10 = (gcnew System::Windows::Forms::Panel());
				 this->panel9 = (gcnew System::Windows::Forms::Panel());
				 this->panel8 = (gcnew System::Windows::Forms::Panel());
				 this->panel7 = (gcnew System::Windows::Forms::Panel());
				 this->panel6 = (gcnew System::Windows::Forms::Panel());
				 this->panel5 = (gcnew System::Windows::Forms::Panel());
				 this->panel4 = (gcnew System::Windows::Forms::Panel());
				 this->textBox10 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox9 = (gcnew System::Windows::Forms::TextBox());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->textBox6 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox8 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox7 = (gcnew System::Windows::Forms::TextBox());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->as->SuspendLayout();
				 this->tabPage1->SuspendLayout();
				 this->toolStrip1->SuspendLayout();
				 this->panel2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				 this->panel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
				 this->panel3->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
				 this->tabPage2->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 this->panel4->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->FileName = L"openFileDialog1";
				 // 
				 // serialPort1
				 // 
				 this->serialPort1->BaudRate = 115200;
				 this->serialPort1->PortName = L"COM6";
				 this->serialPort1->ReadTimeout = 5;
				 this->serialPort1->ReceivedBytesThreshold = 8;
				 this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &MyForm3::serialPort1_DataReceived);
				 // 
				 // as
				 // 
				 this->as->Controls->Add(this->tabPage1);
				 this->as->Controls->Add(this->tabPage2);
				 this->as->Location = System::Drawing::Point(5, 3);
				 this->as->Name = L"as";
				 this->as->SelectedIndex = 0;
				 this->as->Size = System::Drawing::Size(733, 426);
				 this->as->TabIndex = 13;
				 // 
				 // tabPage1
				 // 
				 this->tabPage1->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage1->Controls->Add(this->toolStrip1);
				 this->tabPage1->Controls->Add(this->panel2);
				 this->tabPage1->Controls->Add(this->panel1);
				 this->tabPage1->Controls->Add(this->panel3);
				 this->tabPage1->Location = System::Drawing::Point(4, 22);
				 this->tabPage1->Name = L"tabPage1";
				 this->tabPage1->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage1->Size = System::Drawing::Size(725, 400);
				 this->tabPage1->TabIndex = 0;
				 this->tabPage1->Text = L"Komunikacja";
				 // 
				 // toolStrip1
				 // 
				 this->toolStrip1->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					 this->toolStripProgressBar1,
						 this->toolStripSeparator1, this->toolStripLabel1, this->toolStripSeparator2, this->toolStripLabel2
				 });
				 this->toolStrip1->Location = System::Drawing::Point(3, 372);
				 this->toolStrip1->Name = L"toolStrip1";
				 this->toolStrip1->Size = System::Drawing::Size(719, 25);
				 this->toolStrip1->TabIndex = 16;
				 this->toolStrip1->Text = L"toolStrip1";
				 // 
				 // toolStripProgressBar1
				 // 
				 this->toolStripProgressBar1->Name = L"toolStripProgressBar1";
				 this->toolStripProgressBar1->Size = System::Drawing::Size(100, 22);
				 // 
				 // toolStripSeparator1
				 // 
				 this->toolStripSeparator1->Name = L"toolStripSeparator1";
				 this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
				 // 
				 // toolStripLabel1
				 // 
				 this->toolStripLabel1->Name = L"toolStripLabel1";
				 this->toolStripLabel1->Size = System::Drawing::Size(0, 22);
				 // 
				 // toolStripSeparator2
				 // 
				 this->toolStripSeparator2->Name = L"toolStripSeparator2";
				 this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
				 // 
				 // toolStripLabel2
				 // 
				 this->toolStripLabel2->Name = L"toolStripLabel2";
				 this->toolStripLabel2->Size = System::Drawing::Size(242, 22);
				 this->toolStripLabel2->Text = L"Wybierz port COM i po³¹cz ze sterownikiem !";
				 // 
				 // panel2
				 // 
				 this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->panel2->Controls->Add(this->pictureBox1);
				 this->panel2->Controls->Add(this->textBox2);
				 this->panel2->Controls->Add(this->label9);
				 this->panel2->Controls->Add(this->dataGridView1);
				 this->panel2->Controls->Add(this->button2);
				 this->panel2->Controls->Add(this->button3);
				 this->panel2->Location = System::Drawing::Point(270, 6);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(457, 363);
				 this->panel2->TabIndex = 15;
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(7, 34);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(437, 162);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox1->TabIndex = 13;
				 this->pictureBox1->TabStop = false;
				 // 
				 // textBox2
				 // 
				 this->textBox2->Location = System::Drawing::Point(32, 330);
				 this->textBox2->Multiline = true;
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->ReadOnly = true;
				 this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
				 this->textBox2->Size = System::Drawing::Size(155, 22);
				 this->textBox2->TabIndex = 12;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label9->ForeColor = System::Drawing::SystemColors::ControlText;
				 this->label9->Location = System::Drawing::Point(3, 7);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(85, 24);
				 this->label9->TabIndex = 11;
				 this->label9->Text = L"Szablon";
				 // 
				 // dataGridView1
				 // 
				 this->dataGridView1->AllowUserToAddRows = false;
				 this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
				 this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
					 this->Column1,
						 this->Column3, this->Column2
				 });
				 dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
				 dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
				 dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(238)));
				 dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
				 dataGridViewCellStyle1->NullValue = nullptr;
				 dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
				 dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
				 dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
				 this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
				 this->dataGridView1->EnableHeadersVisualStyles = false;
				 this->dataGridView1->Location = System::Drawing::Point(193, 202);
				 this->dataGridView1->Name = L"dataGridView1";
				 this->dataGridView1->ReadOnly = true;
				 this->dataGridView1->RowHeadersVisible = false;
				 this->dataGridView1->ShowCellErrors = false;
				 this->dataGridView1->ShowCellToolTips = false;
				 this->dataGridView1->ShowEditingIcon = false;
				 this->dataGridView1->Size = System::Drawing::Size(213, 150);
				 this->dataGridView1->TabIndex = 10;
				 // 
				 // Column1
				 // 
				 this->Column1->HeaderText = L"ID";
				 this->Column1->Name = L"Column1";
				 this->Column1->ReadOnly = true;
				 this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->Column1->Width = 30;
				 // 
				 // Column3
				 // 
				 this->Column3->HeaderText = L"Axis Y [mm]";
				 this->Column3->Name = L"Column3";
				 this->Column3->ReadOnly = true;
				 this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->Column3->Width = 90;
				 // 
				 // Column2
				 // 
				 this->Column2->HeaderText = L"Axis Z [mm] ";
				 this->Column2->Name = L"Column2";
				 this->Column2->ReadOnly = true;
				 this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
				 this->Column2->Width = 90;
				 // 
				 // button2
				 // 
				 this->button2->Enabled = false;
				 this->button2->Location = System::Drawing::Point(32, 202);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(155, 54);
				 this->button2->TabIndex = 4;
				 this->button2->Text = L"Wybierz";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click_1);
				 // 
				 // button3
				 // 
				 this->button3->Enabled = false;
				 this->button3->Location = System::Drawing::Point(32, 262);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(155, 58);
				 this->button3->TabIndex = 9;
				 this->button3->Text = L"Wyslij";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &MyForm3::button3_Click_1);
				 // 
				 // panel1
				 // 
				 this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->panel1->Controls->Add(this->textBox3);
				 this->panel1->Controls->Add(this->button1);
				 this->panel1->Controls->Add(this->label8);
				 this->panel1->Controls->Add(this->numericUpDown3);
				 this->panel1->Controls->Add(this->numericUpDown2);
				 this->panel1->Controls->Add(this->label7);
				 this->panel1->Controls->Add(this->label6);
				 this->panel1->Controls->Add(this->label4);
				 this->panel1->Controls->Add(this->label5);
				 this->panel1->Location = System::Drawing::Point(3, 194);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(261, 175);
				 this->panel1->TabIndex = 14;
				 // 
				 // textBox3
				 // 
				 this->textBox3->Enabled = false;
				 this->textBox3->Location = System::Drawing::Point(52, 94);
				 this->textBox3->Multiline = true;
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->ReadOnly = true;
				 this->textBox3->Size = System::Drawing::Size(163, 20);
				 this->textBox3->TabIndex = 25;
				 // 
				 // button1
				 // 
				 this->button1->Enabled = false;
				 this->button1->Location = System::Drawing::Point(80, 120);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(94, 33);
				 this->button1->TabIndex = 24;
				 this->button1->Text = L"Wgraj";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click);
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label8->Location = System::Drawing::Point(6, 11);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(144, 25);
				 this->label8->TabIndex = 23;
				 this->label8->Text = L"Konfiguracja";
				 // 
				 // numericUpDown3
				 // 
				 this->numericUpDown3->Enabled = false;
				 this->numericUpDown3->Location = System::Drawing::Point(123, 68);
				 this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 256, 0, 0, 0 });
				 this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 this->numericUpDown3->Name = L"numericUpDown3";
				 this->numericUpDown3->Size = System::Drawing::Size(68, 20);
				 this->numericUpDown3->TabIndex = 22;
				 this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 // 
				 // numericUpDown2
				 // 
				 this->numericUpDown2->Location = System::Drawing::Point(123, 40);
				 this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
				 this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 this->numericUpDown2->Name = L"numericUpDown2";
				 this->numericUpDown2->Size = System::Drawing::Size(67, 20);
				 this->numericUpDown2->TabIndex = 21;
				 this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(209, 68);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(23, 13);
				 this->label7->TabIndex = 20;
				 this->label7->Text = L"mm";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(209, 42);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(23, 13);
				 this->label6->TabIndex = 19;
				 this->label6->Text = L"mm";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(18, 70);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(81, 13);
				 this->label4->TabIndex = 18;
				 this->label4->Text = L"Iloœæ pasów [Ip]";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(18, 42);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(101, 13);
				 this->label5->TabIndex = 17;
				 this->label5->Text = L"G³ebokoœæ ciêæ [Zl]";
				 // 
				 // panel3
				 // 
				 this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->panel3->Controls->Add(this->label27);
				 this->panel3->Controls->Add(this->numericUpDown1);
				 this->panel3->Controls->Add(this->button6);
				 this->panel3->Controls->Add(this->textBox1);
				 this->panel3->Controls->Add(this->label1);
				 this->panel3->Controls->Add(this->progressBar1);
				 this->panel3->Controls->Add(this->button5);
				 this->panel3->Controls->Add(this->label3);
				 this->panel3->Controls->Add(this->comboBox2);
				 this->panel3->Controls->Add(this->label2);
				 this->panel3->Controls->Add(this->label10);
				 this->panel3->Controls->Add(this->comboBox1);
				 this->panel3->Controls->Add(this->button4);
				 this->panel3->Location = System::Drawing::Point(3, 6);
				 this->panel3->Name = L"panel3";
				 this->panel3->Size = System::Drawing::Size(261, 185);
				 this->panel3->TabIndex = 13;
				 // 
				 // label27
				 // 
				 this->label27->AutoSize = true;
				 this->label27->Location = System::Drawing::Point(5, 104);
				 this->label27->Name = L"label27";
				 this->label27->Size = System::Drawing::Size(39, 13);
				 this->label27->TabIndex = 29;
				 this->label27->Text = L"Adress";
				 // 
				 // numericUpDown1
				 // 
				 this->numericUpDown1->Location = System::Drawing::Point(52, 102);
				 this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
				 this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 this->numericUpDown1->Name = L"numericUpDown1";
				 this->numericUpDown1->Size = System::Drawing::Size(52, 20);
				 this->numericUpDown1->TabIndex = 28;
				 this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
				 // 
				 // button6
				 // 
				 this->button6->Location = System::Drawing::Point(160, 76);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(75, 23);
				 this->button6->TabIndex = 27;
				 this->button6->Text = L"Odœwie¿";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->Click += gcnew System::EventHandler(this, &MyForm3::button6_Click_1);
				 // 
				 // textBox1
				 // 
				 this->textBox1->Enabled = false;
				 this->textBox1->Location = System::Drawing::Point(52, 158);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->ReadOnly = true;
				 this->textBox1->Size = System::Drawing::Size(183, 20);
				 this->textBox1->TabIndex = 26;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label1->Location = System::Drawing::Point(168, 28);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(56, 20);
				 this->label1->TabIndex = 14;
				 this->label1->Text = L"Status";
				 // 
				 // progressBar1
				 // 
				 this->progressBar1->Location = System::Drawing::Point(162, 51);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(73, 23);
				 this->progressBar1->TabIndex = 13;
				 // 
				 // button5
				 // 
				 this->button5->Location = System::Drawing::Point(167, 129);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(68, 23);
				 this->button5->TabIndex = 12;
				 this->button5->Text = L"Roz³¹cz";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &MyForm3::button5_Click_1);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label3->Location = System::Drawing::Point(7, 7);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(110, 24);
				 this->label3->TabIndex = 11;
				 this->label3->Text = L"Ustawienia";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"9600", L"19200", L"115200" });
				 this->comboBox2->Location = System::Drawing::Point(52, 75);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(96, 21);
				 this->comboBox2->TabIndex = 10;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(5, 78);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(32, 13);
				 this->label2->TabIndex = 9;
				 this->label2->Text = L"Boud";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(5, 51);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(26, 13);
				 this->label10->TabIndex = 8;
				 this->label10->Text = L"Port";
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Location = System::Drawing::Point(52, 48);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(96, 21);
				 this->comboBox1->TabIndex = 7;
				 // 
				 // button4
				 // 
				 this->button4->Location = System::Drawing::Point(52, 129);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(75, 23);
				 this->button4->TabIndex = 6;
				 this->button4->Text = L"Po³¹cz";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &MyForm3::button4_Click_1);
				 // 
				 // tabPage2
				 // 
				 this->tabPage2->BackColor = System::Drawing::Color::LightGray;
				 this->tabPage2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->tabPage2->Controls->Add(this->pictureBox2);
				 this->tabPage2->Controls->Add(this->label22);
				 this->tabPage2->Controls->Add(this->label23);
				 this->tabPage2->Controls->Add(this->label24);
				 this->tabPage2->Controls->Add(this->label25);
				 this->tabPage2->Controls->Add(this->label26);
				 this->tabPage2->Controls->Add(this->label20);
				 this->tabPage2->Controls->Add(this->label21);
				 this->tabPage2->Controls->Add(this->label18);
				 this->tabPage2->Controls->Add(this->label19);
				 this->tabPage2->Controls->Add(this->label17);
				 this->tabPage2->Controls->Add(this->label16);
				 this->tabPage2->Controls->Add(this->panel15);
				 this->tabPage2->Controls->Add(this->panel14);
				 this->tabPage2->Controls->Add(this->panel13);
				 this->tabPage2->Controls->Add(this->panel12);
				 this->tabPage2->Controls->Add(this->panel11);
				 this->tabPage2->Controls->Add(this->panel10);
				 this->tabPage2->Controls->Add(this->panel9);
				 this->tabPage2->Controls->Add(this->panel8);
				 this->tabPage2->Controls->Add(this->panel7);
				 this->tabPage2->Controls->Add(this->panel6);
				 this->tabPage2->Controls->Add(this->panel5);
				 this->tabPage2->Controls->Add(this->panel4);
				 this->tabPage2->Location = System::Drawing::Point(4, 22);
				 this->tabPage2->Name = L"tabPage2";
				 this->tabPage2->Padding = System::Windows::Forms::Padding(3);
				 this->tabPage2->Size = System::Drawing::Size(725, 400);
				 this->tabPage2->TabIndex = 1;
				 this->tabPage2->Text = L"Online";
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->pictureBox2->Location = System::Drawing::Point(6, 214);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(713, 181);
				 this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox2->TabIndex = 37;
				 this->pictureBox2->TabStop = false;
				 // 
				 // label22
				 // 
				 this->label22->AutoSize = true;
				 this->label22->Location = System::Drawing::Point(538, 173);
				 this->label22->Name = L"label22";
				 this->label22->Size = System::Drawing::Size(19, 13);
				 this->label22->TabIndex = 36;
				 this->label22->Text = L"Vz";
				 // 
				 // label23
				 // 
				 this->label23->AutoSize = true;
				 this->label23->Location = System::Drawing::Point(540, 135);
				 this->label23->Name = L"label23";
				 this->label23->Size = System::Drawing::Size(19, 13);
				 this->label23->TabIndex = 35;
				 this->label23->Text = L"Vy";
				 // 
				 // label24
				 // 
				 this->label24->AutoSize = true;
				 this->label24->Location = System::Drawing::Point(536, 101);
				 this->label24->Name = L"label24";
				 this->label24->Size = System::Drawing::Size(19, 13);
				 this->label24->TabIndex = 34;
				 this->label24->Text = L"Vx";
				 // 
				 // label25
				 // 
				 this->label25->AutoSize = true;
				 this->label25->Location = System::Drawing::Point(540, 66);
				 this->label25->Name = L"label25";
				 this->label25->Size = System::Drawing::Size(46, 13);
				 this->label25->TabIndex = 33;
				 this->label25->Text = L"KR TY£";
				 // 
				 // label26
				 // 
				 this->label26->AutoSize = true;
				 this->label26->Location = System::Drawing::Point(538, 35);
				 this->label26->Name = L"label26";
				 this->label26->Size = System::Drawing::Size(63, 13);
				 this->label26->TabIndex = 32;
				 this->label26->Text = L"KR PRZÓD";
				 // 
				 // label20
				 // 
				 this->label20->AutoSize = true;
				 this->label20->Location = System::Drawing::Point(661, 184);
				 this->label20->Name = L"label20";
				 this->label20->Size = System::Drawing::Size(39, 13);
				 this->label20->TabIndex = 31;
				 this->label20->Text = L"LEWO";
				 // 
				 // label21
				 // 
				 this->label21->AutoSize = true;
				 this->label21->Location = System::Drawing::Point(659, 149);
				 this->label21->Name = L"label21";
				 this->label21->Size = System::Drawing::Size(48, 13);
				 this->label21->TabIndex = 30;
				 this->label21->Text = L"PRAWO";
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(662, 114);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(30, 13);
				 this->label18->TabIndex = 29;
				 this->label18->Text = L"DÓ£";
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Location = System::Drawing::Point(661, 80);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(38, 13);
				 this->label19->TabIndex = 28;
				 this->label19->Text = L"GÓRA";
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(665, 47);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(28, 13);
				 this->label17->TabIndex = 27;
				 this->label17->Text = L"TY£";
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(663, 14);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(45, 13);
				 this->label16->TabIndex = 26;
				 this->label16->Text = L"PRZÓD";
				 // 
				 // panel15
				 // 
				 this->panel15->Location = System::Drawing::Point(616, 178);
				 this->panel15->Name = L"panel15";
				 this->panel15->Size = System::Drawing::Size(28, 30);
				 this->panel15->TabIndex = 25;
				 // 
				 // panel14
				 // 
				 this->panel14->Location = System::Drawing::Point(616, 143);
				 this->panel14->Name = L"panel14";
				 this->panel14->Size = System::Drawing::Size(28, 28);
				 this->panel14->TabIndex = 24;
				 // 
				 // panel13
				 // 
				 this->panel13->Location = System::Drawing::Point(616, 110);
				 this->panel13->Name = L"panel13";
				 this->panel13->Size = System::Drawing::Size(28, 26);
				 this->panel13->TabIndex = 23;
				 // 
				 // panel12
				 // 
				 this->panel12->Location = System::Drawing::Point(616, 75);
				 this->panel12->Name = L"panel12";
				 this->panel12->Size = System::Drawing::Size(28, 28);
				 this->panel12->TabIndex = 22;
				 // 
				 // panel11
				 // 
				 this->panel11->Location = System::Drawing::Point(616, 42);
				 this->panel11->Name = L"panel11";
				 this->panel11->Size = System::Drawing::Size(28, 26);
				 this->panel11->TabIndex = 21;
				 // 
				 // panel10
				 // 
				 this->panel10->Location = System::Drawing::Point(616, 9);
				 this->panel10->Name = L"panel10";
				 this->panel10->Size = System::Drawing::Size(28, 26);
				 this->panel10->TabIndex = 20;
				 // 
				 // panel9
				 // 
				 this->panel9->Location = System::Drawing::Point(500, 162);
				 this->panel9->Name = L"panel9";
				 this->panel9->Size = System::Drawing::Size(27, 28);
				 this->panel9->TabIndex = 19;
				 // 
				 // panel8
				 // 
				 this->panel8->Location = System::Drawing::Point(500, 130);
				 this->panel8->Name = L"panel8";
				 this->panel8->Size = System::Drawing::Size(27, 25);
				 this->panel8->TabIndex = 18;
				 // 
				 // panel7
				 // 
				 this->panel7->Location = System::Drawing::Point(500, 94);
				 this->panel7->Name = L"panel7";
				 this->panel7->Size = System::Drawing::Size(27, 28);
				 this->panel7->TabIndex = 17;
				 // 
				 // panel6
				 // 
				 this->panel6->Location = System::Drawing::Point(500, 61);
				 this->panel6->Name = L"panel6";
				 this->panel6->Size = System::Drawing::Size(27, 26);
				 this->panel6->TabIndex = 16;
				 // 
				 // panel5
				 // 
				 this->panel5->Location = System::Drawing::Point(500, 28);
				 this->panel5->Name = L"panel5";
				 this->panel5->Size = System::Drawing::Size(27, 26);
				 this->panel5->TabIndex = 15;
				 // 
				 // panel4
				 // 
				 this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->panel4->Controls->Add(this->textBox10);
				 this->panel4->Controls->Add(this->textBox9);
				 this->panel4->Controls->Add(this->label13);
				 this->panel4->Controls->Add(this->label12);
				 this->panel4->Controls->Add(this->label11);
				 this->panel4->Controls->Add(this->textBox6);
				 this->panel4->Controls->Add(this->textBox5);
				 this->panel4->Controls->Add(this->textBox4);
				 this->panel4->Controls->Add(this->textBox8);
				 this->panel4->Controls->Add(this->textBox7);
				 this->panel4->Controls->Add(this->label15);
				 this->panel4->Controls->Add(this->label14);
				 this->panel4->Location = System::Drawing::Point(6, 15);
				 this->panel4->Name = L"panel4";
				 this->panel4->Size = System::Drawing::Size(476, 193);
				 this->panel4->TabIndex = 13;
				 // 
				 // textBox10
				 // 
				 this->textBox10->Enabled = false;
				 this->textBox10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox10->Location = System::Drawing::Point(359, 8);
				 this->textBox10->Name = L"textBox10";
				 this->textBox10->ReadOnly = true;
				 this->textBox10->Size = System::Drawing::Size(34, 35);
				 this->textBox10->TabIndex = 22;
				 // 
				 // textBox9
				 // 
				 this->textBox9->Enabled = false;
				 this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox9->Location = System::Drawing::Point(19, 148);
				 this->textBox9->Name = L"textBox9";
				 this->textBox9->ReadOnly = true;
				 this->textBox9->Size = System::Drawing::Size(427, 26);
				 this->textBox9->TabIndex = 21;
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label13->Location = System::Drawing::Point(29, 106);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(78, 20);
				 this->label13->TabIndex = 20;
				 this->label13->Text = L"Z Zadane";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label12->Location = System::Drawing::Point(29, 65);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(84, 20);
				 this->label12->TabIndex = 19;
				 this->label12->Text = L"Z aktualne";
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label11->Location = System::Drawing::Point(136, 18);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(95, 20);
				 this->label11->TabIndex = 18;
				 this->label11->Text = L"Numer pasa";
				 // 
				 // textBox6
				 // 
				 this->textBox6->Enabled = false;
				 this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox6->Location = System::Drawing::Point(126, 97);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->ReadOnly = true;
				 this->textBox6->Size = System::Drawing::Size(99, 35);
				 this->textBox6->TabIndex = 17;
				 // 
				 // textBox5
				 // 
				 this->textBox5->Enabled = false;
				 this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox5->Location = System::Drawing::Point(126, 56);
				 this->textBox5->Name = L"textBox5";
				 this->textBox5->ReadOnly = true;
				 this->textBox5->Size = System::Drawing::Size(99, 35);
				 this->textBox5->TabIndex = 16;
				 // 
				 // textBox4
				 // 
				 this->textBox4->Enabled = false;
				 this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox4->Location = System::Drawing::Point(237, 8);
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->ReadOnly = true;
				 this->textBox4->Size = System::Drawing::Size(99, 35);
				 this->textBox4->TabIndex = 15;
				 // 
				 // textBox8
				 // 
				 this->textBox8->Enabled = false;
				 this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox8->Location = System::Drawing::Point(342, 97);
				 this->textBox8->Name = L"textBox8";
				 this->textBox8->ReadOnly = true;
				 this->textBox8->Size = System::Drawing::Size(104, 35);
				 this->textBox8->TabIndex = 14;
				 // 
				 // textBox7
				 // 
				 this->textBox7->Enabled = false;
				 this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->textBox7->Location = System::Drawing::Point(342, 55);
				 this->textBox7->Name = L"textBox7";
				 this->textBox7->ReadOnly = true;
				 this->textBox7->Size = System::Drawing::Size(104, 35);
				 this->textBox7->TabIndex = 13;
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label15->Location = System::Drawing::Point(251, 105);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(79, 20);
				 this->label15->TabIndex = 12;
				 this->label15->Text = L"Y Zadane";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(238)));
				 this->label14->Location = System::Drawing::Point(251, 64);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(85, 20);
				 this->label14->TabIndex = 11;
				 this->label14->Text = L"Y aktualne";
				 // 
				 // MyForm3
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(737, 433);
				 this->Controls->Add(this->as);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"MyForm3";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L" Komunikacja";
				 this->as->ResumeLayout(false);
				 this->tabPage1->ResumeLayout(false);
				 this->tabPage1->PerformLayout();
				 this->toolStrip1->ResumeLayout(false);
				 this->toolStrip1->PerformLayout();
				 this->panel2->ResumeLayout(false);
				 this->panel2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
				 this->panel3->ResumeLayout(false);
				 this->panel3->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
				 this->tabPage2->ResumeLayout(false);
				 this->tabPage2->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 this->panel4->ResumeLayout(false);
				 this->panel4->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion 

			 //-----------wyliczenie CRC dla  protokolu MODBUS----------------------------
			 unsigned short crc;
			 int rozmiar, rozmiar2, rozmiar3;
			 unsigned short ModbusCRC(unsigned char * buf, int size){

				 unsigned short crc = 0xffff;
				 int i;

				 while (size--){
					 crc ^= *buf;
					 buf++;
					 for (i = 0; i < 8; i++){
						 if (crc & 1){
							 crc >>= 1;
							 crc ^= 0xA001;
						 }
						 else{
							 crc >>= 1;
						 }
					 }
				 }
				 return crc;
			 }
			 //----------------------------------------------------------------------------------------------------
	private: void findPorts(void)
	{
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		this->comboBox1->Items->AddRange(objectArray);
	}
			 //wysy³anie konfiguracji z potwierdzeniem------------------------------------------------------
	public: void wyslij(void){
		textBox3->Clear();
		unsigned char ramka[8];
		array<Byte>^ transmit = gcnew array< Byte >(8);
		rozmiar = 8;
		ramka[0] = 0x01;
		ramka[1] = 0x10;
		ramka[2] = 0x10;
		ramka[3] = 0x00;
		ramka[4] = Convert::ToInt32(this->numericUpDown2->Value);
		ramka[5] = Convert::ToInt32(this->numericUpDown3->Value);

		crc = ModbusCRC(ramka, rozmiar - 2);
		ramka[rozmiar - 2] = Convert::ToInt32(crc);
		crc >>= 8;
		ramka[rozmiar - 1] = Convert::ToInt32(crc);

		for (int i = 0; i < rozmiar; i++){
			transmit[i] = Convert::ToByte(ramka[i]);
			textBox3->AppendText(ramka[i].ToString("X2"));
		}
		String^ name = this->serialPort1->PortName;
		String^ message = this->textBox3->Text;
		if (this->serialPort1->IsOpen){
			this->serialPort1->Write(transmit, 0, rozmiar);
			toolStripProgressBar1->Value = 75;
		}
		else
			this->textBox1->Text = "Port jest zamkniêty";
	}
			//wysy³anie potwierdzenia == 1 konfiguracji -----------------------------------------------------

	public: void wyslijPotwierdzenieKonfiguracji(void){
		textBox3->Clear();
		unsigned char ramka[8];
		array<Byte>^ transmit = gcnew array< Byte >(8);
		rozmiar = 8;
		ramka[0] = 0x01;
		ramka[1] = 0x06;
		ramka[2] = 0x00;
		ramka[3] = 0x01;
		ramka[4] = 0x01;
		ramka[5] = 0x01;

		crc = ModbusCRC(ramka, rozmiar - 2);
		ramka[rozmiar - 2] = Convert::ToInt32(crc);
		crc >>= 8;
		ramka[rozmiar - 1] = Convert::ToInt32(crc);

		for (int i = 0; i < rozmiar; i++){
			transmit[i] = Convert::ToByte(ramka[i]);
			textBox3->AppendText(ramka[i].ToString("X2"));
		}
		String^ name = this->serialPort1->PortName;
		String^ message = this->textBox3->Text;
		if (this->serialPort1->IsOpen){
			this->serialPort1->Write(transmit, 0, rozmiar);
		}
		else
			this->textBox1->Text = "Port jest zamkniêty";
	}


			//wysy³anie szablonu z potwierdzeniem------------------------------------------------------
	public: void wyslij2(void){
		textBox2->Clear();
		array<Byte>^ transmit2 = gcnew array< Byte >(10);
		unsigned int temp;
		int n = 0;
		int c = 0;
		unsigned char ramka2[10];
		ramka2[0] = 0x01;
		ramka2[1] = 0x10;
		ramka2[2] = 0x00;
		ramka2[3] = szablonOk;
		ramka2[4] = tabYMSB[szablonOk];
		ramka2[5] = tabYLSB[szablonOk];
		ramka2[6] = tabZMSB[szablonOk];
		ramka2[7] = tabZLSB[szablonOk];

		rozmiar2 = transmit2->Length;
		crc = ModbusCRC(ramka2, rozmiar2 - 2);
		ramka2[rozmiar2 - 2] = Convert::ToInt32(crc);
		crc >>= 8;
		ramka2[rozmiar2 - 1] = Convert::ToInt32(crc);

		for (int i = 0; i < transmit2->Length; i++){
			transmit2[i] = Convert::ToByte(ramka2[i]);
			textBox2->AppendText(ramka2[i].ToString("X2"));
		}

		String^ name = this->serialPort1->PortName;
		if (this->serialPort1->IsOpen){
			this->serialPort1->Write(transmit2, 0, transmit2->Length);
		}
		else
			this->textBox1->Text = "Port jest zamkniety";
	}
			//wysy³anie potwierdzenia == 1 szablonu -----------------------------------------------------
	public: void wyslijPotwierdzenieSzablonu(void){
		textBox3->Clear();
		unsigned char ramka[8];
		array<Byte>^ transmit = gcnew array< Byte >(8);
		rozmiar = 8;
		ramka[0] = 0x01;
		ramka[1] = 0x06;
		ramka[2] = 0x00;
		ramka[3] = 0x02;
		ramka[4] = 0x01;
		ramka[5] = 0x01;

		crc = ModbusCRC(ramka, rozmiar - 2);
		ramka[rozmiar - 2] = Convert::ToInt32(crc);
		crc >>= 8;
		ramka[rozmiar - 1] = Convert::ToInt32(crc);

		for (int i = 0; i < rozmiar; i++){
			transmit[i] = Convert::ToByte(ramka[i]);
			textBox3->AppendText(ramka[i].ToString("X2"));
		}
		String^ name = this->serialPort1->PortName;
		String^ message = this->textBox3->Text;
		if (this->serialPort1->IsOpen){
			this->serialPort1->Write(transmit, 0, rozmiar);
		}
		else
			this->textBox1->Text = "Port jest zamkniêty";
	}
			int zlicz = 0;

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text = String::Empty;
		if (this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
			this->textBox1->Text = "Proszê wybrac port";
		else {
			try{
				if (!this->serialPort1->IsOpen){
					this->serialPort1->PortName = this->comboBox1->Text;
					this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text);
					this->serialPort1->Open();
					this->progressBar1->Value = 100;
				}
				else
					this->textBox1->Text = "Port jest zamkniêty";
			}
			catch (UnauthorizedAccessException^){
				this->textBox1->Text = "B³¹d po³¹czenia. Spróbuj ponownie.";
			}
		}
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		this->serialPort1->Close();
		this->progressBar1->Value = 0;
		this->button4->Enabled = true;
		this->button1->Enabled = true;
	}

	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		dataGridView1->Enabled = true;
		dataGridView1->Rows->Clear();
		zlicz = 0;
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		String ^ktory;
		openFileDialog1->InitialDirectory = "d:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){

			if ((myStream = openFileDialog1->OpenFile()) != nullptr){
				String^ pfad = openFileDialog1->FileName; //Datei zum einlesen 
				StreamReader^ sr = gcnew StreamReader(pfad); //lese Daten
				Bitmap^ bmap;

				int n = 1;
				while (sr->Peek() >= 0) {
					String ^s = sr->ReadLine();
					array<String^>^words = s->Split(';');
					for (int i = 1; i < words->Length - 1; i += 2){
						ktory = words[0];
						if (i != 0) zlicz++;
						dataGridView1->Rows->Add(zlicz, words[i], words[i + 1]);

						this->toolStripLabel2->Text = "Wyœlij ramke z konfiguracj¹ !";
						this->toolStripLabel1->Text = "";
						this->button1->Enabled = true;
					}
					this->numericUpDown3->Value = zlicz;
					try{
						bmap = gcnew Bitmap(ktory + ".jpg");
					}
					catch (ArgumentException^){
						MessageBox::Show("B³êdna nazwa obrazka!", "Odczyt",
							MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					this->pictureBox1->Image = bmap;
					this->pictureBox2->Image = bmap;
				}
				sr->Close();
			}
		}
	}
	private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
		String^m;
		this->toolStripLabel1->Text = "Wysy³anie szablonu...";
		textBox2->Clear();
		this->toolStripLabel2->Text = "";
		tabZ = gcnew array<Int32>(zlicz + 1);
		tabY = gcnew array<Int32>(zlicz + 1);
		tabZMSB = gcnew array<Int32>(zlicz + 1);
		tabZLSB = gcnew array<Int32>(zlicz + 1);
		tabYMSB = gcnew array<Int32>(zlicz + 1);
		tabYLSB = gcnew array<Int32>(zlicz + 1);

		for (int i = 0; i < dataGridView1->RowCount; i++){
			m = Convert::ToString(dataGridView1->Rows[i]->Cells[1]->Value);
			String^ correctString = m->Replace(",", "");
			tabZ[i] = Convert::ToInt32(correctString);
		}
		for (int i = 0; i < dataGridView1->RowCount; i++){
			m = Convert::ToString(dataGridView1->Rows[i]->Cells[2]->Value);
			String^ correctString = m->Replace(",", "");
			tabY[i] = Convert::ToInt32(correctString);
		}

		for (int i = 0; i < tabY->Length; i++){
			tabYMSB[i] = tabY[i] & 0xff;
			tabYLSB[i] = tabY[i] >> 8;
		}
		for (int i = 0; i < tabZ->Length; i++){
			tabZMSB[i] = tabZ[i] & 0xff;
			tabZLSB[i] = tabZ[i] >> 8;
		}
		wyslij2();
	}
	private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->textBox1->Text = String::Empty;
		if (this->comboBox1->Text == String::Empty || this->comboBox2->Text == String::Empty)
			this->textBox1->Text = "Proszê wybrac port";
		else {
			try{
				if (!this->serialPort1->IsOpen){
					this->toolStripLabel1->Text = "Wybierz szablon";
					this->serialPort1->PortName = this->comboBox1->Text;
					this->serialPort1->BaudRate = Int32::Parse(this->comboBox2->Text);
					this->serialPort1->Open();
					this->progressBar1->Value = 100;
					this->comboBox1->Enabled = false;
					this->comboBox2->Enabled = false;
					this->numericUpDown1->Enabled = false;
					this->button6->Enabled = false;
					this->button2->Enabled = true;
					this->button2->Enabled = true;
					this->button4->Enabled = false;
					this->toolStripLabel2->Text = "";
				}
				else
					this->textBox1->Text = "Port jest zamkniêty";
			}
			catch (UnauthorizedAccessException^){
				this->textBox1->Text = "B³¹d po³¹czenia. Spróbuj ponownie.";
			}
		}
	}
	private: System::Void button5_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->toolStripProgressBar1->Value = 0;
		this->serialPort1->Close();
		this->progressBar1->Value = 0;
		this->button4->Enabled = true;
		this->button1->Enabled = true;
		this->comboBox1->Enabled = true;
		this->comboBox2->Enabled = true;
		this->button2->Enabled = false;
		this->button4->Enabled = true;
		this->numericUpDown1->Enabled = true;
		this->button1->Enabled = false;
		this->button6->Enabled = true;
		this->button2->Enabled = false;
		this->toolStripLabel1->Text = "";
		this->toolStripLabel2->Text = "Wybierz port COM i po³¹cz ze sterownikiem !";
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		// check if port is ready for reading
		if (this->serialPort1->IsOpen){
			this->textBox9->Text = String::Empty;
			try{
				this->textBox9->Text = this->serialPort1->ReadLine();
			}
			catch (TimeoutException^){
				this->textBox9->Text = "Timeout";
			}
		}
		else
			this->textBox9->Text = "Port jest zamkniêty";
	}
	public: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {

		numbytes = serialPort1->BytesToRead;
		++licznikDanych;

		encodedBytes = gcnew array<Byte>(numbytes);
		for (int ck = 0; ck < numbytes; ck++){
			encodedBytes[ck] = 0;
		}
		if (sender == this->serialPort1){
			for (int ck = 0; ck < numbytes; ck++){
				encodedBytes[ck] = serialPort1->ReadByte();
			}
			this->Invoke(gcnew EventHandler(this, &MyForm3::SetTextCallback), encodedBytes);  //callbeck dla odczytów w innym thread
		}
		else{
		}
	}
	private: System::Void SetTextCallback(System::Object^ sender, System::EventArgs^ e){
		textBox10->Text = licznikDanych.ToString();
		if (sender != this->serialPort1){
			unsigned char ramka23[23];
			textBox9->Clear();
			for (ck = 0; ck < numbytes; ck++){
				this->textBox9->Text += ((encodedBytes[ck].ToString("X2")));
			}
			for (int i = 0; i < numbytes; i++){
				ramka23[i] = Convert::ToChar(encodedBytes[i]);
			}
			crc = ModbusCRC(ramka23, numbytes - 2);
			if (ramka23[numbytes - 2] == (crc & 0xFF)){													//sprawdzenie crc
				crc >>= 8;
				if (ramka23[numbytes - 1] == Convert::ToChar(crc)){										//sprawdzenie crc
					if (numbytes == 8){
						if (ramka23[0] == Convert::ToInt32(this->numericUpDown1->Value)){                //sprawdzenie adresu
							if (ramka23[4] == Convert::ToInt32(this->numericUpDown2->Value)){
								if (ramka23[5] == Convert::ToInt32(this->numericUpDown3->Value)){
									configureOk = 2;
									toolStripLabel1->Text = "Ramka konfiguracyjna wys³ana poprawnie !";				//potwierdzenie ramki configuracyjnej
									toolStripLabel2->Text = "Wyœlij szablon !";
									toolStripProgressBar1->Value = 100;
									wyslijPotwierdzenieKonfiguracji();
									this->button3->Enabled = true;
								}
							}
						}
					}
					else if (numbytes == 10){
						if (szablonOk < (zlicz)){
							if (ramka23[0] == Convert::ToInt32(this->numericUpDown1->Value)){                //sprawdzenie adresu
								if (ramka23[3] == szablonOk){
									if (ramka23[4] == tabYMSB[szablonOk]){
										if (ramka23[5] == tabYLSB[szablonOk]){
											if (ramka23[6] == tabZMSB[szablonOk]){
												if (ramka23[7] == tabZLSB[szablonOk]){
													++szablonOk;
													wyslij2();
													toolStripProgressBar1->Value = (100 * szablonOk) / zlicz;
													this->button3->Enabled = true;
												}
											}
										}
									}
								}
							}
						}
						else{
							wyslijPotwierdzenieSzablonu();
						}
					}
					else{
						unsigned int numerPasa, ZAktualne, ZZadane, YAktualne, YZadane, kontrolki;
						numerPasa = (256 * encodedBytes[2] + encodedBytes[3]);
						ZAktualne = (256 * encodedBytes[4] + encodedBytes[5]);
						ZZadane = (256 * encodedBytes[6] + encodedBytes[7]);
						YAktualne = (256 * encodedBytes[8] + encodedBytes[9]);
						YZadane = (256 * encodedBytes[10] + encodedBytes[11]);
						kontrolki = (256 * encodedBytes[12] + encodedBytes[13]);
						this->textBox4->Text = numerPasa.ToString();
						this->textBox5->Text = (((ZAktualne / 10).ToString() + "." + (ZAktualne % 10).ToString("X2")));
						this->textBox6->Text = (((ZZadane / 10).ToString() + "." + (ZZadane % 10).ToString("X2")));
						this->textBox7->Text = (((YAktualne / 10).ToString() + "." + (YAktualne % 10).ToString("X2")));
						this->textBox8->Text = (((YZadane / 10).ToString() + "." + (YZadane % 10).ToString("X2")));
						if (kontrolki & 0x01) this->panel5->BackColor = Color::Green;
						else if (!(kontrolki & 0x01))  this->panel5->BackColor = Color::Red;
						if (kontrolki & 0x02) this->panel6->BackColor = Color::Green;
						else if (!(kontrolki & 0x02))  this->panel6->BackColor = Color::Red;
						if (kontrolki & 0x04) this->panel7->BackColor = Color::Green;
						else if (!(kontrolki & 0x04))  this->panel7->BackColor = Color::Red;
						if (kontrolki & 0x08) this->panel8->BackColor = Color::Green;
						else if (!(kontrolki & 0x08))  this->panel8->BackColor = Color::Red;
						if (kontrolki & 0x10) this->panel9->BackColor = Color::Green;
						else if (!(kontrolki & 0x10))  this->panel9->BackColor = Color::Red;
						if (kontrolki & 0x20) this->panel10->BackColor = Color::Green;
						else if (!(kontrolki & 0x20))  this->panel10->BackColor = Color::Red;
						if (kontrolki & 0x40) this->panel11->BackColor = Color::Green;
						else if (!(kontrolki & 0x40))  this->panel11->BackColor = Color::Red;
						if (kontrolki & 0x80) this->panel12->BackColor = Color::Green;
						else if (!(kontrolki & 0x80))  this->panel12->BackColor = Color::Red;
						if (kontrolki & 0x100) this->panel13->BackColor = Color::Green;
						else if (!(kontrolki & 0x100))  this->panel13->BackColor = Color::Red;
						if (kontrolki & 0x200) this->panel14->BackColor = Color::Green;
						else if (!(kontrolki & 0x200))  this->panel14->BackColor = Color::Red;
						if (kontrolki & 0x400) this->panel15->BackColor = Color::Green;
						else if (!(kontrolki & 0x400))  this->panel15->BackColor = Color::Red;
					}
				}
			}
		}
	}

	private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->comboBox1->Items->Clear();
		findPorts();
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->button2->Enabled = true;
		this->dataGridView1->Enabled = true;
		wyslij(); //budowa ramki
		toolStripProgressBar1->Value = 50;
		toolStripLabel1->Text = "Wysy³anie konfiguracji ...";
		this->toolStripLabel2->Text = "Poczekaj na wys³anie konfiguracji i wyœlij szablon !";
		String^ name = this->serialPort1->PortName;
		String^ message = this->textBox3->Text;
	}
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		wyslij(); //budowa ramki
	}

	};
}



