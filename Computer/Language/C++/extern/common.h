
#ifndef UTIL_H
#define UTIL_H

typedef int KeyType;
typedef int ValueType;

namespace util {

typedef struct Node {
    KeyType k;
    ValueType v;
}node;

}

util::node z = {3,4};

#endif
