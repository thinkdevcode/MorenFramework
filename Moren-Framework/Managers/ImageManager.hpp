////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_IMAGEMANAGER_HPP
#define MOREN_IMAGEMANAGER_HPP

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include "../Kernel.hpp"

namespace mn
{

////////////////////////////////////////////////////////////
/// ImageManager is the image manager: adding, getting, etc
///
////////////////////////////////////////////////////////////
class ImageManager
{
public:

	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	////////////////////////////////////////////////////////////
	ImageManager();

	////////////////////////////////////////////////////////////
	/// Get reference to image in memory. If it does not exist
	/// then load from file
	///
	/// \param The file name and directory for image
	///
	/// \return reference to Image
	///
	////////////////////////////////////////////////////////////
	static Image& Ret(StdString& FileName);

	////////////////////////////////////////////////////////////
	/// Get the size of the Map
	///
	/// \return size of ImageMap
	///
	////////////////////////////////////////////////////////////
	Uint32 GetSize();

private:

	////////////////////////////////////////////////////////////
	// Member data
	//
	////////////////////////////////////////////////////////////
	static ImageMap myImages;
};

namespace
{
	ImageManager Images;	///< Global static image manager class
}

} // namespace Moren

#endif // MOREN_IMAGEMANAGER_HPP
