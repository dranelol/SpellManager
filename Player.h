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
	
	// updates this player
	void Update();
	
	// adds a spell to this player's spellbook
	void AddSpell(int uniqueID, string Name, float Damage, float CastTime);
	
	// returns whether or not this player is dead
	bool IsDead();
	
	
private:
	
	// hp of the player
	int hp;
	
	// current spell cast cooldown of the player
	float castCooldown;
	
	// player's spellbook
	vector<Spell> spellList;
	
	// reference to the minheap of spellcast objects
	priority_queue<SpellCast, vector<SpellCast>, MinHeapCompare> *spellCastHeap;

};

#endif