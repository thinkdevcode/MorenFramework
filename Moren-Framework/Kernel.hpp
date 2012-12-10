////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_KERNEL_HPP
#define MOREN_KERNEL_HPP

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <list>
#include <map>
#include "WinMainData.hpp"

namespace mn
{

////////////////////////////////////////////////////////////
// Forward Declarations
//
////////////////////////////////////////////////////////////
class Object;
class GameState;

////////////////////////////////////////////////////////////
// SFML types
//
////////////////////////////////////////////////////////////
typedef sf::Vector2f		Vector2f;			///< 2D vector of floats
typedef sf::Vector2i		Vector2i;			///< 2D vector of ints
typedef sf::Vector3f		Vector3f;			///< 3D vector of floats
typedef sf::Vector3i		Vector3i;			///< 3D vector of ints
typedef sf::Uint32			Uint32;				///< Unsigned int (32bit)
typedef sf::Uint16			Uint16;				///< Unsigned short
typedef sf::Uint8			Uint8;				///< Unsigned char
typedef sf::Int32			Int32;				///< Signed int (32bit)
typedef sf::Int16			Int16;				///< Signed short
typedef sf::Int8			Int8;				///< Signed char
typedef sf::String			SfString;			///< SFML String class
typedef sf::RenderWindow	RenderWindow;		///< SFML RenderWindow class
typedef sf::RenderTarget	RenderTarget;		///< SFML RenderTarget class
typedef sf::Renderer		Renderer;			///< SFML Renderer class
typedef sf::Event			Event;				///< SFML Event class
typedef sf::Image			Image;				///< SFML Image class
typedef sf::VideoMode		VideoMode;			///< SFML VideoMode class
typedef sf::View			View;				///< SFML View class
typedef sf::Color			Color;				///< SFML Color class
typedef sf::Sprite			Sprite;				///< SFML Sprite class
typedef sf::Shape			Shape;				///< SFML Shape class
typedef sf::Font			Font;				///< SFML Font class
typedef sf::Drawable		Drawable;			///< SFML Drawable class

////////////////////////////////////////////////////////////
// SFML namespace redeclarations
//
////////////////////////////////////////////////////////////
namespace Style = sf::Style;
namespace Mouse = sf::Mouse;
namespace Blend = sf::Blend;
namespace Joy   = sf::Joy;
namespace Key   = sf::Key;
namespace Style = sf::Style;

////////////////////////////////////////////////////////////
// Global static variables
//
////////////////////////////////////////////////////////////
namespace
{
	RenderWindow	Game;
}

////////////////////////////////////////////////////////////
// STL types
//
////////////////////////////////////////////////////////////
typedef std::string			StdString;			///< STL String class

////////////////////////////////////////////////////////////
// STL custom containers
//
////////////////////////////////////////////////////////////
// maps
typedef std::map<StdString, Image>		ImageMap;		///< Map of StdString and Image
typedef std::map<Uint32, Object *>		ObjectMap;		///< Map of Uint32 and Object ptr
typedef std::map<StdString, GameState*>	StateMap;		///< Map of StdString and GameState

////////////////////////////////////////////////////////////
// Custom Moren structs
//
////////////////////////////////////////////////////////////
typedef WinMainData			WindowParam;		///< WinMainData stuct

////////////////////////////////////////////////////////////
// etc. typedefs
//
////////////////////////////////////////////////////////////
typedef float				Float;

namespace
{
	////////////////////////////////////////////////////////////
	// Returns mouse coords in view coordinates (default view)
	//
	////////////////////////////////////////////////////////////
	Vector2f GetMouseViewCoords() { return Game.ConvertCoords(Game.GetInput().GetMouseX(), Game.GetInput().GetMouseY()); }
}

} // namespace Moren

#endif // MOREN_KERNEL_HPP