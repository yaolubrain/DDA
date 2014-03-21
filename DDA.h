#ifndef DDA_H
#define DDA_H 

#include <vector>
#include <string>
#include "typedef.h"

class DDA {
 public:
  DDA() {}
  ~DDA() {}

  virtual StateType InitState(int color) { 
    StateType state = "init";
    return state;
  }


  virtual MessageType Send(StateType state, int port, int degree, int color, int round_idx) {}
  virtual StateType Receive(StateType state, std::vector<MessageType> msg_receive, int degree, int color, int round_idx) {}

  std::vector<std::string> state_set_;
  std::vector<std::string> message_set_;
  
};


#endif