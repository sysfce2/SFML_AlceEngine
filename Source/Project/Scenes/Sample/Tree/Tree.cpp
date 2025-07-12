#include "Tree.hpp"

using namespace alce;

SampleScene::Tree::Tree(Vector2 position)
{
	transform.position = position;
    sortingLayer = 2;
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void SampleScene::Tree::Init()
{    
	spriteRenderer = std::make_shared<SpriteRenderer>();
    AddComponent(spriteRenderer);

    // light = std::make_shared<Light2D>(Light2D::Type::Radial);
    // AddComponent(light);

    // lightMesh = std::make_shared<LightMesh2D>(std::make_shared<RectShape>(50, 50));
    // AddComponent(lightMesh);

    lightingArea = std::make_shared<alce::LightingArea2D>(std::make_shared<RectShape>(300, 800));
    AddComponent(lightingArea);
    

    spriteRenderer->AddTexture("tree/sprite.png", "sprite");
    spriteRenderer->SetTexture("sprite");
}

void SampleScene::Tree::Start()
{

}

void SampleScene::Tree::Update()
{

}

void SampleScene::Tree::SetterManager(String name, String value)
{
    if(name == "position")
    {
        transform.position.x = value.Split(",")[0].ParseFloat();
        transform.position.y = value.Split(",")[1].ParseFloat();
        Debug.Log(transform.position.ToString());
    }

    if(name == "offset")
    {
        lightingArea->offset.x = value.Split(",")[0].ParseFloat();
        lightingArea->offset.y = value.Split(",")[1].ParseFloat();
    }
}

String SampleScene::Tree::GetterManager(String name)
{
    if(name == "position") return transform.position.ToString();

    return "";
}

#pragma endregion