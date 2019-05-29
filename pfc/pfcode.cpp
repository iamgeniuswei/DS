#include "pfcode.h"
#include <vector>
#include <stdlib.h>
#include <iostream>
PFCode::PFCode()
{

}

PFCTree *PFCode::generateTree()
{
    std::vector<PFCTree*> forest;
    for (int i=0; i<N_CHAR; i++)
    {
        PFCTree *tree = new PFCTree();
        tree->insertAsRoot(0x41+i);
        forest.push_back(tree);
    }

    while (forest.size() > 1) {
        PFCTree *new_tree = new PFCTree;
        new_tree->insertAsRoot('^');
        int r1 = rand() % forest.size();
        new_tree->attachAsLC(new_tree->root(), forest.at(r1));
        forest.erase(forest.begin()+r1);
        int r2 = rand() % forest.size();
        new_tree->attachAsRC(new_tree->root(), forest.at(r2));
        forest.erase(forest.begin()+r2);
        forest.push_back(new_tree);
    }
    _pfcTree = forest.at(0);
    forest.pop_back();
    return _pfcTree;
}

void PFCode::generateTable()
{
    Bitmap *code = new Bitmap;
    generateCT(code, 0, _pfcTree->root());
}

int PFCode::encode(Bitmap *bitmap, char *str)
{
    int length = 0;
    for (size_t m = strlen(str), i=0; i<m; i++)
    {
        char *code = _pfcTable.at(str[i]);
        std::cout << str[i] << "--" << code << std::endl;
        for (size_t m =strlen(code), j=0; j<m;j++)
        {
            '1' == code[j] ? bitmap->set(length++):bitmap->unset(length++);
        }
    }
    return length;
}

void PFCode::decode(Bitmap *bitmap, int length)
{
    BinaryNode<char> *x = _pfcTree->root();
    for (int i=0; i<length; i++)
    {
        x = bitmap->test(i) ? x->rc(): x ->lc();
        if(x->lc() == nullptr && x->rc() == nullptr)
        {
            std::cout << x->data() ;
            x = _pfcTree->root();
        }
    }
    std::cout<<std::endl;

}

void PFCode::generateCT(Bitmap *map, int length, BinaryNode<char> *v)
{
    if(v->lc() == nullptr || v->rc() == nullptr)
    {
        std::cout << v->data() << " " << map->bits2string(length) << std::endl;
        _pfcTable.insert(std::pair<char, char*>(v->data(), map->bits2string(length)));
        return;
    }
    if(v->lc() != nullptr)
    {
        map->unset(length);
        generateCT(map, length+1, v->lc());
    }
    if(v->rc() != nullptr)
    {
        map->set(length);
        generateCT(map, length+1, v->rc());
    }
}

