#pragma once

#include "ResourceManager.h"
#include "System.h"
#include "SFML/Graphics/RenderWindow.hpp"

class ZhizhaVolume_InitSystem : public virtual InitSystem {
	ResourceManager& _resources;

public:
	explicit ZhizhaVolume_InitSystem(ResourceManager& resources);

	void OnInit() override;
};