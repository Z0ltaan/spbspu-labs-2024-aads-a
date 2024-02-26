#include <iostream>

#include "list.hpp"
#include "list.cpp"

#include "node.hpp"
#include "node.cpp"

int main()
{ 
  using namespace arakelyan;

  List<double> list;
  double var = 1;

  list.push_back(15);
  list.printList(std::cout);
  std::cout << "\n";

  list.push_front(17);
  list.printList(std::cout);
  std::cout << "\n";

  list.pop_front();
  list.printList(std::cout);
  std::cout << "\n";

  list.push_back(16);
  list.printList(std::cout);
  std::cout << "\n";

  list.pop_back();
  list.printList(std::cout);
  std::cout << "\n";
  do
  {
    std::cin >> var;
    if (list.isEmpty())
    {
      std::cout << "list empty!\n";
    }
    else
    {
      std::cout << "here some data!\n";
    }
    list.push_back(var);
    list.printList(std::cout);
    std::cout << "\n";
  }
  while (var != 0);

  return 0;
}
