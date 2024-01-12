#include <iostream>
#include <string.h>

using namespace std;

// Base class called Credit with private members card number along with it's first 2 and 4 digits
class Credit
{
public:
    // Method to set card number given by the user
    void getCard(string num)
    {
        card_num = num;
        cout << "Entered card number: " << card_num << endl;
    }

    // Function that tests Luhn's algorithm for the given card, returns 1 if it satisfied
    int isLuhn()
    {
        int len = card_num.length();

        int sum = 0;
        bool second = false;

        // Iterating over all the digits since length of the card could be odd or even
        for (int i = len - 1; i >= 0; i--)
        {
            int second_num = card_num[i] - '0';

            if (second == true)
                second_num = second_num * 2;

            sum += second_num / 10;
            sum += second_num % 10;

            second = !second;
        }
        return (sum % 10 == 0);
    }

protected:
    // Class members
    string card_num;
    string first2 = card_num.substr(0, 2);
    string first4 = card_num.substr(0, 4);
};

// Class for Visa cards, inherits from Credit
class Visa : public Credit
{
public:
    // Method that checks validity for a Visa card
    void testVisa()
    {
        // Checking for the length of the card number
        if (card_num.length() == 16 || card_num.length() == 13)
        {
            // Applying Luhn's algorithm
            if (isLuhn())
            {
                cout << "\nEntered card Number satisfies Lunh's algorithm\n\n";

                string first4 = card_num.substr(0, 4);

                // Checking for the first digit which has to be 4 for a Visa card
                if (card_num[0] == '4')
                {
                    cout << "This is a valid Visa card number" << endl
                         << endl;
                }

                else
                // Since given card number follows Luhn's algorithm, chances are the user chose a wrong provider
                {
                    cout << "Possibly wrong card provider chosen" << endl
                         << endl;
                }
            }
            else
                cout << "Invalid number" << endl;
        }
        else
            cout << "Invalid Visa number" << endl;
    }
};

// Class for MasterCard cards, inherits from Credit
class MasterCard : public Credit
{
public:
    // Method to check for validity of given MasterCard
    void testMasterCard()
    {
        // Checking length of card number
        if (card_num.length() == 16)
        {
            // Applying Luhn's algorithm
            if (isLuhn())
            {
                cout << "\nEntered card number satisfies Luhn's algorithm\n\n";

                // Checking for first to digits, which for a MasterCard must be from 51 to 55
                if (first2.compare("51") == 0 || first2.compare("52") == 0 || first2.compare("53") == 0 || first2.compare("54") == 0 || first2.compare("55"))
                {
                    cout << "This is a valid Master Card card number" << endl
                         << endl;
                }

                else
                {
                    cout << "Possibly wrong card provider chosen" << endl
                         << endl;
                }
            }
            else
                cout << "Invalid number";
        }
        else
            cout << "Invalid MasterCard number";
    }
};

// Class called Rupay, inherits from Credit
class Rupay : public Credit
{
public:
    // Method to check for validity of a Rupay card
    void testRupay()
    {
        if (card_num.length() == 16)
        {
            // Applying Luhn's algorithm
            if (isLuhn())
            {
                cout << "\nEntered card number satisfies the Luhn's algorithm\n\n";
                if (first2.compare("60") == 0 || first4.compare("6521") == 0 || first4.compare("6522") == 0)
                {
                    cout << "This is a valid Rupay card number" << endl;
                }

                else
                {
                    cout << "Possibly wrong card provider chosen" << endl;
                }
            }
            else
                cout << "Invalid number" << endl;
        }
        else
            cout << "Invalid Rupay number" << endl;
    }
};

// Class called Amex, inherits from Credit
class Amex : public Credit
{
public:
    // Method to check for validity for an Amex card
    void testAmex()
    {
        if (card_num.length() == 15)
        {
            // Applying Luhn's algorithm
            if (isLuhn())
            {
                cout << "\nEntered card number satisfies Luhn's algorithm\n\n";
                if (first2.compare("34") == 0 || first2.compare("37") == 0)
                {
                    cout << "This is a valid Amex card number" << endl
                         << endl;
                }
                else
                    cout << "Possibly wrong card provider chosen" << endl;
            }
            else
                cout << "Invalid number";
        }
        else
            cout << "Invalid Amex number" << endl;
    }
};

int main()
{
    int choice;
    string cardno; // Will be used for sending argument to the getCard() function of base class

    // Initializing infinite loop
    while (1)
    {
        // Prompting users to enter the card type and initializing respective classes
        cout << "1-Visa, 2-MasterCard, 3-Rupay, 4-Amex, 5-Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Visa visa;
            cout << "Enter the Visa card number: ";
            cin >> cardno;

            visa.getCard(cardno);
            visa.testVisa();
        }

        else if (choice == 2)
        {
            MasterCard mc;
            cout << "Enter the Master Card number: ";
            cin >> cardno;

            mc.getCard(cardno);
            mc.testMasterCard();
        }

        else if (choice == 3)
        {
            Rupay rupay;
            cout << "Enter the Rupay Card number: ";
            cin >> cardno;

            rupay.getCard(cardno);
            rupay.testRupay();
        }

        else if (choice == 4)
        {
            Amex amex;
            cout << "Enter the Amex number: ";
            cin >> cardno;

            amex.getCard(cardno);
            amex.testAmex();
        }

        // Exiting code for choice 5
        else if (choice == 5)
        {
            cout << "Thank you!" << endl;
            exit(0);
        }

        // Reprompting user for valid choice
        else
            cout << "Invalid choice\n";
    }
}