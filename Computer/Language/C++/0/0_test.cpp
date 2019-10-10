#include <iostream>
#include <cstdio>

int main(){
    // test 1
    {
        double sum = 99.0;
        double res = 0;
        res = sum / 0;
        std::cout <<  res << std::endl;
        std::cout <<  (res < sum) << std::endl;
        std::cout <<  (res > sum) << std::endl;
    }
    // test 2
    {
        double sum = 0.0;
        double res = 0;
        res = sum / 0;
        std::cout <<  res << std::endl;
        std::cout <<  (res < sum) << std::endl;
        std::cout <<  (res > sum) << std::endl;
    }
    // test 3
    {
        double sum = -99.0;
        double res = 0;
        res = sum / 0;
        std::cout <<  res << std::endl;
        std::cout <<  (res < sum) << std::endl;
        std::cout <<  (res > sum) << std::endl;
        printf("%lf\n", res);
    }
    return 0;
}
