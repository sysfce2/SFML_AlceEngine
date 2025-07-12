#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class LightMesh2D : public Component
	{
	public:

		LightMesh2D(ShapePtr shape);

		Shape GetShape();

		void SetShape(ShapePtr shape);

		void DebugRender();

		void Update();

		Vector2 offset = Vector2(0, 0);

	private:

		friend class GameObject;

		ShapePtr shape;
	};

	typedef std::shared_ptr<LightMesh2D> LightMesh2DPtr;
}