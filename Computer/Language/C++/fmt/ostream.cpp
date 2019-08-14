#include <fmt/ostream.h>
#include <fmt/format.h>

#include <sstream>
#include <iostream>

int main(){
    std::ostringstream oss;

    oss << "KT_" << 545 << ".";

    std::cout << oss.str() << std::endl;

/* 
    fmt::Writer w;
    w << "KT_" << 538 << ".";
    std::cout << w.str() << std::endl;
*/
    fmt::print("Elapsed time: {} seconds", 1.23);
/* 
    std::ostream os;
    os << "KT_" << 545 << ".";
    std::cout << os.c_str() << std::endl;
   */ 
    return 0;
}