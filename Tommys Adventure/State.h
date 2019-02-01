
#include <SFML/Graphics.hpp>

class State {
 enum class States{
           INTRO,
           MENU,
           PlAY,
           TOTAL
        }
 
 
   public:
   State(State::States aState) : mCurrentState(aState),
                                 isPaused(false){}
   virtual ~State()                                 
   public:
   
     virtual void Update(sf::Time dT) = 0;
     virtual void Draw() = 0;
     virtual void Render() = 0;
     virtual void handleEvents() = 0;
     virtual void Pause(){
          isPaused= true;
   
   private:
   State::States mCurrentState;
   State::States mNextState;
   
   bool isPaused;
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   }
