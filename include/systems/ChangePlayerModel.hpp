/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** ChangePlayerModel.hpp
*/

#pragma once

#include "GEngine/interface/components/RemoteLocal.hpp"
#include "GEngine/libdev/components/driver/output/Animation.hpp"
#include "GEngine/libdev/components/driver/output/Model.hpp"
#include "components/Player.hpp"

#include "GEngine/libdev/Components.hpp"
#include "GEngine/libdev/System.hpp"

#include "GEngine/interface/events/SharedEvent.hpp"

#include "events/ChangePlayerModelEvent.hpp"

namespace hs::system
{
    class ChangePlayerModel : public gengine::System<ChangePlayerModel, gengine::interface::component::RemoteLocal,
                                                     geg::component::io::Animation, geg::component::Transform3D,
                                                     gengine::component::driver::output::Model, component::Player>
    {
    public:
        void init(void) override;

        void changePlayerModel(gengine::interface::event::SharedEvent<event::ChangePlayerModelEvent> &e);
    };
} // namespace hs::system
