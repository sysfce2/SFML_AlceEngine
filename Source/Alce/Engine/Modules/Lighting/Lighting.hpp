#pragma once

#include "../../../Libs/Libs.hpp"
#include "../Collections/Collections.hpp"
#include "../Math/Math.hpp"
#include "../Debug/Debug.hpp"

namespace alce
{
    class LightingSystem
    {
    private:

        friend class GameObject;
        friend class Scene;

        candle::EdgeVector GenerateEdgesFromShape(ShapePtr shape);

        void Cast();
        
        candle::EdgeVector edgePool;
        List<std::shared_ptr<candle::LightSource>> lights;
        List<ShapePtr> shapes;
    };
}