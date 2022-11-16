#pragma once
#include "picture.h"
#include "statue.h"
#include "creation.h"

class Hanging_statue : public Statue, public Picture
{
private:
	int screw_qty;
public:
	Hanging_statue(char* name, int year, char* genere, float height, Artist* artist, float length, float area, float weight, int screw_qty);
	virtual const char* get_type() { return "h"; }
	virtual void print()const;
	~Hanging_statue();
};
