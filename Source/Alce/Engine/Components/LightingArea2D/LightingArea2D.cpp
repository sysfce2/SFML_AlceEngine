#include "LightingArea2D.hpp"

using namespace alce;

LightingArea2D::LightingArea2D(ShapePtr shape) : Component("LightingArea2D")
{
    lightingArea = std::make_shared<candle::LightingArea>(candle::LightingArea::FOG, Vector2(0, 0).ToPixels().ToVector2f(), sf::Vector2f(300, 300));
}

//Custom methods implementation
#pragma region implementation

void LightingArea2D::SetShape(ShapePtr shape)
{
	
}

// std::vector<sf::Vector2f> _GenerateEdgesFromShape(ShapePtr shape)
// {
//     std::vector<sf::Vector2f> edges;

//     if(!shape)
//     {
//         return edges;
//     }

//     switch (shape->GetType())
//     {
//         case ShapeType::rect:
//         {
//             auto rect = std::static_pointer_cast<RectShape>(shape);

//             Vector2 p1 = shape->position;
//             Vector2 p2 = shape->position + Vector2(rect->width, 0);
//             Vector2 p3 = shape->position + Vector2(rect->width, rect->height);
//             Vector2 p4 = shape->position + Vector2(0, rect->height);

//             edges.emplace_back(p1.ToVector2f());
//             edges.emplace_back(p2.ToVector2f());
//             edges.emplace_back(p3.ToVector2f());
//             edges.emplace_back(p4.ToVector2f());

//             break;
//         }

//         case ShapeType::polygon:
//         {
            
//             break;
//         }

//         case ShapeType::circle:
//         {
            
//             break;
//         }

//         default:
//             break;
//     }

//     return edges;
// }


#pragma endregion

//Inherited methods
#pragma region inherited

void LightingArea2D::Init()
{
	
}

void LightingArea2D::Start()
{
	
}

void LightingArea2D::Render()
{
	if(!enabled) return;
    
	lightingArea->clear();

	for(auto& light : lights)
	{
		lightingArea->draw(*light);
	}

	lightingArea->display();

	Alce.GetWindow().draw(*lightingArea.get());
}

void LightingArea2D::DebugRender()
{
	if(!enabled) return;

    if (auto rect = std::dynamic_pointer_cast<RectShape>(shape))
    {
        Vector2 pos = rect->position.ToPixels();
        pos = pos.ToPixels();
        float w = rect->width;
        float h = rect->height;

        Vector2 a = pos;
        Vector2 b = pos + Vector2(w, 0);
        Vector2 c = pos + Vector2(w, h);
        Vector2 d = pos + Vector2(0, h);

        DrawDottedLine(Alce.GetWindow(), a.ToVector2f(), b.ToVector2f());
        DrawDottedLine(Alce.GetWindow(), b.ToVector2f(), c.ToVector2f());
        DrawDottedLine(Alce.GetWindow(), c.ToVector2f(), d.ToVector2f());
        DrawDottedLine(Alce.GetWindow(), d.ToVector2f(), a.ToVector2f());
    }
    else if (auto circle = std::dynamic_pointer_cast<CircleShape>(shape))
    {
        sf::Vector2f center(circle->position.x, circle->position.y);
        float radius = circle->radius;
        int segments = CIRCLE_QUALITY;

        float angleStep = 2 * 3.14159265f / segments;
        
        for(int i = 0; i < segments; i++)
        {
            float angle1 = i * angleStep;
            float angle2 = (i + 1) * angleStep;

            sf::Vector2f p1 = center + sf::Vector2f(std::cos(angle1), std::sin(angle1)) * radius;
            sf::Vector2f p2 = center + sf::Vector2f(std::cos(angle2), std::sin(angle2)) * radius;

            DrawDottedLine(Alce.GetWindow(), p1, p2);
        }
    }
    else if (auto poly = std::dynamic_pointer_cast<PolygonShape>(shape))
    {
        auto verts = poly->GetVertexList();
        int count = verts.Length();

        for(int i = 0; i < count; i++)
        {
            sf::Vector2f a(verts[i].x, verts[i].y);
            sf::Vector2f b(verts[(i + 1) % count].x, verts[(i + 1) % count].y);
            DrawDottedLine(Alce.GetWindow(), a, b);
        }
    }
}

void LightingArea2D::Update()
{
    Vector2 position = transform->position + offset;

    lightingArea->setPosition(position.ToPixels().ToVector2f());
    lightingArea->setAreaOpacity(opacity);
	lightingArea->setAreaColor(color.ToSFMLColor());
}

#pragma endregion