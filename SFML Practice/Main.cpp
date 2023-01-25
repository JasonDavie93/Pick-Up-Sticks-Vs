#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cmath>



int main()
{

    //--------------------------------------------------
    //SetUp
    //--------------------------------------------------
#pragma region SetUp
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Pick up Sticks", sf::Style::None);
    
    srand(time(NULL));

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

    //Load Textures
    sf::Texture stickTexture;
    if (!stickTexture.loadFromFile("Assets/Stick.png"))
        //Checks if texture has loaded successfully
    {
        //error
        std::cout << "Texture load failed for Assets/Stick.png" << std::endl;
    }

    else
    {
        //error
        std::cout << "Texture load successful for Assets/Stick.png" << std::endl;
    }

    //Sets textures to Sprites
    sf::Sprite playerSprite;
    playerSprite.setTexture(playerTexture);

    sf::Sprite grassSprite;
    grassSprite.setTexture(grassTexture);

    sf::Sprite stickSprite;
    stickSprite.setTexture(stickTexture);


    
    std::vector<sf::Sprite> grassSprites;
    int numGrassSpritesToAdd = 5;
    for (int i = 0; i < numGrassSpritesToAdd; ++i)
    {

        int randScale = 5 + rand() % 11; 
        float scale = randScale / 10.f;
        int colourTint = 100 + rand() % 155;
        //Colour Setup
        grassSprite.setColor(sf::Color(colourTint, colourTint, colourTint));
        grassSprite.setOrigin(grassTexture.getSize().x / 2, (grassTexture.getSize().y / 2));
        //grassSprite.setPosition(sf::Vector2f(400.0f, 400.0f));
        grassSprite.setPosition(sf::Vector2f(rand() % (window.getSize().x - grassTexture.getSize().x), rand() % (window.getSize().y - grassTexture.getSize().y)));
        //grassSprite.setRotation(45);
        //Scale Example
        grassSprite.scale(scale, scale);
        grassSprites.push_back(grassSprite);
       
    }
    
    
    
    std::vector<sf::Sprite> stickSprites;
    int randRotation = rand() % 360;
    stickSprite.setOrigin(stickTexture.getSize().x / 2, (stickTexture.getSize().y / 2));
        stickSprite.setRotation(randRotation);
        //stickSprite.setPosition(sf::Vector2f(400.0f, 400.0f));
        stickSprite.setPosition(sf::Vector2f(rand() % (window.getSize().x - stickTexture.getSize().x), rand() % (window.getSize().y - stickTexture.getSize().y)));
        stickSprites.push_back(stickSprite);

        //Position Setup
        playerSprite.setPosition(sf::Vector2f(300.0f, 300.0f));

  



        //Colour Setup example
        //playerSprite.setColor(sf::Color(190,201,91));
        
        //Rotation Example
        //playerSprite.setRotation(90);

        //Scale Example
        //playerSprite.setScale(1.0f, 3.0f);

        //Origin Example
        playerSprite.setOrigin(playerTexture.getSize().x / 2, (playerTexture.getSize().y / 2));
        

       

        //Load Fonts
        sf::Font gameFont;
        gameFont.loadFromFile("Assets/GameFont.ttf");

        //CreateText
        sf::Text gameTitle;
        gameTitle.setFont(gameFont);
        gameTitle.setString("Pick Up Sticks");
        gameTitle.setFillColor(sf::Color::Yellow);
        gameTitle.setOutlineThickness(2.0f);
        gameTitle.setOutlineColor(sf::Color::Black);
        gameTitle.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
        gameTitle.setCharacterSize(40);
        float textWidth = gameTitle.getLocalBounds().width;
        gameTitle.setPosition((float)window.getSize().x / 2.0f - textWidth / 2.0f, 10.0f);
        
        //CreateText
        sf::Text gameOver;
        gameOver.setFont(gameFont);
        gameOver.setString("GAME OVER!");
        gameOver.setFillColor(sf::Color::Red);
        gameOver.setOutlineThickness(2.0f);
        gameOver.setOutlineColor(sf::Color::Black);
        gameOver.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
        textWidth = gameOver.getLocalBounds().width;
        gameOver.setPosition((float)window.getSize().x / 2.0f - textWidth / 2.0f, (float)window.getSize().y/2 - 300);

        //CreateText
        sf::Text restartText;
        restartText.setFont(gameFont);
        restartText.setString("< Press space to restart >");
        restartText.setFillColor(sf::Color::White);
        restartText.setOutlineThickness(2.0f);
        restartText.setOutlineColor(sf::Color::Black);
        restartText.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);
        restartText.setPosition((float)window.getSize().x / 2.0f - textWidth / 2.0f, (float)window.getSize().y/2 + 100);
        textWidth = restartText.getLocalBounds().width;
        restartText.setPosition((float)window.getSize().x / 2.0f - textWidth / 2.0f, (float)window.getSize().y / 2 - 300);

        //CreateText
        sf::Text scoreLabel;
        scoreLabel.setFont(gameFont);
        scoreLabel.setString("Score:");
        //float textWidth = gameTitle.getLocalBounds().width;
        scoreLabel.setPosition(10.0f,10.0f);
        scoreLabel.setFillColor(sf::Color::Yellow);
        scoreLabel.setOutlineThickness(2.0f);
        scoreLabel.setOutlineColor(sf::Color::Black);
        scoreLabel.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);

        //CreateText
        sf::Text timer;
        timer.setFont(gameFont);
        timer.setString("Time Left:");
        //float textWidth = gameTitle.getLocalBounds().width;
        timer.setPosition((float) window.getSize().x -500.0f, 10.0f);
        timer.setFillColor(sf::Color::Yellow);
        timer.setOutlineThickness(2.0f);
        timer.setOutlineColor(sf::Color::Black);
        timer.setStyle(sf::Text::Style::Bold | sf::Text::Style::Underlined);

        sf::SoundBuffer startSFXBuffer;
        startSFXBuffer.loadFromFile("Assets/Start.wav");


        sf::Sound startSFX;
        startSFX.setBuffer(startSFXBuffer);
        startSFX.play();
        

        sf::Music gameMusic;
        gameMusic.openFromFile("Assets/Music.ogg");
        gameMusic.setVolume(50);
        gameMusic.setLoop(true);
        gameMusic.play();

        float xDir = (10 - rand() % 21) / 10.0f;
        float yDir = (10 - rand() % 21) / 10.0f; 
        sf::Vector2f direction(xDir, yDir);


        bool blinkPressedPrev = false;

        //Clocks and timers
        sf::Clock deltaTimeClock;
        sf::Clock overallTimeClock;
        sf::Clock gameTimer;
        float gameDuration = 5;

        bool gameRunning = true;

        sf::Clock stickSpawnClock;


#pragma endregion
    //End Setup

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
        //Update
        //---------------------------------------------
#pragma region Update
        

        //Get time
        sf::Time deltaTime = deltaTimeClock.restart();
        sf::Time totalTime = overallTimeClock.getElapsedTime();

        //Game Timer
        float gameTimeFloat = gameTimer.getElapsedTime().asSeconds();
        float remainingTimeFloat = gameDuration - gameTimeFloat;
        std::string timerString = "Time: ";
        if (remainingTimeFloat <= 0)
        {
            remainingTimeFloat = 0;
            gameRunning = false;
        }

        timerString += std::to_string((int) ceil(remainingTimeFloat));
        //Display time passed this game
        timer.setString(timerString);

        //player1 controller
        int player1Controller = 1;
        
        //only process if game is running
        if (gameRunning)
        {
            //Move Character
            sf::Vector2f direction;
            direction.x = 0;
            direction.y = 0;

            if (sf::Joystick::isConnected(player1Controller))
            {

                float axisX = sf::Joystick::getAxisPosition(player1Controller, sf::Joystick::X);
                float axisY = sf::Joystick::getAxisPosition(player1Controller, sf::Joystick::Y);

                float deadzone = 25;

                if (abs(axisX) > deadzone)
                    direction.x = axisX / 100.0f;
                if (abs(axisY) > deadzone)
                    direction.y = axisY / 100.0f;

            }


            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                direction.x = -1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                direction.x = 1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                direction.y = -1;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                direction.y = 1;
            }



            //Update player position based on movement direction
            float speed = 500;
            //velocity = direction * speed
            sf::Vector2f velocity = direction * speed;
            //distance travelled = velocity * time
            sf::Vector2f distance = velocity * deltaTime.asSeconds();
            sf::Vector2f newPosition = playerSprite.getPosition() + distance;
            playerSprite.setPosition(newPosition);


            // blink teleport
            bool blinkPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Joystick::isButtonPressed(player1Controller, 0);

            //if we've just now pressed the blink button......
            if (blinkPressed && !blinkPressedPrev)
            {
                sf::Vector2f blinkPosition = playerSprite.getPosition() + direction * 200.0f;
                playerSprite.setPosition(blinkPosition);
            }

            blinkPressedPrev = blinkPressed;


            //Spawn a stick if mouse clicked (debug only)
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                //Get the mouse button
                sf::Vector2i localPosition = sf::Mouse::getPosition(window); //window is a sf::window
                sf::Vector2f mousePositionFloat = (sf::Vector2f)localPosition;



                //Spawn a stick at that location
                stickSprite.setPosition(mousePositionFloat);
                stickSprites.push_back(stickSprite);
            }
            if (stickSpawnClock.getElapsedTime().asSeconds() >= stickSpawnCooldownClock)

        }//End of statement (Game Running)

        
        if (!gameRunning)
        {

            //Restart thre game!
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                gameRunning = true;
                stickSprites.clear();
                //TO DO:Reset score
                gameTimer.restart();
                playerSprite.setPosition(sf::Vector2f(300.0f, 300.0f));
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
        
        for (int i = 0; i < stickSprites.size(); i++)
            window.draw(stickSprites[i]);

        window.draw(playerSprite);
        window.draw(gameTitle);
        window.draw(scoreLabel);
        window.draw(timer);
        if (!gameRunning)
        {
            window.draw(gameOver);
            window.draw(restartText);

        }
        
        window.display();
    }
#pragma endregion


    

    return 0;
}