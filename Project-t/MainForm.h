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

	/* private constants */
	private:
		/* Game Board Logic Constants */
		static const int num_row = 18;												// total number of rows
		static const int num_col = 10;												// total number of columns
		static const int num_lbl = num_row * num_col;								// total number of labels

		/* GUI Size Constants */
		static const int size_block = 30;											// size of each block
		static const int size_border = 5;											// size of the boarder
		static const int size_form_x = size_border * 2 + size_block * num_col;		// main form's x size
		static const int size_form_y = size_border * 2 + size_block * num_row;		// main form's Y size
		

	/* private helper methods */
	private:
		/*
		 * change two dimensional item into one dimentsional
		 * @param x: (int) the x coordinate for two dimensional
		 * @param y: (int) the y coordinate for two dimensional
		 * @returns: (int) the one dimensional code
		 */
		static int to_row_major (int x, int y) {
			return num_row * x + y;
		}

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

		array<System::Windows::Forms::Label^>^ labels = gcnew array<System::Windows::Forms::Label^>(num_lbl);

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

			for (int i = 0; i < num_lbl; i++) {
				this->labels[i] = (gcnew System::Windows::Forms::Label());
			}

			this->SuspendLayout();

			/* Set up the labels */
			for (int i = 0; i < num_col; i++) {
				for (int j = 0; j < num_row; j++) {
					this->labels[to_row_major(i, j)]->AutoSize = false;
					this->labels[to_row_major(i, j)]->Location = System::Drawing::Point(size_border + i * size_block, size_border + j * size_block);	// calculate the location for the block
					this->labels[to_row_major(i, j)]->Name = L"label" + i;
					this->labels[to_row_major(i, j)]->Size = System::Drawing::Size(size_block, size_block);												// set each block's size
					this->labels[to_row_major(i, j)]->TabIndex = 0;
					this->labels[to_row_major(i, j)]->Text = L"";
					this->labels[to_row_major(i, j)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;										// set the border to Fixed3D https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.label.borderstyle?view=windowsdesktop-7.0#system-windows-forms-label-borderstyle
					
				}
			}

			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(size_form_x, size_form_y);							// set the size of the main form as calculated
			for (int i = 0; i < num_lbl; i++) {
				this->Controls->Add(this->labels[i]);													// add all the labels to form
			}
			this->Name = L"MainForm";
			this->Text = L"Tetris(X)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
