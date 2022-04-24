#include "server.hpp"
#include "Simulator.hpp"
#include "buffer.hpp"
#include <assert.h>

Server::Server(const std::string& n)
   : Component(n)
{
   _target = nullptr;   
}

ServerExponential::ServerExponential(const std::string& n,double r)
   : Server(n),
     _rate(r)
{}   

std::ostream& ServerExponential::print(std::ostream& os)  const
{
   return os << _name <<   "=ServerExp(" << _rate << ','
             << "target=" << _target->getName() << ")";
}

double ServerExponential::sampleServiceTime() 
{
   return 0.0; // TODO
}

ServerNormal::ServerNormal(const std::string& n,double m,double d)
   : Server(n),
     _mean(m),
     _deviation(d)
{
}   

std::ostream& ServerNormal::print(std::ostream& os)  const
{
   return os << _name <<   "=ServerNormal(" << _mean << ',' << _deviation
             << ',' << "target=" << _target->getName() << ")";
}

double ServerNormal::sampleServiceTime() 
{
   return 0.0; // TODO
}

ServerConstant::ServerConstant(const std::string& n,double d)
   : Server(n),_dur(d)
{}   

double ServerConstant::sampleServiceTime() 
{
   return _dur;
}

std::ostream& ServerConstant::print(std::ostream& os)  const
{
   return os << _name <<   "=ServerCst(" << _dur << ','
             << "target=" << _target->getName() << ")";
}

std::ostream& Dispatcher::print(std::ostream& os)  const
{
   os << _name << "=Dispatch([";
   for(auto p : _rules) 
      os << '(' << p.first->getName() << ',' << p.second << ')' << ',';   
   return os << '\b' << "])";
}

Dispatcher::Dispatcher(const std::string& n)
   : Server(n)
{}

void Dispatcher::addRule(Component* c,double prob)
{
   _rules.push_back(std::pair<Component*,double>(c,prob));
}
