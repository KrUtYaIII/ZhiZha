#include "Components/TransformComponent.h"
#include "Components/MaterialComponent.h"
#include "Components/RenderedComponent.h"
#include "Stone_2_InitSystem.h"
#include "Components/MeshComponent.h"
#include <random>
#include <ctime>
#include <Components/SpeedComponent.h>
#include <ComponentDrop.h>
#include <DefinesPhysics.h>
#include "Components/LayerComponent.h"
#include "GlobalRotation_Component.h"

void Stone_2_InitSystem::OnInit()
{
	//Initialize Enityty
	_stone = &_entities->CreateEntity();

	_entities->GetOrAddComponent<MeshComponent>(*_stone, [&](MeshComponent& c) {
		c.Mesh = _resources.GetOrAddResource<MeshResource>("stone_2");
		});

	_entities->GetOrAddComponent<MaterialComponent>(*_stone, [&](MaterialComponent& c) {
		c.VertexShader = _resources.GetOrAddResource<VertexShaderResource>("Map");
		c.FragmentShader = _resources.GetOrAddResource<FragmentShaderResource>("Map");
		c.Textures.emplace_back(_resources.GetOrAddResource<TextureResource>("Stone_2_Albedo.png"));
		c.attributesCount = 2;
		});

	_entities->GetOrAddComponent<TransformComponent>(*_stone, [&](TransformComponent& c) {
		c.Location = { 0.0, -.2 };
		c.Scale = { 0.07, 0.07 };
		c.Angle = 0.0f;
		c.parent = nullptr;
		});

	_entities->GetOrAddComponent<LayerComponent>(*_stone, [](LayerComponent& c) {
		c.Index = Game;
	});

	_entities->GetOrAddComponent<GlobalRotation_Component>(*_stone);
}

Stone_2_InitSystem::Stone_2_InitSystem(ResourceManager& resources)
	: _resources(resources) { }

void Stone_2_InitSystem::OnSceneUnload(Scene scene) {
	_entities->DestroyEntity(*_stone);
}
