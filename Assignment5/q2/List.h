#ifndef __LIST_H
#define __LIST_H
#include <memory>
#include <iostream>
#include <functional>

template <class T>
class List {
	public:
        class Node {
                friend class List<T>;
                T                       data;           // The data in this node of the list
                std::unique_ptr<Node>   next;           // Pointer to the next node in the list
                Node(T d, std::unique_ptr<Node> succ) {data = std::move(d); next = std::move(succ);}
                void append(std::unique_ptr<Node> newNode) {
                        if (next == nullptr) {
                                next = std::move(newNode);
                        }
                        else { next->append(std::move(newNode)); }
                }
                void getBodied(std::function<void(const T&)> body) {
                        body(data);
                        if (next == nullptr) return;
                        next->getBodied(body);
                }
        };
	private:
        std::unique_ptr<Node>   head;

	public:
        List() { head = nullptr; }
        ~List() { head.reset(); }
    
		void insert(const T& v) 
			{
                head = std::unique_ptr<Node>(new Node(v, std::move(head)));
            }
		
        void append(const T& v)		
			{
				if (head == nullptr) {
					head = std::unique_ptr<Node>(new Node(v, nullptr));
				}
				else {
					head->append(std::unique_ptr<Node>(new Node(v, nullptr)));
				}
			}

        void forEach(std::function<void(const T&)> body) 
			{
				head->getBodied(body);
			}
		
		void insert(T&& v) 
			{
				head = std::unique_ptr<Node>(new Node(std::move(v), std::move(head)));
			}
			
        void append(T&& v) 
			{
                if (head == nullptr) {
					head = std::unique_ptr<Node>(new Node(std::move(v), nullptr));
				}
				else {
					head->append(std::unique_ptr<Node>(new Node(std::move(v), nullptr)));
                }
            }
};

#endif