#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "../SFML-2.5.0/include/SFML/System/Time.hpp"
#include "Command.h"
namespace Category {
	enum Type {
		NONE,
		Scene,
		PlayerAircraft,
		AlliedAircraft,
		EnemyAircraft
	};
}
class SceneNode : public sf::Drawable, public sf::Transformable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	SceneNode();
	~SceneNode();
public:
	void attachNode(Ptr node);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dT);
	void onCommand(const Command& command,sf::Time dT);
	unsigned int getCategory();
private:
	void updateChildren(sf::Time dT);
	virtual void updateCurrent(sf::Time dT);
private:
	virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	std::vector<Ptr> mChildren;
};

