//s15080 sakamoto jun-ichiro
//kadai2-1.c

#include <stdio.h>
#include <stdlib.h>

#define MEM (1024*32)

void expand(char data[512],char pattern[64][64]){
	for(int i=0;i<512;i++){
		for(int j=7;j>=0;j--){
			if(data[i]&(1<<j)){
				pattern[i/8][(i%8+1)*8-j]=0;
			}else{
				pattern[i/8][(i%8+1)*8-j]=1;
			}
		}
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
			expand(d,p);
			for(int i=0;i<64;i++){
				for(int j=0;j<64;j++){
					if(p[i][j]==0)	printf("*");
					else			printf(".");
				}
				printf("\n");
			}
			getchar();
		}
		fclose(fp);
	}
	return 0;

}