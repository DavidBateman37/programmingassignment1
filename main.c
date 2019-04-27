#include <stdio.h>
//These six lines are part of the functions which complete each task
//These are known as the function prototypes and are used to define what arguements and return value the functions have
//The void, in this case, is the return value which is the number a function gets replaced with in a line of code
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
        case 1://This is the rotation cipher encryption, rotation ciphers move the alphabet along the same amount of times as implied by the key, hence a key greater than 25 will begin to repeat itself
        //Each letter in the message is replaced by the letter the same amount of spaces down the alphabet as the key, eg key of 2 makes A into C
        printf("Enter a message:\n");//User inputs a message to be encrypted (or jumbled up by moving the alphabet along)
        scanf(" %[^\n]", message);//This message is stored in the message array declared above
        printf("Enter a key:\n");//A key between 1-25 is entered to shift the alphabet along for encryption
        scanf("%d", &key);//This number is stored in the key variable
        rotationEncrypt(message, key);//This indicates that variables entered will now be used in the function definition below where encryption takes place


        printf("Decrypted message: %s\n", message);//The now encrypted message was stored back in the message array in the function definition and is printed to the screen
        break;//The break statement breaks the program execution out of the switch case. Since no more code is in main after this switch case, the program finishes
    
        case 2://This is the rotation cipher decryption, takes cipher text and moves the alphabet back the number of spaces allocated by the key 
        printf("Enter a message:\n");//Enter the cipher text to be decoded, it is stored in the array message
        scanf(" %[^\n]", message);//The symbols after the % sign includes blank space in the stored message however it is not encoded 
        printf("Enter a key:\n");
        scanf("%d", &key);//The message and key must be input before the function is executed as these values are used in the function
        rotationDecrypt(message, key);//The cipher text and key entered are used in the function definition where each letter is rotated backwards with the key to form plain text


        printf("Decrypted message: %s\n", message);//The plain text is then printed to the screen after it is stored back in message (done in the function definition)
        break;
    
        case 3://This is an encryption by substitution cipher where an entirely new ordered list of letters is used substituted in for the letters of the alphabet ie the first letter in the substitute list is subbed in everywhere there is an A in the message
        printf("Enter a message:\n");//Plain text is stored in the message string to be encoded
        scanf(" %[^\n]", message);
        printf("Enter a substitution alphabet\n");//A list of 26 letters in any order is entered without spaces, these will be substited in for their corresponding alphabet letters
        scanf("%s", alphabetSub);//This is stored in the array  alphabetSub which has length 27 for the 26 letters entered and a terminating character (you dont enter this)
        substitutionEncrypt(message, alphabetSub);//This entered data is used in the function definition below 

        printf("Encrypted message: %s\n", message);//The encrypted message is stored in message in the function and printed to the screen
        break;
    
        case 4://This is decrypting cipher text with a substitution cipher, similar to encrypting but the letters that correspond to letters in the correct alphabet are replaced with these letters to form plain text
        printf("Enter a message:\n");//Cipher text is entered here
        scanf(" %[^\n]", message);//Cipher text is stored in the string message including white space (white space stays the same)
        printf("Enter a substitution alphabet\n");//The disordered string used to encode the message is entered here in capital form with no spaces
        scanf("%s", alphabetSub);//The 26 letters are stored alphabetSub
        substitutionDecrypt(message, alphabetSub);//The data is run through the function defintion where the message is decoded

        printf("Decrypted message: %s\n", message);//The decoded message is stored in mesage and printed to the screen
        break;
    
        case 5://This task is a rotation cipher decryption without knowing the key, hence the key must be found first
        printf("Enter first word of message:\n");//The first word (or a single word) in the cipher text is entered
        scanf("%s", message);//This word will be used to find the correct key
        wok(message, key);//This function uses the letter entered to print all 26 solutions for different keys, the user can then find the corresponding key that makes a correct word
    
        printf("Enter correct key:");//Once the key has been found, it is entered here and a similar process to case 2 is completed
        scanf("%d", &keycorrect);//Stored in a different variable for easy distinction
        printf("Enter entire message: ");//Now the entire cipher text can be entered for decoding
        scanf(" %[^\n]", completeMessage);//Stored in a different array completeMessage to be used in the following function
        rotationDecryptwok(completeMessage, keycorrect);//The entered data is now run through the function where the message is decoded by rotation corresponding to the correct key
        printf("Decrypted message: %s\n", completeMessage);//The decoded message is then printed to the screen after being stored in completeMessage
        break;
        
        default://If a number corresponding to the cases above is not entered, the program will print an error to the screen and return the program to tell the user to select a valid case
        printf("Error, please enter a number between 1-5\n");//Printed to the screen if a non valid case is selected
    }
}
//This is the function definition for the rotation cipher encryption
//The inputs for this definition from inside main are the plain text to be decrypted and the key which tells the program how many spaces each letter should be rotated
//The return value is void since the function doesn't return a value to the screen but stores information to be printed to the screen
//The limitation for the message string is 99 letters or symbols including blank places since 100 data addresses are allocated for this string and one is needed for the \0 end symbol
void rotationEncrypt(char *message, int key)
{
    
    int i;//Variables used in the function definition are declared at the top of the definition
    int lk;
    char letter;
    for (i=0; message[i]!= '\0'; i++)//While the array storring the message doesn't reach the end starting from the first element message[0] and incrementing by one each loop to increment each letter individually
    {
        letter= message[i];//assigns the ascii value of the first element to the variable letter
        
        if (letter >= 96 && letter <= 122)//if this value is between 'a' and 'z' (note the lowercase)
    
        {
            letter = letter - 32;//This turns any lowercase input into uppercase
        }
        
        lk= letter + key;//assigns the variable lk the value of each element's ascii value plus the key to rotate the letter along the alphabet
   
        if (lk >= 65 && lk <= 90)//If the message element is a capital letter
       
        {
            letter = lk;//the variable letter is assigned the value of the inital element plus the key to shift the element down the ascii alphabet   
        }
    
        else if (lk > 90)//if adding the key to the element pushes if off the end of the alphabet eg: 'Z' rotated two more places
        
        {
            letter = lk - 26;//the letter is rotated back to the beginning of the alphabet       
        }
       
       message[i]= letter;//The string element is reassigned a value equal to letter which is now the encoded letter
    }//This loop continues until all letters are encoded and the '\0' sign is reached
}//These values are now stored ready to be printed to the screen in main

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

