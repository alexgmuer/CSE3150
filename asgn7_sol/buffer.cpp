#include "buffer.hpp"
#include <assert.h>
#include "Simulator.hpp"

void Buffer::addTarget(Component* c2)
{
   _target = c2;
   c2->setFeed(this);
}

std::ostream& FIFO::print(std::ostream& os)  const
{
   assert(_target != nullptr);
   return os <<  _name << "=FIFO(target = " << _target->getName() << ")";
}


