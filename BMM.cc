#include <vector>
#include "BMM.h"
#include "DDA.h"
#include "Node.h"
#include "typedef.h"

void BMM::InitNode(Node* node) { 
  node->set_state(State("UR"));    
  std::vector<int> Xset;
  MessageSet msg_set_empty;
  for (int i = 0; i < node->degree(); ++i) {
    Xset.push_back(i);
    Message msg;
    msg_set_empty.push_back(msg);
  }
  if (node->color() == 1) {
    node->set_Xset(Xset);
  }
  node->set_msg_send(msg_set_empty);
}

void BMM::Send(Node* node, int round_idx) {
  MessageSet msg_send = node->msg_send();

  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (node->color() == 0) {    // white node
      if (node->state() == "UR") {
        if (k <= node->degree()) {  // k <= deg(v)
          msg_send[k - 1] = "proposal";            
          node->set_msg_send(msg_send);
          return;
        } else {                    // k > deg(v)
          node->set_state(State("US"));   
        } 
      } else if (node->state() == "MR") {
        std::fill(msg_send.begin(), msg_send.end(), Message("matched"));
        node->set_msg_send(msg_send);
        node->set_state(State("MS"));       // no need to set_matched_port since it doesn't change          
        return;
      }
    } 
  } else {                        // round = 2k 
    if (node->color() == 1) {     // black node
      std::vector<int> Mset = node->Mset();        
      if (!node->Mset().empty()) {  
        msg_send[Mset[0]] = "accept";
        node->set_msg_send(msg_send);
        node->set_state(State("MS"));
        node->set_matched_port(Mset[0]);          
      }
      if (node->Xset().empty()) {
        node->set_state(State("US"));
      }
      return;
    }
  }      
}

void BMM::Receive(Node* node, int round_idx) {
  if (round_idx % 2 == 1) {      // round = 2k - 1
    if (node->color() == 1) {    // black node
      if (node->state() == "UR") {
        std::vector<Node*> port = node->port();  
        for (int i = 0; i < port.size(); ++i) {
          std::vector<Node*> port_sender = port[i]->port();
          for (int j = 0; j < port_sender.size(); ++j) {
            if (port_sender[j]->idx() == node->idx()) {
              MessageSet msg_send_sender = port[i]->msg_send();
              if (msg_send_sender[j] == "matched") {  
              // remove the port from X                  
                std::vector<int> Xset = node->Xset();
                for (int k = 0; k < Xset.size(); ++k) {
                  if (Xset[k] == i) {
                    Xset.erase(Xset.begin() + k);
                    node->set_Xset(Xset);
                    return;
                  }
                }
              } else if (msg_send_sender[j] == "proposal") {
                std::vector<int> Mset = node->Mset();
                Mset.push_back(i);
                node->set_Mset(Mset);
                return;
              }
            }
          }
        }
      }
    }
  } else {  // round = 2k 
    if (node->color() == 0) {    // white node
      if (node->state() == "UR") {
        std::vector<Node*> port = node->port();  
        for (int i = 0; i < port.size(); ++i) {
          std::vector<Node*> port_sender = port[i]->port();
          for (int j = 0; j < port_sender.size(); ++j) {
            if (port_sender[j]->idx() == node->idx()) {
              MessageSet msg_send_sender = port[i]->msg_send();
              if (msg_send_sender[j] == "accept") {  
                node->set_state(State("MR"));   
                node->set_matched_port(i);
                return;
              }
            }
          }
        }
      }
    }       
  }      
}

bool BMM::Stop(Node* node) {
  if (node->state() == "US" || node->state() == "MS") {
    return 1;
  } else {
    return 0;
  }
}

void BMM::PrintOutput(Node* node) {
  if (node->state() == "MS") {
    std::vector<Node*> port = node->port();
    std::cout << "node " << node->idx() << " - node " << port[node->matched_port()]->idx() << std::endl;
  }    
}  