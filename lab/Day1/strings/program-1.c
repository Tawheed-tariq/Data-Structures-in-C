// implement following functions: 
// strcpy, strncpy, strcmp, strncmp, strcat
#include<stdio.h>
#include<string.h>
int main(){
    char str[20], str1[10]={0}, str2[20], str3[20] = "ExcEpt_mE!";
    printf("Enter the string value: ");
    scanf("%s", str);

    //strcpy()
    strcpy(str2, str);
    printf("Copied string is: %s\n", str2);

    //strncpy()
    strncpy(str1,str,2);
    printf(" strncpy(): %s\n", str1);

    //strcmp()
    printf("comparison gives:  %d\n",strcmp(str, str2));

    //strncmp()
    printf("n comparison gives: %d\n", strncmp(str,str3,3));

    //strcat()
    strcat(str,str3);
    printf("catenation gives: %s\n", str);
    
    //strncat()
    strncat(str2, str3, 4);
    printf("n cat gives: %s", str2);

    //stelen()
    printf("Length of 1st string is %d", strlen(str));
}