#pragma once
#include "ResourceManager.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include <vector>
#include <memory>
#include <array>
#include "SFML/Graphics.hpp"
#include "Airplane.h"
#include "Command.h"
#include "CommandQueue.h"


class World
{
public:
	World(sf::RenderWindow& aWindow);
	void update(sf::Time dT);
	void draw();
	void loadTextures();
	void buildScene();
	CommandQueue& getCommandQueue();
private:
enum RenderLayers {
	BACKGROUND,
	AIR,
	GUI,
	LayerCount
};
private:
	ResourceManager<sf::Texture, Textures::ID> mTextureHolder;
	sf::RenderWindow& mWindow;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	Airplane* mPlayerAirplane;
	CommandQueue mCommandQueue;


	sf::View mWorldView;
	float scrollSpeed;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;


};

