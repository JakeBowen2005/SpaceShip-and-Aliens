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
    vector<Sprite> ships;
    Spaceship.setScale(Vector2f(0.09f, 0.09f));
    ships.push_back(Spaceship);
    
    
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
    
    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        //Update
        
        
        
        //Draw
        window.clear();
        for (size_t i = 0; i < ships.size(); i++) {
            window.draw(Spaceship);
        }
        for (size_t i = 0; i < aliens.size(); i++) {
            window.draw(Alien);
        }
        
        window.display();
    }
}
