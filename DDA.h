#ifndef DDA_H
#define DDA_H 

<<<<<<< HEAD
#include <vector>
#include <string>
#include "typedef.h"

=======
#include "Node.h"
#include "typedef.h"

class Node;

>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
class DDA {
 public:
  DDA() {}
  ~DDA() {}
<<<<<<< HEAD

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


=======
  
  virtual void InitNode(Node* node) {}
  virtual void Send(Node* node, int round_idx) {}
  virtual void Receive(Node* node, int round_idx) {}  
  virtual bool Stop(Node* node) {}  
  virtual void PrintOutput(Node* node) {}  
};

>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
#endif