#ifndef AFDNode_HXX
#define AFDNode_HXX
#include "AFDNode.h"
//constructor
template<class T, class C>
AFDNode<T,C>::AFDNode(T value)
{
  this->value = value;
}
//destructor
template<class T, class C>
AFDNode<T,C>::~AFDNode()
{
  delete this->value;
  delete this->awns;
}
//returns the awns/paths that go from this node to another ones
template<class T, class C>
std::list<std::pair<C,AFDNode<T,C>*> > AFDNode<T,C>::getAwns()
{
  return this->awns;
}
//allows you to set the value of this node
template<class T, class C>
void AFDNode<T,C>::setValue(T value)
{
  this->value = value;
}
//returns the value of the node
template<class T, class C>
T AFDNode<T,C>::getValue()
{
  return this->value;
}
//adds a new awn/path for going from this node to another one
template<class T, class C>
void AFDNode<T,C>::addAwn(AFDNode<T,C>* newNode, C path)
{
  this->awns.push_back(std::make_pair(path,newNode));
}
//delete an awn/path
template<class T, class C>
void AFDNode<T,C>::deleteAwn(C path)
{
  typename std::list<std::pair<C,AFDNode<T,C>*> >::iterator it = this->awns.begin();
  while(it != this->awns.end())
    {
      if(it->first == path)
      {
        this->awns.erase(it);
        break;
      }
    }
}
//searchs for an awn/path in this node
template<class T, class C>
std::pair<C,AFDNode<T,C>*> AFDNode<T,C>::findAwn( C path)
{
  typename std::pair<C,AFDNode<T,C>*> target;
  typename std::list<std::pair<C,AFDNode<T,C>*> >::iterator it = this->awns.begin();
  while(it != this->awns.end())
    {
      if(it->first == path)
      {
        target = *it;
        break;
      }
      it++;
    }
  return target;
}

template<class T, class C>
bool AFDNode<T,C>::hasAwn(C path)
{
  bool exists = false;
  typename std::list<std::pair<C,AFDNode<T,C>*> >::iterator it = this->awns.begin();
  while(it != this->awns.end())
    {
      if(it->first == path)
      {
        exists = true;
        break;
      }
      it++;
    }
  return exists;
}
#endif
