#include "Project/Scenes/Scenes.hpp"

using namespace alce;

int main()
{
    Alce.Window("Alce Engine Test", DisplayMode::Default);
    Alce.stanby = true;

    Debug.SetWaitTime(0);

    Alce.AddScene<Test1Scene::Test1>();
    Alce.AddScene<SampleScene::Sample>();
    
    Alce.SetCurrentScene("Sample");
    
    Alce.Run();

    return 0;
}

// candle::EdgeVector GenerateEdgesFromShape(ShapePtr shape)
// {
//     candle::EdgeVector edges;
//     if (!shape)
//         return edges;

//     sf::Vector2f pos(shape->position.x, shape->position.y);

//     switch (shape->GetType())
//     {
//         case ShapeType::rect:
//         {
//             auto rect = std::static_pointer_cast<RectShape>(shape);
//             float w = rect->width;
//             float h = rect->height;

//             sf::Vector2f p1 = pos;
//             sf::Vector2f p2 = pos + sf::Vector2f(w, 0);
//             sf::Vector2f p3 = pos + sf::Vector2f(w, h);
//             sf::Vector2f p4 = pos + sf::Vector2f(0, h);

//             edges.emplace_back(p1, p2);
//             edges.emplace_back(p2, p3);
//             edges.emplace_back(p3, p4);
//             edges.emplace_back(p4, p1);
//             break;
//         }

//         case ShapeType::polygon:
//         {
//             auto poly = std::static_pointer_cast<PolygonShape>(shape);
//             List<Vector2> verts = poly->GetVertexList();

//             for (size_t i = 0; i < verts.Length(); ++i)
//             {
//                 Vector2 a = verts[i] + shape->position;
//                 Vector2 b = verts[(i + 1) % verts.Length()] + shape->position;

//                 sf::Vector2f p1(a.x, a.y);
//                 sf::Vector2f p2(b.x, b.y);

//                 edges.emplace_back(p1, p2);
//             }
//             break;
//         }

//         case ShapeType::circle:
//         {
//             auto circle = std::static_pointer_cast<CircleShape>(shape);
//             const int segments = 30;
//             float r = circle->radius;

//             for (int i = 0; i < segments; ++i)
//             {
//                 float angle1 = (2 * Math.PI * i) / segments;
//                 float angle2 = (2 * Math.PI * (i + 1)) / segments;

//                 sf::Vector2f p1 = pos + sf::Vector2f(std::cos(angle1), std::sin(angle1)) * r;
//                 sf::Vector2f p2 = pos + sf::Vector2f(std::cos(angle2), std::sin(angle2)) * r;

//                 edges.emplace_back(p1, p2);
//             }
//             break;
//         }

//         default:
//             break;
//     }

//     return edges;
// }

// int main()
// {
//     // create window
//     sf::RenderWindow w(sf::VideoMode(400, 400), "app");

//     std::shared_ptr<candle::LightSource> light;

//     light = std::make_shared<candle::RadialLight>();
//     std::static_pointer_cast<candle::RadialLight>(light)->setRange(200.f);
//     // std::static_pointer_cast<candle::DirectedLight>(light)->setBeamWidth(100.f);

//     alce::CircleShapePtr circle = std::make_shared<CircleShape>(50);

//     List<Vector2> vertices;
//     vertices.Add(Vector2(150, 150));
//     vertices.Add(Vector2(250, 100));
//     vertices.Add(Vector2(300, 200));

//     alce::PolygonShapePtr triangle = std::make_shared<PolygonShape>(vertices);

//     circle->position = Vector2(40, 30);

//     candle::EdgeVector edgePool;

//     auto lightEdges1 = GenerateEdgesFromShape(triangle);
//     auto lightEdges2 = GenerateEdgesFromShape(circle);

//     for(auto& le: lightEdges1)
//     {
//         edgePool.push_back(le);
//     }

    
//     for(auto& le: lightEdges2)
//     {
//         edgePool.push_back(le);
//     }

//     sf::CircleShape circulo(100); 
//     circulo.setFillColor(sf::Color::Green);
//     circulo.setPosition(0, 0); 

//     candle::LightingArea fog(candle::LightingArea::FOG,
//                             sf::Vector2f(0.f, 0.f),
//                             sf::Vector2f(300.f, 379.f));
//     fog.setAreaColor(sf::Color::Black);


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
//                 light->castLight(edgePool.begin(), edgePool.end());
//             }
//         }

//         fog.clear();
//         fog.draw(*light.get());
//         fog.display();
        
//         w.clear();
//         w.draw(circulo);
//         w.draw(fog);
//         w.display();
//     }
//     return 0;
// }