#include <vector>
#include <memory>
#include "State.h"



class StateManager : public State{
 public:
   StateManager()

    void RegisterStates();
    void Update();
    void PushState(State::States aState);
 
  private:
    std::vector<*State> mStateStack;
    int currentStateIndentifier;
}
