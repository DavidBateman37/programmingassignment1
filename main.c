#include <stdio.h>

void rotationEncrypt(char*message, int key);
void rotationDecrypt(char*message, int key);
int main(){
    
char letter;
char message[100];
char alphabet[27]= {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z', '\0'};
int key;
int i;
int lk;
int test;

printf("Select a test by entering a number:\n");
printf("1: Rotation cipher encryption with a key\n");
printf("2: Rotation cipher decryption with a key\n");
printf("Choose a test: \n");
scanf("%d", test);
if (test>=1, test<=6){
    scanf("%d", &test);
    printf("Your selection: %d\n", test);
}

else {
    printf("Error, please select a test");
    return 0;
}

switch(test){
    
    case 1:
rotationEncrypt(message, key);   
printf("Enter a message:\n");
scanf("%s", message);
printf("Enter a key:\n");
scanf("%d", &key); 


    printf("Decrypted message: %s\n", message);
    break;
    
    case 2:
rotationalDecrypt(message, key);
printf("Enter a message:\n");
scanf("%s", message);
printf("Enter a key:\n");
scanf("%d", &key); 


    printf("Encrypted message: %s\n", message);
    break;

}
}

void rotationEncrypt(char*message, int key){
    
 int i;
 int lk;
 for (i=0; message[i]!= '\0'; i++)
{   letter= message[i];
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

void rotationalDecrypt(char*message, int key){
    
    int i;
    in lk;
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
}