
#include <SFML/Graphics.hpp>

class State {
 enum class States{
           INTRO,
           MENU,
           PlAY,
           TOTAL
        }
 
 
   public:
   State(State::States aState) : {}
   virtual ~State()                                 
   public:
   
     virtual void Update(sf::Time dT) = 0;
     virtual void Draw() = 0;
     virtual void Render() = 0;
     virtual void handleEvents() = 0;
    
   
  

   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   }
