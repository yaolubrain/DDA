#include <vector>
#include "VC2.h"
#include "Node.h"

void VC2::Init() { 
  if (degree_ == 0) {
    state_ = std::make_pair(BMM::State::MS, BMM::State::MS);    
    return;
  }

  state_ = std::make_pair(BMM::State::UR, BMM::State::UR); 
  if (color_ == 1) {
    for (int i = 0; i < degree_; ++i) {
      Xset_.insert(i);
    }
  }
}

void VC2::Send(int round_idx) {
  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (state_.first == BMM::State::UR) { // white node
      if (k <= degree_) {  // k <= deg(v)
        msg_send_[k-1].first = BMM::Message::proposal;
        return;
      } else {                    // k > deg(v)
        state_.first = BMM::State::US;   
      } 
    } else if (state_.first == BMM::State::MR) {
      for (int i = 0; i < msg_send_.size(); ++i) {
        msg_send_[i].first = BMM::Message::matched;
      }
      state_.first = BMM::State::MS;         
      return;
    } 
  } else {                        // round = 2k 
    if (!Mset_.empty()) { 
      msg_send_[*Mset_.begin()].second = BMM::Message::accept;
      state_.second = BMM::State::MS;
    }
    if (Xset_.empty()) {
      state_.second = BMM::State::US;
    }
    return;
  }      
}

void VC2::Receive(int round_idx) {
  if (round_idx % 2 == 1) {      // round = 2k - 1
    if (state_.second == BMM::State::UR) {     // black node   
      for (int i = 0; i < port_.size(); ++i) {
        int send_port = port_[i]->port_hash(idx_);
        BMM::Message msg = dynamic_cast<VC2*>(port_[i])->msg_send_[send_port].first;
        if (msg == BMM::Message::matched) {  
          Xset_.erase(i);
        } else if (msg == BMM::Message::proposal) {
          Mset_.insert(i);
        }
      }
    }
  } else {  // round = 2k 
    if (state_.first == BMM::State::UR) {       // white node
      for (int i = 0; i < port_.size(); ++i) {
        int send_port = port_[i]->port_hash(idx_);
        BMM::Message msg = dynamic_cast<VC2*>(port_[i])->msg_send_[send_port].second;
        if (msg == BMM::Message::accept) {  
          state_.first = BMM::State::MR;
        }
      }
    }
  }      
}

bool VC2::Stop() {
  if ((state_.first == BMM::State::US || state_.first == BMM::State::MS) && 
      (state_.second == BMM::State::US || state_.second == BMM::State::MS)) {
    return 1;
  } else {
    return 0;
  }
}

void VC2::ClearMsgSend() {
  Message msg(BMM::Message::empty, BMM::Message::empty);
  msg_send_.assign(degree_, msg);
}

void VC2::PrintOutput() {
  if (state_.first == BMM::State::MS || state_.second == BMM::State::MS ) {
    std::cout << "node " << idx_ << std::endl;
  }    
}  

bool VC2::Saturated() {
  if (state_.first == BMM::State::MS || state_.second == BMM::State::MS) {
    return true;
  } else {
    return false;
  }
}