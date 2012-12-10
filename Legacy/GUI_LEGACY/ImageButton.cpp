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
#include "ImageButton.hpp"

namespace Moren
{

////////////////////////////////////////////////////////////
// Default constructor
//
////////////////////////////////////////////////////////////
ImageButton::ImageButton(Vector2f Coords, Image& Image)
: myImage(Image), mySprite(Image), myMouseStatusNew(false), myMouseStatusOld(false)
{
	mySprite.SetOrigin( (float)Image.GetWidth() / 2, (float)Image.GetHeight() / 2);
	mySprite.SetPosition(Coords);
}

////////////////////////////////////////////////////////////
// /see GUIObject::Update
//
////////////////////////////////////////////////////////////
void ImageButton::Update()
{
	if (myMouseStatusNew != myMouseStatusOld)
	{
		if (myMouseStatusNew)
			OnMouseOver();
		else
			OnMouseOff();
	}
}

////////////////////////////////////////////////////////////
// /see GUIObject::ProcessEvent
//
////////////////////////////////////////////////////////////
void ImageButton::ProcessEvent(Event& EventPacket)
{
	if ( Inside() )
		myMouseStatusNew = true;
	else
		myMouseStatusNew = false;

	if ( EventPacket.Type == Event::MouseButtonReleased && EventPacket.MouseButton.Button == Mouse::Left )
		if ( Inside() )
			OnLeftClick();

	if ( EventPacket.Type == Event::MouseButtonReleased && EventPacket.MouseButton.Button == Mouse::Right )
		if ( Inside() )
			OnRightClick();
}

////////////////////////////////////////////////////////////
// /see Drawable::Render
//
////////////////////////////////////////////////////////////
void ImageButton::Render(RenderTarget& Target, RenderQueue& queue)
{
	Target.Draw(mySprite);
}

bool ImageButton::Inside()
{
	Vector2f Mouse = GetMouseViewCoords();
	Vector2f Begin( mySprite.GetPosition().x - myImage.GetWidth() / 2, mySprite.GetPosition().y - myImage.GetHeight() / 2 );
	Vector2f End( mySprite.GetPosition().x + myImage.GetWidth() / 2, mySprite.GetPosition().y + myImage.GetHeight() / 2 );
	float MinX = std::min(Begin.x, End.x);
	float MaxX = std::max(Begin.x, End.x);
	float MinY = std::min(Begin.y, End.y);
	float MaxY = std::max(Begin.y, End.y);

	if (Mouse.x < MinX || Mouse.x > MaxX ||
		Mouse.y < MinY || Mouse.y > MaxY)
		return false;
	else
		return true;
}

} // namespace Moren