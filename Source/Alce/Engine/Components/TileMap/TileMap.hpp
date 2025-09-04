#pragma once

#include "../../Modules/Modules.hpp"

namespace alce
{
	class TileMap : public Component
	{
	public:

		TileMap();

		void Init();

		void Start();

		void Render();

		void Update();

		bool Load(String tilemap, String tileset);

	private:

		struct Layer 
		{
			String name;
			sf::VertexArray vertices;
		};

        sf::Texture tileset;
        Vector2 tileSize;
        int tilesWide = 0;
        int tilesHigh = 0;
        int tilesPerRow = 0;

        std::vector<Layer> layers;

        void BuildLayer(Json& layerJson);

	};

	typedef std::shared_ptr<TileMap> TileMapPtr;
}