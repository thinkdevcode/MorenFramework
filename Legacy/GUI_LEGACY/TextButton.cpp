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
#include "TextButton.hpp"

namespace Moren
{

////////////////////////////////////////////////////////////
// Default constructor
//
////////////////////////////////////////////////////////////
TextButton::TextButton(Vector2f Coords, Vector2f Size, StdString Text, const Font& FontType, Float FontSize, Color FontColor, Color BgColor, float Outline, Color OutlineColor)
: myButtonText(Text, FontType, FontSize)
{
	/*
	if ( (float)myButtonText.GetRect().GetWidth() > Size.x || myButtonText.GetRect().GetHeight() > Size.y )
		myButtonBox = Shape::Rectangle( Coords.x, Coords.y, myButtonText.GetRect().GetWidth() + Coords.x, myButtonText.GetRect().GetHeight() + Coords.y, BgColor, Outline, OutlineColor );
	else
		myButtonBox = Shape::Rectangle( Coords.x, Coords.y, Size.x + Coords.x, Size.y + Coords.y, BgColor, Outline, OutlineColor );

	myButtonText.SetColor(FontColor);

	myButtonText.SetPosition(Vector2f( ( Coords.x + ( Size.x / 2.f ) ) - ( myButtonText.GetRect().GetWidth() / 2.f ), 
									   ( Coords.y + ( Size.y / 2.f ) ) - ( myButtonText.GetRect().GetHeight() / 1.7f ) ) );
	*/
}

////////////////////////////////////////////////////////////
// /see GUIObject::Update
//
////////////////////////////////////////////////////////////
void TextButton::Update()
{

}

////////////////////////////////////////////////////////////
// /see GUIObject::ProcessEvent
//
////////////////////////////////////////////////////////////
void TextButton::ProcessEvent(Event& EventPacket)
{
	if (EventPacket.Type == Event::Closed)
	{
		//do
	}
}

////////////////////////////////////////////////////////////
// /see Drawable::Render
//
////////////////////////////////////////////////////////////
void TextButton::Render(RenderTarget& Target, RenderQueue& queue)
{
	Target.Draw(myButtonBox);
	Target.Draw(myButtonText);
}

} // namespace Moren