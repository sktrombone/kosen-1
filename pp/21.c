#include <stdio.h>

#define N 8
#define swap(a,b) do{int tmp;tmp=a;a=b;b=tmp;}while(0)

void print(int num[]){
	for(int i=0;i<N;i++){
		printf("%3d",num[i]);
	}
	printf("\n");
}

int main(){
	int num[N]={6,41,52,68,37,23,76,18};
	int left=0,right=N-1,last;
	print(num);
	
	while(1){
		printf("right:%d left:%d\n",right,left);
		for(int i=left;i<right;i++){
//			printf("for");
			if(num[i]>num[i+1]){
				printf("swap");
				swap(num[i],num[i+1]);
				last=i;
			}
		}
		right=last;
		printf("moved to right\n");
		print(num);
		printf("right:%d left:%d\n",right,left);
		for(int i=right;i>left;i--){
			if(num[i]>num[i-1]){
				swap(num[i],num[i+1]);
				last=i;
			}
		}
		left=last;
		printf("moved to left\n");
		print(num);
				printf("right:%d left:%d\n",right,left);
//		break;
	}
	print(num);
}