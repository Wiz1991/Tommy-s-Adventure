#pragma once
#include "ResourceManager.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include <vector>
#include <memory>
#include <array>
#include "SFML/Graphics.hpp"
#include "Airplane.h"


enum RenderLayers {
	BACKGROUND,
	AIR,
	GUI,
	LayerCount
};
class World
{
public:
	World(sf::RenderWindow& aWindow);
	void update(sf::Time dT);
	void draw();
	void loadTextures();
	void buildScene();
private:
	ResourceManager<sf::Texture, Textures::ID> mTextureHolder;
	sf::RenderWindow& mWindow;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	Airplane* mPlayerAirplane;


	sf::View mWorldView;
	float scrollSpeed;
	sf::FloatRect mWorldBounds;
	sf::Vector2f mSpawnPosition;


};

