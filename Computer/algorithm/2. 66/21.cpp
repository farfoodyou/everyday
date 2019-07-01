void RecorderOddEven(int* pData, unsigned int length) {
    if(pData == nullptr || length == 0){
        return ;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && (*pBegin & 0x1 ) != 0){
            pBegin++;
        }
        while(pBegin < pEnd && (*pEnd & Ox1) == 0){
            pEnd--;
        }
        if(pBegin<pEnd){
            //swap(*pBegin, *pEnd);
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEndd = temp;
        }
    }
}

void Recorder(int* pData, unsigned int length, bool (*func)(int)) {
    if(pData == nullptr || length == 0){
        return ;
    }
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd){
        while(pBegin < pEnd && !func(*pBegin)){
            pBegin++;
        }
        while(pBegin < pEnd && func(*pEnd)){
            pEnd--;
        }
        if(pBegin<pEnd){
            //swap(*pBegin, *pEnd);
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEndd = temp;
        }
    }
}

bool isEven(int n){
    return (n & 1) == 0;
}
