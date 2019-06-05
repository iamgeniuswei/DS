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

    BinaryNode<T>* rotateAt(BinaryNode<T> *v)
    {
        BinaryNode<T>* p = v->parent();
        BinaryNode<T>* g = p->parent();
        if(p->isRChild())
        {
            if(v->isRChild()) //zag-zag
            {
                g->setRC(p->lc());
                p->setLC(g);
                p->setParent(g->parent());
                if(g->parent())
                {
                    if(g->isLChild())
                        p->parent()->setLC(p);
                    else {
                        p->parent()->setRC(p);
                    }
                }
                else {
                    this->_root  = p;
                }
                g->setParent(p);
                this->updateHeight(g);
                return p;
            }
            else if (v->isLChild())
            {
                //zig-zag
                //zig(p)
                g->setRC(v);
                p->setLC(v->rc());
                v->setRC(p);
                p->setParent(v);
                //zag(g)
                g->setRC(v->lc());
                v->setLC(g);
                v->setParent(g->parent());
                if(g->parent())
                {
                    if(g->isLChild())
                        g->parent()->setLC(v);
                    else {
                        g->parent()->setRC(v);
                    }
                }
                else {
                    this->_root = v;
                }
                g->setParent(v);
                this->updateHeight(g);
                this->updateHeight(p);
                this->updateHeight(v);
                return v;
            }
        }
        else if (p->isLChild())
        {
            if(v->isLChild()) //zig-zig
            {
                g->setLC(p->rc());
                p->setRC(g);
                p->setParent(g->parent());
                if(g->parent())
                {
                    if(g->isLChild())
                        g->parent()->setLC(p);
                    else {
                        g->parent()->setRC(p);
                    }
                }
            }
        }
    }

protected:
    BinaryNode<T>* _hot = nullptr;
    BinaryNode<T>* connect34(BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*,
                             BinaryNode<T>*t1,
                             BinaryNode<T>*t2,
                             BinaryNode<T>*t3);
    BinaryNode<T>* rotateAt34(BinaryNode<T>* v);

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
        if(!to_remove->hasLChild())
        {
            succ = to_remove->rc();
        }
        else if (!to_remove->hasRChild()) {
            succ = to_remove->lc();
        }
        else {
            succ = to_remove->succ();
            T temp = succ->data();
            x->setData(succ->data());

            to_remove = succ;
            succ = succ->rc();
            BinaryNode<T> *p = to_remove->parent();
            //if p == the node to del before swap,
            (p == x) ? p->setRC(succ) : p->setLC(succ);

        }
        hot = to_remove->parent();
        if(succ)
            succ->setParent(hot);
        hot->lc() == to_remove ? hot->setLC(succ) : hot->setRC(succ);
        delete to_remove;
        return succ;
    }

};




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

template<typename T>
BinaryNode<T> *BST<T>::connect34(BinaryNode<T> *a, BinaryNode<T> *b, BinaryNode<T> *c, BinaryNode<T> *t0, BinaryNode<T> *t1, BinaryNode<T> *t2, BinaryNode<T> *t3)
{
    a->setLC(t0);
    if(t0)
        t0->setParent(a);
    a->setRC(t1);
    if(t1)
        t1->setParent(a);
    this->updateHeight(a);
    c->setLC(t2);
    if(t2)
        t2->setParent(c);
    c->setRC(t3);
    if(t3)
        t3->setParent(c);
    this->updateHeight(c);
    b->setLC(a);
    a->setParent(b);
    b->setRC(c);
    c->setParent(b);
    this->updateHeight(b);
    return b;
}

template<typename T>
BinaryNode<T> *BST<T>::rotateAt34(BinaryNode<T> *v)
{
    BinaryNode<T> *p = v->parent();
    BinaryNode<T> *g = p->parent();
    if(p->isLChild())
    {
        if(v->isLChild())
        {
            p->setParent(g->parent());
            if(g->parent() == nullptr)
                this->_root = p;
            else {
                if(g->isLChild())
                    g->parent()->setLC(p);
                else {
                    g->parent()->setRC(p);
                }
            }
            return connect34(v, p, g, v->lc(), v->rc(), p->rc(), g->rc());
        }
        else {
            v->setParent(g->parent());
            if(g->parent() == nullptr)
                this->_root = v;
            else {
                if(g->isLChild())
                    g->parent()->setLC(v);
                else {
                    g->parent()->setRC(v);
                }
            }
            return connect34(p, v, g, p->lc(), v->lc(), v->rc(), g->rc());
        }
    }
    else {
        if(v->isRChild())
        {
            p->setParent(g->parent());
            if(g->parent() == nullptr)
                this->_root = p;
            else {
                if(g->isLChild())
                    g->parent()->setLC(p);
                else {
                    g->parent()->setRC(p);
                }
            }
            return connect34(g, p, v, g->lc(), p->lc(), v->lc(), v->rc());
        }
        else {
            v->setParent(g->parent());
            if(g->parent() == nullptr)
                this->_root = v;
            else {
                if(g->isLChild())
                    g->parent()->setLC(v);
                else {
                    g->parent()->setRC(v);
                }
            }
            return connect34(g, v, p, g->lc(), v->lc(), v->rc(), p->rc());
        }
    }
}
#endif // BST_H
