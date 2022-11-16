#pragma once
#include "creation.h"

class Picture : virtual public Creation
{
private:
	float length;
public:
	Picture(char* name, int year, char* genere, float height, Artist* artist, float length);
	virtual void print()const;
	virtual const char* get_type() { return "p"; }
	~Picture();
};