#include <vector>
#include <memory>
#include "State.h"



class StateManager : public State{
 public:
   StateManager()

    void RegisterStates();
    void Update();
  private:
    std::vector<*State> mStateStack;
    int currentStateIndentifier;
}
