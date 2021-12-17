

#include "LinkedList.h"

template<class T>
Node<T> *new_node(T new_value) {
    Node<T> *ans = (Node <T> *)calloc (1, sizeof(Node<T>));
    ans->set_value(new_value);
    ans->set_next_node(NULL);
    return ans;
}

template<class T>
T Node<T>::get_value() {
    return this->value;
}

template<class T>
void Node<T>::set_value(T new_value) {
    this->value = new_value;
}

template<class T>
Node<T> *Node<T>::get_next_node() {
    return this->next;
}

template<class T>
void Node<T>::set_next_node(Node <T> *new_nod) {
    this->next = new_nod;
}

template<class T>
Node<T>::~Node<T>()
{
    free (this);
}

template<class T>
Node<T>::Node()
{
    this->next = NULL;
}

template<class T>
T *Node<T>::GetValuePointer()
{
    return &(this->value);
}

template<class T>
size_t LinkedList<T>::get_size() {
    size_t ans = 0;
    Node <T> *now = head;
    while (now != NULL)
    {
        ans++;
        now = now->get_next_node();
    }
    return ans;
}

template<class T>
LinkedList<T>::LinkedList() {
    head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(T *items, size_t size1) {
    head = new_node(items[0]);
    Node <T> *now = head;
    for (size_t i = 1; i < size1; i++)
    {
        now->set_next_node(new_node(items[i]));
        now = now->get_next_node();
    }
}


template<class T>
LinkedList<T>::LinkedList(LinkedList<T> * second_list) {
    head = new_node(second_list->get_i(0));
    Node <T> *now = head;
    for (size_t i = 1; i < second_list->get_size(); i++)
    {
        now->set_next_node(new_node(second_list->get_i(i)));
        now = now->get_next_node();
    }
}

template<class T>
T LinkedList<T>::get_first() {
    return head->get_value();
}

template<class T>
T LinkedList<T>::get_last() {
    return get_i(get_size() - 1);
}

template<class T>
T LinkedList<T>::get_i(size_t index) {
    Node <T> *now = head;
    for (size_t i = 0; i < index; i++)
        now = now->get_next_node();
    return now->get_value();
}

template<class T>
LinkedList<T> *LinkedList<T>::get_sublist(size_t begin, size_t end) {
    T *Data = (T *)calloc (end - begin + 1, sizeof(T));
    for (size_t i = begin; i < end + 1; i++)
    {
        Data[i - begin] = get_i(i);
    }
    LinkedList<T> *ans = (LinkedList<T> *) calloc (1, sizeof(LinkedList<T>));
    *ans = LinkedList<T>(Data, end - begin + 1);
    free(Data);
    return ans;
}

template<class T>
void LinkedList<T>::printList()
{
    Node<T> *now = this->head;
    size_t size = this->get_size();
    for (size_t i = 0; i < size; i++)
    {
        std::cout << now->get_value() << " ";
        now = now->get_next_node();
    }
    std::cout << "\n";
}

template<class T>
void LinkedList<T>::prepend(T new_value) {
    Node<T> *newNode = new_node(new_value);
    newNode->set_next_node(head);
    head = newNode;
}



template<class T>
void LinkedList<T>::append(T new_value) {
    if (this->head == NULL)
    {
        head = new_node (new_value);
        return;
    }
    Node<T> *now = head, *last = head;
    while (now != NULL)
    {
        last = now;
        now = now->get_next_node();
    }
    now = new_node(new_value);
    last->set_next_node(now);
}

template<class T>
void LinkedList<T>::insert(size_t index, T new_value) {
    if (this->get_size() == 0)
    {
        this->head = new_node(new_value);
        return;
    }
    if (index == 0)
    {
        prepend (new_value);
        return;
    }
    Node<T> *now = this->head, *prev = this->head;
    for (size_t i = 0; i < index; i++){
        prev = now;
        now = now->get_next_node();
    }
    Node<T> *newNode = new_node(new_value);
    prev->set_next_node(newNode);
    newNode->set_next_node(now);
}

template<class T>
LinkedList<T> *LinkedList<T>::concat(LinkedList<T> *list1, LinkedList<T> *list2) {
    LinkedList<T> *ans = new LinkedList<T>(list1);
    Node<T> *now = ans->head, *prev = ans->head;
    while (now != NULL)
    {
        prev = now;
        now = now->get_next_node();
    }
    prev->set_next_node(list2->head);
    return ans;
}

template <class T>
LinkedList<T> *LinkedList<T>::CopyLinkedList () {
    LinkedList <T> *ans = (LinkedList<T> *) calloc (1, sizeof (LinkedList <T>));
    Node<T> *now = this->head;
    size_t size = this->get_size();
    for (size_t i = 0; i < size; i++) {
        ans->append(now->get_value());
        now = now->get_next_node();
    }
    return ans;
}

template<class T>
void LinkedList<T>::DeleteLinkedList()
{
    Node <T> *now = this->head, *prev = this->head;
    while (now != NULL)
    {
        prev = now;
        now = now->get_next_node();
        free(prev);
    }
    delete this;
}

template<class T>
void LinkedList<T>::resize(size_t new_size)
{
    if (new_size == 0)
    {
        this->resize(1);
        head = NULL;
        return;
    }
    if (new_size > this->get_size())
        for (size_t i = this->get_size(); i < new_size; i++)
            this->append();
    else if (new_size < this->get_size())
    {
        Node<T> *begin = this->head;
        for (size_t i = 0; i < new_size - 1; i++)
            begin = begin->get_next_node();
        Node<T> *temp = begin->get_next_node();
        begin->set_next_node(NULL);
        while (temp != NULL)
        {
            Node<T> *prev = temp;
            temp = temp->get_next_node();
            free(prev);
        }
    }
}

template<class T>
void LinkedList<T>::set_i(size_t index, T value) {
    Node<T> *now = this->head;
    for (size_t i = 0; i < index; i++)
        now = now->get_next_node();
    now->set_value(value);
}

template<class T>
void LinkedList<T>::append()
{
    if (this->head == NULL)
    {
        head = new Node<T> ();
        return;
    }
    Node<T> *now = head, *last = head;
    while (now != NULL)
    {
        last = now;
        now = now->get_next_node();
    }
    now = new Node<T> ();
    last->set_next_node(now);
}

template<class T>
T *LinkedList<T>::GetPointer(size_t index) {
    Node<T> *now = this->head;
    for (size_t i = 0; i < index; i++)
        now = now->get_next_node();
    return now->GetValuePointer();
}
