// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
  struct ITEM {
    T data;
    ITEM* next;
    ITEM* prev;
  };
  ITEM* create(const T&);
  ITEM* head;
  ITEM* tail;

 public:
  TPQueue():head(nullptr), tail(nullptr) {}
  TPQueue(const T&);
  TPQueue(const TPQueue&);
  ~TPQueue();
  void addTail(const T&);
  void addHead(const T&);
  T rmHead();
  T rmTail();
  bool isEmpty() const;
  void insert(const T&, const T&);
  T pop();
  void push(const T&);
  void print() const;
};
template <typename T>
TPQueue<T> :: TPQueue(const T& data) {
  head = tail = create(data);
}
template <typename T>
TPQueue<T> :: ~TPQueue() {
  while (head)
    rmHead();
}
template <typename T>
typename TPQueue<T> :: ITEM* TPQueue<T> :: create(const T& data) {
  ITEM* item = new ITEM;
  item->data.ch = data.ch;
  item->data.prior = data.prior;
  item->next = nullptr;
  item->prev = nullptr;
  return item;
}
template <typename T>
void TPQueue<T> :: addHead(const T& data) {
  if (tail && head) {
    ITEM* temp = create(data);
    temp->next = head;
    temp->next->prev = temp;
    head = temp;
  }
  else {
    head = create(data);
    tail = head;
  }
}
template <typename T>
  T TPQueue<T> :: rmHead() {
    if (head) {
      ITEM* temp = head->next;
      if (temp)
        temp->prev = nullptr;
      T data = head->data;
      delete head;
      head = temp;
      return data;
  }
  else {
    throw std::string ("Empty!");
  }
}
//template <typename T>
//T TPQueue<T> :: rmTail() {
//  if (head && tail) {
//    ITEM* temp = tail->prev;
//  if (temp)
//    temp->next = nullptr;
//    T data = tail->data;
//    delete tail;
//    tail = temp;
//    return data;
//  }
//  else {
//   throw std::string ("Empty!") ;
//  }
//}
template <typename T>
bool TPQueue <T> :: isEmpty() const {
  return !head;
}
template <typename T>
void TPQueue<T> :: insert(const T& data, const T& value) {
  ITEM* temp = head;
  ITEM* item = create(value);
  //while ( temp && temp->data != data )
  while (temp && (temp->data.prior) > (value.prior))
    temp = temp->next;
  if (!temp && head) {
    tail->next = item;
    tail->next->prev = tail;
    tail = item;
  }
  else if (!temp && !head) {
    head = tail = item;
  }
  else if (!temp->prev) {
    temp->prev = item;
    item->next = temp;
    head = item;
  }
  else {
    temp->prev->next = item;
    item->prev = temp->prev;
    item->next = temp;
    temp->prev = item;
  }
}
template <typename T>
T TPQueue<T> :: pop() {
  return rmHead();
}
template <typename T>
void TPQueue<T> ::push(const T& data) {
  if (isEmpty())
    addHead(data);
  else {
    ITEM* te = head;
    //te->data.prior;
    //while ((te->data.prior)>data.prior) 
    //  te = te->next;
    insert(te->data, data);
  }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
