#include "artist.h"
#pragma once
 
class Creation
{
private:
	char* name;
	int year;
	char* genere;
	float height;
	Artist* artist;
public:
	Creation();
	Creation(char *name, int year, char* genere, float height, Artist* artist);
	char* get_name() { return name; }
	char* get_genere() { return genere; }
	Artist* get_artist() { return artist; }
	virtual void print()const;
	virtual const char* get_type() { return "c"; }
	virtual ~Creation();
};