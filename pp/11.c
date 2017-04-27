//bubble sort

#include <stdio.h>

#define swap(a,b) tmp=a;a=b;b=tmp;

void print(int n[],int size){
	for(int i=0;i<size;i++){
		printf("%3d",n[i]);
	}
	printf("\n");
}

int main(){
	int n[10];
	int tmp;
	int pos=0;
	for(int i=0;i<10;i++){
		scanf("%d",&n[i]);
	}
	for(int j=0;j<10;j++){
		for(int i=0;i<10-pos;i++){
			if(n[i]>n[i+1]){
				swap(n[i],n[i+1])
			}
		}
		print(n,10);
		pos++;
	}
}
