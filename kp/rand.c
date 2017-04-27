
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	unsigned char tmp[128];
	fp=fopen("num.txt","wb");
	if(fp==NULL){
		printf("can't open file.\n");
		exit(1);
	}
	for(int i=0;i<512;i++){
		tmp[0]=0b01010101;
		fwrite(&(tmp[0]),sizeof(unsigned char),1,fp);
	}

	fclose(fp);

}
