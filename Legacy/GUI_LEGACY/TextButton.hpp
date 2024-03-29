////////////////////////////////////////////////////////////
//
// Moren - 2D RPG Framework
// Copyright (C) 2009 Eugene Alfonso (gin@gtproductions.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
////////////////////////////////////////////////////////////

#ifndef MOREN_TEXTBUTTON_HPP
#define MOREN_TEXTBUTTON_HPP

////////////////////////////////////////////////////////////
// Headers
//
////////////////////////////////////////////////////////////
#include "../Base/GUIObject.hpp"

namespace Moren
{

////////////////////////////////////////////////////////////
/// A TextButton is a typical text button
///
////////////////////////////////////////////////////////////
class TextButton : public GUIObject
{
public:

	////////////////////////////////////////////////////////////
	/// Default constructor
	///
	/// \param Coords :       Starting coords of TextButton (top left)
	/// \param Size :         x = Width, y = Height
	/// \param Text :         The text to be displayed
	/// \param TextFont :     The font type for text
	///	\param TextColor :    The color of the text
	/// \param BgColor :      The background color of button
	/// \param Outline :      How large of an outline (in pixels)
	/// \param OutlineColor : The color of the outline
	///
	////////////////////////////////////////////////////////////
	TextButton( Vector2f Coords, Vector2f Size, StdString Text, const Font& FontType = Font::GetDefaultFont(), Float FontSize = 30.000000, Color FontColor = Color(255,255,255), Color BgColor = Color(120, 120, 120), float Outline = 1.000000, Color OutlineColor = Color(255, 255, 255) );

	////////////////////////////////////////////////////////////
	/// /see GUIObject::Update
	///
	////////////////////////////////////////////////////////////
	void Update();

	////////////////////////////////////////////////////////////
	/// /see GUIObject::ProcessEvent
	///
	////////////////////////////////////////////////////////////
	void ProcessEvent(Event& EventPacket);

	////////////////////////////////////////////////////////////
	/// /see Drawable::Render
	///
	////////////////////////////////////////////////////////////
	void Render(RenderTarget& Target, RenderQueue& queue);

	////////////////////////////////////////////////////////////
	// GUI Events
	//
	////////////////////////////////////////////////////////////
	virtual void OnRightClick() =0;
	virtual void OnLeftClick() =0;
	virtual void OnMouseOver() =0;
	virtual void OnMouseOff() =0;

	////////////////////////////////////////////////////////////
	/// Overloaded '=' operator, needed for error
	///
	////////////////////////////////////////////////////////////
	TextButton& operator=(const TextButton& U);

private:

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	SfString	myButtonText;	///< The text of the button
	Shape		myButtonBox;	///< The button

};

} // namespace Moren

#endif // MOREN_TEXTBUTTON_HPP