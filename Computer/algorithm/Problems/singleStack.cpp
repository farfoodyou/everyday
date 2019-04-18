
int L[N];
int a[N];
void buildL(int *a, int *L, int n){
    Stack<int> S;
    for(int i=1 ;i<=n ;i++){
        while(S.size() && a[S.top()] >= a[i]) S.pop();

        if(S.empty())     L[i] = 0;
        else              L[i] = S.top();

        S.push(i);
    }
}
