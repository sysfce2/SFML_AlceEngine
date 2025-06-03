#include "Project/Scenes/Scenes.hpp"

using namespace alce;

// int main()
// {
//     Alce.Window("Alce Engine Test", DisplayMode::Default);
//     Alce.stanby = true;

//     Debug.SetWaitTime(0);

//     Alce.SetClearColor(Colors::Black);

//     Alce.AddScene<Test1Scene::Test1>();
//     Alce.AddScene<SampleScene::Sample>();
    
//     Alce.SetCurrentScene("Sample");
    
//     Alce.Run();

//     return 0;
// }

int main()
{
    // create window
    sf::RenderWindow w(sf::VideoMode(400, 400), "app");

    std::shared_ptr<candle::LightSource> light;

    light = std::make_shared<candle::RadialLight>();
    std::static_pointer_cast<candle::RadialLight>(light)->setRange(200.f);
    // std::static_pointer_cast<candle::DirectedLight>(light)->setBeamWidth(100.f);

     candle::EdgeVector edges;
    edges.emplace_back(sf::Vector2f(200.f, 300.f));
    // edges.emplace_back(sf::Vector2f(300.f, 100.f));
    // edges.emplace_back(sf::Vector2f(300.f, 300.f));

    
    // main loop
    while(w.isOpen())
    {
        sf::Event e;
        while(w.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                w.close();
            }
            else if(e.type == sf::Event::MouseMoved)
            {
                sf::Vector2f mp(sf::Mouse::getPosition(w));
                light->setPosition(mp);
                light->castLight(edges.begin(), edges.end());
            }
        }
        
        w.clear();
        w.draw(*light.get());
        w.display();
    }
    return 0;
}