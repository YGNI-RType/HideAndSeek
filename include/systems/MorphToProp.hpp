/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** MorphToProp.hpp
*/

#pragma once

#include "GEngine/interface/components/RemoteLocal.hpp"
#include "GEngine/libdev/components/Transforms.hpp"
#include "GEngine/libdev/components/driver/output/Model.hpp"
#include "components/Player.hpp"
#include "components/Prop.hpp"

#include "GEngine/libdev/Components.hpp"
#include "GEngine/libdev/System.hpp"
#include "GEngine/libdev/Systems.hpp"

#include "GEngine/interface/events/SharedEvent.hpp"

#include "GEngine/libdev/systems/driver/output/Draw.hpp"
#include "GEngine/libdev/systems/driver/output/ModelManager.hpp"

#include "events/MorphToPropEvent.hpp"

namespace hs::system
{
    class MorphToProp
        : public gengine::System<
              MorphToProp, gengine::interface::component::RemoteLocal, gengine::component::driver::output::Model,
              geg::component::Transform3D, component::Player, component::Prop, gengine::system::driver::output::DrawModel,
              gengine::system::driver::output::ModelManager, gengine::system::driver::output::RenderWindow>,
          public gengine::LocalSystem
    {
    public:
        void init(void) override;

        void morphPlayer(event::MorphToPropEvent &e);
    };
} // namespace hs::system
