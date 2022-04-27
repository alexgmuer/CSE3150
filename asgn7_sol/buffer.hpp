#ifndef __BUFFER_H
#define __BUFFER_H

#include <queue>
#include <iostream>
#include "component.hpp"

class Buffer: public Component {
protected:
   Component* _target;
   void addTarget(Component* c2);
public:
   Buffer(const std::string& n) : Component(n) {  _target = nullptr;}
   virtual ~Buffer() {}
   Component* getTarget() { return _target;}
};

class FIFO : public Buffer {
protected:
   std::ostream& print(std::ostream& os)  const;
public:
   FIFO(const std::string& n) : Buffer(n)  {}
   ~FIFO() {}
};
  
#endif
