/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** Crouch.hpp
*/

#pragma once

#include "GEngine/libdev/System.hpp"

namespace hs::event {
struct Crouch : public gengine::Event {
    bool crouching;

    Crouch(bool crouching = false)
        : crouching(crouching) {
    }
};
} // namespace hs::event
