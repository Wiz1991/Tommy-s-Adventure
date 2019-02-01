
#include <SFML/Graphics.hpp>

class State {
 enum class States{
           INTRO,
           MENU,
           PLAY,
           GAME_OVER,
           TOTAL
        }
 
 
   public:
   State(State::States aState) : mStateType(aState),
                                 mNextState(mStateType){}
   virtual ~State()                                 
   public:
   
     virtual void Update(sf::Time dT) = 0;
     virtual void Draw() = 0;
     virtual void Render() = 0;
     virtual void handleEvents() = 0;
 
     State::States getNextState() const { return mNextState; }
    protected:
     void PushState(State::States aState) { mNextState= aState; }
    
   
    private:
         const State::States mStateType;
         State::States mNextState;
   
   }
  inline *State getStateFromType(State::States stateType){
       switch(stateType){
        case State::States::INTRO:
         return new Intro();
        case State::States::MENU:
         return new Menu();
        case State::States::PLAY:
         return new Play();
        case State::States::GAME_OVER:
         return new GameOver();
        default: 
         return nullptr;
         
         
   
   //LIST OF ALL STATES, returns an object to RegisterStates()
  }
