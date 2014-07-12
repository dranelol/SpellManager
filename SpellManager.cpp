#include <map>
#include <queue>
// include a time library here that gives us access to the current time since start of program

#include "Spell.h"
#include "Player.h"

using namespace std;

int main()
{
	// maps spell ID to spell object
   map<int, Spell> SpellMap;
   
   // maps player ID to player object
   map<int, Player> PlayerMap;
   
   // maps spell ID to player ID
   map<int, int> SpellPlayerMap;
   
   // minheap containing every instance of a spell cast, sorted by the time each spell should be resolved
   priority_queue<SpellCast, vector<SpellCast>, MinHeapCompare> *SpellCastHeap = new priority_queue<SpellCast, vector<SpellCast>, MinHeapCompare>();
   
   // init players, add them to player map
   int playerCounter = 0;
   
   
   PlayerMap.insert( pair<int, Player> (playerCounter++, Player(SpellCastHeap)));
   cout << playerCounter << endl;
   PlayerMap.insert( pair<int, Player> (playerCounter++, Player(SpellCastHeap)));
   PlayerMap.insert( pair<int, Player> (playerCounter++, Player(SpellCastHeap)));
   PlayerMap.insert( pair<int, Player> (playerCounter++, Player(SpellCastHeap)));
   PlayerMap.insert( pair<int, Player> (playerCounter++, Player(SpellCastHeap)));
   
   // init spells, add them to players' spellbooks, add spell to spell map
   
   int spellCounter = 0;
   
   Spell Fireball(spellCounter, "Fireball", 5.0, 5.0);
   
   SpellMap.insert( pair<int, Spell> (spellCounter, Fireball));
   
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 0));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 1));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 2));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 3));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 4));
   
   spellCounter++;
   
   Spell Icebolt(spellCounter, "Icebolt", 5.0, 5.0);
   
   SpellMap.insert( pair<int, Spell> (spellCounter, Icebolt));
   
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 0));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 1));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 2));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 3));
   SpellPlayerMap.insert( pair<int, int> (spellCounter, 4));
   
   for(map<int, Player>::iterator itr = PlayerMap.begin(); itr != PlayerMap.end(); ++itr)
   {
		itr->second.AddSpell(Fireball);
		itr->second.AddSpell(Icebolt);
   }
   
   while(true)
   {
		// iterate through player mapping, calling update on all players
		
		for(map<int, Player>::iterator itr = PlayerMap.begin(); itr != PlayerMap.end(); ++itr)
		{
			itr->second.Update();
		}
   
		// logic to check whether or not a spell should be resolved
   
		// if the spell heap has a spell waiting
		if(SpellCastHeap->empty() == false)
		{
			// if the smallest cast time is less than the current time
			if(SpellCastHeap.top().CastTime <= TimeLib.TimeSinceStart())
			{
				// find the player ID that owns this spell
				int playerID = SpellPlayerMap[SpellCastHeap->top().SpellID];
				
				// get the player object associated with this id
				Player checkPlayer = PlayerMap[playerID];
				
				// if this player is not dead, cast spell!
				if(checkPlayer.IsDead() == false)
				{
					/* do damage, resolve spell effects */
					
					// remove spell
					SpellCastHeap->pop();
				}
				
				// if the player's dead, remove spell
				else
				{
					SpellCastHeap->pop();
				}
			}
			
		}
   }
   
   
   return 0;
	   
}
