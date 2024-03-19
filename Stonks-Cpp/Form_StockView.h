#pragma once
#include "candlestick.h"

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->bindingSource_CandlestickList = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->label_EndDate = (gcnew System::Windows::Forms::Label());
			this->label_StartDate = (gcnew System::Windows::Forms::Label());
			this->chart_StockChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_Refresh = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_DateBegin = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_DateEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
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
			this->label_EndDate->Location = System::Drawing::Point(56, 100);
			this->label_EndDate->Name = L"label_EndDate";
			this->label_EndDate->Size = System::Drawing::Size(77, 20);
			this->label_EndDate->TabIndex = 14;
			this->label_EndDate->Text = L"End Date";
			// 
			// label_StartDate
			// 
			this->label_StartDate->AutoSize = true;
			this->label_StartDate->Location = System::Drawing::Point(50, 59);
			this->label_StartDate->Name = L"label_StartDate";
			this->label_StartDate->Size = System::Drawing::Size(83, 20);
			this->label_StartDate->TabIndex = 13;
			this->label_StartDate->Text = L"Start Date";
			// 
			// chart_StockChart
			// 
			this->chart_StockChart->BorderSkin->BackColor = System::Drawing::Color::WhiteSmoke;
			chartArea1->AlignWithChartArea = L"Chart_Volume";
			chartArea1->Name = L"Chart_OHLC";
			chartArea2->Name = L"Chart_Volume";
			this->chart_StockChart->ChartAreas->Add(chartArea1);
			this->chart_StockChart->ChartAreas->Add(chartArea2);
			this->chart_StockChart->DataSource = this->bindingSource_CandlestickList;
			this->chart_StockChart->Location = System::Drawing::Point(13, 148);
			this->chart_StockChart->Margin = System::Windows::Forms::Padding(2);
			this->chart_StockChart->Name = L"chart_StockChart";
			series1->ChartArea = L"Chart_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series1->IsXValueIndexed = true;
			series1->Name = L"Series1";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series1->YValueMembers = L"High, Low, Open, Close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"Chart_Volume";
			series2->IsXValueIndexed = true;
			series2->Name = L"Series2";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series2->YValueMembers = L"Volume";
			this->chart_StockChart->Series->Add(series1);
			this->chart_StockChart->Series->Add(series2);
			this->chart_StockChart->Size = System::Drawing::Size(1737, 871);
			this->chart_StockChart->TabIndex = 12;
			this->chart_StockChart->Text = L"chart1";
			// 
			// button_Refresh
			// 
			this->button_Refresh->Location = System::Drawing::Point(468, 59);
			this->button_Refresh->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_Refresh->Name = L"button_Refresh";
			this->button_Refresh->Size = System::Drawing::Size(131, 67);
			this->button_Refresh->TabIndex = 11;
			this->button_Refresh->Text = L"Refresh";
			this->button_Refresh->UseVisualStyleBackColor = true;
			this->button_Refresh->Click += gcnew System::EventHandler(this, &Form_StockView::button_Refresh_Click);
			// 
			// dateTimePicker_DateBegin
			// 
			this->dateTimePicker_DateBegin->Location = System::Drawing::Point(152, 59);
			this->dateTimePicker_DateBegin->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_DateBegin->Name = L"dateTimePicker_DateBegin";
			this->dateTimePicker_DateBegin->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_DateBegin->TabIndex = 10;
			this->dateTimePicker_DateBegin->Value = System::DateTime(2019, 1, 15, 0, 0, 0, 0);
			// 
			// dateTimePicker_DateEnd
			// 
			this->dateTimePicker_DateEnd->Location = System::Drawing::Point(152, 100);
			this->dateTimePicker_DateEnd->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_DateEnd->Name = L"dateTimePicker_DateEnd";
			this->dateTimePicker_DateEnd->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_DateEnd->TabIndex = 9;
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Location = System::Drawing::Point(1450, 68);
			this->button_LoadStock->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(300, 58);
			this->button_LoadStock->TabIndex = 15;
			this->button_LoadStock->Text = L"LOAD";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &Form_StockView::button_LoadStock_Click);
			// 
			// Form_StockView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1829, 1047);
			this->Controls->Add(this->button_LoadStock);
			this->Controls->Add(this->label_EndDate);
			this->Controls->Add(this->label_StartDate);
			this->Controls->Add(this->chart_StockChart);
			this->Controls->Add(this->button_Refresh);
			this->Controls->Add(this->dateTimePicker_DateBegin);
			this->Controls->Add(this->dateTimePicker_DateEnd);
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
		List<candlestick^>^ allCandlesticks;

		// Binding list of candlesticks used for data binding with UI controls.
		BindingList<candlestick^>^ bindingCandlesticks = gcnew BindingList<candlestick^>();

		public: Form_StockView(String^ filename, DateTime startDate, DateTime endDate);

		// Reads stock data from the specified file and returns it as a list of candlesticks.
		private: List<candlestick^>^ getStockDataFromFilename(String^ filename);

		// Filters the candlesticks data based on the specified date range.
		private: BindingList<candlestick^>^ filterCandlesticksByDate(List<candlestick^>^ allCandlesticks, DateTime startDate, DateTime endDate);

		// Extracts stock data from the selected file and updates the form's title with the file name.
		private: void getStockDataFromFilename();

		// Filters the candlesticks data based on the specified date range.
		private: void filterCandlesticksByDate();

		// Updates the display by binding the candlestick data to the dataGridView_StockGrid and chart_StockChart.
		private: void updateDisplay();

		// Event handler for the button_Refresh click event. 
		// Calls filterCandlesticksByDate and updateDisplay to update the displayed data.
		private: System::Void button_Refresh_Click(System::Object^ sender, System::EventArgs^ e);


		private: System::Void button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e);


		private: System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);

		private: System::Void InitializeParent(String^ filename);
};
}
