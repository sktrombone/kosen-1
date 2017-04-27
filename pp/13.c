//bubble sort

#include <stdio.h>

#define swap(a,b) tmp=a;a=b;b=tmp;

void print(int n[],int size){
	for(int i=0;i<size;i++){
		printf("%3d,",n[i]);
	}
	printf("\n");
}

int main(){
	int n[10];
	int pos=0;
	int tmp;
	for(int i=0;i<10;i++) scanf("%d",&n[i]);
	for(int i=1,pos;i<10;i++){
		pos=i;
		while(n[pos]<n[pos-1]){
			swap(n[pos],n[pos-1])
			pos--;
		}
	}
	print(n,10);
}

