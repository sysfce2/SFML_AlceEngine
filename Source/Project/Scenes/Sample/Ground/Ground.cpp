#include "Ground.hpp"

using namespace alce;

SampleScene::Ground::Ground()
{
	
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void SampleScene::Ground::Init()
{
    AddTag("Ground");
    
    rigidbody2d = std::make_shared<Rigidbody2D>();
    AddComponent(rigidbody2d);

    rigidbody2d->CreateBody(
        std::make_shared<RectShape>(Vector2(1000.0f, 50.0f)),
        BodyType::kinematic_body,
        true
    );
}

void SampleScene::Ground::Start()
{

}

void SampleScene::Ground::Update()
{
	
}

void SampleScene::Ground::SetterManager(String name, String value)
{
    if(name == "position")
    {
        Vector2 position = Vector2(value.Split(",")[0].ParseFloat(), value.Split(",")[1].ParseFloat());
        rigidbody2d->SetPosition(position, true);
    }
}

#pragma endregion