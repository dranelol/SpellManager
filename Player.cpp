#include "Player.h"

using namespace std;

Player::Player()
{
	hp = 10;
	
	castCooldown = 0.0;
}

Player::Player(priority_queue<SpellCast, vector<SpellCast>, MinHeapCompare> *SpellCastHeap)
{

	spellCastHeap = SpellCastHeap;

	hp = 10;
	
	castCooldown = 0.0;
}


void Player::Update()
{
	// try to cast a spell if some condition has been met: input, automatically, etc; choose index based on some other logic
	
	/* logic to check condition; whether or not a spell should be cast */
	
	bool condition = true;
	
	
	
	if(condition == true)
	{
		/* logic to choose spell */
	
		int spellID = 0;
	
		if(castCooldown <= TimeLib.TimeSinceStart())
		{
		
			// add this spell to the spellcast heap
			
			// create a spellcast object
			SpellCast newCast;
			newCast.SpellID = spellID;
			newCast.CastTime = spellList[spellID].castTime + TimeLib.TimeSinceStart();
			
			// push it onto the spellcast heap
			spellCastHeap->push(newCast);
			
			// update to new cast cooldown
			castCooldown = newCast.CastTime;
	
		}
		
	}
}

void Player::AddSpell(newSpell)
{
	spellList.push_back(newSpell);
}
	
bool Player::IsDead()
{
	return (hp <= 0);
}