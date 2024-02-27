#ifndef __AFD_H__
#define __AFD_H__
#include "AFDNode.h"
#include <list>
template <class T, class C> 
class AFD {
protected:
  std::list<AFDNode<T, C> *> nodes;
  T initialState;
  T currentState;
  T finalState;
  bool stuck;
public:
  AFD(T initState);
  ~AFD();
  void addNode(T value);
  void deleteNode(T value);
  void addAwn(T value1, T value2, C path);
  void deleteAwn(T value1, C path);
  AFDNode<T, C> *findNode(T value);
  std::list<AFDNode<T, C> *> getNodes();
  T getFinalState();
  void setFinalState(T initState);
  T getInitialState();
  void setInitialState(T initState);
  T getCurrentState();
  void evaluate(C path);
  bool accepted();
};
#include "AFD.hxx"
#endif // AFD_H
