#include "Cosa.hpp"

using namespace alce;

OtraScene::Cosa::Cosa()
{
	
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void OtraScene::Cosa::Init()
{
	camera = std::make_shared<Camera>();
	AddComponent(camera);	

	spriteRenderer = std::make_shared<SpriteRenderer>();
	spriteRenderer->AddTexture("logo.png", "EngineLogo");
	AddComponent(spriteRenderer);

	spriteRenderer->SetTexture("EngineLogo");
}

void OtraScene::Cosa::Start()
{
	
}

void OtraScene::Cosa::Update()
{
	
}

void OtraScene::Cosa::SetterManager(String name, String value)
{
	

}

String OtraScene::Cosa::GetterManager(String name)
{

	return "undefined";
}

#pragma endregion