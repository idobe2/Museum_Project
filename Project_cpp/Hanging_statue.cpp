#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "hanging_statue .h"
#include "creation.h"
#include "statue.h"
#include "picture.h"

using namespace std;

Hanging_statue::Hanging_statue(char* name, int year, char* genere, float height, Artist* artist, float length, float area, float weight, int screw_qty) : Creation(name, year, genere, height, artist),Picture(name, year, genere, height, artist, length), Statue(name, year, genere, height, artist, area, weight)
{
	this->screw_qty = screw_qty;
}

void Hanging_statue::print()const
{
	Statue::print();
	cout << "Number of screws : " << this->screw_qty << endl;
}

Hanging_statue::~Hanging_statue() {}