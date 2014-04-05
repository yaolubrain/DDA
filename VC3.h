#ifndef VC3_H
#define VC3_H

#include <vector>
#include "Node.h"
#include "BMM.h"

class VC3 : public Node {
 public:
  typedef std::pair<BMM::State, BMM::State> State;
  typedef std::pair<BMM::Message, BMM::Message> Message;

  VC3(int idx, int color) {
    idx_ = idx;
    color_ = color;
  }
  ~VC3() {}

  void Init();
  void Send(int round_idx);
  void Receive(int round_idx);
  void PrintOutput();
  bool Stop();
  void ClearMsgSend();

 private:
  State state_;
  std::vector<Message> msg_send_;
  std::set<int> Xset_;
  std::set<int> Mset_;

};


#endif