#ifndef AFD_HXX
#define AFD_HXX
#include <iostream>
#include "AFD.h"
//constructor
template<class T, class C>
AFD<T,C>::AFD(T initState)
{
  this->initialState = initState;
  this->currentState = initState;
  this->stuck = false;
  addNode(initState);
}
//destructor
template<class T, class C>
AFD<T,C>::~AFD()
{
  delete this->finalState;
  delete this->nodes;
}
//searchs for a node and returns it
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
//adds a node/state
template<class T, class C>
void AFD<T,C>::addNode(T value)
{
  this->nodes.push_back(new AFDNode<T,C>(value));
}
//deletes a node
template<class T, class C>
void AFD<T,C>::deleteNode(T value)
{
  this->nodes.remove(findNode(value));
}
//adds an awn or "path" to connect 2 nodes/states
template<class T, class C>
void AFD<T,C>::addAwn(T value1, T value2, C path)
{ 
  AFDNode<T,C>* target = findNode(value1);
  target->addAwn(findNode(value2), path);
}
//deletes a path between 2 nodes/states
template<class T, class C>
void AFD<T,C>::deleteAwn(C path)
{
  this->nodes.remove(findNode(path));
}
//returns all the nodes/states of the DFA
template<class T, class C>
std::list<AFDNode<T,C>* > AFD<T,C>::getNodes()
{
  return this->nodes;
}
//returns the final state of the DFA
template<class T, class C>
T AFD<T,C>::getFinalState()
{
  return this->finalState;
}
//allows you to set the final state of the DFA
template<class T, class C>
void AFD<T,C>::setFinalState(T finalState)
{
  this->finalState = finalState;
}
//returns the initial state of the DFA
template <class T, class C>
T AFD<T,C>::getInitialState()
{
  return this->initialState;
}
//set the initial state of the DFA
template <class T, class C>
void AFD<T,C>::setInitialState(T initState)
{
  this->initialState = initState;
  this->currentState = initState;
}
//evaluates an input, searching for a path with the same value as the input that goes from the current state to another state, if there isn't such a path it stays in its current state
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
  else
  {
    this->stuck = true;
  }
}
//returns the current state
template <class T, class C>
T AFD<T,C>::getCurrentState()
{
  return this->currentState;
}
//call this function at the end to evaluate wether the input was accepted or rejected
template <class T, class C>
bool AFD<T,C>::accepted()
{
  return ((this->currentState == this->finalState) && !stuck);
}
#endif
