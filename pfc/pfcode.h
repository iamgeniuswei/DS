#ifndef PFCODE_H
#define PFCODE_H
#include "../tree/binary_tree.h"
#include "../bitmap/bitmap.h"
#include <map>
typedef BinaryTree<char> PFCTree;

//all printable ascii
const int N_CHAR = 0x5b-0x41;
class PFCode
{
public:
    PFCode();
    PFCTree *generateTree();
    void generateTable();
    int encode(Bitmap *bitmap, char *str);
    void decode(Bitmap *bitmap, int length);


protected:
    void generateCT(Bitmap *map, int length, BinaryNode<char>* v);

private:
    PFCTree *_pfcTree = nullptr;
    std::map<char, char*> _pfcTable;
};

#endif // PFCODE_H
