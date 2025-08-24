#include "Renderer.hpp"

using namespace alce;

IntroScene::Renderer::Renderer()
{
	
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void IntroScene::Renderer::Init()
{
	camera = std::make_shared<Camera>();
	AddComponent(camera);

	spriteRenderer = std::make_shared<SpriteRenderer>();
	spriteRenderer->AddTexture("logo.png", "EngineLogo");
	spriteRenderer->AddTexture("Ekrol34.png", "Ekrol34Logo");
	AddComponent(spriteRenderer);
}

void IntroScene::Renderer::Start()
{
	Alce.stanby = false;
	Alce.SetClearColor(Color(0, 0, 0));
	spriteRenderer->SetAlpha(0);
	spriteRenderer->SetTexture("Ekrol34Logo");
	
	elapsed = 0.0f;
}

bool once = false;

void IntroScene::Renderer::Update()
{
	elapsed += Chrono.deltaTime.ToMiliseconds();
	float fadeDuration = 2000.0f;

	if(elapsed < 2000.0f)
	{
		float progress = elapsed / fadeDuration;
		if(progress > 1.0f) progress = 1.0f;

		uint8_t alpha = static_cast<uint8_t>(progress * 255.0f);
		spriteRenderer->SetAlpha(alpha);
	}

	if(elapsed > 3000.0f && elapsed < 3000.0f + fadeDuration)
    {
        float progress = (elapsed - 3000.0f) / fadeDuration;
        if(progress > 1.0f) progress = 1.0f;

        uint8_t alpha = static_cast<uint8_t>((1.0f - progress) * 255.0f);
        spriteRenderer->SetAlpha(alpha);
    }

	if(elapsed > 5000.0f) 
	{
		Debug.Log("Switching to Sample scene...");
		Alce.SetCurrentScene("Sample");
	}
}

void IntroScene::Renderer::SetterManager(String name, String value)
{
	

}

String IntroScene::Renderer::GetterManager(String name)
{

	return "undefined";
}

#pragma endregion