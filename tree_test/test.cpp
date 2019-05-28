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

TEST_CASE("2. Create a tree ")
{
    BinaryTree<int> *tree = new BinaryTree<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(1);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_2 = tree->insertAsLC(root, 2);
    BinaryNode<int> *rc_3 = tree->insertAsRC(root, 3);
    //first level test
    REQUIRE(lc_2 == root->lc());
    REQUIRE(rc_3 == root->rc());

    //Create second level
    BinaryNode<int> *lc_4 = tree->insertAsLC(lc_2, 4);
    BinaryNode<int> *rc_5 = tree->insertAsRC(lc_2, 5);
    BinaryNode<int> *lc_6 = tree->insertAsLC(rc_3, 6);
    BinaryNode<int> *rc_7 = tree->insertAsRC(rc_3, 7);
    //second level test
    REQUIRE(lc_4 == lc_2->lc());
    REQUIRE(rc_5 == lc_2->rc());
    REQUIRE(lc_6 == rc_3->lc());
    REQUIRE(rc_7 == rc_3->rc());
}

TEST_CASE("3. Preorder traverse recursively")
{
    BinaryTree<int> *tree = new BinaryTree<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(1);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_2 = tree->insertAsLC(root, 2);
    BinaryNode<int> *rc_3 = tree->insertAsRC(root, 3);
    //first level test
    REQUIRE(lc_2 == root->lc());
    REQUIRE(rc_3 == root->rc());

    //Create second level
    BinaryNode<int> *lc_4 = tree->insertAsLC(lc_2, 4);
    BinaryNode<int> *rc_5 = tree->insertAsRC(lc_2, 5);
    BinaryNode<int> *lc_6 = tree->insertAsLC(rc_3, 6);
    BinaryNode<int> *rc_7 = tree->insertAsRC(rc_3, 7);
    //second level test
    REQUIRE(lc_4 == lc_2->lc());
    REQUIRE(rc_5 == lc_2->rc());
    REQUIRE(lc_6 == rc_3->lc());
    REQUIRE(rc_7 == rc_3->rc());

    std::queue<BinaryNode<int>* > queue;
    tree->traversePre_R(root, queue);
    REQUIRE(queue.size() == 7);
    BinaryNode<int> *bn1 = queue.front();
    queue.pop();
    REQUIRE(bn1 == root);
    BinaryNode<int> *bn2 = queue.front();
    queue.pop();
    REQUIRE(bn2 == lc_2);

    BinaryNode<int> *bn3 = queue.front();
    queue.pop();
    REQUIRE(bn3 == lc_4);

    BinaryNode<int> *bn4 = queue.front();
    queue.pop();
    REQUIRE(bn4 == rc_5);

    BinaryNode<int> *bn5 = queue.front();
    queue.pop();
    REQUIRE(bn5 == rc_3);

    BinaryNode<int> *bn6 = queue.front();
    queue.pop();
    REQUIRE(bn6 == lc_6);

    BinaryNode<int> *bn7 = queue.front();
    queue.pop();
    REQUIRE(bn7 == rc_7);
}

TEST_CASE("4. Postorder traverse iterately")
{
    BinaryTree<int> *tree = new BinaryTree<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(1);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_2 = tree->insertAsLC(root, 2);
    BinaryNode<int> *rc_3 = tree->insertAsRC(root, 3);
    //first level test
    REQUIRE(lc_2 == root->lc());
    REQUIRE(rc_3 == root->rc());

    //Create second level
    BinaryNode<int> *lc_4 = tree->insertAsLC(lc_2, 4);
    BinaryNode<int> *rc_5 = tree->insertAsRC(lc_2, 5);
    BinaryNode<int> *lc_6 = tree->insertAsLC(rc_3, 6);
    BinaryNode<int> *rc_7 = tree->insertAsRC(rc_3, 7);
    //second level test
    REQUIRE(lc_4 == lc_2->lc());
    REQUIRE(rc_5 == lc_2->rc());
    REQUIRE(lc_6 == rc_3->lc());
    REQUIRE(rc_7 == rc_3->rc());

    tree->traversePost(root);
}
