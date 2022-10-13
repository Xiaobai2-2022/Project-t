#pragma once
#include <random>

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
		static const int num_row_s = 3;																// total number of rows in subportion
		static const int num_col_s = 4;																// total number of cols in subportion
		static const int num_lbl_s = num_row_s * num_col_s;											// total number of labels in left (for storing the block)

		/* GUI Size Constants */
		static const int size_block = 30;															// size of each block
		static const int size_disp_block = 25;														// size of the display blocks
		static const int size_small_block = 15;														// size of the display blocks

		static const int size_border = 5;															// size of the top and bottom boarder
		static const int left_offset = size_border * 4 + size_disp_block * num_col_s;				// size of the left offset
		static const int right_offset = size_border * 4 + size_disp_block * num_col_s;				// size of the right offset
		static const int right_offset_s = size_border * 4 + size_small_block * num_col_s;			// size of the right offset small

		static const int size_leftover = size_disp_block * 4 - size_small_block * 4;				// size of the left over space

		static const int up_offset = size_border + (num_row / 2 - 1) * size_block;					// size of up offset to middle

		static const int size_form_x = left_offset + size_block * num_col + right_offset;			// main form's x size
		static const int size_form_y = size_border * 2 + size_block * num_row;						// main form's Y size

		static const int num_type = 7;
		static const int num_next = 5;

	/* private helper methods */
	private:
		/*
		 * change two dimensional item into one dimentsional
		 * @param x: (int) the x coordinate for two dimensional
		 * @param y: (int) the y coordinate for two dimensional
		 * @returns: (int) the one dimensional code
		 */
		static int to_row_major (int x, int y, int row_size) {
			return row_size * y + x;
		}

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->next_block[0] = 0;
			this->update_right_main();
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
	// All labels
	private: 
		array<System::Windows::Forms::Label^>^ labels = gcnew array<System::Windows::Forms::Label^>(num_lbl);
		array<System::Windows::Forms::Label^>^ labels_left = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		array<System::Windows::Forms::Label^>^ labels_right_main = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		array<System::Windows::Forms::Label^>^ labels_right_2nd = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		array<System::Windows::Forms::Label^>^ labels_right_3rd = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		array<System::Windows::Forms::Label^>^ labels_right_4th = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		array<System::Windows::Forms::Label^>^ labels_right_5th = gcnew array<System::Windows::Forms::Label^>(num_lbl_s);
		System::Windows::Forms::Label^ label_left_hold;
		System::Windows::Forms::Label^ label_left_score;
		System::Windows::Forms::Label^ label_left_score_disp;
		System::Windows::Forms::Label^ label_right_next;
		System::Windows::Forms::Label^ label_right_next_2nd;
		System::Windows::Forms::Label^ label_right_next_3rd;
		System::Windows::Forms::Label^ label_right_next_4th;
		System::Windows::Forms::Label^ label_right_next_5th;

	// All logic fields
	private: 
		array<int>^ next_block = gcnew array<int>(num_next);

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
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_left[i] = (gcnew System::Windows::Forms::Label());
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_right_main[i] = (gcnew System::Windows::Forms::Label());
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_right_2nd[i] = (gcnew System::Windows::Forms::Label());
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_right_3rd[i] = (gcnew System::Windows::Forms::Label());
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_right_4th[i] = (gcnew System::Windows::Forms::Label());
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->labels_right_5th[i] = (gcnew System::Windows::Forms::Label());
			}
			this->label_left_hold = (gcnew System::Windows::Forms::Label());
			this->label_left_score = (gcnew System::Windows::Forms::Label());
			this->label_left_score_disp = (gcnew System::Windows::Forms::Label());
			this->label_right_next = (gcnew System::Windows::Forms::Label());
			this->label_right_next_2nd = (gcnew System::Windows::Forms::Label());
			this->label_right_next_3rd = (gcnew System::Windows::Forms::Label());
			this->label_right_next_4th = (gcnew System::Windows::Forms::Label());
			this->label_right_next_5th = (gcnew System::Windows::Forms::Label());

			this->SuspendLayout();

			/* Set up the labels main */
			for (int i = 0; i < num_row; i++) {
				for (int j = 0; j < num_col; j++) {
					this->labels[to_row_major(i, j, num_row)]->AutoSize = false;
					this->labels[to_row_major(i, j, num_row)]->Location = System::Drawing::Point(left_offset + j * size_block, size_border + i * size_block);						// calculate the location for the block
					this->labels[to_row_major(i, j, num_row)]->Size = System::Drawing::Size(size_block, size_block);																// set each block's size
					this->labels[to_row_major(i, j, num_row)]->TabIndex = 0;
					this->labels[to_row_major(i, j, num_row)]->Text = L"";
					this->labels[to_row_major(i, j, num_row)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;															// set the border to Fixed3D https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.label.borderstyle?view=windowsdesktop-7.0#system-windows-forms-label-borderstyle
					
				}
			}

			/* Set up the labels left */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_left[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_border + j * size_disp_block, size_border + i * size_disp_block);	// calculate the location for the block
					this->labels_left[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_disp_block, size_disp_block);												// set each block's size
					this->labels_left[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_left[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_left[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;													// set the border to Fixed3D

				}
			}

			/* Set up the labels right main */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_right_main[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_form_x - right_offset + size_border * 3 + j * size_disp_block, size_border + i * size_disp_block);	// calculate the location for the block
					this->labels_right_main[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_disp_block, size_disp_block);																				// set each block's size
					this->labels_right_main[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_right_main[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_right_main[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;																					// set the border to Fixed3D

				}
			}

			/* Set up the labels right 2nd */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_right_2nd[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_form_x - right_offset_s + size_border * 3 + j * size_small_block, size_border + i * size_small_block + 4 * size_disp_block + size_border);	// calculate the location for the block
					this->labels_right_2nd[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_small_block, size_small_block);																													// set each block's size
					this->labels_right_2nd[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_right_2nd[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_right_2nd[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;																															// set the border to Fixed3D

				}
			}

			/* Set up the labels right 3rd */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_right_3rd[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_form_x - right_offset_s + size_border * 3 + j * size_small_block, size_border + i * size_small_block + 4 * size_disp_block + 3 * size_small_block + 2 * size_border);	// calculate the location for the block
					this->labels_right_3rd[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_small_block, size_small_block);																																			// set each block's size
					this->labels_right_3rd[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_right_3rd[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_right_3rd[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;																																					// set the border to Fixed3D

				}
			}

			/* Set up the labels right 4th */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_right_4th[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_form_x - right_offset_s + size_border * 3 + j * size_small_block, size_border + i * size_small_block + 4 * size_disp_block + 6 * size_small_block + 3 * size_border);	// calculate the location for the block
					this->labels_right_4th[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_small_block, size_small_block);																																			// set each block's size
					this->labels_right_4th[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_right_4th[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_right_4th[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;																																					// set the border to Fixed3D

				}
			}

			/* Set up the labels right 5th */
			for (int i = 0; i < num_row_s; i++) {
				for (int j = 0; j < num_col_s; j++) {
					this->labels_right_5th[to_row_major(i, j, num_row_s)]->Location = System::Drawing::Point(size_form_x - right_offset_s + size_border * 3 + j * size_small_block, size_border + i * size_small_block + 4 * size_disp_block + 9 * size_small_block + 4 * size_border);	// calculate the location for the block
					this->labels_right_5th[to_row_major(i, j, num_row_s)]->Size = System::Drawing::Size(size_small_block, size_small_block);																																			// set each block's size
					this->labels_right_5th[to_row_major(i, j, num_row_s)]->TabIndex = 0;
					this->labels_right_5th[to_row_major(i, j, num_row_s)]->Text = L"";
					this->labels_right_5th[to_row_major(i, j, num_row_s)]->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;																																					// set the border to Fixed3D

				}
			}

			/* HOLD label */
			this->label_left_hold->AutoSize = false;
			this->label_left_hold->Location = System::Drawing::Point(size_border, size_border + 3 * size_disp_block);																// set the location for the block
			this->label_left_hold->Size = System::Drawing::Size(size_disp_block * 4, size_disp_block);																				// set the block's size
			this->label_left_hold->TabIndex = 0;
			this->label_left_hold->Text = L"HOLD";
			this->label_left_hold->Font->Bold;
			this->label_left_hold->TextAlign = ContentAlignment::MiddleCenter;
			this->label_left_hold->Font = gcnew System::Drawing::Font("Consolas", 12);
			/* SCORE label */
			this->label_left_score->AutoSize = false;
			this->label_left_score->Location = System::Drawing::Point(size_border, up_offset - size_block);																			// set the location for the block
			this->label_left_score->Size = System::Drawing::Size(size_disp_block * 4, size_disp_block);																				// set the block's size
			this->label_left_score->TabIndex = 0;
			this->label_left_score->Text = L"SCORE";
			this->label_left_score->Font->Bold;
			this->label_left_score->TextAlign = ContentAlignment::MiddleCenter;
			this->label_left_score->Font = gcnew System::Drawing::Font("Consolas", 12);
			/* SCORE Display label */
			this->label_left_score_disp->AutoSize = false;
			this->label_left_score_disp->Location = System::Drawing::Point(size_border, up_offset);																					// set the location for the block
			this->label_left_score_disp->Size = System::Drawing::Size(size_disp_block * 4, size_disp_block);																		// set the block's size
			this->label_left_score_disp->TabIndex = 0;
			this->label_left_score_disp->Text = L"" + 0;
			this->label_left_score_disp->Font->Bold;
			this->label_left_score_disp->TextAlign = ContentAlignment::MiddleCenter;
			this->label_left_score_disp->Font = gcnew System::Drawing::Font("Consolas", 12);
			this->label_left_score_disp->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			/* NEXT label */
			this->label_right_next->AutoSize = false;
			this->label_right_next->Location = System::Drawing::Point(size_form_x - right_offset + 3 * size_border, size_border + 3 * size_disp_block);								// set the location for the block
			this->label_right_next->Size = System::Drawing::Size(size_disp_block * 4, size_disp_block);																				// set the block's size
			this->label_right_next->TabIndex = 0;
			this->label_right_next->Text = L"NEXT";
			this->label_right_next->Font->Bold;
			this->label_right_next->TextAlign = ContentAlignment::MiddleCenter;
			this->label_right_next->Font = gcnew System::Drawing::Font("Consolas", 12);
			/* 2nd label */
			this->label_right_next_2nd->AutoSize = false;
			this->label_right_next_2nd->Location = System::Drawing::Point(size_form_x - right_offset + 3 * size_border, 4 * size_disp_block + 2 * size_border);							// set the location for the block
			this->label_right_next_2nd->Size = System::Drawing::Size(size_leftover - 2 * size_border, 3 * size_small_block);															// set the block's size
			this->label_right_next_2nd->TabIndex = 0;
			this->label_right_next_2nd->Text = L"2nd";
			this->label_right_next_2nd->Font->Bold;
			this->label_right_next_2nd->TextAlign = ContentAlignment::MiddleCenter;
			this->label_right_next_2nd->Font = gcnew System::Drawing::Font("Consolas", 9);
			/* 3rd label */
			this->label_right_next_3rd->AutoSize = false;
			this->label_right_next_3rd->Location = System::Drawing::Point(size_form_x - right_offset + 3 * size_border, 4 * size_disp_block + 3 * size_small_block + 3 * size_border);	// set the location for the block
			this->label_right_next_3rd->Size = System::Drawing::Size(size_leftover - 2 * size_border, 3 * size_small_block);															// set the block's size
			this->label_right_next_3rd->TabIndex = 0;
			this->label_right_next_3rd->Text = L"3rd";
			this->label_right_next_3rd->Font->Bold;
			this->label_right_next_3rd->TextAlign = ContentAlignment::MiddleCenter;
			this->label_right_next_3rd->Font = gcnew System::Drawing::Font("Consolas", 9);
			/* 4th label */
			this->label_right_next_4th->AutoSize = false;
			this->label_right_next_4th->Location = System::Drawing::Point(size_form_x - right_offset + 3 * size_border, 4 * size_disp_block + 6 * size_small_block + 4 * size_border);	// set the location for the block
			this->label_right_next_4th->Size = System::Drawing::Size(size_leftover - 2 * size_border, 3 * size_small_block);															// set the block's size
			this->label_right_next_4th->TabIndex = 0;
			this->label_right_next_4th->Text = L"4th";
			this->label_right_next_4th->Font->Bold;
			this->label_right_next_4th->TextAlign = ContentAlignment::MiddleCenter;
			this->label_right_next_4th->Font = gcnew System::Drawing::Font("Consolas", 9);
			/* 5th label */
			this->label_right_next_5th->AutoSize = false;
			this->label_right_next_5th->Location = System::Drawing::Point(size_form_x - right_offset + 3 * size_border, 4 * size_disp_block + 9 * size_small_block + 5 * size_border);	// set the location for the block
			this->label_right_next_5th->Size = System::Drawing::Size(size_leftover - 2 * size_border, 3 * size_small_block);															// set the block's size
			this->label_right_next_5th->TabIndex = 0;
			this->label_right_next_5th->Text = L"5th";
			this->label_right_next_5th->Font->Bold;
			this->label_right_next_5th->TextAlign = ContentAlignment::MiddleCenter;
			this->label_right_next_5th->Font = gcnew System::Drawing::Font("Consolas", 9);


			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(size_form_x, size_form_y);							// set the size of the main form as calculated
			for (int i = 0; i < num_lbl; i++) {
				this->Controls->Add(this->labels[i]);													// add all the labels to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_left[i]);												// add all the labels left to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_right_main[i]);										// add the labels right main to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_right_2nd[i]);											// add the labels right 2nd to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_right_3rd[i]);											// add the labels right 3rd to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_right_4th[i]);											// add the labels right 4th to form
			}
			for (int i = 0; i < num_lbl_s; i++) {
				this->Controls->Add(this->labels_right_5th[i]);											// add the labels right 5th to form
			}
			this->Controls->Add(this->label_left_hold);
			this->Controls->Add(this->label_left_score);
			this->Controls->Add(this->label_left_score_disp);
			this->Controls->Add(this->label_right_next);
			this->Controls->Add(this->label_right_next_2nd);
			this->Controls->Add(this->label_right_next_3rd);
			this->Controls->Add(this->label_right_next_4th);
			this->Controls->Add(this->label_right_next_5th);
			this->Name = L"MainForm";
			this->Text = L"Tetris(X)";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

	// undate UI
	private:
		void update_right_main() {
			for (int i = 0; i < this->labels_right_main->Length; i++) {
				this->labels_right_main[i]->BackColor = Color::White;
			}
			switch(this->next_block[0]){
			case 0:
				this->labels_right_main[to_row_major(1, 0, num_row_s)]->BackColor = Color::LightSkyBlue;
				this->labels_right_main[to_row_major(1, 1, num_row_s)]->BackColor = Color::LightSkyBlue;
				this->labels_right_main[to_row_major(1, 2, num_row_s)]->BackColor = Color::LightSkyBlue;
				this->labels_right_main[to_row_major(1, 3, num_row_s)]->BackColor = Color::LightSkyBlue;

			}
		}

	// logic
	//private:
	//	// update the UI for the left
	//	void update_UI() {
	//	}
	//	int init_block() {
	//		for (int i = 0; i < num_next; i++) {
	//			this->next_block[i] = std::rand() % num_type;
	//		}
	//	}
	//	int load_block() {

	//	}


#pragma endregion
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
