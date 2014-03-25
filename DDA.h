#ifndef DDA_H
#define DDA_H 

#include "Node.h"
#include "typedef.h"

class DDA {
 public:
  DDA() {}
  ~DDA() {}
  
  virtual int max_round(int node_num) {}
  virtual void InitNode() {}
  virtual void Send(int round_idx) {}
  virtual void Receive(int round_idx) {}  
  virtual bool stop() {}  
  virtual void PrintOutput() {}  
};

#endif