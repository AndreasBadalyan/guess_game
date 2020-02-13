/**
\file 
\brief Source file that contains program functions.
*/

#include <iostream>
#include <limits>


void display(const char *);
void single_guess_game();
char update_range(char, int *, int *);

/**
Asks user to have a number between 0 and 100 in mind. Calls single_guess_game function.
After each game asks if user wants to play again.
*/
int main()
{
    char input;

    display("Please have a number between 0 and 100 in your head.\n"
            "I will try to guess it.\nPress enter if you ready."
            "\nPress ctrl + c to exit.");    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    single_guess_game();

    while (!std::cin.eof()) {
        display("Want to play again?\nType 'y' if yes, anything else otherwise. ");
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (input != 'y' && input != 'Y') {
            break;
        }
        single_guess_game();
    }

    return 0;
}

/**
Displays given message to the screen.
\param message Text to be displayed.
*/
void display(const char *message)
{
    std::cout << message << std::endl;
}

/**
Plays a single game.
*/
void single_guess_game()
{
    int start = 0;
    int end = 100;
    int counter = 0;
    char input;

    while(!std::cin.eof() && input != 'e') {

        if (end - start < 0) {
            std::cout << "If your number is not " << (end + start) / 2 
                      << " then your answers were wrong.\n\n"; 
            break;
        }
        ++counter;
        std::cout << "Trial " << counter 
                  << "\nIs your number " << (end + start) / 2 << "?\n";

        input = update_range(input, &start, &end);
    }
}

/**
Asks user if the guessed number is higher or lower.
Changes the start and end of possible values range according to the answer.
\param input User answer.
\param start, end Range limits of possible values.
\return e to end game 0 to continue.
*/
char update_range(char input, int *start, int *end)
{
    while(!std::cin.eof()) {
        display("Enter: \nc - if correct" 
                "\nh - if my number is higher \nl - if my number lower\n\t");
        std::cin >> input;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (input) {
           
            case 'c': case 'C':
                display("The number is guessed, the game is over!");
                return 'e';

            case 'h': case 'H':
                *end = (*end + *start) / 2 - 1;
                return '0';

            case 'l': case 'L':
                *start = (*end + *start) / 2 + 1;
                return '0';
        }
    }
}
