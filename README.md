# Cpp-Mini-Project
This is a simple project made to showcase object oriented programming in C++

## Luhn's algorithm
Luhn's algorithm, also known as the mod-10 algorithm, is used to validate credit card numbers. Starting from the rightmost digit, double every second digit. If the result is a two-digit number, sum its digits. Add all the obtained and unaffected digits. The credit card number is valid if the sum is a multiple of 10. This algorithm detects accidental errors in the digits of a credit card number, providing a simple and efficient way to verify its authenticity during transactions.

## Requirements
The project works with any C++ compiler and all interactions are done through the command prompt itself.

## Working
The program dispays 5 options to choose - 1-Visa, 2-MasterCard, 3-Rupay, 4-Amex, 5-Exit. Pressing 5 terminates the program. Upon pressing any one of the first 4 options, we will be required to enter the credit card number. 

The number is then subject to the Luhn's algorithm, along with the cards' manufacturer specific constraints. The validity of the card number is thus found. 


