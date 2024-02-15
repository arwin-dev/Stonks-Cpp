#include "Form_Stock.h"
#include "candlestick.h"
using namespace $safeprojectname$;

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	$safeprojectname$::MyForm form;
	Application::Run(% form);
}

List<candlestick^>^ MyForm::setDateRangeForCandlesticks(List<candlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
	List<candlestick^>^ filteredCandlesticks = gcnew List<candlestick^>(allCandlesticks->Count);

	if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
		bindingCandlesticks->Clear();

		for each (candlestick ^ cs in allCandlesticks)
		{
			if (cs->date > dateTimePicker_DateEnd->Value) break;

			if (cs->date >= dateTimePicker_DateBegin->Value)
			{
				filteredCandlesticks->Add(cs);
			}
		}
	}
	return filteredCandlesticks;
}

List<candlestick^>^ MyForm::getStockDataFromFilename(String^ filename)
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