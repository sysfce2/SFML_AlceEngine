#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class LightingArea : public Component
	{
	public:

		LightingArea(RectShapePtr bounds);

		void Init();

		void Start();

		void Render();

		void Update();

	private:

		RectShapePtr rect;

	};

	typedef std::shared_ptr<LightingArea> LightingAreaPtr;
}