//inthepictures
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long u64;
typedef unsigned int u32;

#define ABS(x) ((0 - (x)) & (x))

struct Big {
    u32 size, alloc;
    u32* d;

    void reserve(u32 need) {
        if (alloc < need) {
            alloc = need;
            d = (u32*) realloc(d, alloc * sizeof(u32));
            assert(d);
        } else if (alloc > need) {
            alloc = need;
            d = (u32*) realloc(d, alloc * sizeof(u32));
            assert(alloc == 0 || d);
        }
    }

    ~Big() {
        assert(d == NULL);
        free(d);
        d = NULL;
    }

    Big(u32 s = 0, int reserve = 0) {
        size = s;
        alloc = 0;
        d = NULL;
        if (reserve) {
            reserve = (reserve + 31) >> 5;
            alloc = reserve;
            d = (u32*) malloc(alloc * sizeof(u32));
            assert(d);
        }
    }

    Big(const Big &b, int reserve = 0) {
        size = b.size;
        alloc = 0;
        d = NULL;
        if (reserve < (int)b.alloc) reserve = b.alloc;
        if (reserve) {
            alloc = reserve;
            d = (u32*) malloc(alloc * sizeof(u32));
            assert(d);
        }
        memcpy(d, b.d, size * sizeof(u32));
    }

    Big &operator =(const Big &b) {
        if (this != &b) {
            reserve(b.size);
            size = b.size;
            memcpy(d, b.d, size * sizeof(u32));
        }
        return *this;
    }

    void zero() {
        size = 0;
    }

    void read() {
        size = 0;
        while (1) {
            int c = getchar();
            if (c == EOF) break;
            if (c == '0') {
                size++;
                d[size >> 5] = (d[size >> 5] << 1) | 0;
            } else if (c == '1') {
                size++;
                d[size >> 5] = (d[size >> 5] << 1) | 1;
            } else break;
        }
    }

    Big &operator <<=(int y) {
        if (y >= 32) {
            int n = y >> 5;
            reserve(size + n);
            memmove(d + n, d, size * sizeof(u32));
            memset(d, 0, n * sizeof(u32));
            size += n;
            y &= 31;
        }
        if (y) {
            reserve(size + 1);
            for (int i = size; i > 0; i--) {
                d[i] = (d[i] << y) | (d[i - 1] >> (32 - y));
            }
            d[0] <<= y;
            size++;
        }
        return *this;
    }

    void set(u32 y) {
        if (y == 0) {
            size = 0;
            return;
        }
        size = 1;
        d[0] = y;
    }

    void set(u32 y, int n) {
        reserve(n);
        size = n;
        for (int i = 0; i < n; i++) {
            d[i] = y;
        }
    }

    Big &operator ^=(const Big &y) {
        if (y.size > size) reserve(y.size);
        for (int i = 0; i < y.size; i++) {
            d[i] ^= y.d[i];
        }
        return *this;
    }

    const char *str() const {
        static char buf[1024];
        static const char *hex = "0123456789ABCDEF";
        char *p = buf + 1024;
        *--p = 0;
        for (int i = 0; i < size; i++) {
            u32 x = d[i];
            for (int j = 0; j < 8; j++) {
                *--p = hex[x & 15];
                x >>= 4;
            }
        }
        return p;
    }
};

Big A[100005];

int main() {
    int n, m, k;
    while (scanf("%d %d %d", &n, &m, &k) == 3) {
        for (int i = 0; i < n; i++) {
            // el c├│digo contin├║a...
        }
    }
}
