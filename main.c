#include <stdio.h>


int main(){
    
char message[100];
char alphabet[26]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z'};
int key;
int i;

for (i=0; message[i]!= '\0'; i++)
{ 
   letter = message[i];
   
   if (letter >= 'A' && letter <= 'Z')
   {
       letter = letter + key;
       message[i] = letter;
            
   }
   else {
       printf("Error");
   }
     
}

    printf{"Encrypted message; %s", letter};

    return 0;
}