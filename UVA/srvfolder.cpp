#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Press Enter to skip writting:\n");
    char ch[100];
int i = system("mkdir SRV_Folder");
FILE *fp=fopen("SRV_Folder\\sabuj.txt","w");
gets(ch);
if(ch[0]!='\0')
fputs(ch,fp);
fclose(fp);
return 0;
}

//Read more: http://wiki.answers.com/Q/Is_there_any_program_to_create_a_folder_using_language_c#ixzz1nsaQJ7GV


//Read more: http://wiki.answers.com/Q/Is_there_any_program_to_create_a_folder_using_language_c#ixzz1nsa2uZGT
