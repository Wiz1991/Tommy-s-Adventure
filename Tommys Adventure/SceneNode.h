#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class SceneNode : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;
	SceneNode();
	~SceneNode();
public:
	void attachNode(Ptr node);
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void update(sf::Time dT);
private:
	void updateChildren(sf::Time dT);
	virtual void updateCurrent(sf::Time dT);
private:
	virtual void drawCurrent(sf::RenderTarget& target,sf::RenderStates states) const;
	void drawChildren(sf::RenderTarget& target, sf::RenderStates states)const;
private:
	std::vector<Ptr> mChildren;
};

