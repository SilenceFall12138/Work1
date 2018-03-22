/*
 *打开当前目录下的文件 foo.txt ，并将其内容显示出来。
 *如果该文件不存在，就报告错误并退出。
 *可以参照Linux下cat 命令所实现的功能来实现。
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char buf[33] ={0};

	fp = fopen("foo.txt","r");
	if(NULL == fp)
	{
		perror("fopen");
		exit(1);
	}

	while(fread(buf, 1, 32, fp))
	{
		printf("%s", buf);
		memset(buf, 0, strlen(buf));
	}
	fclose(fp);

	return 0;
}
