/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** GuessEvent.hpp
*/

#pragma once

#include "GEngine/libdev/System.hpp"

namespace hs::event
{
    struct GuessEvent : public gengine::Event
    {
        float strength;

        GuessEvent(float strength = 0.1)
            : strength(strength)
        {
        }
    };
} // namespace hs::event
