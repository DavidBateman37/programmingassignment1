#include <stdio.h>


int main(){

char letter;
char message[100];
int key;
int i;
int lk;

printf("Enter a message:\n");
scanf("%s", message);
printf("Enter a key:\n");
scanf("%d", &key); 
for (i=0; message[i]!= '\0'; i++)
{   letter= message[i];
    lk= letter - key;
   
   if (lk >= 65 && lk <= 90)
   {
       letter = lk;
            
   }
   else if (lk < 65) {
       letter = lk + 26;
       
   }
       message[i]= letter;
}

    printf("Encrypted message: %s", message);

    return 0;
}