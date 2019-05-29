#ifndef BITMAP_H
#define BITMAP_H

#include <string.h>
class Bitmap
{
public:
    Bitmap(int n = 8);
    void set(int i);
    void unset(int i);
    bool test(int i);
    char *bits2string(int n)
    {
        expand(n-1);
        char *s = new char[n+1];
        memset(s, 0, n+1);
        s[n] = '\0';
        for (int i=0; i<n;i++) {
            s[i] = test(i)?'1':'0';
        }
        return s;
    }

protected:
    void init(int n);
    void expand(int k);

private:
    char *_map = nullptr;
    int _size = 0;
};

#endif // BITMAP_H
