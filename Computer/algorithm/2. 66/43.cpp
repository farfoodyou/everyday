int NumberOf1Between1AndN(int n){
    if(n<= 0){
        return 0;
    }

    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int NumberOf1(const char* strN){
    if(!strN || *strN < '0' || *strN > '9' || *strN =='\0'){
        return 0;
    }
    int first = *strN - '0';

    unsigned int length = static_cast<unsigned int> (strlen(strN));
    if(length == 1 && first == 0){
        return 0;
    }
    if(length == 1 && first > 0 ){
        return 1;
    }

    int numbFirstDigit = 0;
    if(first > 1){
        numFirstDigit = PowerBase10(length - 1);
    } else if (first == 1){
        numberFirstDigit = atoi(strN + 1) + 1;
    }

    int numOtherDigits = first* (length - 1)*PowerBase10(length -2);

    int numRecursive = NumberOf1(strN + 1);

    return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n){
    int result = 1;
    for(unsigned int i = 0; i<n; ++i){
        result *= 10;
    }
    return result;
}