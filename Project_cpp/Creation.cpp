#define _CRT_SECURE_NO_WARNINGS
#include "creation.h"
#include "artist.h"
#include <iostream>
#include <string>

Creation::Creation()
{
	this->name = NULL;
	this->year = 0;
	this->genere = NULL;
	this->height = 0;
	artist = NULL;
}

Creation::Creation(char* name, int year, char* genere, float height, Artist* artist)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->year = year;
	this->genere = new char[strlen(genere) + 1];
	strcpy(this->genere, genere);
	this->height = height;
	this->artist = artist;
}

void Creation::print()const
{
	cout << "Creation name: " << name << endl << "Year: " << year << endl << "Genere: " << genere << endl << "Height: " << height << endl << "Artist: " << artist->get_name() << endl;;
}

Creation::~Creation()
{
	delete[]this->name;
	delete[]this->genere;
}
