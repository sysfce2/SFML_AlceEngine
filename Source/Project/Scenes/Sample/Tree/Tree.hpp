#pragma once

#include "../Sample.hpp"

using namespace alce;

namespace SampleScene
{
	class Tree : public GameObject
	{
	public:

		Tree(Vector2 position);

		void Init();

		void Start();

		void Update();

		void SetterManager(String name, String value);

		String GetterManager(String name);

	private:

		SpriteRendererPtr spriteRenderer;
		// Light2DPtr light;

		LightMesh2DPtr lightMesh;

	};
	typedef std::shared_ptr<Tree> TreePtr;
}