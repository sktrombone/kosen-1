#include <stdio.h>

#define N 100
#define swap(a,b) do{int tmp;tmp=a;a=b;b=tmp;}while(0)
#define swap2(a,b) a^=b^=a^=b
#define debug printf("%d %s ",__LINE__,__func__); printf


void print(int num[]){
	for(int i=0;i<N;i++){
		printf("%3d",num[i]);
	}
	printf("\n");
}

int bubble1(int n[],int size){
//	debug ("size :%d\n ",size);
	int last;
	for(int i=0;i<size;i++){
		if(n[i]>n[i+1]){
			swap(n[i],n[i+1]);
			last=i;
		}
	}
	debug ("%d\n",last);
	return last;
}

int bubble2(int n[],int size){
	int last=0;
	for(int i=size;i>0;i--){
		if(n[i-1]>n[i]){
			swap(n[i],n[i-1]);
			last=i;
		}
	}
	debug ("%d\n",last);
	return last;
}

int main(){
	char str[128];
	int num[N],size=0;//={6,41,52,68,37,23,76,18};
	FILE *fp;
	fp=fopen("num.txt","r");
	if(fp==NULL){
		printf("can't open the file");
		exit(1);
	}
	while(fgets(str,80,fp)){
		num[size]=atoi(str);
		size++;
	}
	
	int left=0,right=size-1;//,last;
	print(num);
	while(1){
//		debug ("right :%d left:%d\n ",right,left);
//		print(num);
		right=left+bubble1((num+left),right-left);
		debug ("right :%d left:%d\n ",right,left);
		print(num);
		left=left+bubble2((num+left),right-left);
		debug ("right :%d left:%d\n ",right,left);

		if(left== right) break;

	}
	print(num);
}