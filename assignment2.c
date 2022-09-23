/******************************************************************************
Conor McFadyen - C20520596

Programming Assignment 2

C program that encrypt and decrypt a four diget access code. Compare an entered Code
to the default code. Can also display how many times an enter code mached the default Code

Compliled using MinGW

Last Modified: 07/03/21
*******************************************************************************/
#include <stdio.h>

//Array size symbolic name
#define SIZE 4

//Defining global variables
int access_code[SIZE] = {4, 5, 2, 3};
static int successfull_count = 0;
static int unsuccessfull_count = 0;


//funtion signitures
void entercode(int []);
void end_program(int *);
void encrypt(int []);
void decrypt(int []);
void display_couter(void);

void main()
{

  int i;
  //used to end the do while loop
  int terminator = 0;
  //used to select menu options
  int option_input =  0;
  //Array for entered Code
  int user_code[SIZE];
  //To track if access code has been encrypted
  int encrypted = 0;

  do
  {

    //prints inital menu and takes input from user
    printf ("1. Enter any 4 diget code\n2. Encrypt code entered and verify it matches authorised access code\n");
    printf("3. Decrypt inputted code\n4. Display number of times code has been entered i) Successfully ii) Unsuccessfully\n5. End Program\n");

    scanf("%d", &option_input);
    printf("\n");

    switch(option_input)
    {

      case 1:
      {
        //Enter any code
        entercode(user_code);

        //allows new code to be encrypted and not decrypted
        encrypted = 0;

        break;
      }

      case 2:
      {
        //if to check the code is not already encrypted
        if(encrypted == 0)
        {
          encrypt(user_code);
          encrypted = 1;
        }
        else
        {
        printf("Error , code entered is already encrypted\n\n");

        } //end if

        break;
      }

      case 3:
      {
        //if to check the code is not already decrypted
        if(encrypted == 1)
        {
          decrypt(user_code);
          encrypted = 0;
        }
        else
        {
          printf("Error , code entered is already decrypted\n\n");
        } // end if

        break;
      }

      case 4:
      {
        //Dispay counters of number of times code was entered Successfully/Unsuccessfully
        display_couter();

        break;
      }

      case 5:
      {
        end_program(&terminator);

        break;
      }

      default:
      {
        printf("Option entered is invalid\n\n");
      }

    } // end switch


  } // end do

  //end program
  while(terminator == 0) ;


}


void entercode(int user_code[])
{
  int i;
  int entered_number;

  //for loop checks diget entered is valid and then enters it into the arrry
  for(i = 0 ; i < SIZE ; i ++)
  {

    printf("Enter a diget of your access code\n");
    scanf("%d", &entered_number);

    if(entered_number > 9 || entered_number < 0)
    {
      printf("Error , diget entered is invalid, enter number between 0 - 9\n");
      i = i - 1;
    }
    else
    {
      *(user_code + i) = entered_number;
    } // end if

  } // end for

} // end entercode


void encrypt(int user_code[])
{
  int i;
  int temp = 0;
  int codes_match = 0;

  //Makes sure values in code do not exceed 9
  for(i = 0 ; i < SIZE ; i ++)
  {
    if( *(user_code + i) == 9 )
    {
      *(user_code + i) = -1;
    }
  } // end for

  //add one to each element
  for(i = 0 ; i < SIZE ; i ++)
  {
    *(user_code + i) = *(user_code + i) + 1;
  } // end for

  //swap 1st and 3rd numbers
  temp = *(user_code + 2);
  *(user_code + 2) = *user_code;
  *user_code = temp;

  //swap 2nd and 4th numbers
  temp = *(user_code + 1);
  *(user_code + 1) = *(user_code + 3);
  *(user_code + 3) = temp;

  //Lets user know their code has been encrypted
  printf("Entered code is now encrypted\n");

  //Compare encrypted access code to user entered Code
  codes_match = 1;

  for(i = 0 ; i < SIZE ; i ++)
  {
    if( *(user_code + i) == *(access_code + i) )
    {

    }
    else
    {
      codes_match = 0;
    } // end if

  } // end for

  //Tell user if code is correct and add to the count of Successfull/Unsuccessfull matches
  if(codes_match == 1)
  {
    printf("Correct code entered\n\n");

    successfull_count = successfull_count + 1;
  }
  else
  {
    printf("Wrong code entered\n\n");

    unsuccessfull_count = unsuccessfull_count + 1;
  } // end if


} // end encrypt

void decrypt(int user_code[])
{
  int i;
  int temp = 0;


  //Makes sure values in code do not exceed 0
  for(i = 0 ; i < SIZE ; i ++)
  {
    if( *(user_code + i) = 0 );
    {
      *(user_code + i) = 10;
    }
  } // end for

  //add one to each element
  for(i = 0 ; i < SIZE ; i ++)
  {
    *(user_code + i) = *(user_code + i) - 1;
  } // end for

  //swap 1st and 3rd numbers
  temp = *(user_code + 2);
  *(user_code + 2) = *user_code;
  *user_code = temp;

  //swap 2nd and 4th numbers
  temp = *(user_code + 1);
  *(user_code + 1) = *(user_code + 3);
  *(user_code + 3) = temp;

  //Lets user know code was Successfully decrypted
  printf("Code Successfully Decrypted\n\n");

} // end decrypt

void display_couter(void)
{
  printf("Times your encrypted access code has matched %d Successfull and %d Unsuccessfull\n\n", successfull_count , unsuccessfull_count);
} // end display counter

void end_program(int *end)
{
  *end = 1;

} // end end_program
