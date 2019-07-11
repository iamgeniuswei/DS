#include <gtest/gtest.h>
#include "../list/listnode.h"
#include <iostream>
using namespace std;
int add(int a, int b)
{
    return a+b;
}

TEST(testCase, test_ctor)
{
    ListNode<int> *node = new ListNode<int>(10);
    EXPECT_TRUE(node != nullptr);
    EXPECT_EQ(node->data(), 10);
    EXPECT_EQ(node->prev(), nullptr);
    EXPECT_EQ(node->succ(), nullptr);

}

template <typename T>
class SmartPointer
{
private:
    T *_ptr = nullptr;
    size_t *_count = nullptr;
public:
    SmartPointer(T *ptr = nullptr)
        :_ptr(ptr)
    {
        if(_ptr)
            _count = new size_t(1);
        else {
            _count = new size_t(0);
        }
    }

    SmartPointer(const SmartPointer& ptr)
    {
        if(this != &ptr)
        {
            _ptr = ptr._ptr;
            _count = ptr._count;
            (*_count)++;
        }
    }

    SmartPointer& operator=(const SmartPointer& ptr)
    {
        if(_ptr == ptr._ptr)
            return *this;
        //First, dealing with the current _ptr.
        if(_ptr)
        {
            (*_count)--;
            if((*_count) == 0)
            {
                delete this->_ptr;
                delete this->_count;
            }
        }
        _ptr = ptr._ptr;
        _count = ptr._count;
        (*_count)++;
        return *this;
    }

    T& operator*()
    {
        assert(_ptr == nullptr);
        return *_ptr;
    }

    T* operator->()
    {
        assert(_ptr == nullptr);
        return _ptr;
    }
    ~SmartPointer()
    {
        (*_count)--;
        cout << "~SmartPointer" << endl;
        cout << "*_count: " << (*_count) << endl;
        if(*(_count) == 0)
        {
            delete this->_ptr;
            delete this->_count;
            cout << "use_count = 0, delete." << endl;
        }

    }

    size_t use_count()
    {
        return (*_count);
    }
};










class A
{
public:
    A(int e):a(e)
    {
        cout << "ctor" << endl;
        p = new int[5]{e, e, e, e, e};
    }
    A(A &rhs):
    a(rhs.a){
        cout << "copy ctor" << endl;
        p = new int[5]{rhs.a};
    }

    A(A&& rhs):
        a(rhs.a)
    {
        cout << "copy ctor &&" << endl;
        delete [] p;
        p = nullptr;
        p = rhs.p;
        rhs.p = nullptr;
    }

    A& operator=(A &rhs)
    {
        cout << "operator=" <<endl;
        delete [] p;
        a = rhs.a;
        p = new int[5]{rhs.a};
        return *this;
    }
    A& operator=(A&& rhs)
    {
        cout << "operator &&=" << endl;
        a = rhs.a;
        p = rhs.p;
        rhs.p = nullptr;
        return *this;
    }

    int& getA()
    {
        return a;
    }

private:
    int a = 0;
    int *p = nullptr;
};

A foo()
{
    A a(20);
    return a;
}

template<typename T, typename Arg>
shared_ptr<T> facotry(Arg &arg)
{
    return shared_ptr<T>(new T(arg));
}

void Test(A&& a)
{
    A anotherA = a;
    cout << "Test" << endl;
}

int& test()
{
    int *a = new int(10);
    return *a;
}

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
    return N;
}


//auto createInitList()
//{
//    return {1, 2, 3};
//}

class Widget{
public:
    Widget()
    {
        cout << "default ctor" << endl;
    }
    Widget(int i, bool b)
    {
        cout << "ctor1 called" << endl;
    }
    Widget(initializer_list<int> il)
    {
        cout << "initializer_list<int> called" << endl;
    }
    Widget(std::initializer_list<string> il){}
};

void f(int )
{
    cout << "f(int)" << endl;
}

void f(void*)
{
    cout << "f(void*)" << endl;
}

enum class Color{black, white,red};


template<typename E>
constexpr typename std::underlying_type<E>::type
toUType(E enumerator) noexcept
{
    return static_cast<typename std::underlying_type<E>::type>(enumerator);
}


class Child;
class Parent;

class Parent
{
public:
    Parent() {}
    void setChild(shared_ptr<Child> child)
    {
        cptr = child;
    }
    void doSomething()
    {
        shared_ptr<Child> new_c = cptr.lock();
        cout << "in Parent: child's use: " << new_c.use_count() << endl;
    }
private:
    weak_ptr<Child> cptr;
};

class Child
{
public:
    Child() {}
    void setParent(shared_ptr<Parent> parent)
    {
        pptr = parent;
    }
    void doSomething()
    {
        cout << "in child, parent's use: " << pptr.use_count() << endl;
    }
private:
    shared_ptr<Parent> pptr;
};







#include <unordered_map>
#include <memory>
#include <vector>
int main(int argc, char **argv)
{
//    testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//    A a1(10);
//    A a2 = a1;
//    A a3(a1);
//    A a4(0);5.0
//    a4 = a2;
//    a4 = foo();
//    Test(foo());
//    int i = 0;
//    facotry<A>(foo());

//    test() = 20;
//    cout << &(test()) << endl;

//    int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };
//    cout << arraySize(keyVals) << endl;

//    auto x = {1, 2, 3, 4};

//    Widget w{10, true};
//    Widget w1;
//    Widget w2{};
//    Widget w3 {{}};

//    initializer_list<int> li{1, 2, 3, 4};

//    for(const int *it = begin(li); it != end(li); it++)
//        cout << *it << endl;
//    int i = 0;
//    int *ptr = nullptr;

//    f(0);
//    f(nullptr);

//    using UPtrMapSS = unique_ptr<unordered_map<string, string>>;

//    std::tuple<int, char> foo(10, 'x');

//    auto val = std::get<0>(foo);

//    cout << "val: " << val << endl;

//    cout << toUType<Color>(Color::red) << endl;

//    int lo =0;
//    int hi = 3;
//    while(lo < hi--)
//    {
//        cout << "hi: " << hi << endl;
//    }
//    cout << "hi: " << hi << endl;

//    int a = 10;
//    shared_ptr<int> ptra = make_shared<int>(a);
//    shared_ptr<int> ptra2(ptra);
//    cout << "ptra use_count: " << ptra.use_count() << endl;

//    int b = 20;
//    int *pb = &b;
//    cout << "pb: " << pb << endl;
//    shared_ptr<int> ptrb = make_shared<int>(b);
//    ptra2 = ptrb;
//    pb = ptrb.get();
//    cout << "pb: " << pb << endl;
//    cout << "ptra use_count: " << ptra.use_count() << endl;
//    cout << "ptrb use_count: " << ptrb.use_count() << endl;


//    weak_ptr<int> wp(ptrb);
//    cout << "wp use_count: " << wp.use_count() << endl;

//    if(!wp.expired())
//    {
//        shared_ptr<int> sh_ptr2 = wp.lock();
//        *sh_ptr2 = 100;
//        cout << "wp use_count: " << wp.use_count() << endl;
//    }
//    cout << "wp use_count: " << wp.use_count() << endl;
//    cout << "ptrb use_count: " << ptrb.use_count() << endl;
//    cout << "*ptrb: " << *ptrb << endl;

//    unique_ptr<int> uptr(new int(10));
//    unique_ptr<int> uptr2 = std::move(uptr);
//    cout << "uptr: " << uptr.get() << endl;
//    cout << "uptr2: " << uptr2.get() << endl;


//    weak_ptr<Parent> wpp;
//    weak_ptr<Child> wpc;
//    {
//        shared_ptr<Parent> p(new Parent);
//        shared_ptr<Child> c(new Child);
//        p->setChild(c);
//        c->setParent(p);
//        wpp = p;
//        wpc = c;
//        cout << "p.use: " << p.use_count() << endl;
//        cout << "c.use: " << c.use_count() << endl;
//        p->doSomething();
//        c->doSomething();
//        cout << "p.use: " << p.use_count() << endl;
//        cout << "c.use: " << c.use_count() << endl;
//    }
//    cout << "wpp.use: " << wpp.use_count() << endl;
//    cout << "wpc.use: " << wpc.use_count() << endl;


//    SmartPointer<int> sp (new int(50));
//    SmartPointer<int> sp2 = sp;
//    SmartPointer<int> sp3 (new int(30));

//    sp2 = sp3;
//    cout << "sp.use: " << sp.use_count() << endl;
//    cout << "sp3.use: " << sp3.use_count() << endl;

//    cout << i << endl;

    vector<int> v0;
    vector<int> v1(5, 0);
    vector<int> v2(v1.begin(), v1.end());
    vector<int> v3(v2);
    vector<int> v4{1, 2, 3, 4, 5};

    int a[5] = {3, 2, 0, 1, 4};
    cout << a << " " << &a << " " << &a+1 << " " << *(&a+1) << endl;

    vector<int> v5(a, *(&a+1));

    for (int item : v5)
    {
        item *= 2;
    }

    for (auto item = v5.begin(); item != v5.end(); item++) {
        *item *= 2;
    }

    sort(v5.begin(), v5.end());
    cout << "i" << endl;
}
