/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** LockPlayerEvent.hpp
*/

#pragma once

#include "GEngine/libdev/System.hpp"

namespace hs::event
{
    struct LockPlayerEvent : public gengine::Event
    {
        bool locked;

        LockPlayerEvent(bool locked)
            : locked(locked)
        {
        }
    };
} // namespace hs::event
