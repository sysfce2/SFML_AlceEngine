#pragma once

#include "../Otra.hpp"

using namespace alce;

namespace OtraScene
{
	class Cosa : public GameObject
	{
	public:

		Cosa();

		void Init();

		void Start();

		void Update();

		void SetterManager(String name, String value);

		String GetterManager(String name);

	private:
		CameraPtr camera;		
		SpriteRendererPtr spriteRenderer;

	};

	typedef std::shared_ptr<Cosa> CosaPtr;
}