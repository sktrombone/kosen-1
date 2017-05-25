#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define swap(a,b) tmp=a;a=b;b=tmp;
#define debug printf("%d %s \n",__LINE__,__func__); 
int tmp;

void print(int n[],int size){
	for(int i=0;i<size;i++){
		printf("%3d,",n[i]);
	}
	printf("\n");
}


void insert(int n[],int size){
	int tmp,pos=1;
	for(int i=1;i<size;i++){
		pos=i;
		while(n[pos-1]>n[pos]){
			swap(n[pos],n[pos-1]);
			if(pos==1) break;
			pos--;
		}
	}
	print(n,size);
}
int getMin(int n[],int size){
	int min=100,minpos;
	for(int i=0;i<size;i++){
		if(n[i]<min){
			min=n[i];
			minpos=i;
		}
	}
	return minpos;
}

void choice(int n[],int size){
	int pos;
	for(int j=0;j<100;j++){
		pos=getMin((n+j),100-j);
		if(pos!=-1){
			swap(*(n+j),n[pos+j])
		}
	}
	print(n,size);
}

void bubble(int n[],int size){
	int pos=0;
	for(int j=0;j<size;j++){
		for(int i=0;i<size-pos;i++){
			if(n[i]>n[i+1]){
				swap(n[i],n[i+1])
			}
		}
		print(n,size);
		pos++;
	}
}

int main(){
	int n[128];
	char str[128];
	int size=0;
	FILE *fp;
	fp=fopen("num.txt","r");
	if(fp==NULL){
		printf("can't open the file");
		exit(1);
	}
	while(fgets(str,80,fp)){
		n[size]=atoi(str);
		size++;
	}
	printf("%d\n",size);
	printf("choose (B)ubble,(C)hoice,(I)nsert\n");
//	print(n,100);
	scanf("%s",str);
	if(str[0]=='B'){
		choice(n,size);
	}else if(str[0]=='C'){
		choice(n,size);
	}else if(str[0]=='I'){
		insert(n,size);
	}else{
		printf("unknown command");
	}
	fclose(fp);
}
