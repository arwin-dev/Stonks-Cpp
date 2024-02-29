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
	/// Summary for Form_Init
	/// </summary>
	public ref class Form_Init : public System::Windows::Forms::Form
	{
		public:
			Form_Init(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateEnd;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_DateBegin;

	public:
	private:

	private: System::Windows::Forms::Label^ label_StartDate;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock;

	private: System::Windows::Forms::Label^ label_EndDate;


		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~Form_Init()
			{
				if (components)
				{
					delete components;
				}
			}

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
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_DateEnd = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_DateBegin = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_StartDate = (gcnew System::Windows::Forms::Label());
			this->label_EndDate = (gcnew System::Windows::Forms::Label());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->SuspendLayout();
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Location = System::Drawing::Point(34, 181);
			this->button_LoadStock->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(300, 58);
			this->button_LoadStock->TabIndex = 0;
			this->button_LoadStock->Text = L"LOAD";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &Form_Init::button_LoadStock_Click);
			// 
			// dateTimePicker_DateEnd
			// 
			this->dateTimePicker_DateEnd->Location = System::Drawing::Point(35, 131);
			this->dateTimePicker_DateEnd->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_DateEnd->Name = L"dateTimePicker_DateEnd";
			this->dateTimePicker_DateEnd->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_DateEnd->TabIndex = 2;
			// 
			// dateTimePicker_DateBegin
			// 
			this->dateTimePicker_DateBegin->Location = System::Drawing::Point(35, 55);
			this->dateTimePicker_DateBegin->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dateTimePicker_DateBegin->Name = L"dateTimePicker_DateBegin";
			this->dateTimePicker_DateBegin->Size = System::Drawing::Size(298, 26);
			this->dateTimePicker_DateBegin->TabIndex = 3;
			this->dateTimePicker_DateBegin->Value = System::DateTime(2019, 1, 15, 0, 0, 0, 0);
			// 
			// label_StartDate
			// 
			this->label_StartDate->AutoSize = true;
			this->label_StartDate->Location = System::Drawing::Point(30, 25);
			this->label_StartDate->Name = L"label_StartDate";
			this->label_StartDate->Size = System::Drawing::Size(83, 20);
			this->label_StartDate->TabIndex = 6;
			this->label_StartDate->Text = L"Start Date";
			// 
			// label_EndDate
			// 
			this->label_EndDate->AutoSize = true;
			this->label_EndDate->Location = System::Drawing::Point(30, 102);
			this->label_EndDate->Name = L"label_EndDate";
			this->label_EndDate->Size = System::Drawing::Size(77, 20);
			this->label_EndDate->TabIndex = 7;
			this->label_EndDate->Text = L"End Date";
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->Filter = L"All Files |*.*|Month Files|*-Month.csv|Week Files|*-Week.csv|Day Files|*-Day.csv";
			this->openFileDialog_LoadStock->Multiselect = true;
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_Init::openFileDialog_LoadStock_FileOk);
			// 
			// Form_Init
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(367, 278);
			this->Controls->Add(this->label_EndDate);
			this->Controls->Add(this->label_StartDate);
			this->Controls->Add(this->dateTimePicker_DateBegin);
			this->Controls->Add(this->dateTimePicker_DateEnd);
			this->Controls->Add(this->button_LoadStock);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Form_Init";
			this->Text = L"Stonks";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Event handler for the openFileDialog_LoadStock FileOk event. 
		// Calls getStockDataFromFilename, filterCandlesticksByDate, and updateDisplay to load, filter, and display stock data.

		private: System::Void button_LoadStock_Click(System::Object^ sender, System::EventArgs^ e);

		private: System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
};
}
