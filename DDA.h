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
    StateType state_init = "init";
    return state_init;
  }


  virtual MessageType Send(StateType state, int port, int degree, int color, int round_idx) {
    MessageType msg = "send";
    return msg;
  }

  virtual StateType Receive(StateType state, std::vector<MessageType> msg_receive, int degree, int color, int round_idx) {
    StateType state_receive = "receive";
    return state_receive;
  }

  std::vector<StateType> state_set_;
  std::vector<MessageType> message_set_;
  
};


#endif