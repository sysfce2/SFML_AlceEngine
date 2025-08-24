# 🧩 TextRenderer
The ```TextRenderer``` component provides styled text rendering capabilities for a GameObject.
It supports rich text formatting (bold, italic, underline, strike-through, and inline colors), optional background boxes with borders and rounded corners, and automatic alignment inside its bounding box.

Unlike raw SFML ```sf::Text```, ```TextRenderer``` integrates directly with the engine’s component system and synchronizes its position with the owning ```GameObject```’s Transform.

## Behaviour

The ```TextRenderer``` component handles the full pipeline of displaying text inside the game window:

It parses the assigned string for inline tags (```<bold>```, ```<italic>```, ```<underlined>```, ```<strikeThrough>```, ```<color>```), applying the appropriate ```sf::Text::Style``` and ```sf::Color```.

It automatically calculates the text bounds, adds padding, and computes the final size of the background box.

If ```borderRadius > 0```, the background is drawn as a rounded rectangle; otherwise, a standard rectangle with optional border thickness is drawn.

The text is then centered inside this box, positioned relative to the ```GameObject```’s transform.

By default, TextRenderer does not apply scaling from the Transform, since text size is controlled by the font size.

### ⚠️ Important notes:

> TextRenderer ignores transform scaling.

> The background box always uses the calculated size (text width + padding). If you want transparent backgrounds, set backgroundColor to transparent.

> If tags are malformed (e.g., unclosed ```<bold>```), text may render partially without the intended style.

# Parameters

* ```String text```: The UTF-8 encoded text to display. Supports inline formatting tags.

* ```Color color```: Default text color (before applying <color> tags).

* ```int fontSize```: Character size in pixels.

* ```String font```: The font resource key used to retrieve the SFML font from the engine.

* ```Vector2 padding```: Horizontal and vertical padding around the text inside the background box.

* ```float borderWidth```: Thickness of the box outline (0 = no outline).

* ```Color borderColor```: Outline color of the box.

* ```Color backgroundColor```: Fill color of the box.

* ```float borderRadius```: Corner roundness. If > 0, the box is drawn with rounded corners.

* ```Vector2 size```: Final computed size of the text box (auto-updated each frame).

## Constructors

### Default Constructor
```cpp
TextRenderer()
```

Creates a new TextRenderer component. Font and text must be assigned before rendering.

## Example Usage
```cpp
auto text = gameObject->AddComponent<TextRenderer>();
text->font = "Arial";
text->fontSize = 24;
text->color = Color::White;
text->padding = Vector2(8, 4);
text->backgroundColor = Color::Black.WithAlpha(128);
text->borderWidth = 2;
text->borderColor = Color::Yellow;

// Supports inline styling
text->SetText("Hello <bold>World</bold>! <color='red'>Red text</color>");
```


This will render:

* A semi-transparent black box with yellow outline.

* The word "World" in bold.

* The words "Red text" in red.