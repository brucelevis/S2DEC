#pragma once

#include "Enemy.h"

using namespace S2D;

class FireEnemy : public Enemy {
private:
	std::uniform_int_distribution<int> randomInt{ 0,2500 };
public:
	FireEnemy(sf::Vector2f position, sf::Vector2f endPosition, void* spawner) : Enemy(position, endPosition, spawner) {
		image.setFillColor(sf::Color::Red);
	}


	void update(float frameTime) override {
		Enemy::update(frameTime);
	}

	void draw(sf::RenderTarget& target) override {
		Enemy::draw(target);
	}

	void beginCollision(Component* collidedComponent, b2Contact* contact) override {
		if (auto spell = dynamic_cast<Fireball*>(collidedComponent)) {
			return;
		}
		if (auto spell = dynamic_cast<Spell*>(collidedComponent)) {
			spell->setDestroySpell(true);
			destroy = true;
		}
		if (auto spell = dynamic_cast<LightningBolt*>(collidedComponent)) {
			spell->createExplosion();
		}
	}
};