#ifndef DDA_H
#define DDA_H 

#include <vector>
#include <string>
#include "typedef.h"

class DDA {
 public:
  DDA() {}
  ~DDA() {}

  virtual MessageType Send(StateType state, int port, int degree, int color, int round) {}
  virtual StateType Receive(StateType state, int degree, int color, int round) {}

  std::vector<std::string> state_set_;
  std::vector<std::string> message_set_;
  
};


#endif