#ifndef __SERVER_H
#define __SERVER_H

#include <random>
#include "component.hpp"

class Server: public Component {
protected:
   Component*           _target;
   Buffer*                _feed;
   void addTarget(Component* c2) { _target = c2;}
public:
   Server(const std::string& n);
   virtual ~Server() {}
   virtual double sampleServiceTime() = 0;
   void setFeed(Buffer* b) { _feed = b;}
   Component* getTarget()  { return _target;}  
};

class ServerExponential :public Server {
   double _rate;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerExponential(const std::string& n,double r);
   double sampleServiceTime();
};

class ServerNormal :public Server {
   double _mean,_deviation;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerNormal(const std::string& n,double m,double d);
   double sampleServiceTime();
};

class ServerConstant :public Server {
   double _dur;
   std::ostream& print(std::ostream& os)  const;
public:
   ServerConstant(const std::string& n,double d);
   double sampleServiceTime();
};

class ServerExit :public Server {
   std::ostream& print(std::ostream& os)  const { return os << _name <<  "=ServerExit()";}
public:
   ServerExit(const std::string& n) : Server(n) {}
   double sampleServiceTime() { return 0;}   
};

class Dispatcher :public Server {   
   std::vector<std::pair<Component*,double> > _rules;
   std::ostream& print(std::ostream& os)  const;
public:
   Dispatcher(const std::string& n);
   ~Dispatcher() {}
   void addRule(Component* c,double prob); 
   double sampleServiceTime() final { return 0;}     
};

#endif
