#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    // TODO: Return the correct size of the list.
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
    Element* node = new Element{entry};
    node->next = head;
    head = node;
    ++current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    if(!head) return 0;
    Element* old_head = head;
    head = head->next;
    current_size--;
    int value = old_head->data;
    delete old_head;
    return value;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
    Element* prev=nullptr;
    Element* current=head;
    while(current)
    {
        Element* next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
    for (Element* e = head; e != nullptr;)
    {
        Element *next = e->next;
        delete e;
        e = next;
    }
}
}  // namespace simple_linked_list
