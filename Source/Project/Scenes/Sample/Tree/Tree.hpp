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

	private:

		SpriteRendererPtr spriteRenderer;
		Light2DPtr light;

	};
	typedef std::shared_ptr<Tree> TreePtr;
}