#include <stdio.h>
#include <stdlib.h>

void print(unsigned char d[]){
	for(int k=0;k<20;k++){
		for(int i=0;i<512;i++){
			for(int j=7;j>=0;j--){
				if(d[k*64*64+i]&(1<<j)){
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
}
int main(int argc,char **argv){
	unsigned char d[64*64*20];
	FILE *fp;
	printf("input file name %s\n","01.img");
	fp=fopen("01.img","rb");
	if(fp==NULL){
		printf("can't open %s","01.img");
		exit(1);
	}
	fscanf(fp,"%s",d);
	print(d);
	fclose(fp);
	return 0;
}