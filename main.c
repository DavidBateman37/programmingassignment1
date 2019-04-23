#include <stdio.h>
#include <string.h>

void rotationEncrypt(char*message, int key);
void rotationDecrypt(char*message, int key);
int main(){
    
char message[100];
char alphabet[27]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z', '\0'};
int key;
int i;
int test;

printf("Select a test by entering a number:\n");
printf("1: Rotation cipher encryption with a key\n");
printf("2: Rotation cipher decryption with a key\n");
printf("Choose a test: \n");
scanf("%d", &test);


switch(test){
    
    case 1:
printf("Enter a message:\n");
scanf("%s", &message);
printf("Enter a key:\n");
scanf("%d", &key); 
rotationEncrypt(message, key);


    printf("Decrypted message: %s\n", message);
    break;
    
    case 2:
printf("Enter a message:\n");
scanf("%s", message);
printf("Enter a key:\n");
scanf("%d", &key); 
rotationDecrypt(message, key);


    printf("Encrypted message: %s\n", message);
    break;

}
}

void rotationEncrypt(char *message, int key){
    
 int i;
 int lk;
 char letter;
 for (i=0; message[i]!= '\0'; i++)
{   letter= message[i];
if (letter >= 96 && letter <= 122)
        {
            letter = letter - 32;
        }
    lk= letter + key;
   
   if (lk >= 65 && lk <= 90)
   {
       letter = lk;
            
   }
   else if (lk > 90) {
       letter = lk - 26;
       
   }
       message[i]= letter;
}
}

void rotationDecrypt(char*message, int key){
    
    int i;
    int lk;
    char letter;
    for (i=0; message[i]!= '\0'; i++)
{   letter= message[i];
if (letter >= 96 && letter <= 122)
        {
            letter = letter - 32;
        }
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
}