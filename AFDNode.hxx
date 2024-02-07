#ifndef AFDNode_HXX
#define AFDNode_HXX
#include "AFDNode.h"
template<class T, class C>
AFDNode<T,C>::AFDNode(T value)
{
  this->value = value;
}
template<class T, class C>
AFDNode<T,C>::~AFDNode()
{
  delete this->value;
  delete this->awns;
}
template<class T, class C>
std::list<std::pair<C,AFDNode<T,C>*> > AFDNode<T,C>::getAwns()
{
  return this->awns;
}
template<class T, class C>
void AFDNode<T,C>::setValue(T value)
{
  this->value = value;
}
template<class T, class C>
T AFDNode<T,C>::getValue()
{
  return this->value;
}

template<class T, class C>
void AFDNode<T,C>::addAwn(AFDNode<T,C>* newNode, C path)
{
  this->awns.push_back(std::make_pair(path,newNode));
}
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