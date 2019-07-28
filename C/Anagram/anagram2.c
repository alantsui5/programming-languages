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

int main(){
    char file_name[25],anagram[50];
    printf("Enter name of a file you wish to see\n");
    scanf("%s",file_name);

    FILE *anagram_file;
    anagram_file = fopen(file_name,"r");
    if (anagram_file == NULL)
    {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
    }

    printf("The contents are:\n");

    while(fgets(anagram,50,anagram_file)!=NULL){
        anagram[strcspn(anagram, "\r\n")] = 0;
        printf("%s\n",anagram);

        char anagram_new[50];
        strcpy(anagram_new,anagram);
        reverse(anagram_new,anagram);
        printf("(%s)\n",anagram_new);
    }
    fclose(anagram_file);
    //free(anagram);
    return 0;
}