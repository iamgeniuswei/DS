#ifndef LISTNODE_H
#define LISTNODE_H



template <typename T>
class ListNode
{
public:
    ListNode(){}
    ListNode(T e, ListNode<T> *p = nullptr, ListNode<T> *s = nullptr)
        :_data(e), _prev(p), _succ(s)
    {

    }

    ListNode<T> *prev() const
    {
        return _prev;
    }
    void setPrev(ListNode<T> *prev)
    {
        _prev = prev;
    }

    ListNode<T> *succ() const
    {
        return _succ;
    }
    void setSucc(ListNode<T> *succ)
    {
        _succ = succ;
    }

    T data() const
    {
        return _data;
    }
    void setData(const T &data)
    {
        _data = data;
    }

private:
    T _data;
    ListNode<T> *_prev = nullptr;
    ListNode<T> *_succ = nullptr;
};




#endif // LISTNODE_H
