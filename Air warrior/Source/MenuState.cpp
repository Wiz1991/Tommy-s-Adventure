#include <Book/MenuState.hpp>

MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mGUIContainer()
{
	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	mBackgroundSprite.setTexture(texture);

	auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	playButton->setPosition(230, 240);
	playButton->setText("Play");
	playButton->setCallback([this]()
		{
			requestStackPop();
			requestStackPush(States::Game);
		});

	auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	exitButton->setPosition(230, 370);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
		{
			requestStackPop();
		});
	auto hintLabel = std::make_shared<GUI::Label>("Press enter", *context.fonts);
	hintLabel->setPosition(2, 460);
	hintLabel->setCharacterSize(10);

	auto settingsButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	settingsButton->setText("Settings");
	settingsButton->setPosition(230, 300);
	settingsButton->setCallback([this]() {
		requestStackPush(States::Settings);
		});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(settingsButton);
	mGUIContainer.pack(exitButton);
	mGUIContainer.pack(hintLabel);
}

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());

	window.draw(mBackgroundSprite);
	window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
	return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;
}