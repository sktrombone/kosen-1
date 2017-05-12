//3j19 sakamoto 
//kadai2-3

//unexecutable
#include <stdio.h>
#include <stdlib.h>

#define MEM (1024*32)

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
			getchar();
		}
		fclose(fp);
	}
	return 0;

}