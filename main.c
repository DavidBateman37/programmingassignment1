
#include <stdio.h>
//These six lines are part of the functions which complete each task
//These are known as the function prototypes and are used to define what arguements and return value the functions have
//The void, in this case, is the return value which is the number a functoin gets replaced with in a line of code
//In these functions, the return value is void since the function does not return a value once it is executed but rather stores calculated information before it is printed to the screen
//The words in from of the return value are the function names, used when recalling the function in main
//The values in parentheses are function arguments
//These arguments are passed to the function by recieving an exact copy of its value
//Once the function is executed, the new values stored in the arguments can be used as any other variable
void rotationEncrypt(char*message, int key);
void rotationDecrypt(char*message, int key);
void substitutionEncrypt(char*message, char*sub);
void substitutionDecrypt(char*message, char*sub);
void wok(char*message, int key);
void rotationDecryptwok(char*completeMessage, int keycorrect);
//The asterix in the arguments indicate these as pointers
//Pointers store the address of other variables
//In this case, when the function is called, any change made to the pointer will also effect the original variable
int main()
{
    
    char message[100];//Array of length 100 which will store the message to be encrypted or decrypted
    char alphabetSub[27];//Array which will be used in substitution ciphers to store the new alphabet order which will be substituted in for the conventional alphabet order
    int key;//This variable will store the key (an integer between 0 and 26) for the rotation ciphers
    int test;//This variable is used in selecting which test will be implemented
    int keycorrect;//Used in the rotaion cipher without a key to store the key once found to be used to decipher the entire message
    char completeMessage[100];//Used to store the entire message after key is found in the rotaion cipher without a key task

    printf("Select a test by entering a number:\n");//These printf statements are printed to the screen for the user to choose a task to run    
    printf("1: Rotation cipher encryption with a key\n");
    printf("2: Rotation cipher decryption with a key\n");
    printf("3: Subsitution cipher encryption with a substitute alphabet\n");
    printf("4: Substitution cipher decryption with a substitute alphabet\n");
    printf("5: Rotation cipher decryption without a key\n");
    printf("Choose a test: \n");//Each number corresponds to the task described, inputting that number and hitting enter begins that task
    scanf("%d", &test);//After the task number is entered, the number is stored and that information is used to tell the program which task to run


    switch(test)//This is a switch case, which is used to organise large numbers of individual tasks
    {//The word test in parenthesis indicates this switch case is evaluating numbers from the task variable
    //This means once a number is inputted by the user, the corresponding case to the number implemented is executed
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


        printf("Decrypted message: %s\n", message);
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
    
        case 5:
        printf("Enter first word of message:\n");
        scanf("%s", message);
        wok(message, key);
    
        printf("Enter correct key:");
        scanf("%d", &keycorrect);
        printf("Enter entire message: ");
        scanf(" %[^\n]", completeMessage);
        rotationDecryptwok(completeMessage, keycorrect);
        printf("Decrypted message: %s\n", completeMessage);
        break;
        
        default:
        printf("Error, please enter a number between 1-5\n");
    }
}

void rotationEncrypt(char *message, int key)
{
    
    int i;
    int lk;
    char letter;
    for (i=0; message[i]!= '\0'; i++)
    {
        letter= message[i];
        
        if (letter >= 96 && letter <= 122)
    
        {
            letter = letter - 32;
        }
        
        lk= letter + key;
   
        if (lk >= 65 && lk <= 90)
       
        {
            letter = lk;    
        }
    
        else if (lk > 90)
        
        {
            letter = lk - 26;       
        }
       
       message[i]= letter;
    }
}

void rotationDecrypt(char*message, int key)
{
    
    int i;
    char letter;
    for(i = 0; message[i] != '\0'; ++i)
    {
		letter = message[i];
		
		if(letter >= 97 && letter <= 122)
		{
			letter = letter -key;
			
			if(letter < 97)
			{
				letter = letter + 26;
			}
			
			message[i] = letter - 32;
		}
		
		else if(letter >= 65 && letter <= 90)
		{
			letter = letter - key;
			
			if(letter < 65)
			{
				letter = letter + 26;
			}
			
			message[i] = letter;
		}
	}
}

void substitutionEncrypt(char*message, char*sub)
{
    int i;
    int letter;
    
    for(i=0; message[i]!= '0'; i++)
    {
        letter = message[i];
        
        if (letter >= 97 && letter <= 122)
        {
            letter = letter - 32;
        }
        
        if(letter>=65 && letter<=90)
        {
            letter = sub[letter-65];
        }
        
        message[i] = letter;
    }
}

void substitutionDecrypt(char*message, char*sub)
{
    int i;
    int compare=0;
    int letter;
    
    for(i=0; message[i]!= '0'; i++)
    {
        letter = message[i];
        
        if (letter >= 96 && letter <= 122)
        {
            letter = letter - 32;
        }
        
        if(letter >= 65 && letter <=90)
        {
            for( compare=0; compare<27; compare++)
            {
                if(message[i]== sub[compare])
                {
                    break;
                }
            }    
            message[i]= compare + 65;
        }
    }
}
    
void wok(char*message, int key)
{
    
    int i;
    int lk;
    char letter;
    int counter=1;
    
    while(counter<=26)
    {
        key = 1;
        for (i=0; message[i]!= '\0'; i++)
        {
            letter= message[i];
            
        
            if (letter >= 96 && letter <= 122)
            {
                letter = letter - 32;
            }   
            
            lk= letter - key;
   
            if (lk >= 65 && lk <= 90)
            {    
                letter = lk;
            }
             else if (lk < 65)
            {
                letter = lk + 26; 
            }
            
            message[i]= letter;
        }
        
        printf("%d: %s\n", counter, message);
        counter++;
    }
}

void rotationDecryptwok(char*completeMessage, int keycorrect)
{
    int i;
    char letter;

    for(i = 0; completeMessage[i] != '\0'; ++i)
    {
		letter = completeMessage[i];
		
		if(letter >= 97 && letter <= 122)
		{
			letter = letter - keycorrect;
			
			if(letter < 97)
			{
				letter = letter + 26;
			}
			
			completeMessage[i] = letter - 32;
		}
		
		else if(letter >= 65 && letter <= 90)
		{
			letter = letter - keycorrect;
			
			if(letter < 65)
			{
			     letter = letter + 26;
			}
			
			completeMessage[i] = letter;
		}
    }
}
