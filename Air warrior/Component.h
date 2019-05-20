#pragma once
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
namespace sf {
	class Event;
}
#include <memory>
namespace GUI {
	class Component : public sf::Drawable, public sf::Transformable, private sf::NonCopyable
	{
	public:
		typedef std::shared_ptr<Component> Ptr;
	public:
		Component();

		virtual bool isSelected() const = 0;
		bool isSelectable() const;
		virtual void select();
		virtual void deselect();
		virtual bool isActive() const;
		virtual void activate();
		virtual void deactivate();
		virtual void handleEvent(const sf::Event& event) = 0;
	private:
		bool mIsSelected;
		bool mIsActive;
	};
}
