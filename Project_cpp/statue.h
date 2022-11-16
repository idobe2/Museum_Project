#pragma once
#include "creation.h"

class Statue : virtual public Creation
{
private:
	float area;
	float weight;
public:
	Statue(char* name, int year, char* genere, float height, Artist* artist, float area, float weight);
	virtual const char* get_type() { return "s"; }
	float get_weight() { return weight; }
	virtual void print()const;
	~Statue();
};