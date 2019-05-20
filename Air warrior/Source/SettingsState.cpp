#include <Book/SettingsState.h>

SettingsState::SettingsState(StateStack& stack, Context context)
	: mBackGroundSprite(context.textures->get(Textures::TitleScreen))
	, mGUIContainer()
	, State(stack, context)
{
	addButtonLabel(Player::MoveLeft, 150, "Move Left", context);
	addButtonLabel(Player::MoveRight, 200, "Move Right", context);
	addButtonLabel(Player::MoveUp, 250, "Move Up", context);
	addButtonLabel(Player::MoveDown, 300, "Move Down", context);

	auto backButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	backButton->setText("Back");
	backButton->setPosition(80, 370);
	backButton->setCallback([this]() {
		requestStackPop();
		});

	mGUIContainer.pack(backButton);
}

void SettingsState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.draw(mBackGroundSprite);
	window.draw(mGUIContainer);
}

bool SettingsState::update(sf::Time dt)
{
	updateLabels();
	return false;
}

bool SettingsState::handleEvent(const sf::Event& event)
{
	bool keyBound = false;
	for (size_t i = 0; i < Player::ActionCount; ++i) {
		if (mBindingButtons[i]->isActive()) {
			if (event.type == sf::Event::KeyReleased) {
				keyBound = true;
				getContext().player->assignKey(static_cast<Player::Action>(i), event.key.code);
				mBindingButtons[i]->deactivate();
			}
			break;
		}
	}
	if (keyBound)
		updateLabels();
	else
		mGUIContainer.handleEvent(event);
	return false;
}

void SettingsState::updateLabels()
{
	Player& player = *getContext().player;

	for (size_t it = 0; it < Player::ActionCount; ++it) {
		sf::Keyboard::Key key = player.getAssignedKey(static_cast<Player::Action>(it));
		mBindingLabel[it]->setText(keyToString(key));
	}
}

void SettingsState::addButtonLabel(Player::Action action, float y, std::string text, Context context)
{
	mBindingButtons[action] = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	mBindingButtons[action]->setText(text);
	mBindingButtons[action]->setToggle(true);
	mBindingButtons[action]->setPosition(80, y);

	mBindingLabel[action] = std::make_shared<GUI::Label>(" ", *context.fonts);
	mBindingLabel[action]->setPosition(300, y + 15);

	mGUIContainer.pack(mBindingButtons[action]);
	mGUIContainer.pack(mBindingLabel[action]);
}