#include <stdio.h>


int main(){
    
char letter;
char message[100];
char alphabet[27]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z', '\0'};
int key;
int i;

printf(" Enter message\n");
scanf("%s", message);

for (i=0; message[i]!= '\0'; i++)
{ 
   
   if (letter >= 'A' && letter <= 'Z')
   {
       letter = letter + key;
       message[i] = letter;
            
   }
   else if (letter > 'z') {
       letter = letter - 'z' + 'a' -1;
       
   }
      letter = message[i];
}

    printf{"Encrypted message; %s", letter};

    return 0;
}