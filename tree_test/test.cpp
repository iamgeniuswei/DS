#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../tree/binary_tree.h"
TEST_CASE ("1. Create a tree only has root.", "[insertAsRoot]")
{
    BinaryTree<int> *tree = new BinaryTree<int>();
    REQUIRE(tree != nullptr);
    REQUIRE(tree->root() == nullptr);
    REQUIRE(tree->size() == 0);
    BinaryNode<int> *root = tree->insertAsRoot(1);
    REQUIRE(tree != nullptr);
    REQUIRE(tree->root() == root);
    REQUIRE(tree->size() == 1);
}
