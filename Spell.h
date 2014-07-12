#ifndef SPELL_H
#define SPELL_H


#include <iostream>
#include <string>

using namespace std;

// contains information about each spell that has been cast
struct SpellCast
{
	// id of the spell that was cast
	int SpellID;
	
	// how long the spell will take to resolve
	float CastTime;
	
	bool operator< (const SpellCast other)
	{
		return CastTime < other.CastTime;
	}
	
	
};

// used in comparing two SpellCast objects; provides a reverse comparison to allow a priority queue to be used as a minheap
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
	// unique ID of the spell
	int id;
	
	// name of the spell
	string name;
	
	// how much damage the spell does
	float damage;
	
	// how long it takes for the spell to cast
	float castTime;

};

#endif