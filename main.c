#include <stdio.h>
#include <string.h>

void rotationEncrypt(char*message, int key);
void rotationDecrypt(char*message, int key);
void substitutionEncrypt(char*message, char*sub);
void substitutionDecrypt(char*message, char*sub);
int main(){
    
char message[100];
char alphabetSub[27];
int key;
int test;

printf("Select a test by entering a number:\n");
printf("1: Rotation cipher encryption with a key\n");
printf("2: Rotation cipher decryption with a key\n");
printf("3: Subsitution cipher encryption with a substitute alphabet\n");
printf("4: Substitution cipher decryption with a substitute alphabet\n");
printf("Choose a test: \n");
scanf("%d", &test);


switch(test){
    
    case 1:
printf("Enter a message:\n");
scanf(" %[^\n]", message);
printf("Enter a key:\n");
scanf("%d", &key); 
rotationEncrypt(message, key);


    printf("Decrypted message: %s\n", message);
    break;
    
    case 2:
printf("Enter a message:\n");
scanf(" %[^\n]", message);
printf("Enter a key:\n");
scanf("%d", &key); 
rotationDecrypt(message, key);


    printf("Encrypted message: %s\n", message);
    break;
    
    case 3:
printf("Enter a message:\n");
scanf(" %[^\n]", message);
printf("Enter a substitution alphabet\n");
scanf("%s", alphabetSub);
substitutionEncrypt(message, alphabetSub);

    printf("Encrypted message: %s\n", message);
    break;
    
    case 4:
printf("Enter a message:\n");
scanf(" %[^\n]", message);
printf("Enter a substitution alphabet\n");
scanf("%s", alphabetSub);
substitutionDecrypt(message, alphabetSub);

    printf("Decrypted message: %s\n", message);
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

void substitutionEncrypt(char*message, char*sub){
    int i;
    int letter;
    
    for(i=0; message[i]!= '0'; i++){
        letter = message[i];
        if (letter >= 96 && letter <= 122)
        {
            letter = letter - 32;
        }
        if(letter>=65 && letter<=90){
            letter = sub[letter-65];
        }
        message[i] = letter;
    }
}

void substitutionDecrypt(char*message, char*sub){
    int i;
    int compare=0;
    int letter;
    for(i=0; message[i]!= '0'; i++){
        letter = message[i];
        if (letter >= 96 && letter <= 122)
        {
            letter = letter - 32;
        }
        if(letter >= 65 && letter <=90) {
            
            for( compare=0; compare<27; compare++) {
                if(message[i]== sub[compare]) {
                    break;
                }
            }
        message[i]= compare + 65;
        }
    }
}