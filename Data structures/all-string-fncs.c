#include<stdio.h>
#include<string.h>
int main(){
    char s1[10]="tawheed";
    char s2[10]="isstudent";
    char s3[10]="hello";
    char s4[10]="convo";
    char s5[10]="Convo";
    char s6[10]="is";
    char *p;
    p=strstr(s2,s6);
    printf("string concatenation %s \n",strcat(s1,s2));
    printf("string concatenation(n char) %s \n",strncat(s1,s2,2));
    printf("string after copy is %s\n",strcpy(s1,s2));
    printf("string after copy(n) is %s\n",strncpy(s3,s4,3));
    printf("string(s1,s2) after comparing is %d\n",strcmp(s4,s5));
    printf("string(s1,s2) after comparing(strcmpi) is %d\n",strcmpi(s4,s5));
    //printf("first occurance of %s in %s is %s",s6,s2,p);
    printf("after strupr is %s\n",strupr(s3));
    printf("after strlwr is %s\n",strlwr(s3));
    printf("after using strlen len of s3= %d\n",strlen(s3));
    printf("after using strrev on s3: s3= %s\n",strrev(s3));
    printf("This is the string after strnset: %s\n", strnset(s2, 'x', 3));
    printf("This is the string after strset: %s\n", strset(s6, 'k'));
    char* target = strdup(s2); 
    printf("%s\n", target);
    char v1[50] = "how's the weather";
    char v2[30] = "weather";
    char *found_string = strstr(v1, v2);
    printf ("Substring located -> %s\n", found_string);
    char str[] = "Delhi,Hyderabad,Noida";  
    char *token;  
    token = strtok(str, ",");   
   while(token != NULL) {  
      printf("%s\n", token);  
      token = strtok(NULL, ",");  
   }  

    
return 0;
}