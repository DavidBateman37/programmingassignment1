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
//This is the function definition for the rotation cipher encryption which takes each letter from message and rotates in the number of spaces in the alphabet specified by the key
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

//The is the rotation cipher decryption which takes a decrypted message and rotates each letter back the number of spaces in the alphabet specificed by the key to make plain text which can be read
//The inputs for this function are the cipher text to be decoded and the rotation key which tells the program how many spaces each letter should be rotated to be decrypted
//The return value is again void since the function doesn't return a value after execution itself
//The limitation for the message string is again 99 for the same reasons as in the previous function
void rotationDecrypt(char*message, int key)
{
    
    int i;//variables need to be declared again since variables in previous function are only known inside that function definition
    char letter;
    for(i = 0; message[i] != '\0'; i++)//i is declared as starting at 0 and the loop runs, incrementing i each cycle until the end of the cipher text is found
    {
		letter = message[i];//the variable letter is assigned the value of the elements of message each iteration
		
		if(letter >= 97 && letter <= 122)//If the letter is lowercase
		{
			letter = letter -key;//letter is assigned the value of the encoded element minus the key to produce the decrypted lowercase letter
			
			if(letter < 97)//if substracting the key makes the element fall of the start of the alphabet
			{
				letter = letter + 26;//26 is added to make the letter added to the end of the alphabet again
			}
			
			message[i] = letter - 32;//32 is subtracted to turn any lowercase elements into uppercase since all output should be uppercase
		}
		
		else if(letter >= 65 && letter <= 90)//if the element is an uppercase letter
		{
			letter = letter - key;//the variable letter is assigned the value of the decoded element 
			
			if(letter < 65)//the subtracting the key pushes the element off the front of the alphabet
			{
				letter = letter + 26;//26 is added to move that element back to the end of the alphabet
			}
			
			message[i] = letter;//each element is then reassigned the coded letter for each iteration of the program
		}
	}
}

//The function encrypts a cipher by substitution, that is is replaces each letter in the alphabet with a letter from an alphabet of a different order, eg A in the message is replaced with the first letter of the substitution alphabet 
//The inputs for the function are the message in plain text to be encrypted and a string of 26 uppercase letters which will be used to encrypt the message
//The return value is again void since the function isn't returning a value itself but is being used to alter the values of each letter in the message
//The limitation for the message is again 99 for the same reason as previously and the string length for the substitute alphabet is 27 since 26 letters need to be entered and one space if left for the '0\' symbol
void substitutionEncrypt(char*message, char*sub)
{
    int i;//variables used inside the function definition need to be declared
    int letter;
    
    for(i=0; message[i]!= '0'; i++)//for loop is initiated where the loop runs for each element of the string message until the entire message has been encrypted
    {
        letter = message[i];//the variable letter is assigned the value of the message elements for encryption to begin
        
        if (letter >= 97 && letter <= 122)//if the value assigned to letter is a lowercase letter
        {
            letter = letter - 32;//the lowercase letter is converted into an uppercase letter
        }
        
        if(letter>=65 && letter<=90)//if the value assigned to letter is an uppercase letter
        {
            letter = sub[letter-65];//the variable letter is given the value of the element in the sub array that is equal to the initial element minus 65 ie A in the message is given the value of the first array element in the substitute alphabet and so on
        }
        
        message[i] = letter;//The string element is replaced with the now encrypted letter
    }
}

//This function decrypts cipher text by replacing each letter in the message that was substituted with a letter from a substitute alphabet with the correct letter corresponding to their place in the alphabet
//The inputs are message which is the cipher text to be decrypted and the substitue alphabet string which was used to encrypt the message initially
//The return value is void since the function isn't return a value itself but is being used to decode letters and store them in the string message to be recalled in main
//The limitation for the message is 99 characters since one is needed for the end '0\' symbol (this doesn't need to be entered) and 26 uppercase letters for the substitute alphabets with one space again left for the end symbol
void substitutionDecrypt(char*message, char*sub)
{
    int i;//Variables to be used inside the function definition are initialised
    int compare=0;//This variable is used to compare between the substitue alphabet and the message string elements. Once the message element has the same value as the sub element, the loop breaks 
    int letter;
    
    for(i=0; message[i]!= '0'; i++)//For loop which decodes each element individually and ends once the end of the message is reached
    {
        letter = message[i];//Letter is assigned the value of the message elements
        
        if (letter >= 96 && letter <= 122)//If the message element is lower case
        {
            letter = letter - 32;//The lower case letter is made uppercase
        }
        
        if(letter >= 65 && letter <=90)//If the element is uppercase
        {
            for( compare=0; compare<27; compare++)//For loop which compares the message element to all of the possible elements in the substitute alphabet until a match is found
            {
                if(message[i]== sub[compare])//If the message element is the same as the element in the substitue alphabet (ie once the letter in the message is the same as the letter in the substite alphabet)
                {
                    break;//The loop breaks
                }
            }    
            message[i]= compare + 65;//The message element is then assigned the position number of which the matching letters were found plus 65 which gives the uppercase letter which should be in that position of the alphabet (since the elements in an array start at 0) ie the 7th position should be ascii value 71 which is G which is correct 
        }
    }
}
//The function is the first part of task 5, it takes the first word in an rotation encrypted cipher and prints all 26 possible decryptions for all 26 different key options
//The input for this function is only the encrypted word, no key is needed to be entered since we don't yet know the correct key for decryptions
//The return value is void since the function itself isn't returning a value
//The limitation for the length of the word entered is 99 characters
void wok(char*message, int key)
{
    
    int i;//Variables used inside the function definition are declared before being used
    int lk;
    char letter;
    int counter=1;//This variable is used to count the number of possible decyptions printed and exit the loop when all 26 different possiblities are printed
    
    while(counter<=26)//This while loop limits the number of possible solutions printed to only 26 since after this the same words would started being repeatedly printed
    {
        key = 1;//Initialise the key at 1 at the beginning, each iteration of the loop the message elements are moved one place down the alphabet
        for (i=0; message[i]!= '\0'; i++)//Alters each element of the message beginning with the message[0] element and ends once all elements are altered
        {
            letter= message[i];//Letter variable is assigned the value of the message string element
            
        
            if (letter >= 96 && letter <= 122)//If the element ascii value indicates it's a lowercase letter
            {
                letter = letter - 32;//Subtract 32 to make the element the uppercase variant of its letter
            }   
            
            lk= letter - key;//Initialise the variable lk to have the value of the string element minus the value of the key (which progressively substracts more each iteration)
   
            if (lk >= 65 && lk <= 90)//If the string element minus the key is an uppercase letter
            {    
                letter = lk;//The letter variable is assigned this value
            }
             else if (lk < 65)//If the substracted key moves the elements value off the top of the alphabet
            {
                letter = lk + 26;//26 is added to move that element back to the end of the alphabet
            }
            
            message[i]= letter;//The string element is assigned the new altered value of letter 
        }
        
        printf("%d: %s\n", counter, message);//Each altered word is then printed with its respective key next to it
        counter++;//Counter is incremented each loop to keep track of how many possible solutions that have been printed
    }
}
//This function is used in the second part of task 5, it is essentially the same as task 2 but uses different strings and variables since the usual variables are used in the first section of task 5
//Once the correct key is known, the entire message can be decrypted
//The input for this function is the entire cipher text to be decrypted and the correct key found in the first section of task 5 
//The return value is again void since the function itself is not returning any values but strings being used inside the functoin are storing decoded letters to be printed to the screen in main
//The limitations of the message entered to be decrypted is 99 characters since one is needed for the end of string symbol
void rotationDecryptwok(char*completeMessage, int keycorrect)
{
    int i;//Variables used in the function are declared in the function definition
    char letter;

    for(i = 0; completeMessage[i] != '\0'; ++i)//Loop is used to alter each element of the message individually and finish when the end of the message is reached
    {
		letter = completeMessage[i];//The letter variable is assigned the value of the element in the string completeMessage
		
		if(letter >= 97 && letter <= 122)//If the element is a lowercase letter
		{
			letter = letter - keycorrect;//The letter variable is assigned the value of what is originall was (the inital element value) minus the key found in the earlier function
			
			if(letter < 97)//If subtracting the key pushes the element off the front of the alphabet
			{
				letter = letter + 26;//26 is added to move that element to the end of the alphabet
			}
			
			completeMessage[i] = letter - 32;//The value assigned back to the array element is the value decoded in letter minus 32 to make the letter an uppercase letter
		}
		
		else if(letter >= 65 && letter <= 90)//If the array element is an uppercase letter
		{
			letter = letter - keycorrect;//The letter variable is again assigned the value of the inital element minus the key
			
			if(letter < 65)//If subtracting the key moves the element off the front of the alphabet
			{
			     letter = letter + 26;//The element is moved to the back of the alphabet by adding 26 to it
			}
			
			completeMessage[i] = letter;//The decoded letter is then assigned back to the array element to be printed to the user in main
		}
    }
}

