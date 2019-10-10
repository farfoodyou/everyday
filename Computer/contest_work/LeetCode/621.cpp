class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result;
        int hashmap[26];
        memset(hashmap, 0, sizeof(hashmap));
        int max_  = 0;
        int max_same_count = 1;
        
        for (char ch : tasks) {
            hashmap[ch-'A'] ++;
        }
        for (int num:hashmap) {
            if (num > max_) {
                max_ = num;
                
                max_same_count = 1;
            } else if (num == max_) {
                max_same_count++;
            }
        }
        result = max((max_-1) * (n +1) + max_same_count, int(tasks.size()));
        return result;
    }

    int leastInterval2(vector<char>& tasks, int n) {
        int sum[26];
        memset(sum,0,sizeof(int)*26);
        for(int i=0;i<tasks.size();++i){
            ++sum[tasks[i]-'A'] ;
        }
        int max = sum[0];
        for(int i=1;i<26;++i){
            if(sum[i]>max) max = sum[i];
        }
        int num = 0;
        for(int i=0;i<26;++i){
            if(sum[i]==max) num++;
        }
        return (max-1)*(n+1)+num>tasks.size()?(max-1)*(n+1)+num:tasks.size();
    }
    
    int any = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0; }();
};


/*

给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
你需要计算完成所有任务所需要的最短时间。

统计26种任务的数量
答案是  max( (max-1)*(n+1) + num, tasks.size());

*/