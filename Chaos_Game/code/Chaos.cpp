#include <iostream>
#include<vector>
#include<SFML/Graphics.hpp>



int main()
{

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chaos Game");
	sf::Font font;
	font.loadFromFile("fonts/KOMIKAP_.ttf");
	
	sf::Text text;
	text.setFont(font);
	text.setString("Click three points on the screen and pick a 4th point to get started");
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(25);

	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(5, 5));
	shape.setFillColor(sf::Color::White);


	sf::Vector2i a, b, c, z, position, lastPos;

	int count = 0;
	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		window.draw(text);

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				position = sf::Mouse::getPosition(window);
				shape.setPosition(position.x, position.y);
				if (count == 0)
				{
					a.x = position.x;
					a.y = position.y;
					shape.setFillColor(sf::Color::Red);
					window.draw(shape);
					window.display();
				}
				if (count == 1)
				{
					b.x = position.x;
					b.y = position.y;
					shape.setFillColor(sf::Color::Red);
					window.draw(shape);
					window.display();

				}
				if (count == 2)
				{
					c.x = position.x;
					c.y = position.y;
					shape.setFillColor(sf::Color::Red);
					window.draw(shape);
					window.display();
				}
				if (count == 3)
				{
					lastPos.x = position.x;
					lastPos.y = position.y;
					shape.setFillColor(sf::Color::Green);
					window.draw(shape);
					window.display();
				}
				count++;
				break;

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		if (count > 3)
		{
			shape.setFillColor(sf::Color::White);
			for (size_t i = 0; i < 1000; i++)
			{
				int genRand = rand() % 3;
				if (genRand == 0)
				{
					z.x = (lastPos.x + a.x) / 2;
					z.y = (lastPos.y + a.y) / 2;
					lastPos.x = z.x;
					lastPos.y = z.y;
				}
				if (genRand == 1)
				{
					z.x = (lastPos.x + b.x) / 2;
					z.y = (lastPos.y + b.y) / 2;
					lastPos.x = z.x;
					lastPos.y = z.y;
				}
				if (genRand == 2)
				{
					z.x = (lastPos.x + c.x) / 2;
					z.y = (lastPos.y + c.y) / 2;
					lastPos.x = z.x;
					lastPos.y = z.y;
				}
				shape.setPosition(z.x, z.y);
				window.draw(shape);
				window.display();
			}
		}


		window.display();




	}
	return 0;
}
