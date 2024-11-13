/*
** EPITECH PROJECT, 2024
** GameEngine
** File description:
** shared.cpp
*/

#include "GEngine/libdev/Systems.hpp"
#include "GEngine/GEngine.hpp"

#include "GEngine/libdev/systems/driver/input/KeyboardCatcher.hpp"
#include "GEngine/libdev/systems/driver/input/MouseCatcher.hpp"
#include "GEngine/libdev/systems/driver/output/Animate.hpp"
#include "GEngine/libdev/systems/driver/output/Draw.hpp"
#include "GEngine/libdev/systems/driver/output/FontManager.hpp"
#include "GEngine/libdev/systems/driver/output/RenderWindow.hpp"
#include "GEngine/libdev/systems/driver/output/TextureManager.hpp"

#include "Constants.hpp"
#include "systems/BackgroundMotion.hpp"
#include "systems/CameraRotation.hpp"
#include "systems/ChangePlayerModel.hpp"
#include "systems/Guess.hpp"
#include "systems/HUD.hpp"
#include "systems/InputsToGameEvents.hpp"
#include "systems/MorphToProp.hpp"
#include "systems/PlayerMotion.hpp"
#include "systems/ResetPlayerRotation.hpp"
#include "systems/Start.hpp"

#include "GEngine/interface/network/systems/ClientEventPublisher.hpp"
#include "GEngine/interface/network/systems/ClientServer.hpp"
#include "GEngine/interface/network/systems/ServerEventReceiver.hpp"

#include "GEngine/interface/events/RemoteLocal.hpp"
#include "GEngine/interface/systems/RemoteLocal.hpp"

#include "GEngine/libdev/systems/driver/output/AudioManager.hpp"

// VOIP

#include "GEngine/libdev/systems/CLI.hpp"
#include "GEngine/libdev/systems/events/CLI.hpp"

#include "GEngine/interface/network/systems/VoIPManager.hpp"
#include "GEngine/libdev/systems/driver/input/VoIPAudioCatcher.hpp"
#include "GEngine/libdev/systems/driver/output/VoIPAudio.hpp"

#include "GEngine/libdev/System.hpp"

struct V : public gengine::System<V>, public gengine::LocalSystem
{
    void init(void) override
    {
        // publishEvent(gengine::system::event::driver::input::StartVoIP());
        subscribeToEvent<gengine::system::event::CLINewInput>(&V::onCLi);
    }

    void onCLi(gengine::system::event::CLINewInput &e)
    {
        if (!e.prompt.size())
            return;
        if (!e.prompt[0].compare("voip-start"))
            publishEvent(gengine::system::event::driver::input::StartVoIP());
        if (!e.prompt[0].compare("voip-stop"))
            publishEvent(gengine::system::event::driver::input::EndVoIP());
    }
};

void GEngineDeclareSystems(Registry *r)
{
    r->registerSystem<gengine::system::driver::output::RenderWindow>(WINDOW_WIDTH, WINDOW_TOTAL_HEIGHT, "R-Type");
    r->registerSystem<gengine::system::driver::output::Draw>(BLACK);
    r->registerSystem<gengine::system::driver::output::DrawSprite>();
    r->registerSystem<gengine::system::driver::output::DrawModel>();
    r->registerSystem<gengine::system::driver::output::DrawText>();
    r->registerSystem<gengine::system::driver::output::DrawRectangle>();
    r->registerSystem<gengine::system::driver::output::DrawCircle>();

    r->registerSystem<gengine::system::driver::output::TextureManager>("../assets/sprites");
    // r->registerSystem<gengine::system::driver::output::FontManager>("../assets/fonts");
    r->registerSystem<gengine::system::driver::input::KeyboardCatcher>();
    r->registerSystem<gengine::system::driver::input::MouseCatcher>();
    r->registerSystem<gengine::system::driver::output::ModelManager>("../assets/models");
    r->registerSystem<geg::system::io::AnimationManager>("../assets/animations");
    r->registerSystem<gengine::system::driver::output::Animate>();
    r->registerSystem<gengine::system::driver::output::AnimateModel>();

    r->registerSystem<gengine::system::Motion2D>();
    r->registerSystem<gengine::system::Motion3D>();
    r->registerSystem<gengine::system::MotionAcceleration3D>();
    r->registerSystem<gengine::system::Collision2D>();
    r->registerSystem<gengine::system::AutoKiller>();

    r->registerSystem<hs::system::Crossair>();

    r->registerSystem<hs::system::InputsToGameEvents>();
    r->registerSystem<hs::system::Start>();
    r->registerSystem<hs::system::BackgroundMotion>();
    r->registerSystem<hs::system::PlayerMotion>();
    r->registerSystem<hs::system::CameraRotation>();
    r->registerSystem<hs::system::ResetPlayerRotation>();
    r->registerSystem<hs::system::ChangePlayerModel>();
    r->registerSystem<hs::system::Guess>();
    r->registerSystem<hs::system::MorphToProp>();

    r->registerSystem<gengine::interface::system::HandleRemoteLocal>();
    r->registerSystem<gengine::interface::system::HandleLocal>();

    r->registerSystem<gengine::interface::network::system::ClientEventPublisher<
        hs::event::Movement, hs::event::Rotation, hs::event::Jump, hs::event::ChangeCameraMode,
        hs::event::ChangePlayerModelEvent, hs::event::ResetPlayerRotationEvent, hs::event::LockPlayerEvent,
        hs::event::Sprint, hs::event::Crouch, gengine::interface::event::GetRemoteLocalWhoIAm>>();
    r->registerSystem<gengine::interface::network::system::ServerEventReceiver<
        hs::event::Movement, hs::event::Rotation, hs::event::Jump, hs::event::ChangeCameraMode,
        hs::event::ChangePlayerModelEvent, hs::event::ResetPlayerRotationEvent, hs::event::LockPlayerEvent,
        hs::event::Sprint, hs::event::Crouch, gengine::interface::event::GetRemoteLocalWhoIAm>>();

    r->registerSystem<gengine::interface::network::system::ConnectAtStart>("127.0.0.1", 4242);

    r->registerSystem<V>();

    r->registerSystem<gengine::system::CLI>();

    // Audio
    r->registerSystem<gengine::system::driver::output::AudioManagerLocal>("../assets/sounds", "../assets/musics");
    r->registerSystem<gengine::system::driver::output::AudioManagerRemote>("../assets/sounds", "../assets/musics");

    // VOIP
    r->registerSystem<gengine::interface::network::system::VoIPManager>(7.f);
    r->registerSystem<gengine::system::driver::output::VoIPAudio>();
    r->registerSystem<gengine::system::driver::input::VoIPAudioCatcher>();
    // TODO auto register ↓
}
