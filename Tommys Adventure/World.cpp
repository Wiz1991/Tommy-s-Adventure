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
	mSceneLayers[AIR]->move(0, scrollSpeed* dT.asSeconds());
	mSceneGraph.update(dT);
	
}

void World::draw()
{
	
	mWindow.setView(mWorldView);
	mWindow.draw(mSceneGraph);
}

void World::loadTextures()
{
	mTextureHolder.load(Textures::ID::AIRPLANE, "textures/pl1dm0.png");
    mTextureHolder.load(Textures::ID::BACKGROUND, "textures/desert.png");
	mTextureHolder.load(Textures::ID::test, "thief.png");
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

	std::unique_ptr<Airplane> player(new Airplane(mTextureHolder.get(Textures::ID::AIRPLANE),Airplane::Type::Owl));
	player->setPosition(mSpawnPosition);
	player->setScale(0.5, 0.5);
	mPlayerAirplane = player.get();
	mSceneLayers[RenderLayers::AIR]->attachNode(std::move(player));






}

void World::handleInput(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Key::D) {
		mPlayerAirplane->setVelocity(100, 0);
	}
}



