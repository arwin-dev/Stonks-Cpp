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

/// <summary>
/// Sets the text of the form to the filename selected through the openFileDialog_LoadStock dialog,
/// then retrieves stock data from the selected file and assigns it to the allCandlesticks global variable.
/// </summary>
void Form_StockPicker::getStockDataFromFilename()
{
    // Set the form's text to the selected filename
    this->Text = openFileDialog_LoadStock->FileName;
    // Retrieve stock data from the selected file
    allCandlesticks = getStockDataFromFilename(openFileDialog_LoadStock->FileName);
}

/// <summary>
/// Filters allcandlesticks based on dateTimePicker_DateBegin and dateTimePicker_DateEnd
/// </summary>
void Form_StockPicker::filterCandlesticksByDate()
{
    // Assigns the filtered Candlesticks to the bindingCandlesticks global variable
    bindingCandlesticks = filterCandlesticksByDate(allCandlesticks, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
}

/// <summary>
/// Updates the display by binding the candlestick data to the dataGridView_StockGrid and chart_StockChart.
/// </summary>
void Form_StockPicker::updateDisplay()
{
    // Bind the candlestick data to the stock grid view
    dataGridView_StockGrid->DataSource = bindingCandlesticks;
    // Bind the candlestick data to the stock chart
    chart_StockChart->DataSource = bindingCandlesticks;
    chart_StockChart->DataBind();
}

/// <summary>
/// Event handler for the button_LoadStock click event. Shows the openFileDialog_LoadStock dialog.
/// </summary>
System::Void Form_StockPicker::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Show the open file dialog
    openFileDialog_LoadStock->ShowDialog();
}

/// <summary>
/// Event handler for the openFileDialog_LoadStock FileOk event. 
/// Calls getStockDataFromFilename, filterCandlesticksByDate, and updateDisplay to load, filter, and display stock data.
/// </summary>
System::Void Form_StockPicker::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    // Load stock data from the selected file, filter it, and update the display
    getStockDataFromFilename();
    filterCandlesticksByDate();
    updateDisplay();
}

/// <summary>
/// Event handler for the button_Refresh click event. 
/// Calls filterCandlesticksByDate and updateDisplay to update the displayed data.
/// </summary>
System::Void Form_StockPicker::button_Refresh_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Filter candlesticks by date and update the display
    filterCandlesticksByDate();
    updateDisplay();
}

/// <summary>
/// Filters the candlesticks data based on the specified date range.
/// </summary>
/// <param name="allCandlesticks">list of all candlesticks</param>
/// <param name="startDate">Fitler Start Date</param>
/// <param name="endDate">Filter End Date</param>
/// <returns>filteredCandlesticks - filtered Candlesticks</returns>
BindingList<candlestick^>^ Form_StockPicker::filterCandlesticksByDate(List<candlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
    // Create a new list to hold filtered candlesticks
    BindingList<candlestick^>^ filteredCandlesticks = gcnew BindingList<candlestick^>();

    // Check if there are candlesticks and the count is greater than 0
    if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
        // Clear the previous binding candlesticks
        bindingCandlesticks->Clear();

        // Loop through all candlesticks
        for each (candlestick ^ cs in allCandlesticks)
        {
            // If the candlestick date is beyond the end date, break the loop
            if (cs->Date > dateTimePicker_DateEnd->Value) break;

            // If the candlestick date is within the specified range, add it to the filtered list
            if (cs->Date >= dateTimePicker_DateBegin->Value)
            {
                filteredCandlesticks->Add(cs);
            }
        }
    }
    return filteredCandlesticks;
}

/// <summary>
/// Reads stock data from the specified file and returns it as a list of candlesticks.
/// </summary>
/// <param name="filename">filename of the file to extract stock data</param>
/// <returns>listOfCandlesticks - list of all candlesticks</returns>
List<candlestick^>^ Form_StockPicker::getStockDataFromFilename(String^ filename)
{
    // Create a new list to hold candlesticks
    List<candlestick^>^ listOfCandlesticks = gcnew List<candlestick^>(1024);
    // Open the file for reading
    StreamReader^ sr = gcnew StreamReader(filename);

    // Read the header line
    String^ header = sr->ReadLine();

    String^ line;
    // Read each line of the file
    while ((line = sr->ReadLine()) != nullptr)
    {
        // Create a new candlestick object and add it to the list
        listOfCandlesticks->Add(gcnew candlestick(line));
    }

    return listOfCandlesticks;
}
