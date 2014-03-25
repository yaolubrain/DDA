#ifndef BMM_H
#define BMM_H

#include <vector>
#include "DDA.h"
#include "Node.h"

class BMM : public Node {
 public:
  typedef enum {UR, MR, US, MS} State;
  typedef enum {proposal, matched, accept, empty} Message;

  BMM(int idx, int color) {
    idx_ = idx;
    color_ = color;
  }
  ~BMM() {}

  void Init();
  void Send(int round_idx);
  void Receive(int round_idx);
  void PrintOutput();
  bool stop();
  void clear_msg_send();

 private:
  State state_;
  std::vector<Message> msg_send_;
  std::set<int> Xset_;
  std::set<int> Mset_;

};


#endif