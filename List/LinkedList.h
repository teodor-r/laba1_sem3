

#ifndef LAB2_VECTOR_LINKEDLIST_H
#define LAB2_VECTOR_LINKEDLIST_H
#include <iostream>
#include <cstdlib>

template <class T> class Node
{
protected:
    Node *next;
    T value;
public:
    Node ();
    Node<T> *get_next_node();
    void set_next_node(Node <T> *);
    T get_value ();
    T *GetValuePointer ();
    void set_value(T);
    ~Node<T> ();
};

template <class T>
Node<T> *new_node (T);

template <class T> class LinkedList
{
protected:
    Node<T> *head;
public:
    LinkedList ();
    LinkedList (T* , size_t);
    LinkedList (LinkedList <T> *);
    T get_first ();
    T get_last ();
    T get_i (size_t);
    void set_i (size_t, T);
    LinkedList <T> * get_sublist (size_t, size_t);
    size_t get_size();
    void resize(size_t);
    void append();
    void append(T);
    void prepend (T);
    void insert (size_t, T);
    void printList ();
    LinkedList <T> *concat (LinkedList <T> *, LinkedList <T> *);
    LinkedList <T> *CopyLinkedList ();
    void DeleteLinkedList();
    T *GetPointer (size_t);
};


#endif //LAB2_VECTOR_LINKEDLIST_H
