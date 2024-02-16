#include "Form_Stock.h"
#include "candlestick.h"
using namespace Stonks;

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Stonks::Form_StockPicker form;
	Application::Run(% form);
}

void Form_StockPicker::getStockDataFromFilename()
{
	this->Text = openFileDialog_LoadStock->FileName;
	allCandlesticks = getStockDataFromFilename(openFileDialog_LoadStock->FileName);
}

void Form_StockPicker::setDateRangeForCandlesticks()
{
	bindingCandlesticks = setDateRangeForCandlesticks(allCandlesticks, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
}

void Form_StockPicker::updateDisplay()
{
	dataGridView_StockGrid->DataSource = bindingCandlesticks;
	chart_StockChart->DataSource = bindingCandlesticks;
	chart_StockChart->DataBind();
}

System::Void Form_StockPicker::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e)
{
	openFileDialog_LoadStock->ShowDialog();
}

System::Void Form_StockPicker::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	getStockDataFromFilename();

	setDateRangeForCandlesticks();

	updateDisplay();
}

System::Void Form_StockPicker::button_Refresh_Click(System::Object^ sender, System::EventArgs^ e)
{
	setDateRangeForCandlesticks();
	updateDisplay();
}

BindingList<candlestick^>^ Form_StockPicker::setDateRangeForCandlesticks(List<candlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
	BindingList<candlestick^>^ filteredCandlesticks = gcnew BindingList<candlestick^>();

	if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
		bindingCandlesticks->Clear();

		for each (candlestick ^ cs in allCandlesticks)
		{
			if (cs->Date > dateTimePicker_DateEnd->Value) break;

			if (cs->Date >= dateTimePicker_DateBegin->Value)
			{
				filteredCandlesticks->Add(cs);
			}
		}
	}
	return filteredCandlesticks;
}

List<candlestick^>^ Form_StockPicker::getStockDataFromFilename(String^ filename)
{
	List<candlestick^>^ listOfCandlesticks = gcnew List<candlestick^>(1024);
	StreamReader^ sr = gcnew StreamReader(filename);

	String^ header = sr->ReadLine();

	String^ line;
	while ((line = sr->ReadLine()) != nullptr)
	{
		listOfCandlesticks->Add(gcnew candlestick(line));
	}

	return listOfCandlesticks;
}