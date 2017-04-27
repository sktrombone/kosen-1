//bubble sort

#include <stdio.h>

#define swap(a,b) tmp=a;a=b;b=tmp;

void print(int n[],int size){
	for(int i=0;i<size;i++){
		printf("%3d,",n[i]);
	}
	printf("\n");
}
int min(int n[],int size){
	printf("min first:%d\n",n[0]);
	int min=100,minpos;
	for(int i=0;i<size;i++){
		if(n[i]<min){
			min=n[i];
			minpos=i;
		}
	}
	printf("min:%d min pos:%d\n",min,minpos);
	return minpos;
}

int main(){
	int n[10];
	int pos=0;
	int tmp;
	for(int i=0;i<10;i++) scanf("%d",&n[i]);
	for(int j=0;j<10;j++){
		pos=min(&n[j],10-j);
		if(pos!=-1){
			swap(n[j],n[pos+j])
		}else{
//		printf("no swap\n");
		}
//		print(n,10);
	}
	print(n,10);
}

