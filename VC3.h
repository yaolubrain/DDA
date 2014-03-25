#ifndef VC3_H
#define VC3_H

#include <vector>
#include "Node.h"
#include "typedef.h"

class VC3 : public Node {

  typedef std::pair<std::string, std::string> State;
  typedef std::pair<std::string, std::string> Message;

 public:
  VC3(int idx, int color) {
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