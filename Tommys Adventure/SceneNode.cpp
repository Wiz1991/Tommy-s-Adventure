#include "SceneNode.h"

SceneNode::SceneNode()
{
}

SceneNode::~SceneNode()
{
}

void SceneNode::attachNode(Ptr node)
{
	mChildren.push_back(std::move(node));
}


void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states)const
{
	//nothing
}

void SceneNode::draw(sf::RenderTarget & target, sf::RenderStates states)const
{
	states.transform *= getTransform();
	drawCurrent(target, states);
	drawChildren(target, states);
}

void SceneNode::update(sf::Time dT) {
	updateCurrent(dT);
	updateChildren(dT);

}
void SceneNode::onCommand(const Command& command, sf::Time dT)
{
	if (command.category & getCategory()) {
		command.action(*this, dT);
	}
	for (Ptr& child : mChildren) {
		child->onCommand(command, dT);
	}
}
unsigned int SceneNode::getCategory()
{
	return Category::Type::Scene;
}
void SceneNode::updateChildren(sf::Time dT)
{
	for (const Ptr &current : mChildren) {
		current->update(dT);
	}
}



void SceneNode::updateCurrent(sf::Time dT)
{
	//do nothing for a scene node object'
}

void SceneNode::drawChildren(sf::RenderTarget & target, sf::RenderStates states)const
{
	for (const Ptr& current : mChildren) {
		current->draw(target, states);
	}
}