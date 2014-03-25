#ifndef BMM_H
#define BMM_H

#include <vector>
#include "Node.h"

class BMM : public Node {
 public:
  enum class State {UR, MR, US, MS};
  enum class Message {proposal, matched, accept, empty};

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