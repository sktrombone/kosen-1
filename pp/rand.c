
#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fp;
	fp=fopen("num.txt","w");
	if(fp==NULL){
		printf("can't open file.\n");
		exit(1);
	}
	for(int i=0;i<100;i++){
		fprintf(fp,"%d\n",rand()%100);
	}

	fclose(fp);


}
