#include <bits/stdc++.h>  // 这个头文件再mac里得自己下载,挺麻烦的.
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    long _begin_time = clock();
#endif
    int n, k; scanf("%d%d", &n, &k);
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int tmp; scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end());
    int pos = lower_bound(vec.begin(), vec.end(), k) - vec.begin();
    int ans = pos == vec.size() ? -1 : vec[pos];
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    long _end_time = clock();
    printf("time = %ld ms\n", _end_time - _begin_time);
#endif
	return 0;
}
