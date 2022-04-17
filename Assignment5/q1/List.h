#ifndef __LIST_H
#define __LIST_H
#include <memory>
#include <iostream>
#include <functional>

using namespace std;
template <class T>
class List {
	public:
			class Node {
					friend class List<T>;
					T               data;           // The data in this node of the list
					Node*           next;           // Pointer to the next node in the list
					Node(T d, Node* succ) {data = move(d); next = succ;}
			};

	private:
			Node*   head;

	public:
			List() { head = nullptr; }
			
			~List() {
					while(head != nullptr) {
					auto nextNode = move(head->next);       // Get the next Node.
					delete head;
					head = move(nextNode);                  // Overwrite head with next Node. Cpp will do auto delete 
					}
				}
			
			void insert(const T& v) 
				{
					Node* node = new Node(v, head);
					head = node;
				}
			
			void append(const T& v) 
				{
					Node* node = new Node(v, nullptr);
					auto curNode = head;
					if (curNode == nullptr) {
						head = node;
					}
					else {
						while (curNode->next != nullptr) {
							curNode = curNode->next;
						}
						curNode->next = node;
					}
				}
			// Unique Pointer Versions 

			void insert(T&& v)
				{
				head = new Node(move(v), head);
				}

			void append(T&& v)
				{
					Node* node = new Node(move(v), nullptr);
					auto curNode = move(head);
					if(curNode == nullptr) {
						head = move(node);
					}
					else {
						while (curNode->next != nullptr) {
							curNode = move(curNode->next);
						}
						curNode->next = move(node);
						}
				}

};
#endif