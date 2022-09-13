#include <iostream>

class game
{
private:
    int score;
    const int betCash;
    static int turns;

public:
    // Constructors
    game(int betCash = 0, int score = 0) : betCash(betCash)
    {
        setScore1(score);
    }

    // setters
    void setScore1(int score) { this->score = score; }

    // getters
    int getScore1() { return score; }
    int getBetCash() { return betCash; }
    void getData()
    {
        std::cout << "The score = " << score << "\n";
        std::cout << "The betCash = " << betCash << "\n";
        std::cout << "The turns remaining = " << game::turns << "\n";
    }

    // Staticity
    static void setTurns(int turns)
    {
        game::turns = turns;
    }
    static void turnsRemaining()
    {
        game::turns--;
    }
    static int getTurns() { return game::turns; }

    // Destructor
    ~game()
    {
        std::cout << "Destructor has been called:\n";
    }
};
int game::turns=0;
int main()
{

    const int noOfplayers = 2;
    int betCashes[noOfplayers]{};
    static int i{0};
    for (auto &obj : betCashes)
    {
        std::cout << "Enter the amount that you want to bet :" << i+1 << "\n";
        std::cin >> obj;
        i++;
    }
    game *players = new game[2]{(game(betCashes[0])), (game(betCashes[1]))};
    game::setTurns((rand() % (betCashes[0] + betCashes[1] > 100 ? 20 : 10)) + 1);
    std::cout << "The total turns you both got = " << game::getTurns() << "\n";
    players[0].getScore1();
    players[1].getScore1();

    delete[] players;
    players = nullptr;

    return 0;
}