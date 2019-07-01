
int MaxDiff(const *numbers ,unsigned length){
    if (numbers == nullptr && length < 2){
        return 0;
    };
    int min = numbers[0];
    int maxDiff = numbers[1] - min;
    for(int i = 2 ; i<length; ++i){
        if(numbers[i-1] < min) {
            min = numbers[i-1];
        }
        int currentDiff = numbers[i] - min;
        if (currentDiff > maxDiff) {
            maxDiff = currentDiff;
        }
        return maxDiff;
    }
}
