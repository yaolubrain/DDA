#include <vector>
#include "VC3.h"
#include "Node.h"
#include "typedef.h"

void VC3::Init() { 
  if (degree_ == 0) {
    state_ = std::make_pair(US, US);    
    return;
  }

  state_ = std::make_pair(UR, UR); 
  if (color_ == 1) {
    for (int i = 0; i < degree_; ++i) {
      Xset_.insert(i);
    }
  }
}

/*
void VC3::Send(int round_idx) {

  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (color_ == 0) {    // white node
      if (state_ == "UR") {
        if (k <= degree_) {  // k <= deg(v)
          msg_send_[k-1] = "proposal";
          return;
        } else {                    // k > deg(v)
          state_ = "US";   
        } 
      } else if (state_ == "MR") {
        msg_send_.assign(degree_, "matched");
        state_ = "MS";       // no need to set_matched_port since it doesn't change          
        return;
      }
    } 
  } else {                        // round = 2k 
    if (color_ == 1) {     // black node
      if (!Mset_.empty()) { 
        msg_send_[*Mset_.begin()] = "accept";
        state_ = "MS";
        matched_port_ = *Mset_.begin();
      }
      if (Xset_.empty()) {
        state_ = "US";
      }
      return;
    }
  }      
}

void VC3::Receive(int round_idx) {

  if (round_idx % 2 == 1) {      // round = 2k - 1
    if (color_ == 1) {    // black node
      if (state_ == "UR") {        
        for (int i = 0; i < port_.size(); ++i) {
          int send_port = port_[i]->port_hash(idx_);
          Message msg = dynamic_cast<VC3*>(port_[i])->msg_send_[send_port];
          if (msg == "matched") {  
            Xset_.erase(i);
          } else if (msg == "proposal") {
            Mset_.insert(i);
          }
        }
      }
    }
  } else {  // round = 2k 
    if (color_ == 0) {    // white node
      if (state_ == "UR") {
        for (int i = 0; i < port_.size(); ++i) {
          int send_port = port_[i]->port_hash(idx_);
          Message msg = dynamic_cast<VC3*>(port_[i])->msg_send_[send_port];
          if (msg == "accept") {  
            state_ = "MR";
            matched_port_ = i;
          }
        }
      }
    }       
  }      
}

bool VC3::stop() {
  if (state_ == "US" || state_ == "MS") {
    return 1;
  } else {
    return 0;
  }
}

void VC3::clear_msg_send() {
  msg_send_.assign(degree_, "");
}


void VC3::PrintOutput() {
  if (state_ == "MS") {
    std::cout << "node " << idx_ << " - node " << port_[matched_port_]->idx() << std::endl;
  }    
}  */