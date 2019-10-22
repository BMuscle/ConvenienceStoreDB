#pragma once
#include <msclr/marshal_cppstd.h>
#include "Mysql.h"
#include <vector>

namespace ConvenienceStore {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ bt1;
	private: System::Windows::Forms::Label^ titlelb;
	private: System::Windows::Forms::CheckedListBox^ product_list;



	protected:

	protected:


	private: System::Windows::Forms::Label^ debuglb;

	private: System::Windows::Forms::Button^ linkbutton;
	private: System::Windows::Forms::NumericUpDown^ amount_numUpDown;
	private: System::Windows::Forms::Label^ amount_lb;


	private: System::Windows::Forms::ComboBox^ store_comboBox;
	private: System::Windows::Forms::Label^ store_lb;


	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->bt1 = (gcnew System::Windows::Forms::Button());
			this->titlelb = (gcnew System::Windows::Forms::Label());
			this->product_list = (gcnew System::Windows::Forms::CheckedListBox());
			this->debuglb = (gcnew System::Windows::Forms::Label());
			this->linkbutton = (gcnew System::Windows::Forms::Button());
			this->amount_numUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->amount_lb = (gcnew System::Windows::Forms::Label());
			this->store_comboBox = (gcnew System::Windows::Forms::ComboBox());
			this->store_lb = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_numUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// bt1
			// 
			this->bt1->Location = System::Drawing::Point(645, 390);
			this->bt1->Name = L"bt1";
			this->bt1->Size = System::Drawing::Size(266, 115);
			this->bt1->TabIndex = 0;
			this->bt1->Text = L"発注決定";
			this->bt1->UseVisualStyleBackColor = true;
			this->bt1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// titlelb
			// 
			this->titlelb->AutoSize = true;
			this->titlelb->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(128)));
			this->titlelb->Location = System::Drawing::Point(31, 34);
			this->titlelb->Name = L"titlelb";
			this->titlelb->Size = System::Drawing::Size(385, 60);
			this->titlelb->TabIndex = 1;
			this->titlelb->Text = L"商品在庫追加";
			this->titlelb->Click += gcnew System::EventHandler(this, &MyForm::Label1_Click);
			// 
			// product_list
			// 
			this->product_list->FormattingEnabled = true;
			this->product_list->Location = System::Drawing::Point(41, 171);
			this->product_list->Name = L"product_list";
			this->product_list->Size = System::Drawing::Size(375, 334);
			this->product_list->TabIndex = 2;
			// 
			// debuglb
			// 
			this->debuglb->AutoSize = true;
			this->debuglb->Location = System::Drawing::Point(38, 128);
			this->debuglb->Name = L"debuglb";
			this->debuglb->Size = System::Drawing::Size(129, 18);
			this->debuglb->TabIndex = 3;
			this->debuglb->Text = L"デバッグメッセージ";
			// 
			// linkbutton
			// 
			this->linkbutton->Location = System::Drawing::Point(442, 438);
			this->linkbutton->Name = L"linkbutton";
			this->linkbutton->Size = System::Drawing::Size(123, 67);
			this->linkbutton->TabIndex = 4;
			this->linkbutton->Text = L"データベースと同期";
			this->linkbutton->UseVisualStyleBackColor = true;
			this->linkbutton->Click += gcnew System::EventHandler(this, &MyForm::Linkbutton_Click);
			// 
			// amount_numUpDown
			// 
			this->amount_numUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->amount_numUpDown->Location = System::Drawing::Point(442, 392);
			this->amount_numUpDown->Name = L"amount_numUpDown";
			this->amount_numUpDown->Size = System::Drawing::Size(123, 26);
			this->amount_numUpDown->TabIndex = 5;
			// 
			// amount_lb
			// 
			this->amount_lb->AutoSize = true;
			this->amount_lb->Location = System::Drawing::Point(439, 359);
			this->amount_lb->Name = L"amount_lb";
			this->amount_lb->Size = System::Drawing::Size(44, 18);
			this->amount_lb->TabIndex = 6;
			this->amount_lb->Text = L"数量";
			// 
			// store_comboBox
			// 
			this->store_comboBox->FormattingEnabled = true;
			this->store_comboBox->ImeMode = System::Windows::Forms::ImeMode::On;
			this->store_comboBox->Location = System::Drawing::Point(442, 209);
			this->store_comboBox->Name = L"store_comboBox";
			this->store_comboBox->Size = System::Drawing::Size(121, 26);
			this->store_comboBox->TabIndex = 8;
			this->store_comboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Store_comboBox_SelectedIndexChanged);
			// 
			// store_lb
			// 
			this->store_lb->AutoSize = true;
			this->store_lb->Location = System::Drawing::Point(442, 179);
			this->store_lb->Name = L"store_lb";
			this->store_lb->Size = System::Drawing::Size(42, 18);
			this->store_lb->TabIndex = 9;
			this->store_lb->Text = L"店ID";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1058, 664);
			this->Controls->Add(this->store_lb);
			this->Controls->Add(this->store_comboBox);
			this->Controls->Add(this->amount_lb);
			this->Controls->Add(this->amount_numUpDown);
			this->Controls->Add(this->linkbutton);
			this->Controls->Add(this->debuglb);
			this->Controls->Add(this->product_list);
			this->Controls->Add(this->titlelb);
			this->Controls->Add(this->bt1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->amount_numUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Linkbutton_Click(System::Object^ sender, System::EventArgs^ e) {
		//同期ボタンが押された時の処理
		Mysql* mysql = new Mysql();
		//product_listのデータ取得
		std::vector<std::string> product_data;
		mysql->getSqlString(product_data, "SELECT name FROM product ORDER BY product_id");
		product_list->Items->Clear();
		for (int i = 0; i < product_data.size(); i++) {
			product_list->Items->Add(mysql->encodeString(product_data.at(i)));
		}

		//store_comboBoxのデータ取得
		std::vector<int> store_data;
		mysql->getSqlIntger(store_data, "SELECT store_id FROM store ORDER BY store_id");
		store_comboBox->Items->Clear();
		for (int i = 0; i < store_data.size(); i++) {
			store_comboBox->Items->Add(store_data.at(i));
		}
		
	}

private: System::Void Store_comboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
