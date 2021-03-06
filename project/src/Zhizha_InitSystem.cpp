#include "Components/TransformComponent.h"
#include "Components/MaterialComponent.h"
#include "Components/RenderedComponent.h"
#include "Zhizha_InitSystem.h"
#include "Components/MeshComponent.h"
#include "Components/MeshCollider.h"
#include <random>
#include <ctime>
#include <Components/SpeedComponent.h>
#include <ComponentDrop.h>
#include "GlobalRotation_Component.h"
#include "Components/LayerComponent.h"

void Zhizha_InitSystem::OnInit()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Entity& ball = _entities->CreateEntity();
			_createdEntities.emplace_back(&ball);

			_entities->GetOrAddComponent<MeshComponent>(ball, [&](MeshComponent& c) {
				c.Mesh = _resources.GetOrAddResource<MeshResource>("Circle");
				});

			_entities->GetOrAddComponent<MaterialComponent>(ball, [&](MaterialComponent& c) {
				c.VertexShader = _resources.GetOrAddResource<VertexShaderResource>("ZhizhaVolume");
				c.FragmentShader = _resources.GetOrAddResource<FragmentShaderResource>("ZhizhaVolume");
				c.Textures.emplace_back(_resources.GetOrAddResource<TextureResource>("Circle_Albedo.png"));
				c.attributesCount = 2;
				});

			_entities->GetOrAddComponent<TransformComponent>(ball, [&](TransformComponent& c) {
				c.Location = {
				i * 0.04f + 0.1f,
				j * 0.04f
				};
				c.Scale = { 0.2f, 0.2f };
				c.Angle = 0;
				c.parent = nullptr;
				});

			_entities->GetOrAddComponent<LayerComponent>(ball, [](LayerComponent& c) {
				c.Index = Game;
				});

			_entities->GetOrAddComponent<ComponentDrop>(ball);
			_entities->GetOrAddComponent<SpeedComponent>(ball);

			_entities->GetOrAddComponent<GlobalRotation_Component>(ball);
		}
	}
}

Zhizha_InitSystem::Zhizha_InitSystem(ResourceManager& resources)
	: _resources(resources) { }

void Zhizha_InitSystem::OnSceneUnload(Scene scene) {
	for (auto entity: _createdEntities)
		_entities->DestroyEntity(*entity);
}
