#pragma once
#include "smartCandlestick.h"
#include "recognizer.h"

namespace Stonks_Cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form_StockView
	/// </summary>
	public ref class Form_StockView : public System::Windows::Forms::Form
	{
	public:
		Form_StockView(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_StockView()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock;
	protected:

	private: System::Windows::Forms::BindingSource^ bindingSource_CandlestickList;
	private: System::Windows::Forms::Label^ label_EndDate;
	private: System::Windows::Forms::Label^ label_StartDate;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_StockChart;
	private: System::Windows::Forms::Button^ button_Refresh;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateBegin;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateEnd;
	private: System::Windows::Forms::Button^ button_LoadStock;
	private: System::Windows::Forms::ComboBox^ comboBox_patterns;
	private: System::Windows::Forms::Label^ label_Patterns;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->bindingSource_CandlestickList = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->label_EndDate = (gcnew System::Windows::Forms::Label());
			this->label_StartDate = (gcnew System::Windows::Forms::Label());
			this->chart_StockChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_Refresh = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_DateBegin = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_DateEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->comboBox_patterns = (gcnew System::Windows::Forms::ComboBox());
			this->label_Patterns = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource_CandlestickList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockChart))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->Multiselect = true;
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockView::openFileDialog_LoadStock_FileOk);
			// 
			// label_EndDate
			// 
			this->label_EndDate->AutoSize = true;
			this->label_EndDate->Location = System::Drawing::Point(37, 46);
			this->label_EndDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_EndDate->Name = L"label_EndDate";
			this->label_EndDate->Size = System::Drawing::Size(52, 13);
			this->label_EndDate->TabIndex = 14;
			this->label_EndDate->Text = L"End Date";
			// 
			// label_StartDate
			// 
			this->label_StartDate->AutoSize = true;
			this->label_StartDate->Location = System::Drawing::Point(33, 19);
			this->label_StartDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_StartDate->Name = L"label_StartDate";
			this->label_StartDate->Size = System::Drawing::Size(55, 13);
			this->label_StartDate->TabIndex = 13;
			this->label_StartDate->Text = L"Start Date";
			// 
			// chart_StockChart
			// 
			this->chart_StockChart->BorderSkin->BackColor = System::Drawing::Color::WhiteSmoke;
			chartArea3->AlignWithChartArea = L"Chart_Volume";
			chartArea3->Name = L"Chart_OHLC";
			chartArea4->Name = L"Chart_Volume";
			this->chart_StockChart->ChartAreas->Add(chartArea3);
			this->chart_StockChart->ChartAreas->Add(chartArea4);
			this->chart_StockChart->DataSource = this->bindingSource_CandlestickList;
			this->chart_StockChart->Location = System::Drawing::Point(9, 77);
			this->chart_StockChart->Margin = System::Windows::Forms::Padding(1);
			this->chart_StockChart->Name = L"chart_StockChart";
			series3->ChartArea = L"Chart_OHLC";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series3->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series3->IsXValueIndexed = true;
			series3->Name = L"Series_OHLC";
			series3->XValueMember = L"Date";
			series3->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series3->YValueMembers = L"High, Low, Open, Close";
			series3->YValuesPerPoint = 4;
			series3->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series4->ChartArea = L"Chart_Volume";
			series4->IsXValueIndexed = true;
			series4->Name = L"Series_Volume";
			series4->XValueMember = L"Date";
			series4->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series4->YValueMembers = L"Volume";
			this->chart_StockChart->Series->Add(series3);
			this->chart_StockChart->Series->Add(series4);
			this->chart_StockChart->Size = System::Drawing::Size(1158, 566);
			this->chart_StockChart->TabIndex = 12;
			this->chart_StockChart->Text = L"chart1";
			// 
			// button_Refresh
			// 
			this->button_Refresh->Location = System::Drawing::Point(312, 19);
			this->button_Refresh->Name = L"button_Refresh";
			this->button_Refresh->Size = System::Drawing::Size(87, 44);
			this->button_Refresh->TabIndex = 11;
			this->button_Refresh->Text = L"Refresh";
			this->button_Refresh->UseVisualStyleBackColor = true;
			this->button_Refresh->Click += gcnew System::EventHandler(this, &Form_StockView::button_Refresh_Click);
			// 
			// dateTimePicker_DateBegin
			// 
			this->dateTimePicker_DateBegin->Location = System::Drawing::Point(101, 19);
			this->dateTimePicker_DateBegin->Name = L"dateTimePicker_DateBegin";
			this->dateTimePicker_DateBegin->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_DateBegin->TabIndex = 10;
			this->dateTimePicker_DateBegin->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_DateEnd
			// 
			this->dateTimePicker_DateEnd->Location = System::Drawing::Point(101, 46);
			this->dateTimePicker_DateEnd->Name = L"dateTimePicker_DateEnd";
			this->dateTimePicker_DateEnd->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_DateEnd->TabIndex = 9;
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Location = System::Drawing::Point(967, 25);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(200, 38);
			this->button_LoadStock->TabIndex = 15;
			this->button_LoadStock->Text = L"LOAD";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &Form_StockView::button_LoadStock_Click);
			// 
			// comboBox_patterns
			// 
			this->comboBox_patterns->FormattingEnabled = true;
			this->comboBox_patterns->Location = System::Drawing::Point(465, 22);
			this->comboBox_patterns->Name = L"comboBox_patterns";
			this->comboBox_patterns->Size = System::Drawing::Size(119, 21);
			this->comboBox_patterns->TabIndex = 16;
			this->comboBox_patterns->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_StockView::comboBox_patterns_SelectedIndexChanged);
			// 
			// label_Patterns
			// 
			this->label_Patterns->AutoSize = true;
			this->label_Patterns->Location = System::Drawing::Point(419, 26);
			this->label_Patterns->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label_Patterns->Name = L"label_Patterns";
			this->label_Patterns->Size = System::Drawing::Size(41, 13);
			this->label_Patterns->TabIndex = 17;
			this->label_Patterns->Text = L"Pattern";
			// 
			// Form_StockView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1182, 656);
			this->Controls->Add(this->label_Patterns);
			this->Controls->Add(this->comboBox_patterns);
			this->Controls->Add(this->button_LoadStock);
			this->Controls->Add(this->label_EndDate);
			this->Controls->Add(this->label_StartDate);
			this->Controls->Add(this->chart_StockChart);
			this->Controls->Add(this->button_Refresh);
			this->Controls->Add(this->dateTimePicker_DateBegin);
			this->Controls->Add(this->dateTimePicker_DateEnd);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form_StockView";
			this->Text = L"Form_StockView";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource_CandlestickList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_StockChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private:
			// List of candlesticks containing all the data read from the file.
			// This list is populated when loading stock data from a file.
			List<smartCandlestick^>^ allCandlesticks;
			List<smartCandlestick^>^ allCandlestteasdasdasdicks = gcnew List<smartCandlestick^>();

			// Binding list of candlesticks used for data binding with UI controls.
			BindingList<smartCandlestick^>^ bindingCandlesticks = gcnew BindingList<smartCandlestick^>();

			// Dictionary to track patterns and associated candlesticks.
			// Key: Pattern name, Value: List of candlesticks matching the pattern.
			List<recognizer^> recognizerTracker;

		public:
			// Constructor for Form_StockView.
			// Initializes the form with stock data from a file and specified date range.
			Form_StockView(String^ filename, DateTime startDate, DateTime endDate);

		private:
			// Reads stock data from the specified file and returns it as a list of candlesticks.
			List<smartCandlestick^>^ getStockDataFromFilename(String^ filename);

			// Filters the candlesticks data based on the specified date range.
			BindingList<smartCandlestick^>^ filterCandlesticksByDate(List<smartCandlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate);

			// Extracts stock data from the selected file and updates the form's title with the file name.
			void getStockDataFromFilename();

			// Filters the candlesticks data based on the specified date range.
			void filterCandlesticksByDate();

			// Updates the display by binding the candlestick data to the dataGridView_StockGrid and chart_StockChart.
			void updateDisplay();

			// Event handler for the button_Refresh click event.
			// Calls filterCandlesticksByDate and updateDisplay to update the displayed data.
			System::Void button_Refresh_Click(System::Object^ sender, System::EventArgs^ e);

		private:
			// Event handler for the button_LoadStock click event.
			// Opens the file dialog to allow the user to select stock files for loading.
			System::Void button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e);

			// Event handler for the FileOk event of the openFileDialog_LoadStock.
			// Loads the selected stock files, initializes the parent window with the first file,
			// and creates child windows for additional files.
			System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);

			// Initializes the form as a parent window with the specified filename.
			void InitializeParent(String^ filename);

			// Initializes the pattern combo box with patterns stored in the patternTracker.
			void InitializePatternComboBox();

			// Event handler for the SelectedIndexChanged event of the comboBox_patterns.
			// Clears existing annotations on the chart and adds annotations for candlesticks associated with the selected pattern.
			System::Void comboBox_patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);

			// Creates an arrow annotation on the chart to highlight a specific candlestick.
			void CreateAnnotation(int csIndex, Color color);

			void CreateListOfAnnotations(List<smartCandlestick^>^ cs, String^ patternName);

			// Normalizes the Y-axis range of the chart to ensure all data points are visible with some padding.
			void normalizeChart();
};
}
