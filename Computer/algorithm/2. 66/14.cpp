/*
 * 输入参数: 整数n
 * 输出参数: 
 * 返回结果: 返回最大乘积
 * 描述: 剪绳子, 给一根长度为n的绳子, 剪成m段, 它们长度的乘积最大的值是多少?
 * 
*/
int maxProductAfterCutting_solution1(int length) {
    if(length < 2) {
        return 0;
    }
    if(length == 2) {
        return 1;
    }
    if(length == 3) {
        return 2;
    }
    int *products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;

    for(int i = 4; i<= length; ++i) {
        max = 0;
        for(int j = 1; j<=i/2; ++j) {
            int product = products[j] * products[i - j];
            if(max < product) {
                max = product;
            }
            products[i] = max;
        }
    }

    max = products[length];
    delete[] products;

    return max;
}

int maxProductAfterCutting_solution1(int length) {
    if(length < 2) {
        return 0;
    }
    if(length == 2) {
        return 1;
    }
    if(length == 3) {
        return 2;
    }
    int timesOf3 =length/3;
    if(length - timesOf3 * 3 == 1) {
        timesOf3 -=1;
    }
    int timesOf2 = (length -timesOf3 * 3) /2;
    return (int )(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}

