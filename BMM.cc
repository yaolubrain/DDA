#include <vector>
#include "BMM.h"
#include "Node.h"

void BMM::Init() { 
  if (degree_ == 0) {
    state_ = State::US;    
    return;
  }

  state_ = State::UR; 
  if (color_ == 1) {
    for (int i = 0; i < degree_; ++i) {
      Xset_.insert(i);
    }
  }
}

void BMM::Send(int round_idx) {
  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (color_ == 0) {    // white node
      if (state_ == State::UR) {
        if (k <= degree_) {  // k <= deg(v)
          msg_send_[k-1] = Message::proposal;
          return;
        } else {                    // k > deg(v)
          state_ = State::US;   
        } 
      } else if (state_ == State::MR) {
        msg_send_.assign(degree_, Message::matched);
        state_ = State::MS;       // no need to set_matched_port since it doesn't change          
        return;
      }
    } 
  } else {                        // round = 2k 
    if (color_ == 1) {     // black node
      if (!Mset_.empty()) { 
        msg_send_[*Mset_.begin()] = Message::accept;
        state_ = State::MS;
        matched_port_ = *Mset_.begin();
      }
      if (Xset_.empty()) {
        state_ = State::US;
      }
      return;
    }
  }      
}

void BMM::Receive(int round_idx) {
  if (round_idx % 2 == 1) {      // round = 2k - 1
    if (color_ == 1) {    // black node
      if (state_ == State::UR) {        
        for (int i = 0; i < port_.size(); ++i) {
          int send_port = port_[i]->port_hash(idx_);
          Message msg = dynamic_cast<BMM*>(port_[i])->msg_send_[send_port];
          if (msg == Message::matched) {  
            Xset_.erase(i);
          } else if (msg == Message::proposal) {
            Mset_.insert(i);
          }
        }
      }
    }
  } else {  // round = 2k 
    if (color_ == 0) {    // white node
      if (state_ == State::UR) {
        for (int i = 0; i < port_.size(); ++i) {
          int send_port = port_[i]->port_hash(idx_);
          Message msg = dynamic_cast<BMM*>(port_[i])->msg_send_[send_port];
          if (msg == Message::accept) {  
            state_ = State::MR;
            matched_port_ = i;
          }
        }
      }
    }       
  }      
}

bool BMM::stop() {
  if (state_ == State::US || state_ == State::MS) {
    return 1;
  } else {
    return 0;
  }
}

void BMM::clear_msg_send() {
  msg_send_.assign(degree_, Message::empty);
}

void BMM::PrintOutput() {
  if (state_ == State::MS) {
    std::cout << "node " << idx_ << " - node " << port_[matched_port_]->idx() << std::endl;
  }    
}  