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
                T                       _data;
                private:
                        std::shared_ptr<Node>   _next;
                //public:
                        Node(T d, std::shared_ptr<Node> succ) { _data = std::move(d), _next = succ;}
        };
private:
        std::shared_ptr<Node>   _head;
        std::shared_ptr<Node>   _tail;
public:
        class iterator {
                friend class List<T>;
				              friend class List<T>::Node;
                public:
                        //TODO
                        std::shared_ptr<Node>   currant;        // Hehe, fruit name
                        iterator(std::shared_ptr<Node> n) {currant = n;}
                        iterator(const iterator& o) { currant = o.currant;}
                        const T& operator*()        {
                                                return currant->_data;
                                        } // (dereference operator, returns the current element)
                        const iterator& operator++() {
                                                currant = currant->_next;
                                                return *this;
                                        } // (pre-increment operator. used for expressions such as ++i 
                        iterator operator++(int)     {
                                                auto old = *this;
                                                ++*this;
                                                return old;
                                        } // (post-increment operator, used for expressions such as i++
                        bool operator==(const iterator& i2) {
                                                return (currant == i2.currant);
                                        } // (equality operator. True if the receiver and i2 point to the same location)
                        bool operator!=(const iterator& i2) {
                                                return (currant != i2.currant);
                                        } // (disequality operator. Negation of equality ;-)). 
        };
        List() { _head = nullptr; _tail = nullptr;}
        ~List() {
                while (_head != _tail) {
                        auto nextNode = std::move(_head->_next);
                        _head.reset();
                        _head = std::move(nextNode);
                }
                _head.reset();
                _tail.reset();
        }
        std::shared_ptr<Node> insert(const T& v) {
                if (_tail == nullptr) {
                        _head = std::shared_ptr<Node>(new Node(v, _head));
                        _tail = _head;
                }
                else {
                        _head = std::shared_ptr<Node>(new Node(v, _head));
                }
                return _head;
        }
        std::shared_ptr<Node> insert(T&& v)      {
                if (_tail == nullptr ) {
                        _head = std::shared_ptr<Node>(new Node(std::move(v), _head));
																									std::shared_ptr<Node> insert(T&& v)      {
                if (_tail == nullptr ) {
                        _head = std::shared_ptr<Node>(new Node(std::move(v), _head));
                        _tail = _head;
                }
                else {
                        _head = std::shared_ptr<Node>(new Node(std::move(v), _head));
                }
                return _head;
        }

        std::shared_ptr<Node> append(const T& v) {
                if (_head == nullptr) {
                        _head = std::shared_ptr<Node>(new Node(v, nullptr));
                        _tail = _head;
                }
                else {
                        //_head->append(std::shared_ptr<Node>(new Node(v, nullptr)));
                        _tail->_next = std::shared_ptr<Node>(new Node(v, nullptr));
                        _tail = _tail->_next;
                }
                return _tail;
        }
        std::shared_ptr<Node> append(T&& v)      {

                if (_head == nullptr) {
                        _head = std::shared_ptr<Node>(new Node(std::move(v), nullptr));
                        _tail = _head;
                }
                else {
                        //_head->append(std::shared_ptr<Node>(new Node(std::move(v), nullptr)));
                        _tail->_next = std::shared_ptr<Node>(new Node(std::move(v), nullptr));
                        _tail = _tail->_next;
                }
                return _tail;
        }
        void  change(std::shared_ptr<Node>& loc,const T& v) {
                loc->_data = std::move(v);
        }
        iterator begin() const { return iterator(_head);}         // graciously provided ;-) [clearly, you'll need a _head]
        iterator end()  const  { return iterator(_tail->_next);}  // graciously provided ;-) [clearly, you'll need a _tail]
};

#endif