#include <vector>
#include "VC3.h"
#include "Node.h"
#include "typedef.h"

void VC3::Init() { 
  if (degree_ == 0) {
    state_ = std::make_pair(BMM::MS, BMM::MS);    
    return;
  }

  state_ = std::make_pair(BMM::UR, BMM::UR); 
  if (color_ == 1) {
    for (int i = 0; i < degree_; ++i) {
      Xset_.insert(i);
    }
  }
}


void VC3::Send(int round_idx) {

  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (state_.first == BMM::UR) { // white node
      if (k <= degree_) {  // k <= deg(v)
        msg_send_[k-1].first = BMM::proposal;
        return;
      } else {                    // k > deg(v)
        state_.first = BMM::US;   
      } 
    } else if (state_.first == BMM::MR) {
      for (int i = 0; i < msg_send_.size(); ++i) {
        msg_send_[i].first = BMM::matched;
      }
      state_.first = BMM::MS;         
      return;
    } 
  } else {                        // round = 2k 
    if (!Mset_.empty()) { 
      msg_send_[*Mset_.begin()].second = BMM::accept;
      state_.second = BMM::MS;
    }
    if (Xset_.empty()) {
      state_.second = BMM::US;
    }
    return;
  }      
}

void VC3::Receive(int round_idx) {

  if (round_idx % 2 == 1) {      // round = 2k - 1
    if (state_.second == BMM::UR) {     // black node   
      for (int i = 0; i < port_.size(); ++i) {
        int send_port = port_[i]->port_hash(idx_);
        BMM::Message msg = dynamic_cast<VC3*>(port_[i])->msg_send_[send_port].first;
        if (msg == BMM::matched) {  
          Xset_.erase(i);
        } else if (msg == BMM::proposal) {
          Mset_.insert(i);
        }
      }
    }
  } else {  // round = 2k 
    if (state_.first == BMM::UR) {       // white node
      for (int i = 0; i < port_.size(); ++i) {
        int send_port = port_[i]->port_hash(idx_);
        BMM::Message msg = dynamic_cast<VC3*>(port_[i])->msg_send_[send_port].second;
        if (msg == BMM::accept) {  
          state_.first = BMM::MR;
        }
      }
    }
  }      
}

bool VC3::stop() {
  if (state_.first == BMM::US && state_.first == BMM::MS) {
    return 1;
  } else {
    return 0;
  }
}

void VC3::clear_msg_send() {
  Message msg(BMM::empty, BMM::empty);
  msg_send_.assign(degree_, msg);
}

void VC3::PrintOutput() {
  if (state_.first == BMM::MS || state_.second == BMM::MS ) {
    std::cout << "node " << idx_ << std::endl;
  }    
}  