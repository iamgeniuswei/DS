#include "bitmap.h"
#include <string.h>
#include <assert.h>
#include <new>
Bitmap::Bitmap(int n)
{
    init(n);
}

void Bitmap::set(int i)
{
    expand(i);
    int index = i >> 3;
    int y = i&0x07;
    _map[index] |= (0x01 << ( y) );
}

void Bitmap::unset(int i)
{
    expand(i);
    _map[i >> 3] &= ~(0x01 << ( i & 0x07) );
}

bool Bitmap::test(int i)
{
    expand(i);
    return _map[i >> 3] & (0x01 << ( i & 0x07) );
}

void Bitmap::init(int n)
{
    _size = (n+7)/8;
    _map = new (std::nothrow) char[_size];
    assert(_map != nullptr);
    memset(_map, 0, _size);
}

void Bitmap::expand(int k)
{
    if(k < 8 * _size)
        return;
    int old_size = _size;
    char *old_map = _map;
    init(2*k);
    memcpy(_map, old_map, old_size);
    delete [] old_map;
    old_map = nullptr;
}
