////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_GUI_HPP
#define MOREN_GUI_HPP

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include "../Base/GUIObject.hpp"

namespace Moren
{

////////////////////////////////////////////////////////////
/// GUI defines the container class for all GUI objects
///
////////////////////////////////////////////////////////////
class GUI : public Drawable
{
public:

	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	GUI();

	////////////////////////////////////////////////////////////
	/// Destructor : Calls Clear()
	///
	////////////////////////////////////////////////////////////
	~GUI();

	////////////////////////////////////////////////////////////
	/// Overloaded "+=" Operator : Add a GUI Object to the list
	///
	////////////////////////////////////////////////////////////
	GUI& operator+=(GUIObject* object);

	////////////////////////////////////////////////////////////
	/// Add a GUI object to the list
	///
	/// \param object : The GUI object to add
	///
	////////////////////////////////////////////////////////////
	void Add(GUIObject* object);

	////////////////////////////////////////////////////////////
	/// Dispatch an event packet to all GUI objects
	///
	/// \param EventPacket : An event packet
	///
	////////////////////////////////////////////////////////////
	void DispatchEvent(Event& EventPacket);

	////////////////////////////////////////////////////////////
	/// Delete all pointers of objects and clear list
	///
	////////////////////////////////////////////////////////////
	void Clear();

private:

	////////////////////////////////////////////////////////////
	/// /see Drawable::Render
	///
	////////////////////////////////////////////////////////////
	virtual void Render(RenderTarget& Target, RenderQueue& queue) const;

	////////////////////////////////////////////////////////////
	// Member data
	//
	////////////////////////////////////////////////////////////
	GUIObjectList	myGUI;		///< List of GUI Objects
};

} // namespace Moren

#endif // MOREN_GUI_HPP