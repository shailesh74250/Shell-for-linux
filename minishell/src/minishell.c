/*
 ============================================================================
 Name        : minishell.c
 Author      : shailesh kumar
 Description : it is minishell for linux os
 ============================================================================
 */
//this is working fine
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <time.h>


void command(){
	char com[30];
	char pathname[30];
	char cwd[1024];
	struct dirent *pDirent;
	DIR *pDir;
	/*int response;*/
	while(1){
			printf(">");
			scanf("%s",com); //input command
			scanf("%s",pathname); //path name

			/*create directory  */
			if(strcmp(com,"mkdir") == 0)
				mkdir(pathname, S_IRWXG | S_IROTH | S_IXOTH);
			/* delete directory */
			if(strcmp(com,"rmdir") == 0)
				rmdir(pathname);
			/* change directory path */
			if(strcmp(com,"chdir") == 0)
				chdir("/home/user/workspace/minishell/shailesh");
			/* get current working directory */
			if(strcmp(com,"pwd") == 0){
				getcwd(cwd, sizeof(cwd));
				printf("Current working dir:%s\n",cwd);
			}
			if(strcmp(com,"ls") == 0)
			{
				pDir = opendir(pathname);
				while((pDirent = readdir(pDir)) != NULL)
				{
					printf("[%s]\n", pDirent->d_name);
				}
			}
			/* file manipulation  */
			if(strcmp(com,"touch") == 0)
			{
				FILE *fp;
				fp = fopen(pathname,"w");
			}
			/* remove file or delete file */
			if(strcmp(com,"rm") == 0)
			{
				/*rm(pathname);
				printf("\n%d",response);*/
			}
			if(strcmp(com,"edit") == 0)
			{
				fileEditor(pathname);
				/*printf("edit");*/
			}
			/* print date and calender */
			if(strcmp(com,"date") == 0)
			{
				time_t t = time(NULL);
				struct tm *tm = localtime(&t);
				printf("%s\n", asctime(tm));
			}
			/* exit terminal */
			if(strcmp(com,"exit") == 0)
				exit(0);


	}
	printf("Thanks for using");

		//printf("error");
}
/* file editor */
void fileEditor(char pathname[30])
{
	char ch;
	FILE *fp;
	fp = fopen(pathname,"w");
	while((ch = getchar()) != 'a'){
		fputc(ch, fp);
	}
	fclose(fp);
}

int main(void) {
	//puts("$"); /* prints !!!Hello World!!! */
	//printf '\e[5;32;40m Blink Text\e[m\n'
	command();
	//fileEditor("myfile");


	return 0;
}
