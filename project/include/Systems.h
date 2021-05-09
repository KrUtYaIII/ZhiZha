#include "System.h"
#include "SFML/Graphics/RenderWindow.hpp"

class TestSystem : public virtual System<TestSystem>, public virtual UpdateSystem, public virtual PostInitSystem {
public:
	TestSystem() = default;
	
	void OnUpdate() override;

	void OnPostInit() override;
};

class EventSystem : public virtual System<EventSystem>, public virtual UpdateSystem {
	sf::RenderWindow& _window;

public:
	EventSystem(sf::RenderWindow& window) : _window(window) {}

	void OnUpdate() override;
};

class RenderSystem : public virtual System<RenderSystem>, public virtual PostUpdateSystem {
	sf::RenderWindow& _window;
	sf::Uint8 _step;
	sf::Color _latestColor = sf::Color::White;

public:
	explicit RenderSystem(sf::RenderWindow& window, sf::Uint8 step): _window(window), _step(step) {
		srand(time(nullptr));
	}

	void OnPostUpdate() override;
};