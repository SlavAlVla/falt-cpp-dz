// A little guessing game called
//    (for some obscure reason) <<Bulls and Cows>>.

#include <std_lib_facilities.h>
#include "./constants/constants.hpp"
#include "./game/game_mode.hpp"
#include "./game/game.hpp"

int main()
try
{
    std::cout << "<<Bulls and Cows>>\n"
              << "Computer sets a number of " << constants::NUM_SIZE << " unique digits.\n"
              << "Try to guess it.\n"
              << "<Bull> means right digit in the right position.\n"
              << "<Cow> means right digit in the wrong position.\n"
              << "\n";

    char game_mode = '0';
    while (true)
    {
        std::cout << "Choose game mode:\n"
                  << constants::EXIT_MODE << ": quit the game\n"
                  << constants::SINGLE_MODE << ": single game\n"
                  << constants::COMPUTER_MODE << ": game with computer\n"
                  << "> ";
        game_mode = get_game_mode();
        if (game_mode == constants::INVALID)
            continue;
        if (game_mode == constants::EXIT_MODE)
            break;
        std::cout << '\n';
        game(game_mode);
    }
}
catch (exception &e)
{
    cerr << e.what() << endl;
    return 1;
}
catch (...)
{
    cerr << "Oops, something went wrong..." << endl;
    return 2;
}
