#include <stdio.h>


int main(){
    
char letter;
char message[100];
char alphabet[27]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z', '\0'};
int key;
int i;

printf("Enter a message:\n");
scanf("%s", message);
printf("Enter a key:\n");
scanf("%d", &key); 
for (i=0; message[i]!= '\0'; i++)
{ letter= message[i];
   
   if (letter >= 'A' && letter <= 'Z')
   {
       letter = letter + key;
            
   }
   else if (letter > 'Z') {
       letter = letter - 'Z' + 'A' -1;
       
   }
       message[i]= letter;
}

    printf("Encrypted message: %s", message);

    return 0;
}