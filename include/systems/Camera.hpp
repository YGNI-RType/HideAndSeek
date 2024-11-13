/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** PlayerMotion.hpp
*/

#pragma once

#include "GEngine/libdev/systems/events/GameLoop.hpp"

#include "GEngine/interface/components/RemoteLocal.hpp"
#include "GEngine/libdev/components/Transforms.hpp"
#include "GEngine/libdev/components/Velocities.hpp"
#include "GEngine/libdev/components/driver/output/Animation.hpp"
#include "components/Player.hpp"

#include "GEngine/libdev/System.hpp"

#include "GEngine/interface/events/SharedEvent.hpp"
#include "events/Movement.hpp"
#include "events/Rotation.hpp"

namespace hs::system
{
    class PlayerMotion
        : public gengine::System<PlayerMotion, gengine::interface::component::RemoteLocal, gengine::component::Velocity3D,
                                 gengine::component::Transform3D, component::Player>
    {
    public:
        void init(void) override;
        void onGameLoop(gengine::system::event::GameLoop &);
        void movePlayer(gengine::interface::event::SharedEvent<event::Movement> &e);
        void rotatePlayer(gengine::interface::event::SharedEvent<event::Rotation> &e);
    };
} // namespace hs::system
