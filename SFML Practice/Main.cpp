#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


int main()
{

    //--------------------------------------------------
    //SetUp
    //--------------------------------------------------
#pragma region SetUp
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pick up Sticks", sf::Style::None);

    //Load Textures
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Assets/Player_Stand.png"))
        //Checks if texture has loaded successfully
    {
        //error
        std::cout << "Texture load failed for Assets/Player_Stand.png" << std::endl;
    }

    else
    {
        //error
        std::cout << "Texture load successful for Assets/Player_Stand.png" << std::endl;
    }
    //Load Textures
    sf::Texture grassTexture;
    if (!grassTexture.loadFromFile("Assets/Grass.png"))
        //Checks if texture has loaded successfully
    {
        //error
        std::cout << "Texture load failed for Assets/Grass.png" << std::endl;
    }

    else
    {
        //error
        std::cout << "Texture load successful for Assets/Grass.png" << std::endl;
    }

    //Sets textures to Sprites
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);

    sf::Sprite grassSprite;
    grassSprite.setTexture(grassTexture);

    std::vector<sf::Sprite> grassSprites;
    int numGrassSpritesToAdd = 5;
    for (int i = 0; i < numGrassSpritesToAdd; ++i)
    {
        grassSprites.push_back(grassSprite);
    }


    //Position Setup
    playerSprite.setPosition(sf::Vector2f(5.0f, 100.0f));
#pragma endregion


    //Allows user to close window using escape key
    while (window.isOpen())
    {

        //---------------------------------------------
        //PollEvent
        //---------------------------------------------
#pragma region PollEvent

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {


                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
#pragma endregion
        //---------------------------------------------
        //Drawing 
        //---------------------------------------------
#pragma region Drawing
        window.clear(sf::Color(64, 204, 90));


        //Draw all the things
        
        for (int i = 0; i < grassSprites.size(); i++)
            window.draw(grassSprites[i]);

        window.draw(playerSprite);
        window.display();
    }
#pragma endregion


    

    return 0;
}