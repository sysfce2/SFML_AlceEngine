#include "Test.hpp"

using namespace alce;

CLITestScene::Test::Test()
{
	
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void CLITestScene::Test::Init()
{
	
}

void CLITestScene::Test::Start()
{
	
}

void CLITestScene::Test::Update()
{
	
}

void CLITestScene::Test::SetterManager(String name, String value)
{
	if(name == "hp")
	{
		hp = value.ParseInt();
	}
	if(name == "nombre")
	{
		nombre = value;
	}

}

String CLITestScene::Test::GetterManager(String name)
{
	if(name == "hp") return hp;
	if(name == "nombre") return nombre;

	return "undefined";
}

#pragma endregion