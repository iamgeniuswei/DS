#include <iostream>
using namespace std;
#include "tree/binary_tree.h"
int main()
{
    cout << "Hello World!" << endl;

    BinaryNode<int> *node = new BinaryNode<int>(10);
    node->insertAsLC(20);

    int i = 10;
    return 0;
}
