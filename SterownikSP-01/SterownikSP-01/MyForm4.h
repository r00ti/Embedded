#pragma once
#using <system.data.dll>
#include <fstream>
namespace SterownikSP01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Data::SqlClient;
	using namespace System::Data::OleDb;


	/// <summary>
	/// Summary for MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::Button^  button1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm4::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 77);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"G³êbokoœæ ciêæ [Z]";
			// 
			// saveFileDialog1
			// 
			this->saveFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm4::saveFileDialog1_FileOk);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->DecimalPlaces = 1;
			this->numericUpDown4->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown4->Location = System::Drawing::Point(116, 75);
			this->numericUpDown4->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(65, 20);
			this->numericUpDown4->TabIndex = 22;
			this->numericUpDown4->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(216, 68);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(76, 59);
			this->button3->TabIndex = 23;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm4::button3_Click_1);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
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
			this->dataGridView1->Location = System::Drawing::Point(298, 4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(213, 354);
			this->dataGridView1->TabIndex = 29;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm4::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column1->Frozen = true;
			this->Column1->HeaderText = L"ID";
			this->Column1->MaxInputLength = 255;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Column1->Width = 30;
			// 
			// Column2
			// 
			this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->Column2->Frozen = true;
			this->Column2->HeaderText = L"Axis Z [mm]";
			this->Column2->MaxInputLength = 255;
			this->Column2->Name = L"Column2";
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->Width = 90;
			// 
			// Column3
			// 
			this->Column3->Frozen = true;
			this->Column3->HeaderText = L"Axis Y [mm]";
			this->Column3->Name = L"Column3";
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->Width = 90;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(51, 133);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 30;
			this->button4->Text = L"Zapisz";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm4::button4_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(187, 77);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 31;
			this->label4->Text = L"mm";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(10, 133);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(255, 227);
			this->pictureBox1->TabIndex = 32;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(6, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(198, 24);
			this->label2->TabIndex = 33;
			this->label2->Text = L"Tworzenie szablonu";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(90, 50);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 34;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Nazwij szablon";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(7, 361);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(471, 12);
			this->label5->TabIndex = 36;
			this->label5->Text = L"*nazwa szablonu powinna odpowiadac nazwie zdjêcia danego szablonu i znaleŸæ siê w"
				L" g³ównym folderze aplikacji";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->DecimalPlaces = 1;
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown1->Location = System::Drawing::Point(116, 102);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(65, 20);
			this->numericUpDown1->TabIndex = 37;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(187, 104);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(23, 13);
			this->label6->TabIndex = 38;
			this->label6->Text = L"mm";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(5, 104);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(99, 13);
			this->label7->TabIndex = 39;
			this->label7->Text = L"G³êbokoœæ ciêæ [Y]";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(174, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Odczytaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click_1);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(518, 379);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm4";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dodaj..";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm4_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {

		if ((e->KeyChar < 0) || (e->KeyChar >255)){
			MessageBox::Show("Zakres od 0 do 255mm", "Uwaga",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			e->KeyChar = (char)0;
		}
	}

			 int b, c;
			 int size = 255, i = 0;
			 int* myarr = new int[size];
			 int error = 0;
			 int zlicz = 0;
			 int zlicz1 = 0;

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		numericUpDown4->Maximum = 255;

		numericUpDown4->Minimum = 0;
		numericUpDown4->Value = 150;
		numericUpDown4->Visible = true;
		button3->Visible = true;

	}

	private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {

		zlicz++;
		if (zlicz <= 255){
			int n = dataGridView1->Rows->Add();
			dataGridView1->Rows[n]->Cells[0]->Value = zlicz;
			dataGridView1->Rows[n]->Cells[2]->Value = numericUpDown1->Value.ToString("0.0##");
			dataGridView1->Rows[n]->Cells[1]->Value = numericUpDown4->Value.ToString("0.0##"); // do 1 miejsca po przecinku
		}
		else  MessageBox::Show("Maksymalna iloœæ to 255 ", "Parametry",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	}
			 bool ready;
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

		error = 0;
		for (int m = 0; m < (dataGridView1->RowCount); m++){
			if ((Convert::ToDouble(dataGridView1->Rows[m]->Cells[1]->Value) >= 300, 0) && (Convert::ToDouble(dataGridView1->Rows[m]->Cells[0]->Value) >= 1)){
				dataGridView1->Rows[m]->Cells[1]->Style->BackColor = Color::Red;
				error++;
			}
			else { dataGridView1->Rows[m]->Cells[1]->Style->BackColor = Color::Green; }
			if ((Convert::ToDouble(dataGridView1->Rows[m]->Cells[2]->Value) >= 1000, 0) && (Convert::ToDouble(dataGridView1->Rows[m]->Cells[0]->Value) >= 1)){
				dataGridView1->Rows[m]->Cells[2]->Style->BackColor = Color::Red;
				error++;
			}
			else { dataGridView1->Rows[m]->Cells[2]->Style->BackColor = Color::Green; }

		}
		if (error != 0){
			MessageBox::Show("Maksymalna wartoœæ to 300 [mm]", "Parametry",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			ready = false;
		}
		else if (textBox1->Text == "")  {
			MessageBox::Show("Nadaj nazwê dla tworzonego szablonu", "Zapis",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		else{
			//-----------ZAPIS DO PLIKU TXT------------//
			ready = true;
			dataGridView1->Enabled = false;

			saveFileDialog1->Filter = "Pliki programu Stone (*.txt)|*.txt|Wszystkie pliki (*.*)|*.*";
			int col = 0, row = 0;
			String^ linia;
			col = Convert::ToInt32(dataGridView1->ColumnCount);
			row = Convert::ToInt32(dataGridView1->RowCount);

			if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				StreamWriter^ plik = gcnew StreamWriter(saveFileDialog1->FileName, 0, System::Text::Encoding::Default);
				linia += textBox1->Text;
				linia += ";";
				for (row = 0; row < (dataGridView1->RowCount); row++) {

					linia += Convert::ToString(dataGridView1->Rows[row]->Cells[1]->Value);

					linia += ";";
					linia += Convert::ToString(dataGridView1->Rows[row]->Cells[2]->Value);
					linia += ";";
				}
				plik->WriteLine(linia);
				plik->Close();
			}
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

		dataGridView1->Enabled = true;
		dataGridView1->Rows->Clear();
		zlicz = 0;
		Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
		String ^ktory;
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		this->button3->Enabled = true;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){

			if ((myStream = openFileDialog1->OpenFile()) != nullptr){
				String^ pfad = openFileDialog1->FileName; //Datei zum einlesen 
				StreamReader^ sr = gcnew StreamReader(pfad); //lese Daten
				int n = 1;
				while (sr->Peek() >= 0) {
					String ^s = sr->ReadLine();
					array<String^>^words = s->Split(';');
					for (int i = 1; i < words->Length - 1; i += 2){
						ktory = words[0];
						if (i != 0) zlicz++;
						dataGridView1->Rows->Add(zlicz, words[i], words[i + 1]);
					}
				}
				sr->Close();
			}
		}
	}
	private: System::Void saveFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		MessageBox::Show("Szablon zostal zapisany", "Zapis",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog ^openFileDialog1 = gcnew OpenFileDialog();  //create openfileDialog Object
		openFileDialog1->Filter = "XML Files (*.xml; *.xls; *.xlsx; *.xlsm; *.xlsb) |*.xml; *.xls; *.xlsx; *.xlsm; *.xlsb";//open file format define Excel Files(.xls)|*.xls| Excel Files(.xlsx)|*.xlsx| 
		openFileDialog1->FilterIndex = 3;

		openFileDialog1->Multiselect = false;        //not allow multiline selection at the file selection level
		openFileDialog1->Title = "Open Text File-R13";   //define the name of openfileDialog
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			String ^ pathconn = "Provider = Microsoft.jet.OLEDB.4.0; Data source=" + openFileDialog1->FileName + ";Extended Properties=\"Excel 8.0;HDR= yes;\";";
			OleDbConnection ^conn = gcnew OleDbConnection(pathconn);
			OleDbDataAdapter ^MyDataAdapter = gcnew OleDbDataAdapter("Select * from [" + "Arkusz1" + "$]", conn);
			DataTable^ dt = gcnew DataTable();

			MyDataAdapter->Fill(dt);
			dataGridView1->DataSource = dt;
		}
	}
	};
}
