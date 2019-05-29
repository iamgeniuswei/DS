#include <iostream>
using namespace std;
#include "tree/binary_tree.h"
#include "bitmap/bitmap.h"
#include "pfc/pfcode.h"
int main()
{
    cout << "Hello World!" << endl;
    Bitmap *bitmap = new Bitmap();
//    bitmap->set(10);
////    REQUIRE(bitmap->test(10) == true);
//    std::cout << bitmap->test(10) << std::endl;
//    std::cout << bitmap->test(11) << std::endl;
//    delete bitmap;

    PFCode *code = new PFCode;
    code->generateTree();
    code->generateTable();
    int length = code->encode(bitmap, "ABCDEZEO");
    std::cout << bitmap->bits2string(length) << std::endl;
    code->decode(bitmap, length);
    int i = 10;
    return 0;
}
