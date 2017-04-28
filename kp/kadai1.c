//s15080 â–{“Õˆê˜Y
//kadai1.c

#include <stdio.h>
#include <stdlib.h>

#define MEM (1024*32)

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

int main(int argc,char **argv){
	unsigned char d[MEM];
	char p[64][64];
	FILE *fp;
	char fname[128]="01.img";
	for(int i=0;i<MEM;i++)	d[i]=0;
	printf("input file name %s\n",fname);
	fp=fopen(fname,"rb");
	if(fp==NULL){
		printf("can't open %s",fname);
		exit(1);
	}
	for(int i=0;i<20;i++){
		fread(d,512,1,fp);
		printimg(d);
		getchar();
	}
	fclose(fp);
	return 0;

}