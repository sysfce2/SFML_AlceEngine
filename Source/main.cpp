#include "Project/Scenes/Scenes.hpp"

using namespace alce;

int main()
{
    Alce.Window("Alce Engine Test", DisplayMode::Default);
    Alce.stanby = true;

    Debug.SetWaitTime(0);

    Alce.SetClearColor(Colors::Black);

    Alce.AddScene<Test1Scene::Test1>();
    Alce.AddScene<SampleScene::Sample>();
    
    Alce.SetCurrentScene("Sample");
    
    Alce.Run();

    return 0;
}

// int main()
// {
//     // create window
//     sf::RenderWindow w(sf::VideoMode(400, 400), "app");
    
//     // create a light source
//     //candle::RadialLight light;
//     // light.setRange(150);

//     std::shared_ptr<candle::LightSource> light;

//     light = std::make_shared<candle::RadialLight>();
//     std::static_pointer_cast<candle::RadialLight>(light)->setRange(100.f);
    

//     sf::CircleShape circulo(100); // Radio de 100 píxeles
//     circulo.setFillColor(sf::Color::Green);
    
//     // main loop
//     while(w.isOpen())
//     {
//         sf::Event e;
//         while(w.pollEvent(e))
//         {
//             if(e.type == sf::Event::Closed)
//             {
//                 w.close();
//             }
//             else if(e.type == sf::Event::MouseMoved)
//             {
//                 sf::Vector2f mp(sf::Mouse::getPosition(w));
//                 light->setPosition(mp);
//                 circulo.setPosition(mp);

//             }
//         }
        
//         w.clear();
//         w.draw(circulo);
//         w.draw(*light.get());
//         w.display();
//     }
//     return 0;
// }