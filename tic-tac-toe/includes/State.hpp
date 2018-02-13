#pragma once

namespace game
{
    class State
    {
    public:
        virtual void init() = 0;
        virtual void handle_input() = 0;
        virtual void update(float dt) = 0;
        virtual void draw(float dt) = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
    };
}