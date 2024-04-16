#include "Form_StockView.h"
#include "candlestick.h"
#include "recognizer.h"

using namespace Stonks_Cpp;

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Windows::Forms::DataVisualization::Charting;
using namespace System::Reflection;


[STAThreadAttribute]

int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Stonks_Cpp::Form_StockView form;
    Application::Run(% form);
    return 0;
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

    Type^ baseType = recognizer::typeid;
    array<Type^>^ allTypes = Assembly::GetExecutingAssembly()->GetTypes();

    for each (Type ^ type in allTypes)
    {
        if (type->IsSubclassOf(baseType))
        {
            recognizer^ recognizerInstance = dynamic_cast<recognizer^>(Activator::CreateInstance(type));

            // Access the patternName property and add it to the ComboBox
            comboBox_patterns->Items->Add(recognizerInstance->patternName);
            recognizerTracker.Add(recognizerInstance);
        }
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
    recognizer^ selected = recognizerTracker[comboBox_patterns->SelectedIndex];
    // Retrieve the list of candlesticks associated with the selected pattern from patternTracker
    List<smartCandlestick^>^ pattern = nullptr;
    //if (patternTracker->TryGetValue(selectedPattern, pattern))
    //{
    //    // Iterate through each candlestick in the pattern and create annotations for them
    //    for each (smartCandlestick ^ candlestick in pattern)
    //    {
    //        CreateAnnotation(candlestick);
    //    }
    //}

    for (int i = 0; i < bindingCandlesticks->Count; i++)
    {
        if (selected->recognizePattern(bindingCandlesticks[i]) && selected->patternSize == 1)
        {
            CreateAnnotation(bindingCandlesticks[i], Color::Red);
        }
        else if (i < bindingCandlesticks->Count - selected->patternSize + 1)
        {
            List<smartCandlestick^>^ subList = filteredCandlesticks->GetRange(i, selected->patternSize);
            if (selected->recognizePattern(subList))
            {
                CreateListOfAnnotations(subList, selected->patternName);
            }
        }

    }

    // Refresh the chart to reflect the changes
    chart_StockChart->Refresh();
}


/// <summary>
/// Creates an arrow annotation on the chart to highlight a specific candlestick.
/// </summary>
/// <param name="cs">The smartCandlestick to create the annotation for.</param>
void Form_StockView::CreateAnnotation(smartCandlestick^ cs, Color color )
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
    // Set the axes for the annotationdghghfghnfghfghfghfgh
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

void Form_StockView::CreateListOfAnnotations(List<smartCandlestick^>^ cs, String^ patternName)
{
    if (cs->Count == 2)
    {
        CreateAnnotation(cs[0], Color::Red);
        CreateAnnotation(cs[1], Color::Red);
    }
    else if (cs->Count == 3)
    {
        CreateAnnotation(cs[0], Color::Red);
        CreateAnnotation(cs[1], Color::Red);
        CreateAnnotation(cs[2], Color::Red);
    }
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
    filteredCandlesticks->Clear();

    // Assigns the filtered Candlesticks to the filteredCandlesticks global variable
    filteredCandlesticks = filterCandlesticksByDate(allCandlesticks, dateTimePicker_DateBegin->Value, dateTimePicker_DateEnd->Value);
    

    for each (smartCandlestick^ cs in filteredCandlesticks)
    {
        bindingCandlesticks->Add(cs);
    }
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
List<smartCandlestick^>^ Form_StockView::filterCandlesticksByDate(List<smartCandlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate)
{
    // Create a new list to hold filtered candlesticks
    List<smartCandlestick^>^ filteredCandlesticks = gcnew List<smartCandlestick^>();

    // Check if there are candlesticks and the count is greater than 0
    if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
        // Clear the previous binding candlesticks

        // Loop through all candlesticks
        for each (smartCandlestick ^ cs in allCandlesticks)
        {
            // If the candlestick date is beyond the end date, break the loop
            if (cs->Date > dateTimePicker_DateEnd->Value) break;

            // If the candlestick date is within the specified range, add it to the filtered list
            if (cs->Date >= dateTimePicker_DateBegin->Value)
            {
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
