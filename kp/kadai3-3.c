
//3j19 sakamoto 
//³‹K‰»
//unfinished


#include <stdio.h>
#include <stdlib.h>

#define MEM (1024*32)
#undef min
#undef max
#define min(x,y) ((x<y)? x:y)
#define max(x,y) ((x>y)? x:y)

void expand(char data[512],char pattern[64][64]){
	for(int i=0;i<512;i++){
		for(int j=7;j>=0;j--){
			if(data[i]&(1<<j)){
				pattern[i/8][(i%8+1)*8-j]=1;
			}else{
				pattern[i/8][(i%8+1)*8-j]=0;
			}
		}
	}
}


void printimg(unsigned char d[]){
	for(int i=0;i<512;i++){
		for(int j=7;j>=0;j--){
			if(d[i]&(1<<j)){
				printf("*");
			}else{
				printf(".");
			}
		}
		if(i%8==7 ){
			printf("\n");
		}
	}
}

void outlines(char pattern[64][64]){
	for(int i=1;i<64-1;i++){
		for(int j=1;j<64-1;j++){
			if(	pattern[i-1][j-1] && pattern[i  ][j-1] && pattern[i+1][j-1] &&
				pattern[i-1][j  ] &&					  pattern[i+1][j  ] &&
				pattern[i-1][j+1] && pattern[i  ][j+1] && pattern[i+1][j+1] ){
				pattern[i][j]=2;
			}

			if(pattern[i][j]==1)	printf("*");
			else					printf(".");
		
		}
		printf("\n");
	}
}

//(x >= 0)?  x : -x
//#define min(x,y) ((x>y)? x:y)
//
void printPattern(char p[64][64],int x,int y){
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			for(int k=0;k<x;k++){
				
				if(p[i][j]){
					printf("*");
				}else{
					printf(".");
				}
			}
		}
		printf("\n");
	}
}
void printPattern2(char p[64][64],int x,int y,int x1,int y1){
	for(int i=y;i<y1;i++){
		for(int j=x;j<x1;j++){
			for(int k=0;
			if(p[i][j]){
				printf("*");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
}

#define H 64*3

void normalize(char p[64][64]){
	int x0=64,y0=64,x1=0,y1=0,h,w;
//	const int H=64*3;
	for(int i=0;i<64;i++){
		for(int j=0;j<64;j++){
			if(p[i][j]==1){
				x0=min(x0,j);
				y0=min(y0,i);
				x1=max(x1,j);
				y1=max(y1,i);
			}
			
		}
	}
	w=x1-x0;
	h=y1-y0;
	printf("%d \nx0: %d y0:%d \nx1: %d y1:%d\n h:%d w:%d\n",__LINE__,x0,y0,x1,y1,w,h);
	printPattern2(p,x0,y0,x1,y1);
//	printPattern(p,2,2);

}

int main(int argc,char **argv){
	unsigned char d[MEM];
	char p[64][64];
	FILE *fp;
	char fname[128];
	for(int file=1;file<47;file++){
		for(int i=0;i<MEM;i++)	d[i]=0;
		snprintf(fname,sizeof(fname),"%02d.img",file);
		printf("input file name %s\n",fname);
		fp=fopen(fname,"rb");
		if(fp==NULL){
			printf("can't open %s",fname);
			exit(1);
		}
		for(int i=0;i<20;i++){
			fread(d,512,1,fp);
//			printimg(d);
			expand(d,p);
			outlines(p);
			normalize(p);
			
			getchar();
		}
		fclose(fp);
	}
	return 0;

}