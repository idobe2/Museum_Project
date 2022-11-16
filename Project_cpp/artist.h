#pragma once
#include "Date.h"

class Creation;

class Artist
{
private:
	char* name;
	Date birth;
	Date death;
	int creations;
	Creation** Creations;
public:
	Artist();
	Artist(char* name, Date birth, Date death);
	bool Add_Creation(Creation*);
	friend ostream& operator << (ostream& out, const Artist& a);
	int get_creations() { return creations; }
	char* get_name() { return name; }
	virtual void print()const;
	bool PictureExist();
	bool StatueExist();
	virtual const char* get_type() { return "a"; }
	void Remove(char* name);
	virtual ~Artist();
};