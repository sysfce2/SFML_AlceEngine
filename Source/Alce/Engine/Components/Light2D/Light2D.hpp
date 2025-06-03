#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class Light2D : public Component
	{
	public:

		enum class Type { Radial, Directed };

		Light2D(Type type = Type::Radial);

		void SetIntensity(float intensity);

		void SetColor(Color color);

		void SetFade(bool fade = true);

		void SetRange(float range);

		void Init();

		void Start();

		void Render();

		void Update();

	private: 
		
		friend class GameObject;

		Type lightType;
		std::shared_ptr<candle::LightSource> light;

		float range;

	};

	typedef std::shared_ptr<Light2D> Light2DPtr;
}