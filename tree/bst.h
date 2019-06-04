#ifndef BST_H
#define BST_H

#include "binary_tree.h"



template<typename T>
class BST : public BinaryTree<T>
{
public:
    virtual BinaryNode<T> *search(const T& e);
    virtual BinaryNode<T>* insert(const T& e);
    virtual bool remove(const T& e);
    BinaryNode<T>* hot() const
    {
        return _hot;
    }

protected:
    BinaryNode<T>* _hot = nullptr;
    BinaryNode<T>* connect34(BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*);
    BinaryNode<T>* rotateAt(BinaryNode<T>* x);

private:
    BinaryNode<T>* searchIn_R(BinaryNode<T>* v,
                                    const T& e,
                                    BinaryNode<T>* &hot)
    {
        if(v == nullptr || v->data() == e)
            return v;
        hot = v;
        return searchIn_R(((v->data() > e) ? v->lc():v->rc()), e, hot);
    }


    BinaryNode<T>* searchIn_I(BinaryNode<T>* v,
                                    const T& e,
                                    BinaryNode<T>* hot)
    {
        while (true)
        {
            if(v == nullptr || v->data() == e)
                return v;
            if(v->data() > e)
            {
                hot = v;
                v = v->lc();
            }
            else {
                hot = v;
                v= v->rc();
            }
        }
    }

    BinaryNode<T>* removeAt(BinaryNode<T> *x, BinaryNode<T> *&hot)
    {
        BinaryNode<T> *to_remove = x;
        BinaryNode<T> *succ = nullptr;
        if(x->lc() == nullptr)
        {
            succ = to_remove->rc();
        }
        else if (x->rc() == nullptr) {
            succ = to_remove->lc();
        }
        else {
            succ = to_remove->succ();
            T temp = succ->data();
            succ->setData(to_remove->data());
            to_remove->setData(temp);
            to_remove = succ;
            BinaryNode<T> *p = to_remove->parent();
            (p == x) ? p->setRC(succ->rc()) : p->setLC(succ->rc());
            succ = succ->rc();
        }
        hot = to_remove->parent();
        if(succ)
            succ->setParent(hot);
        hot->lc() == to_remove ? hot->setLC(succ) : hot->setRC(succ);
        delete to_remove;
        return succ;
    }

};



#endif // BST_H
#include "binary_tree.h"
template<typename T>
BinaryNode<T> *BST<T>::search(const T &e)
{
    return searchIn_R(this->_root, e, _hot = nullptr);
}

template<typename T>
BinaryNode<T> *BST<T>::insert(const T &e)
{
    BinaryNode<T> *ret = search(e);
    if(ret != nullptr)
        return ret;
    ret = new BinaryNode<T>(e, _hot);
    _hot->data() > e ? _hot->setLC(ret) : _hot->setRC(ret);
    this->_size ++;
    this->updateHeightAbove(ret);
    return ret;
}

template<typename T>
bool BST<T>::remove(const T &e)
{
    BinaryNode<T> *ret = search(e);
    if(ret == nullptr)
        return false;
    removeAt(ret, _hot);
    this->_size--;
    this->updateHeightAbove(_hot);
    return true;
}
