#pragma once
#include "ResourceManager.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include <vector>
#include <memory>
#include <array>
#include "Airplane.h"
#include "CommandQueue.h"
#include "Command.h"

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>



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

