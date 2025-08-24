#include "Project/Scenes/Scenes.hpp"

using namespace alce;

int main()
{
    Alce.Window("AlceEngine Sample", DisplayMode::Default);
    Alce.stanby = true;

    Debug.SetWaitTime(0);

    Alce.AddScene<SampleScene::Sample>();
    Alce.AddScene<IntroScene::Intro>();
    Alce.AddScene<Test1Scene::Test1>();
    Alce.AddScene<OtraScene::Otra>();

    Alce.SetCurrentScene("Sample");
    
    Alce.Run();

    return 0;
}
