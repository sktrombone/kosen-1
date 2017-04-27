#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a,b) tmp=a;a=b;b=tmp;
int tmp;

void print(int n[],int size){
	for(int i=0;i<size;i++){
		printf("%3d,",n[i]);
	}
	printf("\n");
}
int min(int n[],int size){
//	printf("min first:%d\n",n[0]);
	int min=100,minpos;
	for(int i=0;i<size;i++){
		if(n[i]<min){
			min=n[i];
			minpos=i;
		}
	}
//	printf("min:%d min pos:%d\n",min,minpos);
	return minpos;
}

void insert(int n[],int size){
//	int tmp;
	for(int i=1,pos;i<100;i++){
		pos=i;
		while(n[pos]<n[pos-1]){
			swap(n[pos],n[pos-1])
			pos--;
		}
	}
	printf("insert\n");
	print(n,size);
}

int main(){
	int n[128];
	int ni[128];
	int pos=0, tmp;
	int size=100;
	FILE *fp;
	fp=fopen("num.txt","r");
	if(fp==NULL){
		printf("can't open the file");
		exit(1);
	}
	for(int i=0;i<size;i++) fscanf(fp,"%d\n",&n[i]);
	//insert sort
	memmove(ni,n,sizeof(n));
	insert(ni,size);
	//min
	for(int j=0;j<100;j++){
		pos=min(&n[j],100-j);
		if(pos!=-1){
			swap(n[j],n[pos+j])
		}
	}
	printf("min\n");
	print(n,size);
	//
	fclose(fp);
}

