/* 
* Code by Zhifan (Xiaobai) Li,
* This is the Entry Point of the Program to run code using MainForm
* Code modified from https://www.simplilearn.com/tutorials/cpp-tutorial/cpp-gui
* Since 0.0
*/

#include "pch.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<System::String^>^ args) {

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Projectt::MainForm form;
    Application::Run(% form);

}