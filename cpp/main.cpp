
#include <iostream>
#include "QuadTree.hpp"

int main() {

  auto q = Quadtree(10,10,10);
  std::cout << q.max_depth << std::endl;

  return 0;
}
