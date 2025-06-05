#pragma once

#include "../../Modules/Core/Core.hpp"

namespace alce
{
	class LightMesh2D : public Component
	{
	public:

		LightMesh2D(ShapePtr shape);

		Shape GetShape();

		void SetShape(ShapePtr shape);

		void Init();

		void Start();

		void Render();

		void Update();

	private:

		friend class GameObject;

		ShapePtr shape;

	};

	typedef std::shared_ptr<LightMesh2D> LightMesh2DPtr;
}