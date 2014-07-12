#ifndef PLAYER_H
#define PLAYER_H


#include <iostream>
#include <vector>
#include <queue>

// include a time library here that gives us access to the current time since start of program
//#include <TimeLib>

#include "Spell.h"

using namespace std;


class Player
{

public:

	Player();
	
	Player( priority_queue< SpellCast, vector< SpellCast >, MinHeapCompare > *SpellCastHeap );
	
	void Update();
	
	void AddSpell(int uniqueID, string Name, float Damage, float CastTime);
	
	void CastSpell(int index);
	
	bool IsDead();
	
	
private:
	
	int hp;
	
	float castCooldown;
	
	vector<Spell> spellList;
	
	priority_queue<SpellCast, vector<SpellCast>, MinHeapCompare> *spellCastHeap;

};

#endif