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


/// <summary>
/// Event handler for the Click event of the button_LoadStock.
/// Opens the openFileDialog_LoadStock to allow the user to select stock files for loading.
/// </summary>
/// <param name="sender">The object that raised the event.</param>
/// <param name="e">Event arguments.</param>
System::Void Form_StockView::button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Set filter options for the file dialog
    openFileDialog_LoadStock->Filter = "All Files (*.*)|*.*|Month Files (*-Month.csv)|*-Month.csv|Week Files (*-Week.csv)|*-Week.csv|Day Files (*-Day.csv)|*-Day.csv";

    // Show the file dialog
    openFileDialog_LoadStock->ShowDialog();
}


/// <summary>
/// Event handler for the FileOk event of the openFileDialog_LoadStock.
/// Loads the selected stock files, initializes the parent window with the first file,
/// and creates child windows for additional files.
/// </summary>
/// <param name="sender">The object that raised the event.</param>
/// <param name="e">Event arguments.</param>
System::Void Form_StockView::openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
    // Get the number of selected files
    int fileCount = openFileDialog_LoadStock->FileNames->Length;

    // Loop through each selected file
    for (int i = 0; i < fileCount; i++)
    {
        // Get the filename
        String^ filename = openFileDialog_LoadStock->FileNames[i];

        // Initialize parent window with the first file
        if (i == 0)
        {
            InitializeParent(filename);
        }
        // Create child windows for additional files
        else
        {
            // Create a new instance of Form_StockView for the file
            Stonks_Cpp::Form_StockView^ stockViewForm = gcnew Stonks_Cpp::Form_StockView(filename, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);

            // Show the child window
            stockViewForm->Show();
        }
    }
}


/// <summary>
/// Initializes the form as a parent window.
/// Sets the form title, clears chart annotations, retrieves stock data from a file,
/// filters candlesticks by date, initializes pattern combo box, normalizes the chart,
/// and updates the display.
/// </summary>
/// <param name="filename">The filename of the stock data.</param>
void Form_StockView::InitializeParent(String^ filename)
{
    // Set the form title as parent
    this->Text = filename + " (Parent)";

    // Clear chart annotations
    chart_StockChart->Annotations->Clear();

    // Retrieve stock data from the specified filename
    allCandlesticks = getStockDataFromFilename(filename);

    // Filter candlesticks by date
    filterCandlesticksByDate();

    // Initialize pattern combo box
    InitializePatternComboBox();

    // Normalize the chart
    normalizeChart();

    // Update the display
    updateDisplay();
}


/// <summary>
/// Constructor for the Form_StockView class.
/// Initializes the form components, sets the form title, sets date picker values,
/// retrieves stock data from a file, filters candlesticks by date, initializes pattern combo box,
/// normalizes the chart, and updates the display.
/// </summary>
/// <param name="filename">The filename of the stock data.</param>
/// <param name="startDate">The start date for filtering candlesticks.</param>
/// <param name="endDate">The end date for filtering candlesticks.</param>
Form_StockView::Form_StockView(String^ filename, DateTime startDate, DateTime endDate)
{
    // Initialize form components
    InitializeComponent();

    // Set the form title
    this->Text = filename + " (Child)";

    // Set date picker values
    dateTimePicker_DateBegin->Value = startDate;
    dateTimePicker_DateEnd->Value = endDate;

    // Retrieve stock data from the specified filename
    allCandlesticks = getStockDataFromFilename(filename);

    // Filter candlesticks by date
    filterCandlesticksByDate();

    // Initialize pattern combo box
    InitializePatternComboBox();

    // Normalize the chart
    normalizeChart();

    // Update the display
    updateDisplay();
}


/// <summary>
/// Initializes the pattern combo box with patterns stored in the patternTracker.
/// </summary>
void Form_StockView::InitializePatternComboBox()
{
    // Clear existing items in the combo box
    comboBox_patterns->Items->Clear();

    // Iterate through each pattern in the patternTracker and add it to the combo box
    for each (KeyValuePair<String^, List<smartCandlestick^>^> ^ pattern in patternTracker)
    {
        comboBox_patterns->Items->Add(pattern->Key);
    }
}


/// <summary>
/// Event handler for the SelectedIndexChanged event of the comboBox_patterns.
/// Clears existing annotations on the chart and adds annotations for candlesticks associated with the selected pattern.
/// </summary>
/// <param name="sender">The object that raised the event.</param>
/// <param name="e">Event arguments.</param>
System::Void Form_StockView::comboBox_patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
    // Clear existing annotations on the chart
    chart_StockChart->Annotations->Clear();

    // Get the selected pattern from the comboBox_patterns
    String^ selectedPattern = comboBox_patterns->SelectedItem->ToString();

    // Retrieve the list of candlesticks associated with the selected pattern from patternTracker
    List<smartCandlestick^>^ pattern = nullptr;
    if (patternTracker->TryGetValue(selectedPattern, pattern))
    {
        // Iterate through each candlestick in the pattern and create annotations for them
        for each (smartCandlestick ^ candlestick in pattern)
        {
            CreateAnnotation(candlestick);
        }
    }

    // Refresh the chart to reflect the changes
    chart_StockChart->Refresh();
}


/// <summary>
/// Creates an arrow annotation on the chart to highlight a specific candlestick.
/// </summary>
/// <param name="cs">The smartCandlestick to create the annotation for.</param>
void Form_StockView::CreateAnnotation(smartCandlestick^ cs)
{
    // Find the index of the specified candlestick in the bindingCandlesticks list
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
    // Set the axes for the annotation
    arrowAnnotation->AxisX = chart_StockChart->ChartAreas[0]->AxisX;
    arrowAnnotation->AxisY = chart_StockChart->ChartAreas[0]->AxisY;

    // Set annotation properties
    arrowAnnotation->LineWidth = 1;
    arrowAnnotation->Width = 0;
    arrowAnnotation->Height = 5;
    arrowAnnotation->ArrowSize = 2;
    arrowAnnotation->ForeColor = cs->IsBullish ? Color::Green : Color::Red;
    arrowAnnotation->LineColor = cs->IsBullish ? Color::Red : Color::Green;
    arrowAnnotation->BackColor = cs->IsBullish ? Color::Green : Color::Red;
    arrowAnnotation->AnchorOffsetY = 5;
    // Set the anchor point for the annotation
    arrowAnnotation->SetAnchor(chart_StockChart->Series["Series_OHLC"]->Points[index]);
    // Add the annotation to the chart
    chart_StockChart->Annotations->Add(arrowAnnotation);
}


/// <summary>
/// Normalizes the Y-axis range of the chart to ensure all data points are visible with some padding.
/// </summary>
void Form_StockView::normalizeChart()
{
    // Initialize variables to store the minimum and maximum values
    double max = Double::MinValue;
    double min = Double::MaxValue;

    // Loop through each smartCandlestick in the bindingCandlesticks list
    for each (smartCandlestick ^ cs in bindingCandlesticks)
    {
        // Update the minimum value if the low of the current candlestick is lower
        if (cs->Low < min)
        {
            min = cs->Low;
        }

        // Update the maximum value if the high of the current candlestick is higher
        if (cs->High > max)
        {
            max = cs->High;
        }
    }

    // Set the minimum value of the Y-axis of the chart to 90% of the minimum value found
    chart_StockChart->ChartAreas["Chart_OHLC"]->AxisY->Minimum = Math::Round(min * 0.9, 2);
    // Set the maximum value of the Y-axis of the chart to 110% of the maximum value found
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
    patternTracker->Clear();
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
/// Calls filterCandlesticksByDate, clears existing annotations, initilizes the pattern combobox and calls updateDisplay to update the displayed data.
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
/// - Filters the candlesticks data based on the specified date range.
/// - Added the corresponding candlestick to the pattern dictionary 
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
                // Loop through all patterns
                for each (KeyValuePair<String^, bool> ^ pattern in cs->Patterns)
                {
                    // checks if the current pattern is true
                    if (pattern->Value)
                    {
                        // If pattern key is already present in patternTracker, add cs to its associated list
                        if (patternTracker->ContainsKey(pattern->Key))
                        {
                            patternTracker[pattern->Key]->Add(cs);
                        }
                        // If pattern key is not present, create a new list with cs and add it to patternTracker
                        else
                        {
                            List<smartCandlestick^>^ newList = gcnew List<smartCandlestick^>();
                            newList->Add(cs);
                            patternTracker->Add(pattern->Key, newList);
                        }
                    }
                    // If the current pattern is false
                    else
                    {
                        // If pattern key is already present in patternTracker, continue to the next pattern
                        if (patternTracker->ContainsKey(pattern->Key))
                            continue;
                        // If pattern key is not present, create a new empty list and add it to patternTracker
                        else
                        {
                            List<smartCandlestick^>^ newList = gcnew List<smartCandlestick^>();
                            patternTracker->Add(pattern->Key, newList);
                        }
                    }
                }
                // Add the candlestick to the filtered list
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
