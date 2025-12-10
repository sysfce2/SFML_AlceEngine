<p align="center">
<img src="./Build/Assets/logo.png">
</p>

<h1 align="center">Alce Game Engine</h1>

<p align="center">
<img src="https://img.shields.io/badge/C++-20-00599C?style=flat-square&logo=c%2B%2B">
<img src="https://img.shields.io/badge/SFML-v2.6.1-8CC445?logo=SFML&style=flat-square">
<a href="LICENSE"><img src="https://img.shields.io/badge/license-MIT-informational?style=flat-square"/></a>
</p>

Alce Game Engine is a game engine based on SFML and Box2D, designed to simplify the development of 2D games. Its primary goal is to provide a comprehensive suite of tools and components that streamline the creation process. From physics simulations and animations to user interface management and local storage.

# 📰 News and Updates

> [🌐 See full page here](Documentation/News/News.md)

### > (6/9/2025) TileMap Component Released

The new TileMap component is now available. It lets you render tile-based maps exported from PyxelEdit directly on a GameObject, handling tilesets, layers, flips, and rotations automatically, while keeping the map centered on the object’s transform and updating its bounding corners for efficient scene culling. Perfect for creating levels, backgrounds, or any grid-based environment.

[📖 TileMap documentation](Source/Alce/Engine/Components/TileMap/TileMap.md)

### > (24/8/2025) TextRenderer Component Released

The new TextRenderer component is now available. It allows you to render styled text directly in the game world, with support for formatting, colors, backgrounds, and borders. Useful for names, dialogue, or any text that should exist as part of the scene rather than the UI.

[📖 TextRenderer documentation](Source/Alce/Engine/Components/TextRenderer/TextRenderer.md)

### > (3/8/2025) Candle Lighting Now Available in AlceEngine

We're excited to introduce a new integration of Candle into AlceEngine, bringing advanced 2D lighting capabilities to your SFML projects. This implementation includes support for radial and directional lights, fog-based lighting areas, and custom light meshes with support for rectangular, circular, and polygonal shapes. 

Designed to be modular and easy to use within the AlceEngine's component system, this integration enables dynamic lighting effects, real-time intensity control, and debug visualizations to streamline your workflow.

# 📖 Documentation

> ⚠️ Documentation effort is still in progress.

AlceEngine provides structured and comprehensive documentation for every component, method, and feature, making it easy for developers to understand, integrate, and utilize the engine’s functionality efficiently. Each part of the engine is clearly explained, ensuring that users can quickly find the information they need without confusion.

> [🌐 Check out the full documentation here.](https://github.com/Ekrol34/AlceEngine/wiki)

# ⌨️ Contributing

Alce Engine is completely open to new contributors. We welcome fresh ideas, feature proposals, bug reports, and code improvements from anyone interested. Whether you want to fix a small issue, suggest a new component, or take on a bigger task, your input and participation are highly valued and encouraged.

> [Check out the TODO list](Documentation/TODO/EN.txt)

# 🧾 Features

### 🧩 Components:

* [Animation2d](Source/Alce/Engine/Components/Animation2d/Animation2D.md): handles 2D sprite sheet animations, allowing you to define, play, and control animations with different playback modes, frame timing, and origins. It also updates cardinal positions for spatial references.

* [Camera](Source/Alce/Engine/Components/Camera/Camera.md): defines a 2D camera that controls the visible area of the scene, supporting zoom, viewport configuration, and smooth following of its associated game object's position and rotation.

* <img src="https://box2d.org/images/logo.svg" style="width: 23px; position: relative; top: 1px"> [ParticleSystem](Source/Alce/Engine/Components/ParticleSystem/ParticleSystem.md): manages a 2D particle system that emits physics-based particles from a defined area, applying customizable behaviors, collisions, and lifetimes to simulate effects like explosions, smoke, or sparks.

* <img src="https://box2d.org/images/logo.svg" style="width: 23px; position: relative; top: 1px"> [Raycast2d](Source/Alce/Engine/Components/Raycast2d/Raycast2D.md): performs 2D raycasting to detect collisions along a direction and length, triggering impact events when objects are hit or no longer hit.

* <img src="https://box2d.org/images/logo.svg" style="width: 23px; position: relative; top: 1px"> [Rigidbody2d](Source/Alce/Engine/Components/Rigidbody2d/Rigidbody2D.md): manages the 2D physics simulation of an object using Box2D, allowing the creation of rigid bodies with different shapes, applying forces and impulses, configuring physical properties (such as friction, density, or restitution), and synchronizing their position and rotation with the engine's transform system.

* [SpriteRenderer](Source/Alce/Engine/Components/SpriteRenderer/SpriteRenderer.md): renders a 2D sprite using a texture, allowing you to load, assign, and manage multiple textures, while also updating its position, scale, rotation, and cardinal points based on the associated game object's transform.

* <img src="https://raw.githubusercontent.com/MiguelMJ/Candle/master/doc/logo.svg" style="width: 19px; position: relative; top: 2px"> [Light2D](Source/Alce/Engine/Components/Light2D/Light2D.md): defines a 2D light source (either radial or directional) that can be positioned, colored, and configured with parameters like range, intensity, beam width, and angle, to simulate dynamic lighting effects in a 2D environment.

* <img src="https://raw.githubusercontent.com/MiguelMJ/Candle/master/doc/logo.svg" style="width: 19px; position: relative; top: 2px"> [LightMesh2D](Source/Alce/Engine/Components/LightMesh2D/LightMesh2D.md):  represents a 2D shape used as a light-blocking or light-interacting mesh, allowing you to define custom geometry (rectangle, circle, or polygon) that updates with the object's transform and can be visualized in debug mode.

* <img src="https://raw.githubusercontent.com/MiguelMJ/Candle/master/doc/logo.svg" style="width: 19px; position: relative; top: 2px"> [LightingArea2D](Source/Alce/Engine/Components/LightingArea2D/LightingArea2D.md): defines and manages a 2D lighting area that can render fog-like effects, adjusting its size, position offset, color, and opacity dynamically within a game or graphical application.

* <img src="https://pyxeledit.com/images/icon256.png" style="width: 18px; position: relative; top: 2px"> [TileMap](Source/Alce/Engine/Components/TileMap/TileMap.md): renders a [PyxelEdit](https://pyxeledit.com/)-exported JSON tilemap on a GameObject, slicing the tileset, handling flips and rotations, centering on the transform, applying scale and offset, and updating its bounding corners for efficient scene culling.

* [TextRenderer](Source/Alce/Engine/Components/TextRenderer/TextRenderer.md): renders styled text directly in the game world, supporting formatting, colors, and optional backgrounds with borders.

### 📦 Modules:

* [Core](Source/Alce/Engine/Modules/Core/): manages window creation, scene management, asset loading (textures, sounds, fonts), system info retrieval, input handling, and the main game loop for a graphical application using SFML.

* [Audio](Source/Alce/Engine/Modules/Audio/Audio.md): manages audio playback by organizing sounds into channels, allowing loading, controlling (play, pause, stop), and adjusting sound properties (volume, pitch, looping) within each channel.

* [Storage](Source/Alce/Engine/Modules/Storage/Storage.md): manages persistent JSON-based data storage by dynamically mapping named entries to multiple segmented files, ensuring size limits are respected and providing methods to set, get, delete, and clear stored data.

* [Chrono](Source/Alce/Engine/Modules/Chrono/Chrono.md): implements a Time class that stores time internally in milliseconds and provides methods and operators to add, subtract, convert, compare, and reset time values with validation against negative inputs.

* [Debug](Source/Alce/Engine/Modules/Debug/Debug.md): provides a DEBUG utility for formatted console logging with color-coded message types (info, warning, ARL messages/errors), optional asynchronous file persistence, and rate-limiting based on elapsed time.

* [Input](Source/Alce/Engine/Modules/Input/Input.md): handles input detection and state tracking for keyboard, mouse, and joystick devices, including button presses, button downs (edge detection), axis values, mouse position, and joystick connectivity, with an enable/disable control.

* [Math](Source/Alce/Engine/Modules/Math/):  provides mathematical utilities, random number generation, 2D vector operations, and shape classes (rectangle, polygon, circle) with geometry-related functions and conversions.

* [Color](Source/Alce/Engine/Modules/Color/Color.md): Wrapper class for SFML's sf::Color providing multiple constructors and setters for RGB, RGBA, hex and string formats, color blending, conversions, and predefined common colors with error handling and string parsing utilities in C++.

### 🛠️ Utils:

* [Collections](Source/Alce/Engine/Modules/Collections/Collections.md): provides a collection of generic, exception-safe container classes—including a customizable List with advanced manipulation and filtering capabilities, a Pair utility, and a Dictionary implemented on top of the List—designed to facilitate flexible and efficient data storage and retrieval.

* [String](Source/Alce/Engine/Modules/String/): versatile String class wrapping SFML’s string type, offering extensive manipulation methods such as substring operations, case conversion, comment removal, parsing to various data types, trimming, splitting, regex matching, and comprehensive operator overloads for flexible and efficient string handling in C++.

* [Json](Source/Alce/Engine/Modules/Json/Json): JSON wrapper class for C++ using RapidJSON, providing methods to parse from strings or files, get/set JSON values (strings, nested JSON, lists), check keys, delete or clear members, validate JSON, and serialize back to formatted strings or save as files — with exception handling for type errors and missing keys.

* [FileSystem](Source/Alce/Engine/Modules/FileSystem/FileSystem.md): File and Folder management wrapper using C++17 std::filesystem, providing methods to create, delete, read, write, append, and clear files, check existence of files and folders, and handle paths as absolute strings with exception handling for invalid operations.

### 📇 UIElements (User Interface):

* [Animation](Source/Alce/Engine/UI/Animation/Animation.md): component handles 2D spritesheet-based animations for a UI or game element. Animations can loop, play only once, or remain on the first frame.

* [Button](Source/Alce/Engine/UI/Button/): represents an interactive UI element that can display text, respond to mouse events, and trigger custom callbacks on click, mouse enter, or mouse exit.

* [Image](Source/Alce/Engine/UI/Image/): represents a UI element that can display and manage multiple textures, allowing dynamic switching and rendering of images with adjustable origin offsets.

* [Text](Source/Alce/Engine/UI/Text/Text.md): represents a UI element that displays customizable text, allowing you to set color, font, size, style, borders, and background, with support for initialization from various data types.

* [TextInput](Source/Alce/Engine/UI/TextInput/): represents a UI element that allows users to enter and edit text, featuring customizable appearance, placeholder text, cursor behavior, font size, and an onSubmit callback for handling input events.

### ⚙️CLI:

* [Alce CLI](Documentation/CLI/cli.md): prompt program designed to compile, generate and run Alce projects. Perfect if you dont want to install a complete C++ environment like Visual Studio or Code::Blocks.

* [ARL](Documentation/ARL/ARL.md): the in-game development prompt language. Allows the developer to make a lot of repetitive debug stuff without the need of being compiling constantly.

# 💻 Setup

Learn how to set up Alce Engine with ease through [this tutorial](./Documentation/Tutorials/setup.md).

Once installed, you can compile and run your project using the [CLI](Documentation/CLI/cli.md):

#### 1. Go to the build folder
```bash
cd build
```

#### 2. Initialize the project (only once)
```bash
./alce init
```

#### 2. Compile your build
```bash
./alce compile alias=dev
```

#### 3. Run the game
```bash
./alce run alias=dev
``` 

# 📋 Requirements

Minimun requirements:
* GCC 32bit v13.1.0^ (g++, mingw32-make, gdb)
* Windows 10, 11
* Python v3.1.0^

Recommended:

* <img src="https://pyxeledit.com/images/icon256.png" style="width: 18px; position: relative; top: 2px"> [PyxelEdit](https://pyxeledit.com/)

# ☎️ Contact

For any professional inquiries, please contact me at gabrielbeguren@outlook.com. If you wish to contribute ideas or report any bugs, feel free to use the tools that GitHub provides.

# External Libraries used by Alce Engine

* <img src="https://www.sfml-dev.org/images/favicon.ico" style="width: 18px; position: relative; top: 2px"> [SFML](https://github.com/SFML/SFML) under the [ZLIB license](https://github.com/SFML/SFML?tab=Zlib-1-ov-file#readme)
* <img src="https://box2d.org/images/logo.svg" style="width: 23px; position: relative; top: 1px"> [Box2d](https://github.com/erincatto/box2d) under the [MIT license](https://github.com/erincatto/box2d?tab=MIT-1-ov-file#readme)
* <img src="https://raw.githubusercontent.com/MiguelMJ/Candle/master/doc/logo.svg" style="width: 19px; position: relative; top: 2px"> [Candle](https://github.com/MiguelMJ/Candle) under the [MIT license](https://github.com/MiguelMJ/Candle?tab=MIT-1-ov-file#readme)
* <img src="https://github.com/fluidicon.png" style="width: 20px; position: relative; top: 3px"> [RichText](https://github.com/skyrpex/RichText) under [public domain](https://github.com/skyrpex/RichText?tab=License-1-ov-file#readme)
* <img src="https://raw.githubusercontent.com/Tencent/rapidjson/master/doc/logo/rapidjson.png" style="width: 60px; position: relative; top: 3px"> [rapidjson](https://github.com/Tencent/rapidjson) under the [MIT license](https://github.com/Tencent/rapidjson?tab=License-1-ov-file#readme)
