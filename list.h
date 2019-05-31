#ifndef LABB3_LIST_H
#define LABB3_LIST_H
#include <cstdio>
#include <iostream>

#endif // LABB3_LIST_H

void test_msg(std::string str);

class linked_list {
public:
  linked_list();
  linked_list(const linked_list &src);
  ~linked_list();
  linked_list &operator=(const linked_list &rhs);
  // adds elements to the back.
  linked_list &operator+=(const linked_list &rhs);
  // inserting elements void insert(double value, size_t pos);
  void push_front(double value); // in front
  void push_back(double value);  // in back
  // accessing elements
  double front() const;
  double back() const;
  double at(size_t pos) const;
  // removing elements
  void remove(size_t pos);
  // and access
  double pop_front();
  double pop_back();
  // informational
  size_t size() const;
  bool is_empty() const;
  // output
  void print() const;
  void print_reverse() const;
private:
  struct node_t {
    node_t(double value, node_t *next = nullptr, node_t *prev = nullptr);
    double value;
    node_t *next;
    node_t *prev;
  };
  node_t *head;
  node_t *tail;
};
void print_list(linked_list &list);