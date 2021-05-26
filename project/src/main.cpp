#include "Systems/RenderSystem.h"
#include "Systems/MoveSystem.h"
#include "DefinesPhysics.h"
#include "Zhizha_InitSystem.h"
#include "Map_InitSystem.h"
#include "Engine.h"
#include "Components/LayerComponent.h"
#include "glad/glad.h"

#include "Systems/CollisionSystem.h"
#include "Systems/EventSystem.h"
#include "Systems/FPSSystem.h"
#include "Systems/GravitationSystem.h"
#include "Systems/RotateSystem.h"
#include "Systems/ResetParamsSystem.h"
#include "Systems/MaterialAttachSystem.h"
#include "ZhizhaVolume_InitSystem.h"
#include "FormZhizhaVolume_System.h"

#if defined(linux)
#include <X11/Xlib.h>
#endif

int main() {
#if defined(linux)
	XInitThreads();
#endif
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	auto window = sf::RenderWindow(sf::VideoMode(1080, 720), "Sample", sf::Style::Default,
			settings);

	gladLoadGL();

	sf::Vector2f gravity = { 0, G };
	std::vector views = {
			window.getDefaultView(), // game view
			window.getDefaultView() // gui view
	};

	views.at(Game).zoom(3);

	auto engine = new Engine(window);
	engine->RegisterSystem<Zhizha_InitSystem>(engine->GetResourceManager())
		.RegisterSystem<Map_InitSystem>(engine->GetResourceManager())
		.RegisterSystem<ZhizhaVolume_InitSystem>(engine->GetResourceManager())
		.RegisterSystem<MaterialAttachSystem>(window)
		//.RegisterSystem<RotateSystem>(views[Game], gravity, engine->GetTime())
		//.RegisterSystem<EventSystem>(window)
		.RegisterSystem<RenderSystem>(window, views)
		.RegisterSystem<FPSSystem>(engine->GetTime(), engine->GetResourceManager())
		.RegisterSystem<GravitationSystem>(engine->GetTime(), gravity)
		//.RegisterSystem<MoveSystem>(engine->GetTime())
		.RegisterSystem<FormZhizhaVolume_System>()
		.RegisterSystem<ResetParamsSystem>()
	    .RegisterSystem<CollisionSystem>();
	engine->Start();
}
