#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../tree/binary_tree.h"
#include "../tree/bst.h"
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
    BinaryTree<int> *tree = new BST<int>();

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

TEST_CASE("5. search() in BST")
{
    BST<int> *tree = new BST<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(4);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_2 = tree->insertAsLC(root, 2);
    BinaryNode<int> *rc_6 = tree->insertAsRC(root, 6);
    //first level test
    REQUIRE(lc_2 == root->lc());
    REQUIRE(rc_6 == root->rc());

    //Create second level
    BinaryNode<int> *lc_1 = tree->insertAsLC(lc_2, 1);
    BinaryNode<int> *rc_3 = tree->insertAsRC(lc_2, 3);
    BinaryNode<int> *lc_5 = tree->insertAsLC(rc_6, 5);
    BinaryNode<int> *rc_7 = tree->insertAsRC(rc_6, 7);
    //second level test
    REQUIRE(lc_1 == lc_2->lc());
    REQUIRE(rc_3 == lc_2->rc());
    REQUIRE(lc_5 == rc_6->lc());
    REQUIRE(rc_7 == rc_6->rc());

    BinaryNode<int>* ret = tree->search(2);
    REQUIRE(ret == lc_2);

    ret = tree->search(3);
    REQUIRE(ret == rc_3);

    ret = tree->search(4);
    REQUIRE(ret == root);
    REQUIRE(tree->hot() == nullptr);

    ret = tree->search(6);
    REQUIRE(ret == rc_6);

    ret = tree->search(5);
    REQUIRE(ret == lc_5);

    ret = tree->search(7);
    REQUIRE(ret == rc_7);

    ret = tree->search(1);
    REQUIRE(ret == lc_1);
    std::cout << tree->hot()->data()<< std::endl;
    REQUIRE(tree->hot() == lc_2);

    ret = tree->search(10);
    REQUIRE(ret == nullptr);
    REQUIRE(tree->hot() == rc_7);
}

TEST_CASE("6. insert() in BST")
{
    BST<int> *tree = new BST<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(36);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_27 = tree->insertAsLC(root, 27);
    BinaryNode<int> *rc_58 = tree->insertAsRC(root, 58);
    //first level test
    REQUIRE(lc_27 == root->lc());
    REQUIRE(rc_58 == root->rc());

    //Create second level
    BinaryNode<int> *lc_1 = tree->insertAsLC(lc_27, 6);
//    BinaryNode<int> *rc_3 = tree->insertAsRC(lc_2, 3);
    BinaryNode<int> *lc_53 = tree->insertAsLC(rc_58, 53);
    BinaryNode<int> *rc_69 = tree->insertAsRC(rc_58, 69);
    //second level test
    REQUIRE(lc_1 == lc_27->lc());
//    REQUIRE(rc_3 == lc_2->rc());
    REQUIRE(lc_53 == rc_58->lc());
    REQUIRE(rc_69 == rc_58->rc());

    BinaryNode<int> *lc_46 = tree->insertAsLC(lc_53, 46);

    BinaryNode<int>* lc_40 =  tree->insert(40);

    REQUIRE(lc_40->parent() == lc_46);
    REQUIRE(lc_46->lc() == lc_40);

    REQUIRE(lc_40->height() == 0);
    REQUIRE(lc_53->height() == 2);
    REQUIRE(root->height() == 4);
}



TEST_CASE("7. succ() in BinaryNode<T>")
{
    BST<int> *tree = new BST<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(36);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_27 = tree->insertAsLC(root, 27);
    BinaryNode<int> *rc_58 = tree->insertAsRC(root, 58);
    //first level test
    REQUIRE(lc_27 == root->lc());
    REQUIRE(rc_58 == root->rc());

    //Create second level
    BinaryNode<int> *lc_1 = tree->insertAsLC(lc_27, 6);
//    BinaryNode<int> *rc_3 = tree->insertAsRC(lc_2, 3);
    BinaryNode<int> *lc_53 = tree->insertAsLC(rc_58, 53);
    BinaryNode<int> *rc_69 = tree->insertAsRC(rc_58, 69);
    //second level test
    REQUIRE(lc_1 == lc_27->lc());
//    REQUIRE(rc_3 == lc_2->rc());
    REQUIRE(lc_53 == rc_58->lc());
    REQUIRE(rc_69 == rc_58->rc());

    BinaryNode<int> *lc_46 = tree->insertAsLC(lc_53, 46);
    BinaryNode<int> *rc_54 = tree->insertAsRC(lc_53, 54);
    BinaryNode<int> *rc_55 = tree->insertAsRC(rc_54, 55);

    BinaryNode<int> *s_lc_36 = root->succ();

    REQUIRE(s_lc_36 == lc_46);

    BinaryNode<int> *s_rc_55 = rc_55->succ();

    REQUIRE(s_rc_55 == rc_58);
}


TEST_CASE("8. remove() in BST<T>")
{
    BST<int> *tree = new BST<int>();

    //Create tree's root
    BinaryNode<int> *root = tree->insertAsRoot(36);
    //root test.
    REQUIRE(root == tree->root());

    //Create first level
    BinaryNode<int> *lc_27 = tree->insertAsLC(root, 27);
    BinaryNode<int> *rc_58 = tree->insertAsRC(root, 58);
    //first level test
    REQUIRE(lc_27 == root->lc());
    REQUIRE(rc_58 == root->rc());

    //Create second level
    BinaryNode<int> *lc_1 = tree->insertAsLC(lc_27, 6);
//    BinaryNode<int> *rc_3 = tree->insertAsRC(lc_2, 3);
    BinaryNode<int> *lc_53 = tree->insertAsLC(rc_58, 53);
    BinaryNode<int> *rc_69 = tree->insertAsRC(rc_58, 69);
    //second level test
    REQUIRE(lc_1 == lc_27->lc());
//    REQUIRE(rc_3 == lc_2->rc());
    REQUIRE(lc_53 == rc_58->lc());
    REQUIRE(rc_69 == rc_58->rc());

    BinaryNode<int> *lc_46 = tree->insertAsLC(lc_53, 46);
    BinaryNode<int> *rc_54 = tree->insertAsRC(lc_53, 54);
    BinaryNode<int> *rc_55 = tree->insertAsRC(rc_54, 55);

    bool remove = tree->remove(54);
    REQUIRE(remove == true);
    remove = tree->remove(36);
    REQUIRE(remove == true);
}
