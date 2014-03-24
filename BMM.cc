#include <vector>
#include "BMM.h"
#include "DDA.h"
#include "Node.h"
#include "typedef.h"

int BMM::max_round(int node_num) {
  return 2 * node_num;
}

void BMM::InitNode(Node* node) { 
  if (node->degree() == 0) {
    node->set_state(State("US"));    
    return;
  }

  node->set_state(State("UR"));    
  if (node->color() == 1) {
    for (int i = 0; i < node->degree(); ++i) {
      node->insert_Xset(i);
    }
  }
}

void BMM::Send(Node* node, int round_idx) {

  if (round_idx % 2 == 1) {      // round = 2k - 1  
    int k = (round_idx+1)/2;
    if (node->color() == 0) {    // white node
      if (node->state() == "UR") {
        if (k <= node->degree()) {  // k <= deg(v)
          node->set_msg_send(std::string("proposal"), k-1);
          return;
        } else {                    // k > deg(v)
          node->set_state(State("US"));   
        } 
      } else if (node->state() == "MR") {
        node->msg_send_all_matched();
        node->set_state(State("MS"));       // no need to set_matched_port since it doesn't change          
        return;
      }
    } 
  } else {                        // round = 2k 
    if (node->color() == 1) {     // black node
      if (!node->empty_Mset()) {  
        node->set_msg_send(Message("accept"), node->min_Mset());
        node->set_state(State("MS"));
        node->set_matched_port(node->min_Mset());          
      }
      if (node->empty_Xset()) {
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
          int send_port = port[i]->port_hash(node->idx());
          Message msg = port[i]->msg_send(send_port);
          if (msg == "matched") {  
            node->erase_Xset(i);
          } else if (msg == "proposal") {
            node->insert_Mset(i);
          }
        }
      }
    }
  } else {  // round = 2k 
    if (node->color() == 0) {    // white node
      if (node->state() == "UR") {
        std::vector<Node*> port = node->port();  
        for (int i = 0; i < port.size(); ++i) {
          int send_port = port[i]->port_hash(node->idx());
          Message msg = port[i]->msg_send(send_port);
          if (msg == "accept") {  
            node->set_state(State("MR"));   
            node->set_matched_port(i);
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