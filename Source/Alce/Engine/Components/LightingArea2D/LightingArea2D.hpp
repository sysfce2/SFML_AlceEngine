#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class LightingArea2D : public Component
	{
	public:

		LightingArea2D(ShapePtr shape);

		void SetShape(ShapePtr shape);

		void Init();

		void Start();

		void Render();

		void DebugRender();

		void Update();

		Vector2 offset = Vector2(0, 0);

		Color color = Colors::Black;

		void Compute()
		{
			this->compute = true;
		}

	private:

		friend class GameObject;
		friend class LightingSystem;

		ShapePtr shape;

		bool compute = false;

		float opacity = 1.0f;

		std::shared_ptr<candle::LightingArea> lightingArea = nullptr;

		List<std::shared_ptr<candle::LightSource>> lights;

	};

	typedef std::shared_ptr<LightingArea2D> LightingArea2DPtr;
}