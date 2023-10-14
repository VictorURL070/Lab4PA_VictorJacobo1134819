#pragma once
#include "List.h"
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

namespace Lab4VictorJacobo1134819 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtArea;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtNextCard;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtArea = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtNextCard = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Solitario";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(68, 339);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Empezar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// txtArea
			// 
			this->txtArea->Location = System::Drawing::Point(68, 147);
			this->txtArea->Multiline = true;
			this->txtArea->Name = L"txtArea";
			this->txtArea->Size = System::Drawing::Size(340, 143);
			this->txtArea->TabIndex = 2;
			this->txtArea->TextChanged += gcnew System::EventHandler(this, &MyForm::txtArea_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(46, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Siguiente carta: ";
			// 
			// txtNextCard
			// 
			this->txtNextCard->Location = System::Drawing::Point(163, 83);
			this->txtNextCard->Name = L"txtNextCard";
			this->txtNextCard->ReadOnly = true;
			this->txtNextCard->Size = System::Drawing::Size(100, 22);
			this->txtNextCard->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 477);
			this->Controls->Add(this->txtNextCard);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtArea);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		static bool IsSorted(int* data, int count)
		{
			while (--count >= 1)
				if (data[count] < data[count - 1]) return false;

			return true;
		}

		static void Shuffle(int* data, int count)
		{
			int temp, rnd;

			for (int i = 0; i < count; ++i)
			{
				rnd = rand() % count;
				temp = data[i];
				data[i] = data[rnd];
				data[rnd] = temp;
			}
		}

		static void BogoSort(int* data, int count)
		{
			while (!IsSorted(data, count))
				Shuffle(data, count);
		}

		string Baraja()
		{
			List Baraja = List();
			stack<string> BarajaF;

			int CartaN, CartaR;
			int VRand;
			int S, NR;
			int pos = 0;
			int N[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };


			BogoSort(N, 14);

			for (S = 0; NR < 52; NR++)
			{
				VRand = rand() % 10 + 1;

				if (VRand < 6)
				{
					if (CartaN > 27) 
					{
						string num = to_string(N[pos]);
						BarajaF.push("N" + num);
						CartaN++;

					}
					else if (CartaR > 27)
					{
						string num = to_string(N[pos]);
						BarajaF.push("R" + num);
						CartaR++;
					}
				}
				else 
				{
					if (CartaN > 27)
					{
						string num = to_string(N[pos]);
						BarajaF.push("N" + num);
						CartaN++;

					}
					else if (CartaR > 27)
					{
						string num = to_string(N[pos]);
						BarajaF.push("R" + num);
						CartaR++;
					}
				}
				pos++;
				if (pos == 14)
				{
					pos = 0;
				}
				
			}
			
			string next = BarajaF.top();
			BarajaF.pop();

			return next;
		}

		string Nextcard(string next) 
		{
			string NextC = Baraja();

			//txtNextCard->Text = NextC;
		}

#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   
	private: System::Void txtArea_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
		   
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	
	//txtNextCard->Text = Baraja.GetItem(0).ToString();
}
};
}
