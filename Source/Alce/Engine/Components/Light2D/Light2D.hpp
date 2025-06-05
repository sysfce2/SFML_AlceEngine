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

		float GetIntensity();

		void SetColor(Color color);

		Color GetColor();

		void SetFade(bool fade = true);

		bool IsFading();

		void SetRange(float range);

		float GetRange();

		void SetBeamWidth(float width);

		float GetBeamWidth();

		void SetBeamAngle(float angle);

		float GetBeamAngle();

		void Init();

		void Start();

		void Render();

		void Update();

	private: 
		
		friend class GameObject;
		friend class LightingSystem;

		Type lightType;
		std::shared_ptr<candle::LightSource> light;

		float range;
		float beamWidth;
		float beamAngle;

	};

	typedef std::shared_ptr<Light2D> Light2DPtr;
}