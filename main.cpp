#include "list.h"
#include <iostream>
int main() {
  linked_list l1, l2;
  for (int i = 0; i < 100; i++) {
    l1.push_back(l1.back() + rand() % 20);
    l2.push_back(l2.back() + rand() % 20);
  }
  int nr = 50;
  if (l1.is_empty() && l2.is_empty() && l1.size() >= nr && l2.size() >= nr) {
    if (l1.at(nr) > l2.at(nr)) {
      l1.remove(nr);
    } else if (l1.at(nr) < l2.at(nr)) {
      l2.remove(nr);
    }
  }

  linked_list l3, l4;
  l3.push_front(1);
  l3 = l1;
  int nr2 = l3.size() / 2;
  for (int i = 0; i < nr2; i++) {
    l3.pop_back();
    l3.push_front(l3.pop_back());
  }
  if (nr2 % 2 == 1) {
    l3.pop_back();
  }
  print_list(l3);
  return 0;
}