#ifndef AFD_HXX
#define AFD_HXX
#include <iostream>
#include "AFD.h"
template<class T, class C>
AFD<T,C>::AFD(T initState)
{
  this->initialState = initState;
  this->currentState = initState;
  addNode(initState);
}
template<class T, class C>
AFD<T,C>::~AFD()
{
  delete this->finalState;
  delete this->nodes;
}
template<class T, class C>
AFDNode<T,C>* AFD<T,C>::findNode(T value)
{
  AFDNode<T,C>* target;
  typename std::list<AFDNode<T,C>*>::iterator it = this->nodes.begin();
  while(it != this->nodes.end())
    {
      if((*it)->getValue() == value)
      {
        target = *it;
      }
      it++;
    }
  return target;
}
template<class T, class C>
void AFD<T,C>::addNode(T value)
{
  this->nodes.push_back(new AFDNode<T,C>(value));
}
template<class T, class C>
void AFD<T,C>::deleteNode(T value)
{
  this->nodes.remove(findNode(value));
}
template<class T, class C>
void AFD<T,C>::addAwn(T value1, T value2, C path)
{ 
  AFDNode<T,C>* target = findNode(value1);
  target->addAwn(findNode(value2), path);
}
template<class T, class C>
void AFD<T,C>::deleteAwn(C path)
{
  this->nodes.remove(findNode(path));
}
template<class T, class C>
std::list<AFDNode<T,C>* > AFD<T,C>::getNodes()
{
  return this->nodes;
}
template<class T, class C>
T AFD<T,C>::getFinalState()
{
  return this->finalState;
}
template<class T, class C>
void AFD<T,C>::setFinalState(T finalState)
{
  this->finalState = finalState;
}
template <class T, class C>
T AFD<T,C>::getInitialState()
{
  return this->initialState;
}
template <class T, class C>
void AFD<T,C>::setInitialState(T initState)
{
  this->initialState = initState;
  this->currentState = initState;
}
template <class T, class C>
void AFD<T,C>::evaluate(C path)
{
  AFDNode<T,C>* target = findNode(this->currentState);
  bool exists = target->hasAwn(path);
  std::pair<C,AFDNode<T,C>*> newPath = target->findAwn(path);
  if(exists)
  {
    this->currentState = (newPath.second)->getValue();
  }
}
template <class T, class C>
T AFD<T,C>::getCurrentState()
{
  return this->currentState;
}
template <class T, class C>
bool AFD<T,C>::accepted()
{
  return (this->currentState == this->finalState);
}
#endif