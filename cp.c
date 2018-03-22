#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
	FILE *fp1;
	FILE *fp2;
	char buf[34] ={0};
	if(argc != 3)
	{
		printf("Error!\nFor example:./cp xxxx xxxx\n");
		exit(1);
	}

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "a+");

	if(NULL == fp1)
	{
		perror("fopen2");
		exit(1);
	}

	if(NULL == fp2)
	{
		perror("fopen2");
		exit(2);
	}

	while(fread(buf, 1, 32, fp1))
	{
		fwrite(buf, 1, 32, fp2);
		memset(buf, 0, strlen(buf));
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}
