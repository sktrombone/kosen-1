#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cnt=0;
#define swap(a,b) do{int tmp;tmp=a;a=b;b=tmp;cnt++;}while(0);
#define debug printf("%d %s \n",__LINE__,__func__); 
//#define print(a,b) fprint(a,b,"out.txt")

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
		pos++;
	}
	print(n,size);
}

void fprint(int n[],int size,int order,char *fname){
	debug;
	FILE *fp;
	fp=fopen(fname,"w");
		debug;
	if(fp==NULL){
		printf("file open failed");
		exit(1);
	}
		debug;
	for(int i=0;i<size;i++){
		fprintf(fp,"%3d\n",n[i]);
	}
	fclose(fp);
}

int main(){
	int *n;
	char str[128],fname[128]="num2.txt",fout[128],flong;
	int size=0,lines=0,order;
	FILE *fp;
	printf("please input file name (default is num2.txt)\n");
	scanf("%s",fname);
	flong=sizeof(fname)/sizeof(char);
	sprintf(fout,"%s.out",fname);
	printf("input output file name %s %s\n",fname,fout);
	printf("up(0) or dowm(1) (default is down)\n");
	scanf("%d",&order);

	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("can't open the file");
		exit(1);
	}
	while ( fgets(str,80,fp) ) lines++;
	rewind(fp);
	printf("lines :%d\n",lines);
	n=(int *)malloc(sizeof(int)*lines);
	do {int i=0;while(fscanf(fp,"%d",&(n[i++]))!=EOF); }while(0);
	printf("%d\n",size);
	printf("choose (B)ubble,(C)hoice,(I)nsert\n");
	scanf("%s",str);
	if(str[0]=='B'){
		bubble(n,lines);
	}else if(str[0]=='C'){
		choice(n,lines);
	}else if(str[0]=='I'){
		insert(n,lines);
	}else{
		printf("unknown command");
	}
	printf("swap counter: %d",cnt);
	
	fprint(n,lines,order,fout);
	fclose(fp);
}