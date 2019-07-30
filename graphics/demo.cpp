#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");    
    window.setVerticalSyncEnabled(true);

    window.setPosition(sf::Vector2i(200, 100));
    // change the size of the window
    window.setSize(sf::Vector2u(640, 480));

    sf::CircleShape shape(50.f);
    shape.move(sf::Vector2f(-10,60));
    shape.setFillColor(sf::Color::Yellow);
    
    sf::CircleShape  c2(20.f);
    c2.move(sf::Vector2f(-40,100));
    c2.setFillColor(sf::Color::Red);
    
    sf::Vector2f speed(6, 4);
    sf::Vector2f speed2(1, 2);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;                
        while (window.pollEvent(event))
        {
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code){
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    ;// no handling for now;
            }
        }
        
        
        sf::Vector2f size = window.getView().getSize();
        sf::Vector2f pos = shape.getPosition();
        float r = 2*shape.getRadius();
        
        if(pos.x  >= size.x - r) speed.x *= -1;
        if(pos.x  <= 0) speed.x *= -1;
        if(pos.y  >= size.y - r) speed.y *= -1;
        if(pos.y  <= 0) speed.y *= -1;
        
        shape.move(speed);
        c2.move(speed2);
        
        window.clear(sf::Color::Green);
        window.draw(shape);        
        window.draw(c2);        
        window.display();
    }
}
