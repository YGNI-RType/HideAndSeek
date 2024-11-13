/*
** EPITECH PROJECT, 2024
** B-CPP-500-LYN-5-1-rtype-basile.fouquet
** File description:
** InputsToGameEvents.hpp
*/

#pragma once

#include "GEngine/libdev/Events.hpp"
#include "GEngine/libdev/System.hpp"
#include "GEngine/libdev/Systems.hpp"

#include "events/ChangeCameraMode.hpp"
#include "events/ChangePlayerModelEvent.hpp"
#include "events/Crouch.hpp"
#include "events/GuessEvent.hpp"
#include "events/Jump.hpp"
#include "events/LockPlayerEvent.hpp"
#include "events/MorphToPropEvent.hpp"
#include "events/Movement.hpp"
#include "events/ResetPlayerRotationCameraEvent.hpp"
#include "events/Rotation.hpp"
#include "events/Sprint.hpp"

namespace hs::system
{
    class InputsToGameEvents : public gengine::System<InputsToGameEvents, gengine::system::driver::input::KeyboardCatcher>,
                               public gengine::LocalSystem
    {
    public:
        void init(void) override;
        void sendEvents(geg::event::GameLoop &e);

        void rotatePlayer(geg::event::io::MouseMoveEvent &e);
        void changeCameraMode(geg::event::io::KeyF5Event &e);

        void moveFwd(geg::event::io::KeyWEvent &e);
        void moveLeft(geg::event::io::KeyAEvent &e);
        void moveBck(geg::event::io::KeySEvent &e);
        void moveRight(geg::event::io::KeyDEvent &e);
        void jump(geg::event::io::KeySpaceEvent &e);
        void sprint(geg::event::io::KeyLeftControlEvent &e);
        void crouch(geg::event::io::KeyCEvent &e);

        void guess(geg::event::io::MouseLeft &e);
        void morph(geg::event::io::KeyEEvent &e);
        void lockPlayer(geg::event::io::KeyLeftShiftEvent &e);

        void setPlayerModelCoraline(geg::event::io::KeyOneEvent &e);
        void setPlayerModelBeer(geg::event::io::KeyTwoEvent &e);
        void setPlayerModelChair(geg::event::io::KeyThreeEvent &e);
        void setPlayerModelLamp(geg::event::io::KeyFourEvent &e);
        void setPlayerModelStick(geg::event::io::KeyFiveEvent &e);
        void setPlayerModelTv(geg::event::io::KeySixEvent &e);
        void setPlayerModelTable(geg::event::io::KeySevenEvent &e);
        void setPlayerModelCouch(geg::event::io::KeyEightEvent &e);

    private:
        char m_directionBitmask = 0;
        static const char FWD_MASK = 1 << 0;   // 0b0001
        static const char RIGHT_MASK = 1 << 1; // 0b1000
        static const char BCK_MASK = 1 << 2;   // 0b0010
        static const char LEFT_MASK = 1 << 3;  // 0b0100
        void updateDirectionBitmask(event::Movement::State state, bool);
        event::Movement::State getMovementState(void);
    };
} // namespace hs::system
