#pragma once
#include "creation.h"
#include "artist.h"

class Museum
{
private:
	int a;
	int c;
	Creation** creations;
	Artist** artists;
public:
	Museum();
	bool Add_Artist(Artist*);
	bool Add_Creation(Creation* create);
	bool Remove_Creation(int index);
	void Print_Artists_Creations(Artist** artists);
	void Print_Creations();
	void Print_Pictures();
	void Print_Statues();
	void Print_Creations_Of_Artist(const Artist& a);
	void Print_Creations_Of_Genere(char* genere);
	void Print_Artists_Pictures();
	void Print_Artists_Statues();
	void Print_Statues_By_Weight(float weight);
	void menu();
	int ArtistExist(char* name);
	Artist* get_artist();
	~Museum();
};