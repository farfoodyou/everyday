好惨, 连B都搞不定了.
A 水题, 答案为 m*2; 虽然还有些害怕.
B 分行和列, 看最少需要多少, 再看最少的行号和列号是否相同, 如果相同且交叉点需要填,总数减一
C 对比S,T, 从左到右遍历, 如果有不同看P中是否有能填入的字母. 如果没有则为 NO; 遍历完了则输出YES;
D 看上去像博弈题...我不会

果然需要充足的时间, 大量的练习, 和丰富的经验才能做好.
实际动手才能有所进步. 还是先写下来思路再动手靠谱.
ABC我的思路没问题...但是编码功力下降太多了,以至于ABC 都完不成了...

B 虽然换了简洁的写法但是还是超时了 memset(r, 0, sizeof(int)*(m+1)); 错了 8 次后幡然醒悟...

D 

```
巴什博弈：只有一堆n个物品，两个人轮流从这堆物品中取物，规定每次至少取一个，最多取m个。最后取光者得胜。显然，如果n=m+1，那么由于一次最多只能取m个，所以，无论先取者拿走多少个，后取者都能够一次拿走剩余的物品，后者取胜。所以当总数n是(m+1)的整数倍多出来一些时（当多s吧，s<=m）那先手先取走多出的s；后手去k（1<=k<=m），先手在拿走（m+1-k）个，总是留给后手（m+1）的倍数，最后一定先手胜利。也就是说当n%(m+1)=0时，后手可以获胜，其他情况先手获胜。

威佐夫博弈：有两堆各若干个物品，两个人轮流从任一堆取至少一个或同时从两堆中取同样多的物品，规定每次至少取一个，多者不限，最后取光者得胜。这个博弈问题没有能够理解，就只是知道的如果先手面对的是奇异局势就会输，面对非奇异局势就能赢。最后决定记公式，当两堆数量相同时肯定是先手赢得，数量不等时，假设n<m；若n=(int)(((sqrt(5.0)+1.0)/2.0)*(m-n))；即为奇异局势，先手输。

尼姆博弈：有任意堆物品，每堆物品的个数是任意的，双方轮流从中取物品，每一次只能从一堆物品中取部分或全部物品，最少取一件，取到最后一件物品的人获胜。这个博弈看了博客知道了它与二进制中的异或运算有关（异或运算定义：异或运算方法是一个二进制逻辑运算，设其运算符合为^，a,b为二进制数，则a,b的异或为a^b。其运算满足如下：1^1=0,0^0=0,1^0=1,0^1=1，即相同的为0，不相同为1。）尼姆博弈是将所有堆数量的物品都进行异a1^a2^a3^…^an当结果为0则后手赢否则先手赢。
```
