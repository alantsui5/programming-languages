#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<assert.h>

void reverse (char *dst, const char *src)
{
    size_t i, j = strlen(src);

    for (i = 0; src[i]; i++)        /* loop over each char in src */
        dst[i] = src[--j];          /*  decrement j, reverse copy to dst */

    dst[i] = src[i];                /* nul-terminate dst */
}

void command_line_reverse(){
    
}
int main(){
    char *string = NULL;
    string = (char *)malloc(sizeof(char)*30);
    printf("Enter a string of text: \n");
    //Only Linux:scanf ("%m[^\n]%*c", &string);
    scanf("%s",string);
    //assert(strcmp(string,"qwe")==0);
    //fprintf(stderr,"Passed string input test\n");
    char *string2;
    strcpy(string2,string);
    reverse(string2,string);
    printf("(%s)\n",string2);

    free(string);
    free(string2);
}