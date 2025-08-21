#include "Player.hpp"

using namespace alce;

SampleScene::Player::Player()
{
	
}

//Custom methods implementation
#pragma region implementation


#pragma endregion

//Inherited methods
#pragma region inherited

void SampleScene::Player::Init()
{
    AddTag("Player");
    sortingLayer = 1;

    //transform.position = Vector2(0, 50);

    camera = std::make_shared<Camera>();
    AddComponent(camera);

    rigidbody2d = std::make_shared<Rigidbody2D>();
    AddComponent(rigidbody2d);

    animation = std::make_shared<Animation2D>();
    animation->sortingLayer = 2;
    AddComponent(animation);

    leftRaycast2d = std::make_shared<Raycast2D>();
    AddComponent(leftRaycast2d);

    rightRaycast2d = std::make_shared<Raycast2D>();
    AddComponent(rightRaycast2d);

    canvas = std::make_shared<Canvas>();
    AddComponent(canvas);

    light = std::make_shared<Light2D>(Light2D::Type::Radial);
    light->SetIntensity(0.8f);
    light->sortingLayer = 1;
    AddComponent(light);

    animation->AddAnimation("player/walk-forward.png", "walk-forward", 1, 4, 54, 63);
    animation->AddAnimation("player/walk-backward.png", "walk-backward", 1, 4, 54, 63);
    animation->AddAnimation("player/idle-forward.png", "idle-forward", 1, 1, 54, 63);
    animation->AddAnimation("player/idle-backward.png", "idle-backward", 1, 1, 54, 63);
    animation->AddAnimation("player/jump-forward.png", "jump-forward", 1, 1, 54, 63);
    animation->AddAnimation("player/jump-backward.png", "jump-backward", 1, 1, 54, 63);

    rigidbody2d->CreateBody(
        std::make_shared<RectShape>(Vector2(40.0f, 65.0f)),
        BodyType::dynamic_body,
        true,
        MaskType::mask_2
    );
    rigidbody2d->SetFixedRotation(true);
    
    TextPtr text = std::make_shared<Text>();
    _text = text;
    canvas->AddElement(text);
    text->position = Vector2(20, 20);
    text->padding = Vector2(10, 10);

    text->font = "fonts/Merriweather/Merriweather-Black.ttf";
    *text += "<color='green'>Alce Engine</color> Sample Project";
    *text += "\nby @gabrielbeguren";
    text->borderRadius = 7;
    text->borderWidth = 0;
    text->borderColor = Colors::Yellow;
    text->backgroundColor = Colors::Transparent;

    animation->transform->scale = Vector2(0, 0);
    leftRaycast2d->direction = Vector2(-0.447f, -0.894f);
    leftRaycast2d->length = 1.5f;

    rightRaycast2d->direction = Vector2(0.447f, -0.894f);
    rightRaycast2d->length = 1.5f;

    walking = false;
    status = "idle-forward";
    velocity = 1.0f;

    ButtonPtr button = std::make_shared<Button>(); 
    canvas->AddElement(button);
    button->zIndex = 5;
    button->position = Vector2(40, 100);
    button->borderRadius = 7;
    button->borderWidth = 1;
    button->text = "guardar";
    button->borderColor = Colors::White;
    button->onClick = [](){
        
    };

    TextInputPtr ti = std::make_shared<TextInput>();
    canvas->AddElement(ti);
    ti->width = 500;
    ti->height = 45;
    ti->backgroundColor = Colors::Black;
    ti->textColor = Colors::White;
    ti->borderWidth = 1;
    ti->cursorColor = Colors::White;
    ti->positionType = UIElement::Relative;
    ti->position = Vector2(0.01, 0.925f);
    ti->fontSize = TextInput::Small;
    ti->onSubmit = [=](){
        Debug.Log(ti->GetText());
    };
}

void SampleScene::Player::Start()
{   
    // TextPtr text = std::make_shared<Text>();
    // canvas->AddElement(text);
    // text->position = Vector2(20, 20);
    // text->padding = Vector2(10, 10);

    // text->font = "fonts/Merriweather/Merriweather-Black.ttf";
    // *text += "<color='green'>Alce Engine</color> Sample Project";
    // *text += "\nby @gabrielbeguren";
    // text->borderRadius = 7;
    // text->borderWidth = 3;
    // text->borderColor = Colors::Yellow;
    // text->backgroundColor = Colors::Black;

    // TextInputPtr ti = std::make_shared<TextInput>();
    // canvas->AddElement(ti);
    // ti->width = 500;
    // ti->height = 45;
    // ti->backgroundColor = Colors::Black;
    // ti->textColor = Colors::White;
    // ti->borderWidth = 1;
    // ti->cursorColor = Colors::White;
    // ti->positionType = UIElement::Relative;
    // ti->position = Vector2(0.01, 0.925f);
    // ti->fontSize = TextInput::Small;
    // ti->onSubmit = [=](){
    //     Debug.Log(ti->GetText());
    // };

    // ButtonPtr button = std::make_shared<Button>(); 
    // canvas->AddElement(button);
    // button->zIndex = 5;
    // button->position = Vector2(40, 100);
    // button->borderRadius = 2;
    // button->borderWidth = 1;
    // button->text = "guardar";
    // button->borderColor = Colors::White;
    // button->onClick = [](){
    //     Alce.GetCurrentScene()->Save();

    //     Storage.SetString("mi nombre", "Gabriel Bravo Eguren");
    //     Storage.SetStringList("lista de la compra", {"patatas", "lombarda", "pollo"});
    //     Storage.SetJson("json", Json("{\"test\": \"inicial\", \"funcionara\": \"quien sabe\"}"));
    // };
    
    // ButtonPtr button2 = std::make_shared<Button>(); 
    // canvas->AddElement(button2);
    // button2->zIndex = 2;
    // button2->position = Vector2(20, 100);
    // button2->borderRadius = 2;
    // button2->borderWidth = 1;
    // button2->borderColor = Colors::Pink;
    // button2->text = "borrar";
    // button2->onClick = [](){
    //     Storage.Delete("lista de la compra");
    // };
    //
    // ButtonPtr button3 = std::make_shared<Button>(); 
    // canvas->AddElement(button3);
    // button3->position = Vector2(20, 100);
    // button3->borderRadius = 5;
    // button3->borderWidth = 2;
    // button3->padding = Vector2(15, 10);
    // button3->borderColor = Colors::White;
    // button3->text = "-";
    // button3->onClick = [](){
    //     if(Alce.GetCurrentScene()->GridScale > 1)
    //     {
    //         Alce.GetCurrentScene()->GridScale -= 1;
    //         Debug.Log(Alce.GetCurrentScene()->GridScale);
    //     }

    // };

    // ButtonPtr button4 = std::make_shared<Button>(); 
    // canvas->AddElement(button4);
    // button4->position = Vector2(70, 100);
    // button4->borderRadius = 5;
    // button4->borderWidth = 2;
    // button4->padding = Vector2(13, 10);
    // button4->borderColor = Colors::White;
    // button4->text = "+";
    // button4->onClick = [&](){
    //     Alce.GetCurrentScene()->GridScale += 1;
    //     Debug.Log(Alce.GetCurrentScene()->GridScale);
    // };

    // ImagePtr image = std::make_shared<Image>();
    // canvas->AddElement(image);
    // image->position = Vector2(300, 25);
    // image->AddTexture("meteor.png", "meteor");
    // image->SetTexture("meteor");
}

void SampleScene::Player::OnImpact(GameObject* other)
{
    if(other->HasTag("Ground"))
    {
        grounded = true;
        if(status == "jump-forward") status = "idle-forward";
        if(status == "jump-backward") status = "idle-backward";
    }
}

void SampleScene::Player::OnImpactEnd(GameObject* other)
{
    if(other->HasTag("Ground"))
    {
        grounded = false;
        if(status == "idle-forward") status = "jump-forward";
        if(status == "idle-backward") status = "jump-backward";
    }
}

void SampleScene::Player::Update()
{
    if(Input.IsKeyPressed(Keyboard::W))
    {
        rigidbody2d->SetVerticalVelocity(velocity);
    }

    if(Input.IsKeyPressed(Keyboard::S))
    {
        rigidbody2d->SetVerticalVelocity(-velocity);
    }

    if(Input.IsKeyPressed(Keyboard::A))
    {
        rigidbody2d->SetHorizontalVelocity(-velocity);
        if(grounded) status = "walk-backward";
        else status = "jump-backward";
    }
    else if(Input.IsKeyPressed(Keyboard::D))
    {
        rigidbody2d->SetHorizontalVelocity(velocity);
        if(grounded) status = "walk-forward";
        else status = "jump-forward";
    }
    else
    {
        rigidbody2d->SetHorizontalVelocity(0.0f);
        
        if(grounded)
        {
            if(status == "walk-forward") status = "idle-forward";
            if(status == "walk-backward") status = "idle-backward";
        }
    }

    if (Input.IsKeyDown(Keyboard::Space) && grounded)
    {
        rigidbody2d->ApplyLinearForce(Vector2(0.0f, 90.0f));

        if(status == "walk-forward") status = "jump-forward";
        if(status == "idle-forward") status = "jump-forward";
        if(status == "walk-backward") status = "jump-backward";
        if(status == "idle-backward") status = "jump-backward";
        grounded = false; 
    }

    if(Input.IsKeyDown(Keyboard::F))
    {
        rigidbody2d->SetPosition(Vector2(0, 15));
    }

    AnimationManager();
}
#pragma endregion

void SampleScene::Player::SetterManager(String name, String value)
{
    if(name == "velocity") velocity =  value.ParseFloat();
    if(name == "intensity") light->SetIntensity(value.ParseFloat());
    if(name == "range") light->SetRange(value.ParseFloat());
    if(name == "beam") light->SetBeamAngle(value.ParseFloat());
    if(name == "sortingLayer") sortingLayer = value.ParseInt();
    if(name == "position") _text->position = Vector2(value.Split(",").First().ParseFloat(), value.Split(",").Last().ParseFloat());
}

String SampleScene::Player::GetterManager(String name)
{
    if(name == "velocity") return velocity;
    if(name == "position") return transform.position.ToString();

    return "undefined";
}

void SampleScene::Player::AnimationManager()
{
    if(status == "idle-forward")
    {
        if(animation->GetCurrentAnimation() != "idle-forward")
            animation->PlayAnimation("idle-forward");
    }

    if(status == "idle-backward")
    {
        if(animation->GetCurrentAnimation() != "idle-backward")
            animation->PlayAnimation("idle-backward");
    }

    if(status == "walk-forward")
    {
        if(animation->GetCurrentAnimation() != "walk-forward")
            animation->PlayAnimation("walk-forward");
    }

    if(status == "walk-backward")
    {
        if(animation->GetCurrentAnimation() != "walk-backward")
            animation->PlayAnimation("walk-backward");
    }

    if(status == "jump-forward")
    {
        if(animation->GetCurrentAnimation() != "jump-forward")
            animation->PlayAnimation("jump-forward");
    }

    if(status == "jump-backward")
    {
        if(animation->GetCurrentAnimation() != "jump-backward")
            animation->PlayAnimation("jump-backward");
    }
}