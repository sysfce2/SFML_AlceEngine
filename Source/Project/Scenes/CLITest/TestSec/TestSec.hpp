#pragma once

#include "../CLITest.hpp"

using namespace alce;

namespace CLITestScene
{
	class TestSec : public GameObject
	{
	public:

		TestSec();

		void Init();

		void Start();

		void Update();

		void SetterManager(String name, String value);

		String GetterManager(String name);

	};

	typedef std::shared_ptr<TestSec> TestSecPtr;
}