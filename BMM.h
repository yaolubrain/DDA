#ifndef BMM_H
#define BMM_H

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

};


#endif