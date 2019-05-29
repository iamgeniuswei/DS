#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
template<typename T> class BinaryNode{
private:
    T _data;
    int _height = 0;
    BinaryNode<T> *_parent = nullptr;
    BinaryNode<T> *_lc = nullptr;
    BinaryNode<T> *_rc = nullptr;

public:
    BinaryNode(T e, BinaryNode<T> *parent = nullptr)
        :_data(e), _parent(parent)
    {

    }

public:
    BinaryNode<T> *insertAsLC(T const& e);
    BinaryNode<T> *insertAlRC(T const& e);
    void setLC(BinaryNode<T> * lc)
    {
        _lc = lc;
    }
    void setRC(BinaryNode<T> * rc)
    {
        _rc = rc;
    }
    BinaryNode<T> *lc() const {return _lc;}
    BinaryNode<T> *rc() const {return _rc;}
    BinaryNode<T> *parent() const {return _parent;}
    T data() const{
        return _data;
    }

    int height() const{
        return _height;
    };
    void setHeight(int new_height){
        _height = new_height;
    }
};

template<typename T>
BinaryNode<T> *BinaryNode<T>::insertAsLC(const T &e)
{
    return _lc = new BinaryNode<T>(e, this);
}

template<typename T>
BinaryNode<T> *BinaryNode<T>::insertAlRC(const T &e)
{
    return _rc = new BinaryNode<T>(e, this);
}


template<typename T> class BinaryTree{
private:
    int _size = 0;
    BinaryNode<T> *_root = nullptr;

protected:
    void updateHeight(BinaryNode<T> *x);
    void updateHeightAbove(BinaryNode<T> *x);

public:
    BinaryTree(){}

    BinaryNode<T> *root() const{return _root;}
    BinaryNode<T> *insertAsRoot(T const& e);
    BinaryNode<T> *insertAsLC(BinaryNode<T> *x, T const& e);
    BinaryNode<T> *insertAsRC(BinaryNode<T> *x, T const& e);
    BinaryNode<T> *attachAsLC(BinaryNode<T> *x, BinaryTree<T> *&tree);
    BinaryNode<T> *attachAsRC(BinaryNode<T> *x, BinaryTree<T> *&tree);
    inline int stature(BinaryNode<T> *x)
    {
        if(x != nullptr)
            return x->height();
        return -1;
    }

    void traversePre_R(BinaryNode<T> *x, std::queue<BinaryNode<T> *> &container);
    void traversePost(BinaryNode<T> *x);
    int size() const{return _size;}

private:
    void gotoHLVFL(std::stack<BinaryNode<T>*> &stack);

};


template<typename T>
void BinaryTree<T>::updateHeight(BinaryNode<T> *x)
{
    assert(x != nullptr);

    x->setHeight(1 + std::max(stature(x->lc()), stature(x->rc())));
}

template<typename T>
void BinaryTree<T>::updateHeightAbove(BinaryNode<T> *x)
{
    assert(x != nullptr);
    while (x != nullptr)
    {
        updateHeight(x);
        x = x->parent();
    }
}

template<typename T>
BinaryNode<T> *BinaryTree<T>::insertAsRoot(const T &e)
{
    _root = new BinaryNode<T>(e);
    _size = 1;
    return _root;
}


template<typename T>
BinaryNode<T> *BinaryTree<T>::insertAsLC(BinaryNode<T> *x, const T &e)
{
    x->insertAsLC(e);
    _size++;
    updateHeightAbove(x);
    return x->lc();
}

template<typename T>
BinaryNode<T> *BinaryTree<T>::insertAsRC(BinaryNode<T> *x, const T &e)
{
    x->insertAlRC(e);
    _size++;
    updateHeightAbove(x);
    return x->rc();
}

template<typename T>
BinaryNode<T> *BinaryTree<T>::attachAsLC(BinaryNode<T> *x, BinaryTree<T> *&tree)
{
    if(tree->root() != nullptr)
    {
        x->setLC(tree->root());
        _size += tree->size();
        updateHeightAbove(x);
    }
}

template<typename T>
BinaryNode<T> *BinaryTree<T>::attachAsRC(BinaryNode<T> *x, BinaryTree<T> *&tree)
{
    if(tree->root() != nullptr)
    {
        x->setRC(tree->root());
        _size += tree->size();
        updateHeightAbove(x);
    }
}

template<typename T>
void BinaryTree<T>::traversePre_R(BinaryNode<T> *x, std::queue<BinaryNode<T>*> &container)
{
    if(x == nullptr)
        return;
    std::cout << x->data() << std::endl;
    container.push(x);
    traversePre_R(x->lc(), container);
    traversePre_R(x->rc(), container);
}

template<typename T>
void BinaryTree<T>::traversePost(BinaryNode<T> *x)
{
    std::stack<BinaryNode<T> *> stack;
    stack.push(x);
    while (!stack.empty()) {
        BinaryNode<T> *top = stack.top();
        if(top != x->parent())
        {
            gotoHLVFL(stack);
        }
        x = stack.top();
        std::cout << x->data() << std::endl;
        stack.pop();
    }
}

template<typename T>
void BinaryTree<T>::gotoHLVFL(std::stack<BinaryNode<T> *> &stack)
{
    while (true)
    {
        BinaryNode<T> *cur = stack.top();
        if(cur->lc() != nullptr)
        {
            if(cur->rc() != nullptr)
                stack.push(cur->rc());
            stack.push(cur->lc());
        }
        else if(cur->rc() != nullptr) {
            stack.push(cur->rc());
        }
        else {
            break;
        }
    }
}



#endif // BINARY_TREE_H
