#include "World.h"



World::World(sf::RenderWindow& aWindow)
	: mWindow(aWindow),
	mWorldView(aWindow.getDefaultView()),
	scrollSpeed(-100),
	mWorldBounds(0.f, 0.f, aWindow.getSize().x, 5000.f),
	mTextureHolder(),
	mSpawnPosition(mWorldView.getSize().x/2.f,mWorldBounds.height-mWorldView.getSize().y/2.f),
	mSceneGraph(),
	mSceneLayers(),
	mPlayerAirplane(nullptr)
	
{
	loadTextures();
	buildScene();

	mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dT)
{
	mWorldView.move(0.f,scrollSpeed * dT.asSeconds());
	mPlayerAirplane->setVelocity(0, 0);
	while (!mCommandQueue.isEmpty()) {
		mSceneGraph.onCommand(mCommandQueue.pop(), dT);
	}
	mPlayerAirplane->accelerate(0.f, scrollSpeed);
	mSceneGraph.update(dT);
	
}

void World::draw()
{
	
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextureHolder.load(Textures::ID::PlayerAirplane, "textures/pl1dm0.png");
    mTextureHolder.load(Textures::ID::BACKGROUND, "textures/desert.png");
	mTextureHolder.load(Textures::ID::RaptorAirplane, "textures/pl2dm0.png");
}
 
void World::buildScene()
{
	for (size_t i = 0; i < LayerCount; ++i) {
		std::unique_ptr<SceneNode> layer(new SceneNode());
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachNode(std::move(layer));
	}
	//
	sf::Texture& desert = mTextureHolder.get(Textures::BACKGROUND);
	desert.setRepeated(true);
	sf::Vector2f scale(mWindow.getSize().x / (float)desert.getSize().x
		             , mWindow.getSize().y / (float)desert.getSize().y);
	sf::IntRect textureRect(mWorldBounds);

	std::unique_ptr<SpriteNode> background(new SpriteNode(desert,textureRect));
	background->setPosition(mWorldBounds.left,mWorldBounds.top);
	mSceneLayers[RenderLayers::BACKGROUND]->attachNode(std::move(background));

	std::unique_ptr<Airplane> player(new Airplane(mTextureHolder.get(Textures::ID::PlayerAirplane),Airplane::Type::Eagle));
	player->setPosition(mSpawnPosition);
	player->setScale(0.5, 0.5);
	mPlayerAirplane = player.get();
	mSceneLayers[RenderLayers::AIR]->attachNode(std::move(player));

}



CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}


