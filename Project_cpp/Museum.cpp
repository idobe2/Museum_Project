#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "museum.h"
#include "artist.h"
#include "creation.h"
#include "Date.h"
#include "hanging_statue .h"
#include "picture.h"
#include "statue.h"

using namespace std;

Museum::Museum()
{
	a = 0;
	c = 0;
	this->creations = NULL;
	this->artists = NULL;
}

bool Museum::Add_Artist(Artist* art)
{
	Artist** temp;
	if (this->a == 0)
	{
		artists = new Artist * [1];
		if (!artists)
			return 0;
		artists[0] = art;
		this->a++;
		return 1;
	}
	else
	{
		temp = new Artist * [a + 1];
		if (!temp)
			return 0;
		for (int i = 0; i < a; i++)
			temp[i] = artists[i];
		temp[a] = art;
		delete[] artists;
		artists = temp;
		this->a++;
		return 1;
	}
}

bool Museum::Add_Creation(Creation* create)
{
	Creation** temp;
	if (this->c == 0)
	{
		creations = new Creation * [1];
		if (!creations)
			return 0;
		creations[0] = create;
		this->c++;
		return 1;
	}
	else
	{
		temp = new Creation * [c + 1];
		if (!temp)
			return 0;
		for (int i = 0; i < c; i++)
			temp[i] = creations[i];
		temp[c] = create;
		delete[] creations;
		creations = temp;
		this->c++;
		return 1;
	}
}

bool Museum::Remove_Creation(int index)
{
	Artist* art = creations[index]->get_artist();
	art->Remove(creations[index]->get_name());
	Creation** temp;
	temp = new Creation * [c-1];
	if (!temp)
		return 0;
	int count = 0;
	for (int i = 0; i < c; i++)
		if (i != index)
		{
			temp[count] = creations[i];
			count++;
		}	
	delete[]creations;
	creations = new Creation * [c - 1];
	this->creations = temp;
	c--;
	return 1;
}

void Museum::Print_Artists_Creations(Artist** artists) // At least one creation
{
	for (int i = 0; i < a; i++)
		if (artists[i]->get_creations()>0)
			cout << *(artists[i]) << endl;
}

void Museum::Print_Creations() // All creations
{
	for (int i = 0; i < c; i++)
		creations[i]->print();
}

void Museum::Print_Pictures() // All pictures
{
	for (int i = 0; i < c; i++)
	{
		if ((strcmp(creations[i]->get_type(),"p")==0) || (strcmp(creations[i]->get_type(),"h")==0))
			creations[i]->print();
	}
}

void Museum::Print_Statues() // All statues
{
	for (int i = 0; i < c; i++)
	{
		if ((strcmp(creations[i]->get_type(),"s")==0) || (strcmp(creations[i]->get_type(),"h")==0))
			creations[i]->print();
	}
}

void Museum::Print_Creations_Of_Artist(const Artist &a) { a.print(); }

void Museum::Print_Creations_Of_Genere(char* genere)
{
	for (int i = 0; i < c; i++)
		if(strcmp(creations[i]->get_genere(),genere) == 0)
			creations[i]->print();
}

void Museum::Print_Artists_Pictures()
{
	for (int i = 0; i < c; i++)
		if (artists[i]->PictureExist() == true)
			cout << *(artists[i]) << endl;
}

void Museum::Print_Artists_Statues()
{
	for (int i = 0; i < c; i++)
		if (artists[i]->StatueExist() == true)
			cout << *(artists[i]) << endl;
}

void Museum:: Print_Statues_By_Weight(float weight)
{
	for (int i = 0; i < c; i++)
	{
		Statue* temp;
		temp = dynamic_cast<Statue*>(creations[i]);
		if (temp)
			if (temp->get_weight() > weight)
				temp->print();
	}
}

void Museum::menu()
{
	int option = 1, day, month, year, screw_qty, index;
	char name[20], genere[20];
	float height, length, area, weight;
	char dead;
	Artist* artist = NULL;
	Creation* create = NULL;
	while (option!=13)
	{
		cout << "Please select an option" << endl << "1 - Add artist" << endl << "2 - Add creation" << endl << "3 - Remove creation" << endl << "4 - Print artists with at least one creation" << endl << "5 - Print all the creations" << endl << "6 - Print all the pictures" << endl << "7 - Print all the statues" << endl << "8 - Print creations by specific artist" << endl << "9 - Print creations by specific genere" << endl << "10 - Print all artists with at least one picture" << endl << "11 - Print all artists with at least one statue" << endl << "12 - Print all statues above specific weight" << endl << "13 - Exit" << endl << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			get_artist();
		break;
		case 2:
		{
			int type;
			artist = get_artist();
			cout << "Enter creation name: " << endl;
			cin >> name;
			cout << "Enter year: " << endl;
			cin >> year;
			cout << "Enter height: " << endl;
			cin >> height;
			cout << "Enter genere: " << endl;
			cin >> genere;
			cout << "Select a creation to add: " << endl << "1 - Picture" << endl << "2 - Statue" << endl << "3 - Hanging statue" << endl;
			cin >> type;
			switch (type)
			{
			case 1: // Picture
			{
				cout << "Enter length: " << endl;
				cin >> length;
				create = new Picture(name, year, genere, height, artist, length);
				Add_Creation(create);
				artist->Add_Creation(create);
				break;
			}
			case 2: // Statue
			{
				cout << "Enter area: " << endl;
				cin >> area;
				cout << "Enter weight: " << endl;
				cin >> weight;
				create = new Statue(name, year, genere, height, artist, area, weight);
				Add_Creation(create);
				artist->Add_Creation(create);
				break;
			}
			case 3: // Hanging statue
			{
				cout << "Enter length: " << endl;
				cin >> length;
				cout << "Enter area: " << endl;
				cin >> area;
				cout << "Enter weight: " << endl;
				cin >> weight;
				cout << "Enter number of screws: " << endl;
				cin >> screw_qty;
				create = new Hanging_statue(name, year, genere, height, artist, length, area, weight, screw_qty);
				Add_Creation(create);
				artist->Add_Creation(create);
				break;
			}
			default:
				cout << "Invalid input!" << endl;
				break;
			}
			break;
		}
		case 3:
		{
			cout << "Enter index to remove creation" << endl;
			cin >> index;
			if (index >= 0 && index < c)
				Remove_Creation(index);
			else
				cout << "Invalid input!" << endl;
			break;
		}
		case 4:
			Print_Artists_Creations(artists);
			break;
		case 5:
			Print_Creations();
			break;
		case 6:
			Print_Pictures();
			break;
		case 7:
			Print_Statues();
			break;
		case 8:
			cout << "Enter artist name:" << endl;
			cin >> name;
			if ((index = ArtistExist(name)) != -1)
				Print_Creations_Of_Artist(artist[index]);
			else
				cout << "Invalid input, no matching artist.." << endl;
			break;
		case 9:
			cout << "Enter genere:" << endl;
			cin >> genere;
			Print_Creations_Of_Genere(genere);
			break;
		case 10:
			Print_Artists_Pictures();
			break;
		case 11:
			Print_Artists_Statues();
			break;
		case 12:
			cout << "Enter weight: " << endl;
			cin >> weight;
			Print_Statues_By_Weight(weight);
			break;
		case 13:
			cout << "GoodBye.." << endl;
			return;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}
}

int Museum::ArtistExist(char* name)
{
	for (int i = 0; i < a; i++)
		if (strcmp(name, artists[i]->get_name()) == 0)
			return i;
	return -1;
}

Artist* Museum::get_artist()
{
	Artist* artist = NULL;
	char dead;
	char name[20];
	int day, month, year, i;
	cout << "Enter artist name: " << endl;
	cin >> name;
	if ((i=ArtistExist(name)) != -1)
	{
		cout << "Artist already exist, continue normally.." << endl;
		return artists[i];
	}
	else
	{
		cout << "Enter birth day month year: " << endl;
		cin >> day >> month >> year;
		Date birth(day, month, year);
		cout << "Has the artist died? Y/N" << endl;
		cin >> dead;
		if (dead == 'y' || dead == 'Y')
		{
			cout << "Enter death day month year: " << endl;
			cin >> day >> month >> year;
			Date death(day, month, year);
			artist = new Artist(name, birth, death);
		}
		else
			artist = new Artist(name, birth, Date(0, 0, 0));
		Add_Artist(artist);
		return artist;
	}
}

Museum::~Museum()
{
	for (int i = 0; i < a; i++)
		delete[]artists[i];
	delete[]artists;
	delete[]creations;
	cout << "Destructive function completed successfully " << endl;
}