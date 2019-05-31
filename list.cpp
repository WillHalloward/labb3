#include "list.h"
linked_list::linked_list() {
  head = nullptr;
  tail = nullptr;
};
linked_list::linked_list(const linked_list &src) {}
linked_list::~linked_list() = default;
linked_list &linked_list::operator=(const linked_list &rhs) {
  node_t *temp;
  temp = rhs.head;
  if (is_empty()) {
    while (head != nullptr) {
      remove(0);
    }
  }
  while (temp != nullptr) {
    push_back(temp->value);
    temp = temp->next;
  }
  return *this;
}
linked_list &linked_list::operator+=(const linked_list &rhs) {
  node_t *temp;
  temp = rhs.head;
  while (temp != nullptr) {
    push_back(temp->value);
    temp = temp->next;
  }
  return *this;
}
void linked_list::push_front(double value) {
  node_t *temp = new node_t(value, nullptr, nullptr);
  if (head != nullptr) {
    temp->next = head;
    head->prev = temp;
    temp->value = value;
    head = temp;
  } else {
    head = temp;
    tail = temp;
    temp->value = value;
  }
}

void linked_list::push_back(double value) {
  node_t *temp = new node_t(value, nullptr, nullptr);
  if (tail != nullptr) {
    temp->prev = tail;
    tail->next = temp;
    temp->value = value;
    tail = temp;
  } else {
    head = temp;
    tail = temp;
    temp->value = value;
  }
}
double linked_list::front() const { return head ? head->value : 0; }
double linked_list::back() const { return tail ? tail->value : 0; }

double linked_list::at(size_t pos) const {
  node_t *iter = head;
  int i = 0;
  while (iter != nullptr) {
    if (i == pos) {
      return iter->value;
    }
    iter = iter->next;
    i++;
  }
  return 0;
}
void linked_list::remove(size_t pos) {
  node_t *iter1 = head;
  node_t *iter2;
  int i = 0;
  while (iter1 != nullptr) {
    if (i == pos) {
      if (iter1 == head && iter1 == tail) {
        head = nullptr;
        tail = nullptr;
        delete (iter1);
      } else if (iter1 == head) {
        iter1 = iter1->next;
        iter1->prev = nullptr;
        head = iter1;
      } else if (iter1 == tail) {
        iter1 = iter1->prev;
        iter1->next = nullptr;
        tail = iter1;
      } else {
        iter2 = iter1;
        iter1 = iter1->next;
        iter2 = iter2->prev;
        iter1->prev = iter2;
        iter2->next = iter1;
      }
    }
    iter1 = iter1->next;
    i++;
  }
}
double linked_list::pop_front() {
  head->next->prev = nullptr;
  double r_value = head->value;
  head = head->next;
  return r_value;
}
double linked_list::pop_back() {
  tail->prev->next = nullptr;
  double r_value = tail->value;
  delete (tail);
  tail = tail->prev;
  return r_value;
}
size_t linked_list::size() const {
  int x = 0;
  node_t *temp = head;
  while (temp != nullptr) {
    x++;
    temp = temp->next;
  }
  return x;
}
bool linked_list::is_empty() const { return head != nullptr; }
void print_list(linked_list &list) { list.print(); }
void linked_list::print() const {
  node_t *iter = head;
  int i = 0;
  while (iter != nullptr) {
    std::cout << iter->value << " " << i << "\n";
    iter = iter->next;
    i++;
  }
}
void linked_list::print_reverse() const {}
linked_list::node_t::node_t(double value, linked_list::node_t *next,
                            linked_list::node_t *prev) {}

void test_msg(std::string str) { std::cout << str << "\n"; }

void merge(linked_list list1, linked_list list2, linked_list list3) {}