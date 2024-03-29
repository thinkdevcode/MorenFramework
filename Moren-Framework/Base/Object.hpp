////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_OBJECT_HPP
#define MOREN_OBJECT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../Kernel.hpp"

namespace mn
{

////////////////////////////////////////////////////////////
/// Object defines a game object : Takes care of memory
/// management and provides methods to clear garbage
/// automatically. Do not initialize directly, only through
/// a derived class.
///
////////////////////////////////////////////////////////////
class Object : public Drawable
{
public:

	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	Object();

	////////////////////////////////////////////////////////////
	/// Get the Unique Id of the Object
	///
	/// \return Unique Id
	///
	////////////////////////////////////////////////////////////
	const Uint32 GetId() const;

	////////////////////////////////////////////////////////////
	/// [inline] Increment number of references in memory
	///
	////////////////////////////////////////////////////////////
	inline void AddRef();

	////////////////////////////////////////////////////////////
	/// [inline] Decrement number of references in memory,
	/// if less than or equal to 0, add object to Dead map
	///
	////////////////////////////////////////////////////////////
	inline void DelRef();

	////////////////////////////////////////////////////////////
	/// [static] Delete all dead objects in memory
	///
	////////////////////////////////////////////////////////////
	static void CollectGarbage();

	////////////////////////////////////////////////////////////
	/// [static] Delete all objects in memory
	///
	////////////////////////////////////////////////////////////
	static void CollectAllObjects();

private:

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
			Uint32		myUniqueId;		///< Current objects Id
			Int32		myRefCount;		///< Number of references in memory
	static	Uint32		StaticId;		///< Static incremented Id
	static	ObjectMap	LiveObjects;	///< Static Map of current Live Objects
	static	ObjectMap	DeadObjects;	///< Static Map of dead objects (to be cleaned)
};

////////////////////////////////////////////////////////////
// Increment number of references in memory
//
////////////////////////////////////////////////////////////
void Object::AddRef()
{
	++myRefCount;
}

////////////////////////////////////////////////////////////
// Decrement number of references in memory,
// if less than or equal to 0, add object to Dead map
//
////////////////////////////////////////////////////////////
void Object::DelRef()
{ 
	--myRefCount;
   if(myRefCount <= 0)
   {
	   // Move object to Dead object map
	   // Remove object from Live object map
	   DeadObjects[myUniqueId] = LiveObjects[myUniqueId];
	   LiveObjects.erase(myUniqueId);
   }
}

} // namespace Moren

#endif // MOREN_OBJECT_HPP