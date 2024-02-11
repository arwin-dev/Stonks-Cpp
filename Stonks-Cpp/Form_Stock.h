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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_LoadStock = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog_LoadStock_FileOk);
			// 
			// button_LoadStock
			// 
			this->button_LoadStock->Location = System::Drawing::Point(667, 486);
			this->button_LoadStock->Name = L"button_LoadStock";
			this->button_LoadStock->Size = System::Drawing::Size(110, 27);
			this->button_LoadStock->TabIndex = 0;
			this->button_LoadStock->Text = L"LOAD";
			this->button_LoadStock->UseVisualStyleBackColor = true;
			this->button_LoadStock->Click += gcnew System::EventHandler(this, &MyForm::button_LoadStock_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(855, 566);
			this->Controls->Add(this->button_LoadStock);
			this->Name = L"MyForm";
			this->Text = L"Stonks";
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
			getStockDataFromFilename(openFileDialog_LoadStock->FileName);
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

			listOfCandlesticks->Reverse();
			return listOfCandlesticks;
		}
	};
}
