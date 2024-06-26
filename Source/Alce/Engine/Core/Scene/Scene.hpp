#pragma once

#include <memory>

#include "../../../Libs/Libs.hpp"
#include "../GameObject/GameObject.hpp"
#include "../Chrono/Chrono.hpp"
#include "../B2World/B2World.hpp"
#include "../Interface/Interface.hpp"

namespace alce
{
    typedef std::shared_ptr<List<GameObjectPtr>> GameObjectListPtr;

    class Scene : public Object
    {
    public:

        Scene(String name);

        void InitPhysics(Vector2 gravity);

        void AddGameObject(GameObjectPtr gameObject);

        List<GameObjectPtr> GetAllGameObjects();

        void AddCanvas(CanvasPtr canvasPtr, ComponentPtr camera);

        String GetName();

        void Pause(bool flag = true);

        bool IsPaused();

        void Clear();

        B2WorldPtr GetWorld();

        void DebugMode(bool flag = true);

        virtual void Init()
        {
            
        }

        virtual void Start()
        {
            
        }

    private:

        friend class KERNEL;
        friend class GameObject;
        
        B2WorldPtr world = nullptr;

        String name;
        Dictionary<int, GameObjectListPtr> sortingLayers;
        List<CanvasPtr> canvasList;
        List<Object*> cameras;
        bool paused = false;
        bool debugMode = false;

        List<candle::LightingArea> lightningAreas;

        void EventsManager(sf::Event& e);

        void Render();

        void Update();

        void SetCardinals(GameObjectPtr gameObject, Dictionary<String, Vector2Ptr> cardinals);

        void RenderGrid(sf::RenderWindow& window, const sf::View& view);
    };

    typedef std::shared_ptr<Scene> ScenePtr;
}