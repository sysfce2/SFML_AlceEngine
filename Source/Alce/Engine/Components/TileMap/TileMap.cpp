#include "TileMap.hpp"

using namespace alce;

TileMap::TileMap() : Component("TileMap")
{

}

bool TileMap::Load(String jsonFile, String tilesetFile)
{
    jsonFile = String("./Assets/" + jsonFile.ToAnsiString());
    tilesetFile = String("./Assets/" + tilesetFile.ToAnsiString());

    Json mapJson;
    if (!mapJson.FromFile(jsonFile))
    {
        Debug.Warning("TileMap: cannot load JSON file {}", { jsonFile });
        return false;
    }

    tileSize = Vector2(mapJson.Get("tilewidth").ParseInt(), mapJson.Get("tileheight").ParseInt());
    tilesWide = mapJson.Get("tileswide").ParseInt();
    tilesHigh = mapJson.Get("tileshigh").ParseInt();
    tilesPerRow = 8; 

    if (!tileset.loadFromFile(tilesetFile.ToAnsiString()))
    {
        Debug.Warning("TileMap: cannot load tileset {}", {tilesetFile});
        return false;
    }

    tileset.setSmooth(false);

    auto layersJson = mapJson.GetJsonList("layers");
    for (auto& layerJson : layersJson)
    {
        BuildLayer(layerJson);
    }

    return true;
}

void TileMap::BuildLayer(Json& layerJson)
{
    Layer layer;
    layer.name = layerJson.Get("name");
    auto tilesJson = layerJson.GetJsonList("tiles");

    layer.vertices.setPrimitiveType(sf::Quads);
    layer.vertices.resize(tilesJson.Length() * 4);

    for (int i = 0; i < tilesJson.Length(); i++)
    {
        auto tileJson = tilesJson[i];

        int tileIndex = tileJson.Get("tile").ParseInt();
        if (tileIndex == -1) continue; 

        int x = tileJson.Get("x").ParseInt();
        int y = tileJson.Get("y").ParseInt();
        bool flipX = tileJson.Get("flipX").ParseBoolean();
        int rot = tileJson.Get("rot").ParseInt();

        //screen positions
        float px = x * tileSize.x;
        float py = y * tileSize.y;

        sf::Vertex* quad = &layer.vertices[i * 4];
        quad[0].position = sf::Vector2f(px, py);
        quad[1].position = sf::Vector2f(px + tileSize.x, py);
        quad[2].position = sf::Vector2f(px + tileSize.x, py + tileSize.y);
        quad[3].position = sf::Vector2f(px, py + tileSize.y);

        //atlas coords
        int tu = tileIndex % tilesPerRow;
        int tv = tileIndex / tilesPerRow;

        float tx = tu * tileSize.x;
        float ty = tv * tileSize.y;

        sf::Vector2f tex[4] = {
            {tx, ty},
            {tx + tileSize.x, ty},
            {tx + tileSize.x, ty + tileSize.y},
            {tx, ty + tileSize.y}
        };

        //horizontal flip 
        if (flipX)
        {
            std::swap(tex[0], tex[1]);
            std::swap(tex[3], tex[2]);
        }

        //Rotation in multiples of 90 degrees
        int r = (rot / 90) % 4;
        for (int k = 0; k < r; k++)
        {
            auto tmp = tex[0];
            tex[0] = tex[3];
            tex[3] = tex[2];
            tex[2] = tex[1];
            tex[1] = tmp;
        }

        //Assign texCoords with anti-bleeding offset
        float offset = 0.1f;
        quad[0].texCoords = tex[0] + sf::Vector2f(offset, offset);
        quad[1].texCoords = tex[1] + sf::Vector2f(-offset, offset);
        quad[2].texCoords = tex[2] + sf::Vector2f(-offset, -offset);
        quad[3].texCoords = tex[3] + sf::Vector2f(offset, -offset);
    }

    layers.push_back(layer);
}

void TileMap::Init()
{
    if (transform == nullptr)
    {
        Debug.Warning("TileMap has no associated GameObject");
    }
}

void TileMap::Start()
{
    if (transform == nullptr)
    {
        Debug.Warning("TileMap has no associated GameObject");
    }
}

void TileMap::Update()
{
    
}

void TileMap::Render()
{
    if (transform == nullptr) return;

    sf::Transform t;
    t.translate(transform->position.ToPixels().ToVector2f());
    t.rotate(transform->rotation);
    t.scale((transform->scale + scale).ToVector2f());

    sf::RenderStates states;
    states.transform = t;
    states.texture = &tileset;

    for (auto& layer : layers)
    {
        Alce.GetWindow().draw(layer.vertices, states);
    }
}