#include "Light2D.hpp"

using namespace alce;

Light2D::Light2D(Type type) : Component("Light2D")
{
	lightType = type;

    if (type == Type::Radial) 
    {
        light = std::make_shared<candle::RadialLight>();
    } 
    else 
    {
        light = std::make_shared<candle::DirectedLight>();
        std::static_pointer_cast<candle::DirectedLight>(light)->setBeamWidth(60.f);
    }

    range = 100;   
    light->setColor(sf::Color::White);
    light->setIntensity(1.0f);
}

void Light2D::SetColor(Color color) 
{
    if(light) light->setColor(color.ToSFMLColor());
}

Color Light2D::GetColor()
{
    return Color(light->getColor());
}

void Light2D::SetFade(bool fade)
{
    if(light) light->setFade(fade);
}

bool Light2D::IsFading()
{
    return light->getFade();
}

void Light2D::SetRange(float range) 
{
    this->range = range;
}

float Light2D::GetRange()
{
    return range;
}

void Light2D::SetIntensity(float intensity) 
{
    if(light) light->setIntensity(intensity);
}

float Light2D::GetIntensity()
{
    return light->getIntensity();
}

void Light2D::SetBeamWidth(float width)
{
    beamWidth = width;
}

float Light2D::GetBeamWidth()
{
    return beamWidth;
}

void Light2D::SetBeamAngle(float angle)
{
    beamAngle = angle;
}

float Light2D::GetBeamAngle()
{
    return beamAngle;
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void Light2D::Init()
{
    if(transform == nullptr)
    {
        Debug.Warning("Component Light2D has no association with any GameObject");
    }
}

void Light2D::Start()
{
	if(transform == nullptr)
    {
        Debug.Warning("Component Light2D has no association with any GameObject");
    }
}

void Light2D::Render()
{
    if(transform == nullptr) return;

    Alce.GetWindow().draw(*light.get());

}

void Light2D::Update()
{
	if(!enabled) return;

    light->setPosition(transform->position.ToPixels().ToVector2f());
    light->setRotation(transform->rotation);

    if(lightType == Type::Directed) 
    {
        std::static_pointer_cast<candle::DirectedLight>(light)->setBeamWidth(beamWidth);
    }

    if(lightType == Type::Radial)
    {
        std::static_pointer_cast<candle::RadialLight>(light)->setBeamAngle(beamAngle);
    }

    light->setRange(range);
}

#pragma endregion