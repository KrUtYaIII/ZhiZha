#include "Component.h"

#include <utility>
#include <typeinfo>

TransformComponent::TransformComponent(sf::Vector2f location,
                                       sf::Vector2f rotation,
                                       sf::Vector2f scale)
	: Location(location), Rotation(rotation), Scale(scale) {}

std::shared_ptr<Component> TransformComponent::Copy() {
	return std::make_shared<TransformComponent>(*this);
}

TestComponent::TestComponent(int data): Data(data) {}

std::shared_ptr<Component> TestComponent::Copy() {
	return std::make_shared<TestComponent>(*this);
}

NameComponent::NameComponent(std::string name): Name(std::move(name)) {}

std::shared_ptr<Component> NameComponent::Copy() {
	return std::make_shared<NameComponent>(*this);
}
