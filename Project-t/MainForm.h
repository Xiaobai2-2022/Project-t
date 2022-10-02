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
		static const int num_row = 18;																// total number of rows
		static const int num_col = 10;																// total number of columns
		static const int num_lbl = num_row * num_col;												// total number of labels

		/* Left Display */
		static const int num_row_l = 3;																// total number of rows in left 
		static const int num_col_l = 4;																// total number of cols in left
		static const int num_lbl_l = num_row_l * num_col_l;											// total number of labels in left (for storing the block)

		/* GUI Size Constants */
		static const int size_block = 30;															// size of each block
		static const int size_disp_block = 25;														// size of the display blocks
		static const int size_small_block = 15;														// size of the display blocks

		static const int size_border = 5;															// size of the top and bottom boarder
		static const int left_offset = size_border * 4 + size_disp_block * num_col_l;				// size of the left offset
		static const int right_offset = 5;															// size of the right offset

		static const int size_form_x = left_offset + size_block * num_col + right_offset;			// main form's x size
		static const int size_form_y = size_border * 4 + size_block * num_row;						// main form's Y size
		

	/* private helper methods */
	private:
		/*
		 * change two dimensional item into one dimentsional
		 * @param x: (int) the x coordinate for two dimensional
		 * @param y: (int) the y coordinate for two dimensional
		 * @returns: (int) the one dimensional code
		 */
		static int to_row_major (int x, int y, int row_size) {
			return row_size * x + y;
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
		array<System::Windows::Forms::Label^>^ labels_left = gcnew array<System::Windows::Forms::Label^>(num_lbl_l);
		System::Windows::Forms::Label^ label_left_hold;

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
			for (int i = 0; i < num_lbl_l; i++) {
				this->labels_left[i] = (gcnew System::Windows::Forms::Label());
			}
			this->label_left_hold = (gcnew System::Windows::Forms::Label());

			this->SuspendLayout();

			/* Set up the labels */
			for (int i = 0; i < num_col; i++) {
				for (int j = 0; j < num_row; j++) {
					this->labels[to_row_major(i, j, num_row)]->AutoSize = false;
					this->labels[to_row_major(i, j, num_row)]->Location = System::Drawing::Point(left_offset + i * size_block, size_border + j * size_block);						// calculate the location for the block
					this->labels[to_row_major(i, j, num_row)]->Name = L"label" + i;
					this->labels[to_row_major(i, j, num_row)]->Size = System::Drawing::Size(size_block, size_block);																// set each block's size
					this->labels[to_row_major(i, j, num_row)]->TabIndex = 0;
					this->labels[to_row_major(i, j, num_row)]->Text = L"";
					this->labels[to_row_major(i, j, num_row)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;															// set the border to Fixed3D https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.label.borderstyle?view=windowsdesktop-7.0#system-windows-forms-label-borderstyle
					
				}
			}

			/* Set up the labels */
			for (int i = 0; i < num_col_l; i++) {
				for (int j = 0; j < num_row_l; j++) {
					this->labels_left[to_row_major(i, j, num_row_l)]->AutoSize = false;
					this->labels_left[to_row_major(i, j, num_row_l)]->Location = System::Drawing::Point(size_border + i * size_disp_block, size_border + j * size_disp_block);		// calculate the location for the block
					this->labels_left[to_row_major(i, j, num_row_l)]->Name = L"label" + i;
					this->labels_left[to_row_major(i, j, num_row_l)]->Size = System::Drawing::Size(size_disp_block, size_disp_block);												// set each block's size
					this->labels_left[to_row_major(i, j, num_row_l)]->TabIndex = 0;
					this->labels_left[to_row_major(i, j, num_row_l)]->Text = L"";
					this->labels_left[to_row_major(i, j, num_row_l)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;													// set the border to Fixed3D

				}
			}

			this->label_left_hold->AutoSize = false;
			this->label_left_hold->Location = System::Drawing::Point(size_border, size_border + 3 * size_disp_block);																// set the location for the block
			this->label_left_hold->Name = L"label_hold";
			this->label_left_hold->Size = System::Drawing::Size(size_disp_block * 4, size_disp_block);																				// set the block's size
			this->label_left_hold->TabIndex = 0;
			this->label_left_hold->Text = L"HOLD";
			this->label_left_hold->Font->Bold;
			this->label_left_hold->TextAlign = ContentAlignment::MiddleCenter;
			this->label_left_hold->Font = gcnew System::Drawing::Font("Consolas", 12);


			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(size_form_x, size_form_y);							// set the size of the main form as calculated
			for (int i = 0; i < num_lbl; i++) {
				this->Controls->Add(this->labels[i]);													// add all the labels to form
			}
			for (int i = 0; i < num_lbl_l; i++) {
				this->Controls->Add(this->labels_left[i]);												// add all the labels left to form
			}
			this->Controls->Add(this->label_left_hold);
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
