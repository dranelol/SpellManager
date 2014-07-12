#include "Spell.h"

using namespace std;

Spell::Spell(int uniqueID, string Name, float Damage, float CastTime)
{
	id = uniqueID;
	
	name = Name;
	
	damage = Damage;
	
	castTime = CastTime;
}