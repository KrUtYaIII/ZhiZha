#pragma once

#include <Components/LayerComponent.h>
#include "System.h"
#include "SFML/Graphics.hpp"

class RenderSystem : public virtual PostUpdateSystem {
	sf::RenderWindow& _window;
	std::vector<sf::View>& _views;
	float& _phi;
	sf::Vector2f& _camera_location;

	void drawWithOpenGl(const ComplexComponent<LayerComponent>& item);
	void drawWithSFML(const ComplexComponent<LayerComponent>& item);

public:
	explicit RenderSystem(sf::RenderWindow& window, std::vector<sf::View>& views, sf::Vector2f& camera_location, float& phi)
		: _window(window), _views(views), _camera_location(camera_location), _phi(phi) { }

	void OnPostUpdate() override;
};