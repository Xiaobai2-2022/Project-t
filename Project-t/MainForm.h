#pragma once

namespace Projectt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		} 
	private: 
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Label^ label2;

		array<System::Windows::Forms::Label^>^ labels = gcnew array<System::Windows::Forms::Label^>(10);

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

			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labels[0] = label1;
			this->labels[1] = label2;
			this->SuspendLayout();

			this->labels[0]->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			this->labels[1]->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);

			/* Labels Array Test Complete */
			for (int i = 0; i < 2; i++) {
				this->labels[i]->AutoSize = true;
				this->labels[i]->Location = System::Drawing::Point(0, i * 50);
				this->labels[i]->Name = L"label" + i;
				this->labels[i]->Size = System::Drawing::Size(50, 50);
				this->labels[i]->TabIndex = 0;
				this->labels[i]->Text = L"label" + i;
			}

			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->labels[0]);
			this->Controls->Add(this->labels[1]);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
