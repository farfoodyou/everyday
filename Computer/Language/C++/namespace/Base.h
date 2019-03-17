#ifndef YL_TRY_BASE_H
#define YL_TRY_BASE_H

namespace YL {
namespace TRY {

class Base {
    int value;

public:
    int get();
    int set(int v);
    bool equals(Base &other);
    Base();
    ~Base();
};

class o {
public:
    int oo();
};


int echo();

}
}

#endif