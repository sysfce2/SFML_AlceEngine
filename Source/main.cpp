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

// std::vector<sf::Vector2f> makeCircle(sf::Vector2f center, float radius, int pointCount = 40) {
//     std::vector<sf::Vector2f> points;
//     for (int i = 0; i < pointCount; ++i) {
//         float angle = i * 2.f * Math.PI / pointCount;
//         points.emplace_back(center.x + std::cos(angle) * radius, center.y + std::sin(angle) * radius);
//     }
//     return points;
// }

// std::vector<sf::Vector2f> ConvertShapeToPolygonPoints(ShapePtr shape, int circleResolution = CIRCLE_QUALITY) {
//     std::vector<sf::Vector2f> points;

//     if (!shape) return points;

//     switch (shape->GetType()) {
//         case ShapeType::rect: {
//             auto rect = std::dynamic_pointer_cast<RectShape>(shape);
//             if (rect) {
//                 sf::Vector2f pos(rect->position.x, rect->position.y);
//                 float w = rect->width;
//                 float h = rect->height;

//                 points.push_back(pos);
//                 points.push_back({pos.x + w, pos.y});
//                 points.push_back({pos.x + w, pos.y + h});
//                 points.push_back({pos.x, pos.y + h});
//             }
//             break;
//         }

//         case ShapeType::circle: {
//             auto circle = std::dynamic_pointer_cast<CircleShape>(shape);
//             if (circle) {
//                 float radius = circle->radius;
//                 sf::Vector2f center(circle->position.x, circle->position.y);
//                 for (int i = 0; i < circleResolution; ++i) {
//                     float angle = i * 2.f * Math.PI / circleResolution;
//                     points.emplace_back(
//                         center.x + radius * std::cos(angle),
//                         center.y + radius * std::sin(angle)
//                     );
//                 }
//             }
//             break;
//         }

//         case ShapeType::polygon: {
//             auto poly = std::dynamic_pointer_cast<PolygonShape>(shape);
//             if (poly) {
//                 for (auto& v : poly->GetVertexList()) {
//                     points.emplace_back(v.x, v.y);
//                 }
//             }
//             break;
//         }

//         default:
//             // ShapeType::none u otros no definidos
//             break;
//     }

//     return points;
// }

// int main()
// {
//     // create window
//     sf::RenderWindow w(sf::VideoMode(600, 500), "app");

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

//     sf::CircleShape circulo(200); 
//     circulo.setFillColor(sf::Color::Green);
//     circulo.setPosition(0, 0); 

//     candle::LightingArea lighting(candle::LightingArea::FOG, {100, 100}, {300, 300});

//     ShapePtr squareLA = std::make_shared<RectShape>(50, 50, 200, 300);
//     ShapePtr circleLA = std::make_shared<CircleShape>(50, 50, 200);
//     List<Vector2> trianglePoints = {
//         Vector2(300.f, 0.f),
//         Vector2(600.f, 600.f),
//         Vector2(100.f, 600.f)
//     };
//     ShapePtr triangleLA = std::make_shared<PolygonShape>(trianglePoints);
    
//     lighting.setPolygonShape(ConvertShapeToPolygonPoints(squareLA));
//     lighting.setAreaColor(sf::Color::Black);


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

//         lighting.clear();
//         lighting.draw(*light.get());
//         lighting.display();

//         w.clear(sf::Color::Green);
//         // w.draw(circulo);
//         w.draw(lighting);
//         w.display();
//     }
//     return 0;
// }