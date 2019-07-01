bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength) {
    if((pData == nullptr) || nLength <= 0) {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;
    for(int i = 0; i< nLength; ++i){
        if (nCurSum <= 0){
            nCurSum = pData[i];
        } else {
            nCurSum += pData[i];
        }
        if(nCurSum > nGreatestSum){
            nGreatestSum = nCurSum;
        }
    }
    return nGreatestSum;
}
