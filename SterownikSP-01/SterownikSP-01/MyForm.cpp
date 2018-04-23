#include "MyForm.h"
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"



using namespace System;
using namespace System::Windows::Forms;

[STAThread]  //musimy dodaæ dyrektywê [STAThread] abyœmy mogli korzystaæ z komponentów COM oraz ich w¹tków.  Single Threaded Apartment,
void  main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SterownikSP01::MyForm form;
	Application::Run(%form);
}