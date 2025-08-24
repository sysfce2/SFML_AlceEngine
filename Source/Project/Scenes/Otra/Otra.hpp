#pragma once

#include "../../../Alce/Alce.hpp"

using namespace alce;

namespace OtraScene
{
	class Otra : public Scene
	{
	public:

		Otra();

		void Init();

		void Start();

	};

	typedef std::shared_ptr<Otra> OtraPtr;
}