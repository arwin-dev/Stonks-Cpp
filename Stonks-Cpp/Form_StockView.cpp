#include "Form_StockView.h"

#include "candlestick.h"
using namespace Stonks_Cpp;

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;


[STAThreadAttribute]

void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Stonks_Cpp::Form_StockView form;
    Application::Run(% form);
}


void Form_StockView::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e)
{
    openFileDialog_LoadStock->Filter = "All Files (*.*)|*.*|Month Files (*-Month.csv)|*-Month.csv|Week Files (*-Week.csv)|*-Week.csv|Day Files (*-Day.csv)|*-Day.csv";
    openFileDialog_LoadStock->ShowDialog();
}

void Form_StockView::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    int fileCount = openFileDialog_LoadStock->FileNames->Length;
    for (int i = 0; i < fileCount ; i++)
    {
        String^ filename = openFileDialog_LoadStock->FileNames[i];
        if (i == 0)
        {
            InitializeParent(filename);
        }
        else
        {
            Stonks_Cpp::Form_StockView^ stockViewForm = gcnew Stonks_Cpp::Form_StockView(filename, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
            stockViewForm->Show();
        }
    }
}

void Form_StockView::InitializeParent(String^ filename)
{
    this->Text = filename + " (Parent)";
    chart_StockChart->Annotations->Clear();
    allCandlesticks = getStockDataFromFilename(filename);
    filterCandlesticksByDate();
    InitializePatternComboBox();
    normalizeChart();
    updateDisplay();
}

Form_StockView::Form_StockView(String^ filename, DateTime startDate, DateTime endDate)
{
    InitializeComponent();
    this->Text = filename + " (Child)";
    dateTimePicker_DateBegin->Value = startDate;
    dateTimePicker_DateEnd->Value = endDate;
    allCandlesticks = getStockDataFromFilename(filename);
    filterCandlesticksByDate();
    InitializePatternComboBox();
    normalizeChart();
    updateDisplay();
}

void Form_StockView::InitializePatternComboBox()
{
    comboBox_patterns->Items->Clear();

    if (patternTracker->Count == 0)
        return;

    for each (KeyValuePair<String^, List<smartCandlestick^>^> ^ pattern in patternTracker)
    {
        comboBox_patterns->Items->Add(pattern->Key);
    }

}

System::Void Form_StockView::comboBox_patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    chart_StockChart->Annotations->Clear();
    String^ selectedPattern = comboBox_patterns->SelectedItem->ToString();

    List<smartCandlestick^>^ pattern = nullptr;
    if (patternTracker->TryGetValue(selectedPattern, pattern))
    {
        for each (smartCandlestick ^ candlestick in pattern)
        {
            CreateAnnotation(candlestick);
        }
    }

    chart_StockChart->Refresh();
}

void Form_StockView::CreateAnnotation(smartCandlestick^ cs)
{
    int index = 0;
    for (int i = 0; i < bindingCandlesticks->Count; i++)
    {
        if (cs == bindingCandlesticks[i])
        {
            index = i;
            break;
        }
    }

    // Create a text annotation
    ArrowAnnotation^ arrowAnnotation = gcnew ArrowAnnotation();
    arrowAnnotation->AxisX = chart_StockChart->ChartAreas[0]->AxisX;
    arrowAnnotation->AxisY = chart_StockChart->ChartAreas[0]->AxisY;

    arrowAnnotation->LineWidth = 1;
    arrowAnnotation->Width = 0;
    arrowAnnotation->Height = 5;
    arrowAnnotation->ArrowSize = 2;
    arrowAnnotation->ForeColor = cs->IsBullish ? Color::Green : Color::Red;
    arrowAnnotation->LineColor = cs->IsBullish ? Color::Red : Color::Green;
    arrowAnnotation->BackColor = cs->IsBullish ? Color::Green : Color::Red;
    arrowAnnotation->AnchorOffsetY = 5;
    arrowAnnotation->SetAnchor(chart_StockChart->Series["Series_OHLC"]->Points[index]);
    chart_StockChart->Annotations->Add(arrowAnnotation);

}

void Form_StockView::normalizeChart()
{

    double max = Double::MinValue;
    double min = Double::MaxValue;

    for each (smartCandlestick ^ cs in bindingCandlesticks)
    {
        if (cs->Low < min)
        {
            min = cs->Low;
        }

        if (cs->High > max)
        {
            max = cs->High;
        }
    }

    chart_StockChart->ChartAreas["Chart_OHLC"]->AxisY->Minimum = Math::Round(min * 0.9, 2);
    chart_StockChart->ChartAreas["Chart_OHLC"]->AxisY->Maximum = Math::Round(max * 1.1, 2);

}




/// <summary>
/// Sets the text of the form to the filename selected through the openFileDialog_LoadStock dialog,
/// then retrieves stock data from the selected file and assigns it to the allCandlesticks global variable.
/// </summary>
void Form_StockView::getStockDataFromFilename()
{
    // Set the form's text to the selected filename
    this->Text = openFileDialog_LoadStock->FileName;
    // Retrieve stock data from the selected file
    allCandlesticks = getStockDataFromFilename(openFileDialog_LoadStock->FileName);
}

/// <summary>
/// Filters allcandlesticks based on dateTimePicker_DateBegin and dateTimePicker_DateEnd
/// </summary>
void Form_StockView::filterCandlesticksByDate()
{   
    bindingCandlesticks->Clear();
    // Assigns the filtered Candlesticks to the bindingCandlesticks global variable
    bindingCandlesticks = filterCandlesticksByDate(allCandlesticks, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
}

/// <summary>
/// Updates the display by binding the candlestick data to the dataGridView_StockGrid and chart_StockChart.
/// </summary>
void Form_StockView::updateDisplay()
{
    // Bind the candlestick data to the stock chart
    chart_StockChart->DataSource = bindingCandlesticks;
    chart_StockChart->DataBind();
    
}

/// <summary>
/// Event handler for the button_Refresh click event. 
/// Calls filterCandlesticksByDate and updateDisplay to update the displayed data.
/// </summary>
System::Void Form_StockView::button_Refresh_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Filter candlesticks by date and update the display
    filterCandlesticksByDate();
    chart_StockChart->Annotations->Clear();
    InitializePatternComboBox();
    updateDisplay();
}

/// <summary>
/// Filters the candlesticks data based on the specified date range.
/// </summary>
/// <param name="allCandlesticks">list of all candlesticks</param>
/// <param name="startDate">Fitler Start Date</param>
/// <param name="endDate">Filter End Date</param>
/// <returns>filteredCandlesticks - filtered Candlesticks</returns>
BindingList<smartCandlestick^>^ Form_StockView::filterCandlesticksByDate(List<smartCandlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
    // Create a new list to hold filtered candlesticks
    BindingList<smartCandlestick^>^ filteredCandlesticks = gcnew BindingList<smartCandlestick^>();

    // Check if there are candlesticks and the count is greater than 0
    if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
        // Clear the previous binding candlesticks
        bindingCandlesticks->Clear();
        patternTracker->Clear();

        // Loop through all candlesticks
        for each (smartCandlestick ^ cs in allCandlesticks)
        {
            // If the candlestick date is beyond the end date, break the loop
            if (cs->Date > dateTimePicker_DateEnd->Value) break;

            // If the candlestick date is within the specified range, add it to the filtered list
            if (cs->Date >= dateTimePicker_DateBegin->Value)
            {

                for each (KeyValuePair<String^, bool> ^ pattern in cs->Patterns)
                {

                    if (pattern->Value)
                    {
                        if (patternTracker->ContainsKey(pattern->Key))
                        {
                            patternTracker[pattern->Key]->Add(cs);
                        }
                        else
                        {
                            List<smartCandlestick^>^ newList = gcnew List<smartCandlestick^>();
                            newList->Add(cs);
                            patternTracker->Add(pattern->Key, newList);
                        }
                    }
                    else
                    {
                        if (patternTracker->ContainsKey(pattern->Key))
                            continue;
                        else
                        {
                            List<smartCandlestick^>^ newList = gcnew List<smartCandlestick^>();
                            patternTracker->Add(pattern->Key, newList);
                        }
                    }
                }

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
List<smartCandlestick^>^ Form_StockView::getStockDataFromFilename(String^ filename)
{
    // Create a new list to hold candlesticks
    List<smartCandlestick^>^ listOfCandlesticks = gcnew List<smartCandlestick^>(1024);
    // Open the file for reading
    StreamReader^ sr = gcnew StreamReader(filename);

    // Read the header line
    String^ header = sr->ReadLine();

    String^ line;
    // Read each line of the file
    while ((line = sr->ReadLine()) != nullptr)
    {
        // Create a new candlestick object and add it to the list
        listOfCandlesticks->Add(gcnew smartCandlestick(line));
    }

    return listOfCandlesticks;
}
