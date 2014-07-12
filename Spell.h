#ifndef SPELL_H
#define SPELL_H


#include <iostream>
#include <string>

using namespace std;


struct SpellCast
{
	int SpellID;
	float CastTime;
	
	bool operator< (const SpellCast other)
	{
		return CastTime > other.CastTime;
	}
	
	
};

struct MinHeapCompare
{
	bool operator() ( SpellCast a, SpellCast b)
	{
        return a > b;
	}
};

class Spell
{

public:

	Spell();
	
	Spell(int uniqueID, string Name, float Damage, float CastTime);
	
private:
	
	int id;
	
	string name;
	
	float damage;
	
	float castTime;

};

#endif