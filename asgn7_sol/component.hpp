#ifndef __COMPONENT_H
#define __COMPONENT_H

#include <iostream>

class Simulator;
class Buffer;

class Component {
protected:
   const std::string _name;
   virtual std::ostream& print(std::ostream& os) const       { return os << _name;}
public:
   Component(const std::string& n) : _name(n) {}
   virtual ~Component() {}
   virtual void setFeed(Buffer* b)       {}
   virtual void addTarget(Component* c2) {}
   virtual Component* getTarget() { return nullptr;}
   const std::string& getName()   { return _name;}
   friend std::ostream& operator<<(std::ostream& os,const Component& s) {
      return s.print(os);
   }
};

#endif
