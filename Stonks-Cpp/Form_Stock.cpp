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

List<candlestick^>^ Form_StockPicker::setDateRangeForCandlesticks(List<candlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
	List<candlestick^>^ filteredCandlesticks = gcnew List<candlestick^>(allCandlesticks->Count);

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