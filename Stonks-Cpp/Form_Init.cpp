#include "Form_Init.h"
#include "candlestick.h"
#include "Form_StockView.h"
using namespace Stonks_Cpp;

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Stonks_Cpp::Form_Init form;
    Application::Run(% form);
}

/// <summary>
/// Event handler for the button_LoadStock click event. Shows the openFileDialog_LoadStock dialog.
/// </summary>
System::Void Form_Init::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Show the open file dialog
    openFileDialog_LoadStock->ShowDialog();
}

/// <summary>
/// Event handler for the openFileDialog_LoadStock FileOk event. 
/// PUT COMMENTS HERE
/// </summary>
System::Void Form_Init::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    for each (String^ filename in openFileDialog_LoadStock->FileNames)
    {
        Stonks_Cpp::Form_StockView^ stockViewForm = gcnew Stonks_Cpp::Form_StockView(filename, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
        stockViewForm->Show();
    }
}

