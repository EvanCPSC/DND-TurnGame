#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#inlcude <Randhawa_Levi_FinalExam.cpp>

using namespace std;

class Moves
{
private:
    vector<PlayerChar*> players;
    PlayerChar* boss;
    string[] chosenMoves;
    void doAttack(string move);
    void doBlock(string move);
    void doBuff(string move);
    int turn = 0;
public:
    Moves(vector<PlayerChar*> p, PlayerChar* b);
    ~Moves();
    void doMove(string move);
};

Moves::Moves(vector<PlayerChar*> p, PlayerChar* b)
{
    players = p;
    boss = b;
    chosenMoves = new string[p.length()+1];
}

Moves::~Moves()
{
}

void Moves::doMove(string move) {
    string suffix = move.substr(move.length()-1);
    move = move.substr(0, move.length()-1);
    if (suffix == "!") {
        doAttack(move);
    } else if (suffix == ".") {
        doBlock(move);
    }else if (suffix == "~") {
        doBuff(move);
    }
}

void Moves::doAttack(string move) {
    if (move[0] == 'b') {
        turn = 0;
        return;
    }
    turn++;
}

void Moves::doBlock(string move) {
    if (move[0] == 'b') {
        turn = 0;
        return;
    }
    turn++;
}

void Moves::doBuff(string move) {
    if (move[0] == 'b') {
        turn = 0;
        return;
    }
    turn++;
}
