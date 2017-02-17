#include <algorithm>
#include <iostream>
#include <list>

static void print(const std::list<int> &list) {
  std::cout << "List: ";
  for (const auto &p : list) {
    std::cout << p << " "; // this works, but ...
  }
  std::cout << std::endl;
}

static void deleteVal(std::list<int> &list, int val) {
  list.erase(std::remove(list.begin(), list.end(), val), list.end());
  //
  // Read: Erase-Remove idiom for C++
  // https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
}

int main(int argc, char const *argv[]) {
  std::list<int> myList;
  myList.push_front(1);
  myList.push_front(2);
  myList.push_front(3);
  print(myList);
  deleteVal(myList, 2);
  print(myList);
  myList.push_front(2);
  print(myList);
  return 0;
}