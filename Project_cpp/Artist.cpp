#define _CRT_SECURE_NO_WARNINGS
#include "artist.h"
#include "creation.h"
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Artist::Artist()
{
	name = NULL;
	birth = Date();
	death = Date();
	Creations = NULL;
}

Artist::Artist(char* name, Date birth, Date death)
{
	this->name = new char [strlen(name)+1];
	strcpy(this->name, name);
	this->birth = birth;
	this->death = death;
}

bool Artist::Add_Creation(Creation* c)
{
	Creation** temp;
	if (this->creations == 0)
	{
		Creations = new Creation * [1];
		if (!Creations)
			return 0;
		Creations[0] = c;
		this->creations++;
		return 1;
	}
	else
	{
		temp = new Creation * [creations + 1];
		if (!temp)
			return 0;
		for (int i = 0; i < creations; i++)
			temp[i] = Creations[i];
		temp[creations] = c;
		delete[] Creations;
		Creations = temp;
		this->creations++;
		return 1;
	}
}

ostream& operator << (ostream& out, const Artist& a)
{
	out << "Artist name: " << a.name << endl << "Birth date: " << a.birth << "Death date: " << a.death << endl;
	out << "Creations: " << endl;
	for (int i = 0; i < a.creations; i++)
		out << a.Creations[i]->get_name() << endl;
	return out;
}

void Artist:: print()const 
{
	for (int i = 0; i < creations; i++)
		Creations[i]->print();
}

bool Artist::PictureExist()
{
	for (int i = 0; i < creations; i++)
		if ((strcmp(Creations[i]->get_type(),"p")==0) || (strcmp(Creations[i]->get_type(),"h")==0))
			return true;
	return false;
}

bool Artist::StatueExist()
{
	for (int i = 0; i < creations; i++)
		if ((strcmp(Creations[i]->get_type(), "s") == 0) || (strcmp(Creations[i]->get_type(), "h") == 0))
			return true;
	return false;
}

void Artist::Remove(char* name)
{
	Creation** temp = NULL;
	temp = new Creation * [creations - 1];
	int count = 0;
	for (int i = 0; i < creations; i++) {
		if (strcmp(Creations[i]->get_name(), name) != 0)
		{
			temp[count] = Creations[i];
			count++;
		}
	}
	delete[]Creations;
	Creations = new Creation * [creations - 1];
	this->Creations = temp;
	creations--;
}

Artist::~Artist()
{
	delete[] this->name;
}