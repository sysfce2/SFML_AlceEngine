#include "LightMesh2D.hpp"

using namespace alce;

LightMesh2D::LightMesh2D(ShapePtr shape) : Component("LightMesh2D")
{
    this->shape = shape;
}

//Custom methods implementation
#pragma region implementation

Shape LightMesh2D::GetShape()
{
    return *shape.get();
}

void LightMesh2D::SetShape(ShapePtr shape)
{
    if(!shape) return;

    this->shape = shape;
}


#pragma endregion

//Inherited methods
#pragma region inherited

void LightMesh2D::Init()
{
	
}

void LightMesh2D::Start()
{
	
}

void LightMesh2D::Render()
{
	
}

void LightMesh2D::Update()
{
    if(!enabled) return;

    shape->position = transform->position.ToPixels();
}

#pragma endregion