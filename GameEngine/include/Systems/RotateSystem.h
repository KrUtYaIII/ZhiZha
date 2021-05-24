#pragma once
#include "GameTime.h"
#include "ResourceManager.h"
#include "System.h"
#include "SFML/Graphics/Text.hpp"
#include "SFML/Graphics/View.hpp"

class RotateSystem : public virtual FixedUpdateSystem {
	sf::View& _gameView;
	double _dphi = 0;
	double _ddphi = 0;
	double _phi = 0;
	sf::Vector2f& _gravitation;
	GameTime& _time;

public:
	RotateSystem(sf::View& gameView, sf::Vector2f& gravitation, GameTime& time)
		: _gameView(gameView),
		  _gravitation(gravitation),
		  _time(time) {}

	void OnFixedUpdate() override;
};
