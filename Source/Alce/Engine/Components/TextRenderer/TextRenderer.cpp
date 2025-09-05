#include "TextRenderer.hpp"

using namespace alce;

void TextRenderer::SetNewText(String str)
{
    this->str = str.ToSFMLString();
}   

void TextRenderer::AddText(String str)
{
    this->str += str.ToSFMLString();
}   

Dictionary<String, Vector2Ptr> TextRenderer::GetCardinals()
{
    return cardinals;
}

void TextRenderer::Init()
{
    
}

void TextRenderer::Start()
{
	
}

void TextRenderer::Render()
{
    if (borderRadius > 0)
    {
        int totalPoints = CIRCLE_QUALITY * 4;
        sf::ConvexShape roundedBox;
        roundedBox.setPointCount(totalPoints);

        float angleStep = 90.f / CIRCLE_QUALITY;
        int pointIndex = 0;

        auto addCorner = [&](float cx, float cy, float startAngle) {
            for (int i = 0; i < CIRCLE_QUALITY; ++i, ++pointIndex)
            {
                float angle = startAngle + i * angleStep;
                float rad = angle * (3.14159f / 180.f);
                float x = cx + borderRadius * cos(rad);
                float y = cy + borderRadius * sin(rad);
                roundedBox.setPoint(pointIndex, sf::Vector2f(x, y));
            }
        };

        addCorner(size.x - borderRadius, borderRadius, -90);
        addCorner(size.x - borderRadius, size.y - borderRadius, 0);
        addCorner(borderRadius, size.y - borderRadius, 90);
        addCorner(borderRadius, borderRadius, 180);

        roundedBox.setPosition(boxPos.ToVector2f());
        roundedBox.setFillColor(backgroundColor.ToSFMLColor());
        roundedBox.setOutlineThickness(borderWidth);
        roundedBox.setOutlineColor(borderColor.ToSFMLColor());

        Alce.GetWindow().draw(roundedBox);
    }
    else 
    {
        sf::RectangleShape border;
        border.setPosition(boxPos.ToVector2f());           
        border.setSize(size.ToVector2f());                
        border.setOutlineThickness(borderWidth);
        border.setOutlineColor(borderColor.ToSFMLColor());
        border.setFillColor(backgroundColor.ToSFMLColor());
        
        Alce.GetWindow().draw(border);
    }

    Alce.GetWindow().draw(richText);
}

void TextRenderer::Update()
{
    if (!enabled || transform == nullptr) return;

    // reconstruir richText
    richText = sfe::RichText(*Alce.GetFont(font).get());
    richText.setCharacterSize(fontSize);

    std::string text = ToAnsiString();  

    std::regex tagRegex(R"(<(\/?)([a-zA-Z]+)(?:='([^']+)')?>)");
    std::stack<sf::Text::Style> styleStack;
    std::stack<sf::Color> colorStack;
    sf::Text::Style currentStyle = sf::Text::Regular;
    sf::Color currentColor = color.ToSFMLColor();

    bool isBold = false, isItalic = false, isUnderlined = false, isStrikeThrough = false;

    std::sregex_iterator iter(text.begin(), text.end(), tagRegex);
    std::sregex_iterator end;
    std::size_t lastPos = 0;

    for (; iter != end; ++iter) 
    {
        auto match = *iter;
        std::string tag = match[2].str();
        bool isClosingTag = match[1].str() == "/";
        std::string tagValue = match[3].str();
        std::size_t pos = match.position();

        if (pos > lastPos) 
        {
            currentStyle = sf::Text::Regular;
            if (isBold) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Bold);
            if (isItalic) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Italic);
            if (isUnderlined) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Underlined);
            if (isStrikeThrough) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::StrikeThrough);

            richText << currentColor << currentStyle 
                     << sf::String::fromUtf8(text.begin() + lastPos, text.begin() + pos);
        }

        if (!isClosingTag) 
        {
            if (tag == "bold") { styleStack.push(currentStyle); isBold = true; }
            else if (tag == "italic") { styleStack.push(currentStyle); isItalic = true; }
            else if (tag == "underlined") { styleStack.push(currentStyle); isUnderlined = true; }
            else if (tag == "strikeThrough") { styleStack.push(currentStyle); isStrikeThrough = true; }
            else if (tag == "color") { colorStack.push(currentColor); currentColor = MapColorFromString(tagValue); }
        } 
        else 
        {
            if (tag == "bold") { currentStyle = styleStack.top(); styleStack.pop(); isBold = false; }
            else if (tag == "italic") { currentStyle = styleStack.top(); styleStack.pop(); isItalic = false; }
            else if (tag == "underlined") { currentStyle = styleStack.top(); styleStack.pop(); isUnderlined = false; }
            else if (tag == "strikeThrough") { currentStyle = styleStack.top(); styleStack.pop(); isStrikeThrough = false; }
            else if (tag == "color") { currentColor = colorStack.top(); colorStack.pop(); }
        }

        lastPos = pos + match.length();
    }

    if (lastPos < text.size()) 
    {
        currentStyle = sf::Text::Regular;
        if (isBold) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Bold);
        if (isItalic) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Italic);
        if (isUnderlined) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::Underlined);
        if (isStrikeThrough) currentStyle = static_cast<sf::Text::Style>(currentStyle | sf::Text::StrikeThrough);

        richText << currentColor << currentStyle 
                 << sf::String::fromUtf8(text.begin() + lastPos, text.end());
    }
    else if (lastPos == 0 && !text.empty())
    {
        richText << currentColor << currentStyle 
                 << sf::String::fromUtf8(text.begin(), text.end());
    }

    // Bounding box del texto
    size = Vector2(richText.getGlobalBounds().width, richText.getGlobalBounds().height);
    size += (padding * 2);

    Vector2 centerPos = transform->position.ToPixels() + offset;

    // La esquina superior izquierda del box
    boxPos = centerPos - (size / 2.0f);

    sf::FloatRect textBounds = richText.getLocalBounds();
    sf::Vector2f boxSize(size.x, size.y);

    // Centrar richText dentro del box
    float textX = centerPos.x - textBounds.width / 2.f - textBounds.left;
    float textY = centerPos.y - textBounds.height / 2.f - textBounds.top;

    richText.setPosition(textX, textY);
    richText.setRotation(transform->rotation);

    // ==== CARDINALES ====
    float halfW = size.x / 2.f;
    float halfH = size.y / 2.f;

    cardinals["top-left"]->x = centerPos.x - halfW;
    cardinals["top-left"]->y = centerPos.y - halfH;

    cardinals["top-right"]->x = centerPos.x + halfW;
    cardinals["top-right"]->y = centerPos.y - halfH;

    cardinals["bottom-left"]->x = centerPos.x - halfW;
    cardinals["bottom-left"]->y = centerPos.y + halfH;

    cardinals["bottom-right"]->x = centerPos.x + halfW;
    cardinals["bottom-right"]->y = centerPos.y + halfH;
}
