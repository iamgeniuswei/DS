#ifndef AVL_H
#define AVL_H
#include "bst.h"

template <typename T>
class AVL : public BST<T>
{
public:
    AVL() {}


    // BST interface
public:
    virtual BinaryNode<T> *insert(const T &e) override;

    virtual bool remove(const T &e) override;

public:
    virtual BinaryNode<T> *insert34(const T &e);

public:
    bool balanced(BinaryNode<T> *x)
    {
        int lc_height=-1, rc_height = -1;
        if(x->hasLChild())
            lc_height = x->lc()->height();
        if(x->hasRChild())
            rc_height = x->rc()->height();
        return lc_height == rc_height;
    }
    int balFac(BinaryNode<T> *x)
    {
        int lc_height, rc_height = -1;
        if(x->hasLChild())
            lc_height = x->lc()->height();
        if(x->hasRChild())
            rc_height = x->rc()->height();
        return lc_height - rc_height;
    }
    int avlBalanced(BinaryNode<T> *x)
    {
        int factor = balFac(x);
        return (factor > -2) && (factor < 2);
    }

    BinaryNode<T> *tallerChild(BinaryNode<T> *x)
    {
        int lc_height = -1, rc_height = -1;
        if(x->hasLChild())
            lc_height = x->lc()->height();
        if(x->hasRChild())
            rc_height = x->rc()->height();
        return (lc_height > rc_height) ? x->lc() :
                                  ((lc_height < rc_height) ? x->rc() :
                                                             (x->isLChild()? x->lc():x->rc()));

    }



};

template <typename T>
BinaryNode<T> *AVL<T>::insert(const T &e)
{


}
template <typename T>
bool AVL<T>::remove(const T &e)
{
    return false;
}

template<typename T>
BinaryNode<T> *AVL<T>::insert34(const T &e)
{
    BinaryNode<T> *x = this->search(e);
    if(x != nullptr)
        return x;
    x = new BinaryNode<T>(e, this->_hot);
    this->_hot->data() > e ? this->_hot->setLC(x) : this->_hot->setRC(x);
    this->_size++;
    for (BinaryNode<T> *g=this->_hot; g!=nullptr; g = g->parent())
    {
        if(!avlBalanced(g))
        {
            BinaryNode<T> *ret = this->rotateAt34(tallerChild(tallerChild(g)));
            break;
        }
        else {
            this->updateHeight(g);
        }
    }
    return x;
}

#endif // AVL_H
