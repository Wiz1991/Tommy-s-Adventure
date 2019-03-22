#include "World.h"



World::World(sf::RenderTarget& aWindow)
	: mTarget(aWindow),
	camera(0, 0, 560, 480),
	worldView(camera),
	scrollSpeed(0,-50),
	mWorldBounds(0,0,worldView.getSize().x/2.f,2000.f)
	
{
	loadTextures();
	buildScene();
}

void World::update(sf::Time dT)
{
	worldView.move(scrollSpeed * dT.asSeconds());
	mSceneGraph.update(dT);
}

void World::draw()
{

	mTarget.setView(worldView);
	mTarget.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextureHolder.load(Textures::ID::AIRPLANE, "resources/textures/pl1dm0.png");
	mTextureHolder.load(Textures::ID::BACKGROUND, "resources/textures/desert.jpeg");
}

void World::buildScene()
{
	for (size_t i = 0; i < LayerCount; ++i) {
		std::unique_ptr<SceneNode> layer(new SceneNode());
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachNode(std::move(layer));
	}
	sf::Texture& desert = mTextureHolder.get(Textures::BACKGROUND);
	desert.setRepeated(true);
	sf::IntRect textureRect(mWorldBounds);

	uniqPtr background(new SpriteNode(desert,textureRect));
	mSceneLayers[RenderLayers::BACKGROUND]->attachNode(std::move(background));






}



