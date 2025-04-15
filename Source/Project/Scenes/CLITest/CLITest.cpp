#include "CLITest.hpp"
#include "TestSec/TestSec.hpp"
#include "Test/Test.hpp"

using namespace alce;

CLITestScene::CLITest::CLITest() : Scene("CLITest")
{
	DevelopmentMode(true);
	InitPhysics(Vector2(0.0f, -9.8f));
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void CLITestScene::CLITest::Init()
{
	Factory.RegisterCreator("CLITestScene::TestSec", []() {
		return std::make_shared<CLITestScene::TestSec>();
	});

	Factory.RegisterCreator("CLITestScene::Test", []() {
		return std::make_shared<CLITestScene::Test>();
	});


}

void CLITestScene::CLITest::Start()
{
	
}

#pragma endregion