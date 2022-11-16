#include "statue.h"
#include "creation.h"

using namespace std;

Statue::Statue(char* name, int year, char* genere, float height, Artist* artist, float area, float weight) :Creation(name, year, genere, height, artist)
{
	this->area = area;
	this->weight = weight;
}

void Statue::print()const
{
	Creation::print();
	cout << "Area:" << area << endl << "Weight: " << weight << endl;
}

Statue::~Statue() {}