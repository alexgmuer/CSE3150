#include "Simulator.hpp"
#include "buffer.hpp"
#include "server.hpp"
#include "generator.hpp"
#include <fstream>
#include <assert.h>

using namespace std;

static string readIdentifier(istream& is)
{
   string rv;
   do {
      while (is.good()) {
         char ch = 0;
         is.get(ch);
         if (ch == '=' || ch==',' || ch=='(' || ch==')' || ch=='[' || ch == ']' || ch=='-' || ch=='>' || isspace(ch) || ch==0)
            break;
         rv.push_back(ch);
      }
   } while (rv.length() == 0 && is.good());
   return rv;
}

Simulator::Simulator()
   : _lastEvt(0),
     _lastCli(0)
{
   _builders["FIFO"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         char ch2;
         is.get(ch2);
         Buffer* b = new FIFO(name);
         this->addComponent(name,b);
      });
   
   _builders["ServerExp"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         char ch2;
         double rate;
         is >> rate;
         is.get(ch2);     
         Server* s = new ServerExponential(name,rate);
         this->addComponent(name,s);
      });
   _builders["ServerCst"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         char ch2;
         double time;
         is >> time;
         is.get(ch2);
         Server* s = new ServerConstant(name,time);
         this->addComponent(name,s);
      });
   _builders["ServerNormal"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         char ch2;
         double mean,deviation;
         is >> mean;
         is.get(ch2);
         is >> deviation;
         is.get(ch2);
         Server* s = new ServerNormal(name,mean,deviation);
         this->addComponent(name,s);
      });
   _builders["Exit"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         Server* s = new ServerExit(name);
         this->addComponent(name,s);
      });
   _builders["Poisson"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         char ch2;
         double rate;
         is >> rate;
         is.get(ch2);     
         Generator::Generator* s = new Generator::Poisson(name,rate);
         this->addComponent(name,s);
         _gens.push_back(s);
      });
   _builders["Dispatch"] = function<void(std::istream&,const std::string& name)>([this](istream& is,const std::string& name) {
         Dispatcher* d = new Dispatcher(name);
         bool more=true;
         char ch;
         do {
            double p;
            string id = readIdentifier(is);
            is >> p;
            is.get(ch);
            assert(ch==')');
            is.get(ch);
            more = (ch== ',');
            if (this->hasComponent(id)) {
              Component* cid = this->getComponent(id);
              d->addRule(cid,p);
            } else {
               cerr << "We do not have a component named: " << id
                    << ". Yet it is referred to by the dispatcher " << name << endl;
               exit(1);
            }
         } while(more);
         assert(ch==']');
         is.get(ch);
         assert(ch == ')');         
         this->addComponent(name,d);
      });
}

void Simulator::addComponent(const std::string& key,Component* c)
{
   _cps[key] = c;
}

bool Simulator::hasComponent(const std::string& key) const
{
   auto it = _cps.find(key);
   return (it != _cps.end());      
}

Component* Simulator::getComponent(const std::string& key) 
{
   assert(hasComponent(key) == true);
   return _cps[key];
}

void Simulator::read(const char* fn)
{
   
   ifstream inf(fn);
   while (inf.good()) {
      string key,type;
      key = readIdentifier(inf);
      if (key.length() > 0) {
         if (inf.peek() == '>') {
            string end = readIdentifier(inf);
            if (hasComponent(key) && hasComponent(end)) {
               getComponent(key)->addTarget(getComponent(end));
            } else {
               cerr << "We do not have component(s) for the names:" << key << " or " << end << endl;
               exit(1);
            }
         } else {
            type = readIdentifier(inf);
            auto& b = _builders[type];
            b(inf,key);
         }
      }       
   }   
}


void Simulator::run(double h)
{
  _horizon = h;
  cout << *this << endl;
}

std::ostream& operator<<(ostream& os,const Simulator& s)
{
   for(auto c : s._cps) 
      os << c.first << " --> " << *c.second << endl;   
   return os;
}
