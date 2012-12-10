////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_STATEMANAGER_HPP
#define MOREN_STATEMANAGER_HPP

#include "../Base/GameState.hpp"

namespace mn
{

////////////////////////////////////////////////////////////
/// StateManager is the state manager: adding, deleting, changing,
///	etc.
////////////////////////////////////////////////////////////
class StateManager : public Drawable
{
public:

	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	StateManager();

	////////////////////////////////////////////////////////////
	/// Add a game state to the state manager
	///
	/// \param State :     A pointer to the State
	/// \param StateName : The name of the State
	/// \param SwitchTo :  Should manager switch to new state
	/// \param Pause :     Pause() current state when switched,
	///					   if false Stop() is used instead
	///
	////////////////////////////////////////////////////////////
	static void Add(GameState* State, StdString StateName, bool Switch = true, bool Pause = false);

	////////////////////////////////////////////////////////////
	/// Delete a game state from the state manager
	///
	/// \param StateName : The name of the State to delete
	/// \param Switch :    Should manager switch to new state
	/// \param SwitchTo :  Name of state to switch to
	/// \param Pause :     Pause() current state when switched,
	///					   if false Stop() is used instead
	///
	////////////////////////////////////////////////////////////
	static void Del(StdString StateName, bool Switch, StdString SwitchTo, bool Pause = false);

	////////////////////////////////////////////////////////////
	/// Switch the current state
	///
	/// \param StateName : The name of state to switch to
	/// \param Pause :     Pause() current state when switched,
	///					   if false Stop() is used instead
	///
	////////////////////////////////////////////////////////////
	static void Switch(StdString StateName, bool Pause = false);

	////////////////////////////////////////////////////////////
	/// Dispatch an event packet to current state
	///
	/// \param EventPacket : An event packet
	///
	////////////////////////////////////////////////////////////
	static void DispatchEvent(Event& EventPacket);

	////////////////////////////////////////////////////////////
	/// Delete all pointers of states and clear map
	///
	////////////////////////////////////////////////////////////
	static void Clear();

private:

	////////////////////////////////////////////////////////////
	/// /see Drawable::Render
	///
	////////////////////////////////////////////////////////////
	void Render(RenderTarget& target, Renderer& renderer) const;

	////////////////////////////////////////////////////////////
	// Member data
	//
	////////////////////////////////////////////////////////////
	static StateMap		GameStates;		///< Map of states
	static GameState*	CurrentState;	///< Pointer to current state
};

namespace
{
	StateManager States;	///< Global static state manager class
}

} // namespace Moren

#endif // MOREN_STATEMANAGER_HPP