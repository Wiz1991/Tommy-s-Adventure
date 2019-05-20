#pragma once
#include "Component.h"
#include <vector>
#include <SFML/Graphics/RenderStates.hpp>
#include "SFML/Graphics/RenderTarget.hpp"

#include <memory>
#include "SFML/Window/Event.hpp"
namespace GUI {
	class Container : public Component
	{
	public:
		typedef std::shared_ptr<Container> Ptr;
		Container();
		void push(Component::Ptr component);
		bool isSelectable() const;
		void handelEvent(const sf::Event& event);
		void select(std::size_t index);
		void selectNext();
		void selectPrevious();
		bool hasSelection();
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		std::vector<Component::Ptr> mChildren;
		int mSelectedChild;
	};

}