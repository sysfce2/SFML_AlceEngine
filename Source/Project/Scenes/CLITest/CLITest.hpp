#pragma once

#include "../../../Alce/Alce.hpp"

using namespace alce;

namespace CLITestScene
{
	class CLITest : public Scene
	{
	public:

		CLITest();

		void Init();

		void Start();

	};

	typedef std::shared_ptr<CLITest> CLITestPtr;
}