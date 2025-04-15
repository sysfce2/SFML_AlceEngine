#pragma once

#include "../CLITest.hpp"

using namespace alce;

namespace CLITestScene
{
	class Test : public GameObject
	{
	public:

		Test();

		void Init();

		void Start();

		void Update();

		void SetterManager(String name, String value);

		String GetterManager(String name);

	private:

		int hp;

		String nombre;

	};

	typedef std::shared_ptr<Test> TestPtr;
}