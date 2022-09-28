#include "pch.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<System::String^>^ args){

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Projectt::MainForm form;
    Application::Run(% form);

}