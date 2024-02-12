#pragma once
#include "candlestick.h"

namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}
	private: System::Windows::Forms::DataGridView^ dataGridView_StockGrid;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateEnd;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateBegin;
	private: System::Windows::Forms::BindingSource^ bindingSource_CandlestickList;
	public:
	private:
			List<candlestick^>^ allCandlesticks;
	private: System::Windows::Forms::Button^ button_Refresh;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
		   BindingList<candlestick^>^ bindingCandlesticks = gcnew BindingList<candlestick^>();
		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock;
		protected:
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea5 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea6 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series6 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->dataGridView_StockGrid = (gcnew System::Windows::Forms::DataGridView());
			this->dateTimePicker_DateEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_DateBegin = (gcnew System::Windows::Forms::DateTimePicker());
			this->bindingSource_CandlestickList = (gcnew System::Windows::Forms::BindingSource(this->components));
			this->button_Refresh = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_StockGrid))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource_CandlestickList))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog_LoadStock_FileOk);
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Location = System::Drawing::Point(673, 702);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(110, 27);
			this->button_LoadStock->TabIndex = 0;
			this->button_LoadStock->Text = L"LOAD";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &MyForm::button_LoadStock_Click);
			// 
			// dataGridView_StockGrid
			// 
			this->dataGridView_StockGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_StockGrid->Location = System::Drawing::Point(35, 34);
			this->dataGridView_StockGrid->Name = L"dataGridView_StockGrid";
			this->dataGridView_StockGrid->Size = System::Drawing::Size(1185, 195);
			this->dataGridView_StockGrid->TabIndex = 1;
			// 
			// dateTimePicker_DateEnd
			// 
			this->dateTimePicker_DateEnd->Location = System::Drawing::Point(213, 702);
			this->dateTimePicker_DateEnd->Name = L"dateTimePicker_DateEnd";
			this->dateTimePicker_DateEnd->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_DateEnd->TabIndex = 2;
			// 
			// dateTimePicker_DateBegin
			// 
			this->dateTimePicker_DateBegin->Location = System::Drawing::Point(213, 663);
			this->dateTimePicker_DateBegin->Name = L"dateTimePicker_DateBegin";
			this->dateTimePicker_DateBegin->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_DateBegin->TabIndex = 3;
			this->dateTimePicker_DateBegin->Value = System::DateTime(2019, 1, 15, 0, 0, 0, 0);
			// 
			// button_Refresh
			// 
			this->button_Refresh->Location = System::Drawing::Point(514, 701);
			this->button_Refresh->Name = L"button_Refresh";
			this->button_Refresh->Size = System::Drawing::Size(110, 27);
			this->button_Refresh->TabIndex = 4;
			this->button_Refresh->Text = L"Refresh";
			this->button_Refresh->UseVisualStyleBackColor = true;
			this->button_Refresh->Click += gcnew System::EventHandler(this, &MyForm::button_Refresh_Click);
			// 
			// chart1
			// 
			chartArea5->Name = L"Chart_OHLC";
			chartArea6->Name = L"Chart_Volume";
			this->chart1->ChartAreas->Add(chartArea5);
			this->chart1->ChartAreas->Add(chartArea6);
			this->chart1->DataSource = this->bindingSource_CandlestickList;
			this->chart1->Location = System::Drawing::Point(35, 249);
			this->chart1->Name = L"chart1";
			series5->ChartArea = L"Chart_OHLC";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series5->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Lime";
			series5->Name = L"Series1";
			series5->XValueMember = L"Date";
			series5->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series5->YValueMembers = L"High,Low,Open,Close";
			series5->YValuesPerPoint = 4;
			series5->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series6->ChartArea = L"Chart_Volume";
			series6->Name = L"Series2";
			series6->XValueMember = L"Date";
			series6->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series6->YValueMembers = L"Volume";
			this->chart1->Series->Add(series5);
			this->chart1->Series->Add(series6);
			this->chart1->Size = System::Drawing::Size(1185, 389);
			this->chart1->TabIndex = 5;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1267, 775);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button_Refresh);
			this->Controls->Add(this->dateTimePicker_DateBegin);
			this->Controls->Add(this->dateTimePicker_DateEnd);
			this->Controls->Add(this->dataGridView_StockGrid);
			this->Controls->Add(this->button_LoadStock);
			this->Name = L"MyForm";
			this->Text = L"Stonks";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_StockGrid))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bindingSource_CandlestickList))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			openFileDialog_LoadStock->Filter = "Month Files|*-Month.csv|Week Files|*-Week.csv|Day Files|*-Day.csv|All Files |*.*";;
			openFileDialog_LoadStock->ShowDialog();
		}

		private: System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) 
		{
			
			allCandlesticks = getStockDataFromFilename(openFileDialog_LoadStock->FileName);
			this->Text = openFileDialog_LoadStock->FileName;
			setDateRangeForCandlesticks();
		}

		List<candlestick^>^ getStockDataFromFilename(String^ filename)
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

		void setDateRangeForCandlesticks()
		{
			if (allCandlesticks != nullptr && allCandlesticks->Count > 0) {
				bindingCandlesticks->Clear();

				for each (candlestick ^ cs in allCandlesticks)
				{
					if (cs->date > dateTimePicker_DateEnd->Value) break;

					if (cs->date >= dateTimePicker_DateBegin->Value)
					{
						bindingCandlesticks->Add(cs);
					}
				}

				dataGridView_StockGrid->DataSource = bindingCandlesticks;
				chart1->DataSource = bindingCandlesticks;
				chart1->DataBind();
			}
		}

		private: System::Void button_Refresh_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			setDateRangeForCandlesticks();
		}
};
}
