#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "picture.h"

using namespace std;

Picture::Picture(char* name, int year, char* genere, float height, Artist* artist, float length):Creation(name,year,genere,height,artist)
{
	this->length = length;
}

void Picture::print()const
{
	Creation::print();
	cout << "Length: " << this->length << endl;
}

Picture::~Picture() {}
