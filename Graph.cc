#include <iostream>
#include <vector>
#include <random>

#include "Graph.h"
#include "typedef.h"


void Graph::Init() {
  
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0,1.0);

  if (type_ == "random") {
    for (int i = 0; i < node_num_; ++i) {
      std::vector<int> empty_set; 
      adj_list_.push_back(empty_set);
    }

    for (int i = 0; i < node_num_; ++i) {
      for (int j = i+1; j < node_num_; ++j) {
        double rand_num = distribution(generator);
        if (rand_num < connectivity_) {
          adj_list_[i].push_back(j);
          adj_list_[j].push_back(i);
        }
      }
    }

    for (int i = 0; i < node_num_; ++i) {
      node_color_.push_back(0);
    }

  } else if ((type_ == "bipartite") ) {
    for (int i = 0; i < node_num_; ++i) {
      std::vector<int> empty_set; 
      adj_list_.push_back(empty_set);
    }

    for (int i = 0; i < node_num_/2; ++i) {
      for (int j = node_num_/2; j < node_num_; ++j) {
        double rand_num = distribution(generator);
        if (rand_num < connectivity_) {
          adj_list_[i].push_back(j);
          adj_list_[j].push_back(i);
        }
      }
    }
       
    for (int i = 0; i < node_num_; ++i) {
      if (i < node_num_/2) {
        node_color_.push_back(0);
      } else {
        node_color_.push_back(1);
      }
      
    }   

  } else {
    std::cerr << "unknown graph type" << std::endl;
  }
}

void Graph::PrintGraph() {
  for (int i = 0; i < adj_list_.size(); ++i) {
    std::cout << "node " << i << " neighbors: ";
    for (int j = 0; j < adj_list_[i].size(); ++j) {
      std::cout << adj_list_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}