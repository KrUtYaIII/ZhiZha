#pragma once

#include <SFML/Graphics/View.hpp>
#include <ResourceManager.h>
#include <Engine.h>
#include "System.h"

class MenuSystem : public virtual InitSystem, public virtual UpdateSystem {
	sf::View& _menuView;
	ResourceManager& _resources;
	Engine& _engine;

public:
	explicit MenuSystem(sf::View& menuView, ResourceManager& resources, Engine& engine)
		: _menuView(menuView), _resources(resources), _engine(engine) {}

	void OnInit() override;
	void OnUpdate() override;
};