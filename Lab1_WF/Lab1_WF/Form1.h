#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
#include "Form2.h"
using namespace System::Runtime::InteropServices;

int NC;

struct z {	
	char name[20];
	char country[10];
	int born;
	int height;
	char style[15];
	int medals;
};

struct sp {
	char name[20];
	int born;
	int medals;
	struct sp* sled;
	struct sp* pred;
}*spisok;

struct z *swimmers;

void vstavka(struct z* swimmers, char* name)
{
	int i;
	struct sp* nov, *nt, *z = 0;
	for (nt = spisok; (nt != 0 && (strcmp(nt->name,name) < 0));  z = nt, nt = nt->sled);
	if (nt && (strcmp(nt->name, name) == 0)) return;
	nov = (struct sp*)malloc(sizeof(struct sp));
	strcpy(nov->name, name);
	nov->sled = nt;
	nov->pred = z;
	nov->born = 0;
	nov->medals = 0;
	for (i = 0; i < NC; i++)
		if (strcmp(swimmers[i].name, name) == 0)
		{
			nov->born += swimmers[i].born;
			nov->medals += swimmers[i].medals;
		}
	if (!z) spisok = nov;
	if (z) z->sled = nov;
	if (nt) nt->pred = nov;
	return;
}

void selected_country_form(char* name,char* country, struct z* swimmers)
{
	char sportsmens_names[200] = "";
	for(int i=0;i<NC;i++)
	{
		if (strcmp(country,swimmers[i].country)==0)
		{
			strcat(sportsmens_names, swimmers[i].name);
			strcat(sportsmens_names, "\n");
		}
	}
	strcpy(name, sportsmens_names);
	return;
}

namespace Lab1_WF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	///
	/// ¬нимание! ѕри изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") дл€ средства компил€ции управл€емого ресурса,
	///          св€занного со всеми файлами с расширением .resx, от которых зависит данный класс. ¬ противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  вопросыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  пловцы»з—траныToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  алфавитный—писок—портсменовToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  диаграммаћедалейToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	protected: 

	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вопросыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->пловцы»з—траныToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->алфавитный—писок—портсменовToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->диаграммаћедалейToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->файлToolStripMenuItem, 
				this->вопросыToolStripMenuItem, this->выходToolStripMenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(824, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->открытьToolStripMenuItem, 
				this->выходToolStripMenuItem});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->файлToolStripMenuItem->Text = L"‘айл";
			this->файлToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::файлToolStripMenuItem_Click);
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->открытьToolStripMenuItem->Text = L"ќткрыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::открытьToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->выходToolStripMenuItem->Text = L"«авершить";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
			// 
			// вопросыToolStripMenuItem
			// 
			this->вопросыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem, 
				this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem, this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem, 
				this->пловцы»з—траныToolStripMenuItem, this->алфавитный—писок—портсменовToolStripMenuItem, this->диаграммаћедалейToolStripMenuItem});
			this->вопросыToolStripMenuItem->Enabled = false;
			this->вопросыToolStripMenuItem->Name = L"вопросыToolStripMenuItem";
			this->вопросыToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->вопросыToolStripMenuItem->Text = L"¬опросы";
			// 
			// какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem
			// 
			this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem->Name = L"какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem";
			this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem->Text = L" акой пловец имеет наибольшее количество медалей\?";
			this->какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem_Click);
			// 
			// естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem
			// 
			this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem->Name = L"естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem";
			this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem->Text = L"≈сть ли спортсмены одного года рождени€ из одной страны\?";
			this->естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem_Click);
			// 
			// у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem
			// 
			this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem->Name = L"у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem";
			this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem->Text = L"” какого спортсмена ниже 190 меньше всего медалей\?";
			this->у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem_Click);
			// 
			// пловцы»з—траныToolStripMenuItem
			// 
			this->пловцы»з—траныToolStripMenuItem->Name = L"пловцы»з—траныToolStripMenuItem";
			this->пловцы»з—траныToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->пловцы»з—траныToolStripMenuItem->Text = L"ѕловцы из __ страны";
			this->пловцы»з—траныToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::пловцы»з—траныToolStripMenuItem_Click);
			// 
			// алфавитный—писок—портсменовToolStripMenuItem
			// 
			this->алфавитный—писок—портсменовToolStripMenuItem->Name = L"алфавитный—писок—портсменовToolStripMenuItem";
			this->алфавитный—писок—портсменовToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->алфавитный—писок—портсменовToolStripMenuItem->Text = L"јлфавитный список спортсменов";
			this->алфавитный—писок—портсменовToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::алфавитный—писок—портсменовToolStripMenuItem_Click);
			// 
			// диаграммаћедалейToolStripMenuItem
			// 
			this->диаграммаћедалейToolStripMenuItem->Name = L"диаграммаћедалейToolStripMenuItem";
			this->диаграммаћедалейToolStripMenuItem->Size = System::Drawing::Size(413, 22);
			this->диаграммаћедалейToolStripMenuItem->Text = L"ƒиаграмма медалей";
			this->диаграммаћедалейToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::диаграммаћедалейToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem1
			// 
			this->выходToolStripMenuItem1->Name = L"выходToolStripMenuItem1";
			this->выходToolStripMenuItem1->Size = System::Drawing::Size(53, 20);
			this->выходToolStripMenuItem1->Text = L"¬ыход";
			this->выходToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem1_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(12, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(800, 423);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Silver;
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(792, 397);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"»сходные данные";
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 14;
			this->listBox1->Location = System::Drawing::Point(-4, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(800, 396);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::Color::Silver;
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(792, 397);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"—писок";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox2->Location = System::Drawing::Point(396, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(396, 397);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(400, 397);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &Form1::richTextBox1_TextChanged);
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::Color::White;
			this->tabPage3->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(792, 397);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"ƒиаграмма";
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage3_Paint);
			this->tabPage3->Click += gcnew System::EventHandler(this, &Form1::tabPage3_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"swimmers";
			this->openFileDialog1->Filter = L"“екстовые файлы (*.txt)|*.txt";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFileDialog1_FileOk);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(824, 447);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"‘орма";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 MessageBox::Show("ѕривет!");
			 }
	private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
			 }
private: System::Void файлToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void открытьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 FILE *in;
			 int i;
			 char ctemp[200];
			 String ^s;
			 if(openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
			 {
				 s=openFileDialog1->FileName;
				 char *str_tmp=(char*)(void*)Marshal::StringToHGlobalAnsi(s);
				 if ((in=fopen(str_tmp,"r"))==NULL)
				 {
					 MessageBox::Show("‘айл не открыт!","ќшибка!",
					 MessageBoxButtons::OK, MessageBoxIcon::Error);
					 Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
					 return;
				 }
				 Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
			 }
			 else return;
			 /* if ((in=fopen("swimmers.txt","r"))==NULL)
				 {
				 MessageBox::Show("‘айл не открыт!", "ќшибка!",
					 MessageBoxButtons::OK,	MessageBoxIcon::Error);
				 return;
				 } */
			 вопросыToolStripMenuItem->Enabled=true;
			 listBox1->Items->Clear();
			 fscanf(in,"%d",&NC);
			 swimmers=new z[NC];
			 for (i=0; i<NC; i++)
				{
					fscanf(in,"%s%s%d%d%s%d", swimmers[i].name, swimmers[i].country, 
						&swimmers[i].born, &swimmers[i].height, swimmers[i].style, &swimmers[i].medals);
					sprintf(ctemp,"| %-18s %-12s %-6d %-5d %-17s %-5d |", swimmers[i].name, swimmers[i].country,
						swimmers[i].born, swimmers[i].height, swimmers[i].style, swimmers[i].medals);
					s=gcnew String(ctemp);
					listBox1->Items->Add(s);
				}
			 fclose(in);
		}
private: System::Void выходToolStripMenuItem1_Click
			 (
			 System::Object^  sender,
			 System::EventArgs^  e
			 ) 
					 {
						 this->Close();
					 }
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void какойѕловец»меетЌаибольшее оличествоћедалейToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int i=0; struct z best;
			 char ss[200];
			 String ^s;

			 strcpy(best.name, swimmers[0].name);
			 strcpy(best.country, swimmers[0].country);
			 best.medals = swimmers[0].medals;
			 for (i = 1; i<NC; i++)
				 if (swimmers[i].medals > best.medals)
				 {
					strcpy(best.name, swimmers[i].name);
					strcpy(best.country, swimmers[i].country);
					best.medals = swimmers[i].medals;
				 }
			 sprintf(ss, "—портсмен с наибольшим количеством медалей: %s\n” него %d медалей, и он из %s.",
					best.name, best.medals, best.country);
			 s=gcnew String(ss);
			 MessageBox::Show(s,"—портсмен с наибольшим количеством медалей");
		 }
private: System::Void естьЋи—портсменыќдного√ода–ождени€»зќдной—траныToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			int i, j;
			char ss[200];
			String ^s;
			char same_country_and_born[100] = "";
			struct z examp;
			for (i = 0; i < NC; i++)
			{
				strcpy(examp.name, swimmers[i].name);
				strcpy(examp.country, swimmers[i].country);
				examp.born = swimmers[i].born;
				for (j = i+1; j < NC; j++)
					if ((swimmers[j].born == examp.born) && ((strcmp(swimmers[j].country, examp.country)) == 0))
					{
						strcat(same_country_and_born, swimmers[j].name);
						strcat(same_country_and_born, " ");
					}
				if (strlen(same_country_and_born) > 1) break;
				}
				if (strlen(same_country_and_born) == 0)
				{
					sprintf(ss, "—портсмены одного года рождени€ из одной страны отсутствуют.");
				}
				else
				{
					sprintf(ss,"—портсмены с одинаковым годом рождени€ и страной:\n %s %s\n ќни из %s и %d года рождени€",examp.name, same_country_and_born, examp.country, examp.born);
				}
			s = gcnew String(ss);
			MessageBox::Show(s, "≈сть ли спортсмены одного года рождени€ из одной страны?");
		  }
		private: System::Void у акого—портсменаЌиже190ћеньше¬сегоћедалейToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			{
				int i=0; 
				struct z lowest; 
				char ss[200];
				String ^s;
				strcpy(lowest.name, swimmers[0].name);
				lowest.medals = swimmers[0].medals; 
				lowest.height = swimmers[0].height;
				for (i = 0; i < NC; i++)
					if ((swimmers[i].medals < lowest.medals) && (swimmers[i].height < 190))
					{
						strcpy(lowest.name, swimmers[i].name);
						lowest.medals = swimmers[i].medals;
						lowest.height = swimmers[i].height;
					}

					sprintf(ss,"—портсмен с наименьшим количеством медалей: %s\n ≈го рост: %d и количество медалей: %d", lowest.name, lowest.height, lowest.medals);
					s = gcnew String(ss);
					MessageBox::Show(s,"” какого спортсмена ниже 190 меньше всего медалей?");
			}

private: System::Void алфавитный—писок—портсменовToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			int i,x;
			struct sp* nt, *z;
			char ss[200];
			String ^s;
			tabControl1->SelectTab(1);
			if(!spisok)
				for (i=0; i<NC; i++)
					vstavka(swimmers, swimmers[i].name);
			richTextBox1->ReadOnly=1;
			richTextBox1->Clear();
			richTextBox1->Text="\nјЋ‘ј¬»“Ќџ… —ѕ»—ќ \n=========================\n";
			for(nt=spisok; nt!=0; z=nt, nt=nt->sled)
			{
				sprintf(ss, "%-16s %3d %3d", nt->name, nt->born, nt->medals);
				s=gcnew String(ss,0,31);
				richTextBox1->Text=richTextBox1->Text+"\n"+s;
			}
			richTextBox2->ReadOnly=1;
			richTextBox2->Clear();
			richTextBox2->Text="\nќЅ–ј“Ќџ… јЋ‘ј¬»“Ќџ… —ѕ»—ќ \n=========================\n";
			for(nt=spisok; nt!=0; nt=nt->sled);
			for(nt = z; nt!=0; nt=nt->pred)
			{
				sprintf(ss, "%-16s %3d %3d", nt->name, nt->born, nt->medals);
				s=gcnew String(ss,0,31);
				richTextBox2->Text=richTextBox2->Text+"\n"+s;
			}
		 }
private: System::Void tabPage3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void диаграммаћедалейToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 tabControl1->SelectTab(2);
		 }
private: System::Void tabPage3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
			 Pen ^myPen=gcnew Pen(System::Drawing::Color::Black,3);
			 SolidBrush ^myBrush=gcnew SolidBrush(Color::FromArgb(196,0,0,0));
			 System::Drawing::Font^ myFont=gcnew System::Drawing::Font("Arial",8);

			 int i,K;
			 int iRed,iGreen,iBlue;
			 int aStart,aEnd;
			 long Sum;;
			 float xPos,yPos;
			 struct sp *nt;

			 Graphics ^g=tabPage3->CreateGraphics();
			 g->Clear(System::Drawing::Color::White);

			 if(!spisok)
				 for(i=0;i<NC;i++)
					 vstavka(swimmers, swimmers[i].name);
			 K=0;Sum=0;
			 for(nt=spisok;nt!=0;nt=nt->sled)
				{
				K++;
				Sum+=nt->medals;
				}
			 g->DrawEllipse(myPen,25,25,185,185);
			 aEnd=0;

			 for(nt=spisok,i=0;nt!=0;nt=nt->sled,i++)
				{
				iRed=(((i+1)&4)>0)*255/(i/8+1);
				iGreen=(((i+1)&2)>0)*255/(i/8+1);
				iBlue=(((i+1)&1)>0)*255/(i/8+1);
				aStart=aEnd;
				aEnd+=nt->medals*360/Sum;
				if(i==K-1)aEnd=360;
				myBrush->Color::set(Color::FromArgb(196,iRed,iGreen,iBlue));
				g->FillPie(myBrush,25,25,185,185,aStart,aEnd-aStart);
				g->FillRectangle(myBrush,300,50+(i-1)*20,20,20);

				myBrush->Color::set(Color::FromArgb(196,0,0,0));
				xPos=30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
				yPos=30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);

				g->DrawString(gcnew String(nt->name),myFont,myBrush,320,55+(i-1)*20);
				g->DrawString(Convert::ToString(nt->medals*100/Sum)+"%",myFont,myBrush,xPos,yPos);
				}
		 }
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void пловцы»з—траныToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				char names[200] = "";
				char ss[200];
				String^ s;
				Form2 ^F2=gcnew Form2();
				F2->ShowDialog();
				MessageBox::Show(F2->a,"¬ы ввели");
				char* country = (char*)(void*)Marshal::StringToHGlobalAnsi(F2->a);
				Marshal::FreeHGlobal(IntPtr((void*)country));
				selected_country_form(names, country, swimmers);
				if (strcmp(names, "")==0)
				{
					MessageBox::Show("—портсменов из данной страны нет.", "ќшибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				else
				{
					sprintf(ss, "—портсмены из %s:\n%s", country, names);
					s = gcnew String(ss);
					MessageBox::Show(s, "—портсмены из выбранной страны", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
		 }
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {

		 }
};
}

