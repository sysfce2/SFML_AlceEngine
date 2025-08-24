#include "Otra.hpp"
#include "Cosa/Cosa.hpp"

using namespace alce;

OtraScene::Otra::Otra() : Scene("Otra")
{
	DevelopmentMode(true);
	InitPhysics(Vector2(0.0f, -9.8f));
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void OtraScene::Otra::Init()
{
	

	CosaPtr cosa = std::make_shared<OtraScene::Cosa>();
	AddGameObject(cosa);
}

void OtraScene::Otra::Start()
{
	
}

#pragma endregion