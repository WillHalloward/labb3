#include "list.h"
linked_list::linked_list() = default;
linked_list::linked_list(const linked_list &src) {

}
linked_list::~linked_list() = default;
linked_list &linked_list::operator=(const linked_list &rhs) {
  return <#initializer #>;
}
linked_list &linked_list::operator+=(const linked_list &rhs) {
  return <#initializer #>;
}
void linked_list::push_front(double value) {
  node_t *temp = new node_t(value, nullptr, nullptr);
  if (head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}
void linked_list::push_back(double value) {

}
double linked_list::front() const {
  return 0;
}
double linked_list::back() const {
  return 0;
}
double linked_list::at(size_t pos) const {
  return 0;
}
void linked_list::remove(size_t pos) {

}
double linked_list::pop_front() {
  return 0;
}
double linked_list::pop_back() {
  return 0;
}
size_t linked_list::size() const {
  return 0;
}
bool linked_list::is_empty() const {
  return false;
}
void linked_list::print() const {

}
void linked_list::print_reverse() const {

}
linked_list::node_t::node_t(double value, linked_list::node_t *next,
                            linked_list::node_t *prev) {

}
