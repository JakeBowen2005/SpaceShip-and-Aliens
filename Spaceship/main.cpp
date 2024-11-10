//
//  main.cpp
//  Spaceship
//
//  Created by Jake Bowen on 11/9/24.
//

//cd Desktop/SFML/Spaceship/Spaceship
//g++ -o main main.cpp -I/opt/homebrew/include -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;
using namespace std;

#define screen_width 640
#define screen_length 480


int main(int argc, const char * argv[]) {
    // insert code here...
    srand(time_t(NULL));
    
    RenderWindow window(VideoMode(screen_width, screen_length), "SpaceShip");
    window.setFramerateLimit(60);
    
    //Spaceship
    Texture SpaceshipTex;
    Sprite Spaceship;
    
    if (!SpaceshipTex.loadFromFile("Textures/spaceship.png")) {
        cout <<  "Could not load spaceship from file";
    }
    Spaceship.setTexture(SpaceshipTex);
    Spaceship.setScale(Vector2f(0.09f, 0.09f));
    
    //Alien
    Texture AlienTex;
    Sprite Alien;
    
    if (!AlienTex.loadFromFile("Textures/aliens.png")) {
        cout << "Could not load aliens from file";
    }
    Alien.setTexture(AlienTex);
    vector<Sprite> aliens;
    Alien.setScale(Vector2f(0.05f, 0.05f));
    Alien.rotate(270.f);
    aliens.push_back(Alien);
    int alienSpawnTimer = 0;
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        
        //Update
        
        //Spaceship (player)
        
        
        
        //Aliens (enemies)
        if (alienSpawnTimer < 30) {
            alienSpawnTimer++;
        }
        
        if (alienSpawnTimer >= 30) {
            float ypos = rand() % static_cast<int>(screen_length + 10.f);
            Alien.setPosition(screen_width, ypos);
            aliens.push_back(Alien);
            alienSpawnTimer = 0;
            
        }
        
        for (size_t i = 0; i < aliens.size(); i++) {
            aliens[i].move(-5.f, 0.f);
            
            if (aliens[i].getPosition().x < 0) {
                aliens.erase(aliens.begin() + i);
            }
        }
        
        
        
        //Draw
        window.clear();
        
        window.draw(Spaceship);
        
        for (size_t i = 0; i < aliens.size(); i++) {
            window.draw(aliens[i]);
        }
        
        window.display();
    }
}
