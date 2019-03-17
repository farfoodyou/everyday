#include "Base.h"
namespace YL {
namespace TRY {

int o::oo() {
    return 201;
}

Base::Base() { value = 909;}
Base::~Base() {}

int Base::set(int v){
    value = v;
    return 0;
}   

int Base::get(){
    return value;
}

int echo(){
    return 200;
}

} // end of namespace try
} // end of namespace ly
