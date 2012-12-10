////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include "StateManager.hpp"

namespace mn
{

////////////////////////////////////////////////////////////
// Initialize static members of Moren::StateManager
//
////////////////////////////////////////////////////////////
StateMap	StateManager::GameStates;
GameState*	StateManager::CurrentState = NULL;

////////////////////////////////////////////////////////////
// Default constructor
//
////////////////////////////////////////////////////////////
StateManager::StateManager()
{ }

////////////////////////////////////////////////////////////
// Add a game state to the state manager
//
////////////////////////////////////////////////////////////
void StateManager::Add(GameState *State, StdString StateName, bool Switch, bool Pause)
{
	// set the switch function in custom state
	State->SetSwitchFunc( &States.Switch );

	// check if state is already in map
	if ( GameStates.find(StateName) == GameStates.end() )
		GameStates[StateName] = State;

	// if need to switch states is true
	if ( Switch )
	{
		// make sure current state isnt null
		if ( CurrentState != NULL )
		{
			// if pause needed
			if ( Pause )
				CurrentState->Pause();
			// else stop the state
			else
				CurrentState->Stop();
		}
		// change current state
		CurrentState = GameStates[StateName];
	}
}

////////////////////////////////////////////////////////////
// Delete a game state from the state manager
//
////////////////////////////////////////////////////////////
void StateManager::Del(StdString StateName, bool Switch, StdString SwitchTo, bool Pause)
{
	// find if state exists with key
	StateMap::iterator MapIt = GameStates.find(StateName);
	// if exists
	if ( MapIt != GameStates.end() )
	{
		//delete and erase
		delete MapIt->second;
		GameStates.erase(MapIt);
	}
	// if need to switch states is true
	if ( Switch )
	{
		// verify switch to state is there
		if ( GameStates.find(SwitchTo) != GameStates.end())
		{
			// make sure current state isnt null
			if ( CurrentState != NULL )
			{
				// if pause needed
				if ( Pause )
					CurrentState->Pause();
				// else stop the state
				else
					CurrentState->Stop();
			}
			// change current state
			CurrentState = GameStates.find(SwitchTo)->second;
		}
	}
}

////////////////////////////////////////////////////////////
// Switch the current state
//
////////////////////////////////////////////////////////////
void StateManager::Switch(StdString StateName, bool Pause)
{
	// verify switch to state is there
	if ( GameStates.find(StateName) != GameStates.end() )
	{
		// if pause needed
		if ( Pause )
			CurrentState->Pause();
		// else stop the state
		else
			CurrentState->Stop();
		// change the current state
		CurrentState = GameStates[StateName];
	}
	else
	{
		//return error
	}
}

////////////////////////////////////////////////////////////
// Dispatch an event packet to current state
//
////////////////////////////////////////////////////////////
void StateManager::DispatchEvent(Event& EventPacket)
{
	CurrentState->ProcessEvent(EventPacket);
}

////////////////////////////////////////////////////////////
// Delete all pointers of states and clear map
//
////////////////////////////////////////////////////////////
void StateManager::Clear()
{
	for (StateMap::iterator MapIt = GameStates.begin(); MapIt != GameStates.end(); ++MapIt)
		delete MapIt->second;
	GameStates.clear();
	
}

////////////////////////////////////////////////////////////
// /see Drawable::Render
//
////////////////////////////////////////////////////////////
void StateManager::Render(RenderTarget& target, Renderer& renderer) const
{
	CurrentState->Render(target, renderer);
}

} // namespace Moren