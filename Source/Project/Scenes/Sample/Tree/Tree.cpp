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

    light = std::make_shared<Light2D>();
    AddComponent(light);

    // shadowCast = std::make_shared<ShadowCast2D>();
    // shadowCast->SetShape(std::make_shared<RectShape>(10, 30));
    // AddComponent(shadowCast);

    spriteRenderer->AddTexture("tree/sprite.png", "sprite");
    spriteRenderer->SetTexture("sprite");
}

void SampleScene::Tree::Start()
{

}

void SampleScene::Tree::Update()
{

}

#pragma endregion