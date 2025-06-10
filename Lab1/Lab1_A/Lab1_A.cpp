// Lab1_A.cpp: главный файл проекта.

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <clocale>
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace std;
using namespace System::IO;

#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79

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
} *spisok;

char dan[7][59] =
{
	"Какой боксер имеет наибольшее количество медалей?         ",
	"У какого боксера ниже 185 меньше всего медалей?           ",
	"Боксеры из ______ страны                                  ",
	"Есть ли боксеры одного года рождения одниакового роста?   ",
	"Алфавитный список спортсменов                             ",
	"Диаграмма медалей                                         ",
	"Выход                                                     " 
};

char BlankLine[]="                                                            ";
int NC;

int menu(int);
void maxim(struct z*);
void low(struct z*);
void homeland(struct z*);
void same(struct z*);
void alfalist(struct z*);
void vstavka(struct z*, char*);
void diagram(struct z*);

int main(array<System::String ^> ^args)
{
	int i, n;
	FILE *in;
	struct z *swimmers;
	setlocale(LC_CTYPE, "Russian");
	Console::CursorVisible::set(false);
	Console::BufferHeight=Console::WindowHeight;
	Console::BufferWidth=Console::WindowWidth;

	if ((in=fopen("boxers.txt", "r"))==NULL)
	{
		printf("\nФайл swimmers.dat не открыт !");
		getch(); exit(1);
	}

	fscanf(in, "%d", &NC);
	swimmers = (struct z*)malloc(NC * sizeof(struct z));

	for (i = 0; i < NC; i++)
		fscanf(in, "%s%s%d%d%s%d", swimmers[i].name, swimmers[i].country,
		&swimmers[i].born, &swimmers[i].height, swimmers[i].style, &swimmers[i].medals);
	
	for (i = 0; i < NC; i++)
		printf("\n %-20s %-12s %-7d %-7d %-15s %-7d", swimmers[i].name, swimmers[i].country,
		swimmers[i].born, swimmers[i].height, swimmers[i].style, swimmers[i].medals);
	getch();

	while (1)
	{
		Console::ForegroundColor = ConsoleColor::DarkGray;
		Console::BackgroundColor = ConsoleColor::DarkGreen;
		Console::Clear();
		Console::ForegroundColor = ConsoleColor::DarkRed;
		Console::BackgroundColor = ConsoleColor::DarkGray;
		Console::CursorLeft = 10;
		Console::CursorTop = 4;
		printf(BlankLine);

		for (i=0; i<7; i++)
		{
			Console::CursorLeft = 10;
			Console::CursorTop = i + 5;
			printf(" %s ", dan[i]);
		}
		Console::CursorLeft = 10;
		Console::CursorTop = 12;
		printf(BlankLine);
		n = menu(7);
		switch(n)
		{
			case 1: maxim(swimmers); break;
			case 2: low(swimmers); break;
			case 3: homeland(swimmers); break;
			case 4: same(swimmers); break;
			case 5: alfalist(swimmers); break;
			case 6: diagram(swimmers); break;
			case 7: exit(0);
		}
	}
	return 0;
}

int menu(int n)
{
	int y1 = 0, y2 = n - 1;
	char c = 1;
	while (c != ESC)
	{
		switch(c)
		{
			case DOWN: y2 = y1; y1++; break;
			case UP: y2 = y1; y1--; break;
			case HOME: y2=y1; y1=0; break;
			case END: y2=y1; y1 = n - 1; break;
			case ENTER: return y1 + 1;
		}
		if (y1 > n - 1)
		{
			y2 = n - 1;
			y1 = 0;
		}
		if (y1 < 0)
		{
			y2=0;
			y1 = n-1;
		}
		Console::ForegroundColor = ConsoleColor::DarkRed; 
		Console::BackgroundColor = ConsoleColor::DarkGray;
		Console::CursorLeft = 11;
		Console::CursorTop = y2 + 5;
		printf("%s", dan[y2]);
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 11;
		Console::CursorTop = y1 + 5;
		printf("%s", dan[y1]);
		c = getch();
	}
	exit(0);
}

void maxim(struct z* swimmers)
{
	int i=0; struct z best;
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
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 14;
		printf("Спортсмен с наибольшим количеством медалей: %s", best.name);
		Console::CursorLeft = 10;
		Console::CursorTop = 15;
		printf("У него %d медалей, и он из %s.", best.medals, best.country);
		getch();
}

void low(struct z* swimmers)
{
	int i=0; struct z lowest; 
	strcpy(lowest.name, swimmers[0].name);
	lowest.medals = swimmers[0].medals; 
	lowest.height = swimmers[0].height;
	for (i = 0; i < NC; i++)
		if ((swimmers[i].medals < lowest.medals) && (swimmers[i].height < 185))
		{
			strcpy(lowest.name, swimmers[i].name);
			lowest.medals = swimmers[i].medals;
			lowest.height = swimmers[i].height;
		}
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 14;
		printf("Спортсмен с нименьшим количеством медалей: %s", lowest.name);
		Console::CursorLeft = 10;
		Console::CursorTop = 15;
		printf("Его рост: %d и количество медалей: %d", lowest.height, lowest.medals);
		getch();
}

void homeland(struct z* swimmers)
{
	int i = 0; struct z home; char strana[15]; char people[100] = "";
	Console::ForegroundColor = ConsoleColor::White;
	Console::BackgroundColor = ConsoleColor::Red;
	Console::CursorLeft = 10;
	Console::CursorTop = 14;
	printf("Введите страну: ");
	SetConsoleCP(1251);
	scanf("%s", strana);
	SetConsoleCP(866);

	for (i = 0; i < NC; i++)
		if ((strcmp(swimmers[i].country, strana)) == 0)
		{
			strcat(people, swimmers[i].name);
			strcat(people, " ");
		}
	if (strlen(people) == 0)
	{
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 15;
		printf("Спортсмены из данной страны отсутствуют или было неверно указана страна.");
		getch();
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 16;
		printf("Спортсмены из одной страны:");

		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 17;
		printf("%s", people);
		getch();
	}
}

void same(struct z* swimmers)
{
	int i, j; 
	char same_country_and_born[100] = "";
	struct z examp;
	for (i = 0; i < NC; i++)
	{
		strcpy(examp.name, swimmers[i].name);
		examp.height = swimmers[i].height;
		examp.born = swimmers[i].born;
		for (j = i+1; j < NC; j++)
			if ((swimmers[j].born == examp.born) && (swimmers[j].height == examp.height))
			{
				strcat(same_country_and_born, swimmers[j].name);
				strcat(same_country_and_born, " ");
			}
		if (strlen(same_country_and_born) > 1) break;
	}
	if (strlen(same_country_and_born) == 0)
	{
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 14;
		printf("Спортсмены одного года рождения из одной страны отсутствуют.");
		getch();
	}
	else
	{
		Console::ForegroundColor = ConsoleColor::White;
		Console::BackgroundColor = ConsoleColor::Red;
		Console::CursorLeft = 10;
		Console::CursorTop = 14;
		printf("Спортсмены с одинаковым годом рождения и ростом:");
		Console::CursorLeft = 10;
		Console::CursorTop = 15;
		printf("%s %s", examp.name, same_country_and_born);
		Console::CursorLeft = 10;
		Console::CursorTop = 15;
		printf("%s %s", examp.name, same_country_and_born);
		Console::CursorLeft = 10;
		Console::CursorTop = 16;
		printf("Они %d года рождения и их рост: %d см", examp.born, examp.height);
		getch();
	}
}

void alfalist(struct z* swimmers)
{
	int i,x;
	struct sp* nt, *z;
	x = 3;
	Console::ForegroundColor = ConsoleColor::Red;
	Console::BackgroundColor = ConsoleColor::White;
	Console::Clear();
	printf("\n Алфавитный список пловцов");
	printf("\n=================================================================\n");
	if (!spisok)
		for (i = 0; i < NC; i++)
			vstavka(swimmers, swimmers[i].name);
	for (nt = spisok; nt != 0; nt = nt->sled)
	{
		Console::CursorLeft = 0;
		Console::CursorTop = x+1;
		printf(" %-20s %d %d", nt->name, nt->born, nt->medals);
		x += 1;
	}
	x = 3;
	Console::CursorLeft = 40;
	Console::CursorTop = x + 1;
	printf("Обратный алфавитный список");
	for (nt = spisok; nt != 0; z = nt, nt = nt->sled);
	for (nt = z, i = 0; nt != 0; i++, nt = nt->pred)
	{
		Console::CursorLeft = 40;
		Console::CursorTop = x + 1;
		printf(" %-20s %d %d", nt->name, nt->born, nt->medals);
		x += 1;
	}
	getch();
}

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

void diagram(struct z* swimmers)
{
	struct sp *nt;
	int len, i, NColor;
	int sum = 0;
	char str1[20];
	char str2[20];
	System::ConsoleColor Color;
	Console::ForegroundColor = ConsoleColor::Red;
	Console::BackgroundColor = ConsoleColor::White;
	Console::Clear();
	for (i = 0; i < NC; i++)
		sum = sum + swimmers[i].medals;
	if (!spisok)
		for (i = 0; i < NC; i++)
			vstavka(swimmers, swimmers[i].name);
	Color=ConsoleColor::Black;
	NColor = 0;
	for (nt = spisok, i = 0; nt != 0; nt = nt->sled, i++)
	{
		sprintf(str1,"%s", nt->name);
		sprintf(str2,"%3.1f%%", (nt->medals * 100./ sum));
		Console::ForegroundColor = ConsoleColor::Red;
		Console::BackgroundColor = ConsoleColor::White;
		Console::CursorLeft = 5;
		Console::CursorTop = i + 1;
		printf("%-20s", str1);
		printf("%s", str2);
		Console::BackgroundColor = ++Color; NColor++;
		Console::CursorLeft = 30;
		for (len = 0; len < nt->medals * 100 / sum; len++) printf(" ");
		if (NColor == 14)
		{
			Color = ConsoleColor::Black;
			NColor = 0;
		}
	}
	getch();
	return;
}