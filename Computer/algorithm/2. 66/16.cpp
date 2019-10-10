// 16.cpp
/*
 * 题目: 数值的整数次方
 * 输入参数: 底数, 整数exponent
 * 输出参数: 
 * 返回结果: 底数base 的exponent次方
 * 描述: 用快速幂的方式来计算数值的整数次方
 * 
*/
bool g_InvalidInput = false;
double Power(double base, int exponent) {
    g_InvalidInput =false;
    if(equal(base, 0.0) && exponent < 0){
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int) (exponent);
    if(exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }
    double result = PowdWithUnsignedExponent(base, absExponent);
    if(exponent < 0){
        result = 1.0 / result;
        return result;
    }
    double PowerWithUnsignedExponent(double base, unsigned int exponent) {
        double result = 1.0;
        for(int i = 1; i<= exponent; ++i) {
            result *= base;
        }
        return result;
    }
}

double PowerWithUnsignedExponent(double base, unsigned int exponent) {
    if(exponent == 0){
        return 1;
    }
    if(exponent == 1){
        return base;
    }

    double result = PowerWithUnsignedExponent(base, exponent>>1);
    result *= reslut;
    if(exponent & 0x1 == 1){
        result *= base;
    }
    return result;
}

