#include <cstdio>
#include <cstring>

int sor[55][6];
double ren[55],ke[10];
int n,m;
int main(){
	while(scanf("%d%d",&n,&m)==2){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf("%d",&sor[i][j]);
			}
		}
		for(int i = 1; i <= n; i++){
			double sum = 0;
			for(int j = 1; j <= m; j++){
				sum += sor[i][j];
			}
			ren[i] = sum / m;
		}
		for(int j = 1; j <= m; j++ ){
			double sum = 0;
			for(int i = 1;  i<= n; i++){
				sum += sor[i][j];
			}
			ke[j] = sum / n;
		}
		int sum = 0;
		for(int i = 1; i<= n; i++){
			int flag = 1; // >=
			for(int j = 1; j<= m; j++){
				if(sor[i][j] < ke[j]){
					flag = 0;  // <
					break;
				}
			}
			if(flag){
				sum++;
			}
		}
		for(int i = 1; i<= n; i++){
			printf("%.2f%c",ren[i],i==n?'\n':' ');
		}
		for(int j = 1; j<= m; j++){
			printf("%.2f%c",ke[j],j==m?'\n':' ');
		}
		printf("%d\n\n",sum);
	}
	return 0;
}



