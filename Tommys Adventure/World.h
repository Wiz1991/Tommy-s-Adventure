#pragma once
#include "ResourceManager.h"
#include "SceneNode.h"
#include "SpriteNode.h"
#include <vector>
#include <memory>
#include <array>
#include "SFML/Graphics.hpp"

enum RenderLayers {
	BACKGROUND,
	AIR,
	GUI,
	LayerCount
};
class World
{
public:
	World(sf::RenderTarget& aWindow);
	void update(sf::Time dT);
	void draw();
	void loadTextures();
	void buildScene();
private:
	typedef std::unique_ptr<SceneNode> uniqPtr;
	sf::RenderTarget& mTarget;
	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	TextureManager mTextureHolder;

	sf::View worldView;
	sf::FloatRect camera;
	sf::Vector2f scrollSpeed;
	sf::IntRect mWorldBounds;


};

