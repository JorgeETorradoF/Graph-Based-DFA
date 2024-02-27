#ifndef AFDNODE_H
#define AFDNODE_H
#include<list>
template<class T, class C>
class AFDNode
{
   protected:
    T value;
    std::list<std::pair<C,AFDNode<T,C>*> > awns;
   public:
    AFDNode(T value);
    ~AFDNode();
    T getValue();
    std::list<std::pair<C,AFDNode<T,C>*> > getAwns();
    void setValue(T value);
    void addAwn(AFDNode<T,C>* newNode, C path);
    void deleteAwn(C path);
    std::pair<C,AFDNode<T,C>*> findAwn( C path);
    bool hasAwn(C path);
};
#include "AFDNode.hxx"
#endif //AFDNode_h
