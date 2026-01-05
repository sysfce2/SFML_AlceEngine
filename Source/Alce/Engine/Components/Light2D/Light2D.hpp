#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class Light2D : public Component
	{
	public:

		enum class Type { Radial, Directed };

		Light2D(Type type = Type::Radial);

		void SetFade(bool fade = true);

		bool IsFading();

		void SetRange(float range);

		float GetRange();

		void SetBeamWidth(float width);

		float GetBeamWidth();

		void SetBeamAngle(float angle);

		float GetBeamAngle();

		void SetIntensity(float intensity);

		float GetIntensity();

		void Init();

		void Start();

		void Render();

		void Update();

		Color color = Colors::White;

	private: 
		
		friend class GameObject;
		friend class LightingSystem;
		friend class ParticleSystem;

		Type lightType;
		std::shared_ptr<candle::LightSource> light;

		float intensity = 0.5;

		float range;
		float beamWidth;
		float beamAngle;

	};

	typedef std::shared_ptr<Light2D> Light2DPtr;
}