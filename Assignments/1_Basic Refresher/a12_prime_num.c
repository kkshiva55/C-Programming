/*

Name: Shiva.K
Date: 12-07-2022
Description: Prime numbers using Sieve of Eratosthenes method

Sample output: --> Enter the value of 'n' : 12
                   The primes less than or equal to 12 are : 2, 3, 5, 7, 11

               --> Enter the value of 'n' : -2
                   Please enter a positive number which is > 1


*/



#include <stdio.h>

int main()
{

    int num, inc, root = 1, index = 2, list, mod, prime;        // Declaring variables

    printf("Enter the value of 'n' : ");      // Getting input from the user

    scanf("%d", &num);        // Storing the input value





      if (num > 1)            // True if user has entered valid number
      {

          int arr[num];        // Declaring array of size "num"


               while (inc != num - 1)         // Calculating square root
              {
                  root = (num / root + root) / 2;
                  inc++;

              }


               for (list = 0; list <= num - 2; list++)      // Storing numbers from 2 to "num" in an array
               {

                   arr[list] = index;
                   index++;

               }


               for (list = 1; list <= num; list++)      // Checking for prime one after the other
               {

                   for (mod = 2; mod <= root; mod++)    // Modulus is performed on all adjacent array elements
                   {

                      if ((arr[list] % mod == 0) && (arr[list] != mod))    // True if number is not prime and the number is not same as mod (Eg. 3 % 3 = 0, which is incorrect)
                      {

                          arr[list] = 0;         // Replacing by zero when the number is not a prime number

                      }

                   }

               }


           printf("The primes less than or equal to %d are : ", num);


          for (prime = 0; prime < num - 1; prime++)         // Listing all array elements after modulus operation
          {

              if (prime == 0)       // Printing the first element
              {

                  printf("%d", arr[prime]);

              }

              else if (arr[prime] != 0)       // Printing all the non-zero elements in the array
              {

                  printf(", %d", arr[prime]);

              }

           }

      }

    else        // Prompting error when user enters invalid number
    {

        printf("Please enter a positive number which is > 1");

    }

  return 0;

}
