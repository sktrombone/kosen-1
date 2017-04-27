
#include <stdio.h>
#include <stdlib.h>

void print(unsigned char d[]){
	for(int i=0;i<512;i++){
		for(int j=7;j>=0;j--){
			if(d[i]&(1<<j)){
				printf("1");
			}else{
				printf("0");
			}
		}
//		if(i%16==15 ){
		if(i%8==7 ){
			printf("\n");
		}
	}
}
int main(int argc,char **argv){
	unsigned char d[1024];
	FILE *fp;
	printf("input file name %s\n",argv[1]);
	fp=fopen(argv[1],"rb");
	if(fp==NULL){
		printf("can't open %s",argv[1]);
		exit(1);
	}
	fscanf(fp,"%s",d);
	print(d);
	fclose(fp);
	return 0;
}
