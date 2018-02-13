#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

namespace game
{
    typedef std::unique_ptr<State> StateRef;

    class StateMachine
    {
    public:
        StateMachine();
        ~StateMachine();

        void add_state(StateRef new_state, bool is_replacing = true);
        void remove_state();

        void process_state_changes();

        StateRef &get_active_state();

    private:
        std::stack<StateRef> _states;
        StateRef _new_state;

        bool _is_removing;
        bool _is_adding;
        bool _is_replacing;
    };
}