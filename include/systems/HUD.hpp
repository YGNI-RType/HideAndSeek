
/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** Init.hpp
*/

#pragma once

#include "GEngine/libdev/Events.hpp"
#include "GEngine/libdev/System.hpp"
#include "GEngine/libdev/Systems.hpp"

#include "GEngine/libdev/Components.hpp"

#include <raylib.h>

namespace hs::system
{
    class Crossair : public gengine::OnEventSystem<Crossair, gengine::system::event::StartEngine>,
                     public gengine::LocalSystem
    {
    public:
        void onEvent(gengine::system::event::StartEngine &e);
    };
} // namespace hs::system
