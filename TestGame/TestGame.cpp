#include <SFML/Graphics.hpp>
#include "../Moren-Framework/Kernel.hpp"
#include <iostream>

int main()
try
{
	mn::Game.Create(mn::VideoMode(400, 400, 32), "TestGame");

	while ( mn::Game.IsOpened() )
	{
		mn::Event EventPacket;
		while ( mn::Game.GetEvent(EventPacket) )
		{
			if (EventPacket.Type == mn::Event::Closed)
				mn::Game.Close();
		}

		mn::Game.Clear();

		mn::Game.Display();
	}

	return EXIT_SUCCESS;
}
catch(...)
{
	std::cerr << "Exception occured! ";
}