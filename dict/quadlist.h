#ifndef QUADLIST_H
#define QUADLIST_H

#define QuadListNode(T) QuadlistNode<T>*

template <typename T>
class QuadlistNode
{
public:
    QuadlistNode() {}
    QuadlistNode(T e,
                 QuadlistNode<T>* p = nullptr,
                 QuadlistNode<T>* s = nullptr,
                 QuadlistNode<T>* a = nullptr,
                 QuadlistNode<T>* b = nullptr)
        :entry(e), prev(p),succ(s),above(a),below(b)
    {}

    QuadlistNode<T>* insertAsSuccAbove(T const& e, QuadlistNode<T>* b = nullptr);

private:
    T entry;
    QuadlistNode<T>* prev = nullptr;
    QuadlistNode<T>* succ = nullptr;
    QuadlistNode<T>* above = nullptr;
    QuadlistNode<T>* below = nullptr;

};






template <typename T>
class Quadlist
{
public:
    Quadlist() {init();}

private:
    int _size = 0;
    QuadlistNode<T>* _header = nullptr;
    QuadlistNode<T>* _trailer = nullptr;

protected:
    void init();
};

#endif // QUADLIST_H

template<typename T>
QuadlistNode<T> *QuadlistNode<T>::insertAsSuccAbove(const T &e, QuadlistNode<T> *b)
{

}

template<typename T>
void Quadlist<T>::init()
{
    _header = new QuadlistNode<T>;
    _trailer = new QuadlistNode<T>;
    _header->succ = _trailer;
    _trailer->prev = _header;
}
