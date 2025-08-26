#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class TextRenderer : public Component, public String
	{
	public:

		TextRenderer(): Component("TextRenderer")
		{
			this->str = sf::String("");
		}

        TextRenderer(const char* cstr) : Component("TextRenderer")
		{
			this->str = sf::String(cstr);
		}

		TextRenderer(const wchar_t* cstr) : Component("TextRenderer")
		{
			this->str = sf::String(cstr);
		}

		TextRenderer(std::wstring str) : Component("TextRenderer")
		{
			this->str = sf::String(str);
		}

		TextRenderer(std::string str) : Component("TextRenderer")
		{
			this->str = sf::String(str);
		}

		TextRenderer(sf::String str) : Component("TextRenderer")
		{
			this->str = str;
		}

		TextRenderer(size_t size) : Component("TextRenderer")
		{
			this->str = sf::String(std::to_string(size));
		}

		TextRenderer(bool boolean) : Component("TextRenderer")
		{
			boolean ? this->str = sf::String("true") : this->str = sf::String("false");
		}

		TextRenderer(int integer) : Component("TextRenderer")
		{
			this->str = sf::String(std::to_string(integer));
		}

		TextRenderer(long long_int) : Component("TextRenderer")
		{
			this->str = sf::String(std::to_string(long_int));
		}

		TextRenderer(double dec) : Component("TextRenderer")
		{
			this->str = sf::String(std::to_string(dec));
		}

		TextRenderer(float dec) : Component("TextRenderer")
		{
			this->str = sf::String(std::to_string(dec));
		}

		void Init();

		void Start();

		void Render();

		void Update();

		void SetNewText(String str);	

		void AddText(String str);	

        Color color = Colors::White;

        sf::Text::Style style = sf::Text::Regular;

        unsigned int fontSize = 17;

        String font = "fonts/Basic-Regular/Basic-Regular.ttf";

		Color borderColor = Colors::White;
        float borderWidth = 1.0f;

		float borderRadius = 0.0f;
        Color backgroundColor = Colors::Transparent;

		Vector2 padding = Vector2(15, 15);
		Vector2 offset = Vector2(0, 0);

	protected:

		Vector2 size;
		Vector2 boxPos;
		sfe::RichText richText;

	};

	typedef std::shared_ptr<TextRenderer> TextRendererPtr;
}