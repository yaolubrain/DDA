#ifndef BMM_H
#define BMM_H

<<<<<<< HEAD
#include "DDA.h"

class BMM : public DDA {
 public:
  BMM() {
    state_set_ = {"UR","MR","US","MS"};
    message_set_ = {"proposal","matched","accept"};
  }

  ~BMM() {}


  StateType InitState(int color) { 
    StateType state_init = "UR";
    return state_init;
  }


  MessageType Send(StateType state, int port, int degree, int color, int round_idx) {
    MessageType msg;
    if (round_idx % 2 == 1) {
      if (color == 0) {
        if (state == "UR") {
          if ((round_idx+1)/2 <= degree) {
            msg = "proposal";
            return msg;
          }  
        } 

        if (state == "MR") {

        }
      }  
    } else {

    }
    
    return msg;
  }

  StateType Receive(StateType state, std::vector<MessageType> msg_receive, int degree, int color, int round_idx) {
    StateType state_receive = "receive";
    return state_receive;
  }

=======
#include <vector>
#include "DDA.h"
#include "Node.h"
#include "typedef.h"

class Node;

class BMM : public DDA {
 public:
  BMM() {}
  ~BMM() {}

  void InitNode(Node* node);
  void Send(Node* node, int round_idx);
  void Receive(Node* node, int round_idx);
  bool Stop(Node* node);
  void PrintOutput(Node* node);

>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
};


#endif