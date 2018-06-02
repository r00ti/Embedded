#pragma once

#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "common.h"
namespace SterownikSP01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		array<Object^>^ portname;
		//bool polaczony;
		String ^portnames2;
		String ^bouds2;

	public:
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  button7;
	public :
	
		
		MyForm(void)
		{
			InitializeComponent();
			DateTime now = DateTime::Now;
			DateTime date = now.Date;
			TimeSpan time = now.TimeOfDay;
	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
		
			if (components)
			{
				delete components;
			}
		}

	private: System::ComponentModel::IContainer^  components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(12, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(277, 294);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button5
			// 
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->Location = System::Drawing::Point(446, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(141, 148);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(295, 12);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(145, 148);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->Location = System::Drawing::Point(295, 164);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(292, 140);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(599, 316);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->IsMdiContainer = true;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sterownik przemys³owy SP-01";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 MyForm1 ^okno = gcnew MyForm1(portname);
				 this->Hide();
				 okno->ShowDialog();
				 this->Show();
	}
	 
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 MyForm2 ^okno = gcnew MyForm2();
			 this->Hide();
			 okno->ShowDialog();
			 this->Show();

}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (!polaczony)
				 Application::Exit();
			 
			 MessageBox::Show("Roz³¹cz po³¹czenie z SP-01", "Po³¹czenie",
				 MessageBoxButtons::OK, MessageBoxIcon::Warning);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	MyForm3 ^okno = gcnew MyForm3();
	this->Hide();
	okno->ShowDialog();
	this->Show();
}
// wyliczenie CRC dla  protokolu MODBUS
private: unsigned short ModbusCRC2(unsigned char * buf, int size){
			unsigned short crc = 0xffff;
			int i;
			 while (size--){
						  crc ^= *buf;
						  buf++;
						  for (i = 0; i<8; i++){
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
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
			 MyForm4 ^okno = gcnew MyForm4();
			 this->Hide();
			 okno->ShowDialog();
			 this->Show();
}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			
			 DateTime now = DateTime::Now;
			 DateTime date = now.Date;
			 TimeSpan time = now.TimeOfDay;


}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
			 MyForm1 ^okno = gcnew MyForm1();
			 this->Hide();
			 okno->ShowDialog();
			 this->Show();
}
};
}
