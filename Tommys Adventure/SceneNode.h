#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <memory>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include "Category.h"
#include "Command.h"

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
	virtual unsigned int getCategory();
private:
	void updateChildren(sf::Time dT);
	virtual void updateCurrent(sf::Time dT);
private:
	virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	std::vector<Ptr> mChildren;
	SceneNode* mParent;
};

