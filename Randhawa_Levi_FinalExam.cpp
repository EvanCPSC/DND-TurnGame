#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
using namespace std;




struct Loot {
    string name;
    int value;

    Loot(string arg1 = " ", int arg2 = 0) {
        name = arg1;
        value = arg2;
    }

    virtual void display() {
        cout << "Name: " << name << "   Val: " << value << " Gold" << endl;
    }
};
// Need to fix the display cout to look better
struct Weapon : Loot {
    int damageLow;
    int damageHigh;
    string bonusProperties;

    Weapon(string argN, int argV, int damL, int damH, string bonusP) : Loot(argN, argV) {
        damageLow = damL;
        damageHigh = damH;
        bonusProperties = bonusP;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Min Damage: " << damageLow << "   Max Damage: " << damageHigh << "   Properties: " << bonusProperties << endl;
    }
};

struct HeadWear : Loot {
    string headWearDescription;

    HeadWear(string argN, int argV, string argG) : Loot(argN, argV) {
        headWearDescription = argG;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Properties: " << headWearDescription << endl;
    }
};

struct Armor : Loot {
    string armorDescription;

    Armor(string argN, int argV, string argG) : Loot(argN, argV) {
        armorDescription = argG;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Properties: " << armorDescription << endl;
    }
};

struct HandWear : Loot {
    string handWearDescription;

    HandWear(string argN, int argV, string argG) : Loot(argN, argV) {
        handWearDescription = argG;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Properties: " << handWearDescription << endl;
    }
};

struct Boots : Loot {
    string bootsDescription;

    Boots(string argN, int argV, string argG) : Loot(argN, argV) {
        bootsDescription = argG;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Properties: " << bootsDescription << endl;
    }
};

struct MagicRing : Loot {
    string ringDescription;

    MagicRing(string argN, int argV, string argG) : Loot(argN, argV) {
        ringDescription = argG;
    }
    virtual void display() {
        cout << " Name: " << name << "   Val: " << value << " Gold" << endl;
        cout << " Properties: " << ringDescription << endl;
    }
};


struct PlayerChar {
    string name = " ";
    int level = 1;
    string job = " ";
    string charTraits; // is this needed for constructor?
    list<Loot*> gear;
    int health = 1;
    int damage = 0;

    int strength = 0;
    int dexterity = 0;
    int constitution = 0;
    int intelligence = 0;
    int wisdom = 0;
    int charisma = 0;


    PlayerChar(string argName, int argLevel, string argJob, list<Loot*> argGear) {
        name = argName;
        level = argLevel;
        job = argJob;
        gear = argGear;
    }

    void printCharInfo(void) {
        cout << "\n " << name << "'s Info:" << endl;
        cout << "*****************************************" << endl;
        cout << " Job: " << job << "\tLevel: " << level << "\tTraits: " << charTraits << endl;
        cout << "----------------------------------------" << endl;
        cout << "\n\t       Gear List" << endl;
        cout << "----------------------------------------" << endl;
        if (!gear.empty()) {
            while (!gear.empty()) {
                gear.front()->display();
                gear.pop_front();
                cout << "----------------------------------------" << endl;
            }
        }
        else {
            cout << " There's nothing HERE" << endl;
            cout << "----------------------------------------" << endl;
        }
        cout << "\t\t Stats" << endl;
        cout << "----------------------------------------" << endl;
        cout << " Health: " << health << endl << endl;;
        cout << " Str: " << strength << endl;
        cout << " Dex: " << dexterity << endl;
        cout << " Con: " << constitution << endl;
        cout << " Int: " << intelligence << endl;
        cout << " Wis: " << wisdom << endl;
        cout << " Cha: " << charisma << endl;
        cout << endl << endl;
    }
    vector<string> getMoveset() {
        vector<string> moveset;
        if (job == "Fighter") {
            moveset.push_back("Big Punch!");
            moveset.push_back("Guard.");
            moveset.push_back("Beserk~"); //Fighter dmg up by 1d6 + str
        } else if (job == "Mage") {
            moveset.push_back("Fireball!");
            moveset.push_back("Force Field.");
            moveset.push_back("Cast Fear~"); //Boss dmg down by 1d6
        } else if (job == "Cleric") {
            moveset.push_back("Smite!");
            moveset.push_back("Faithful Shield.");
            moveset.push_back("Heal~"); //Heal everyone by 1d6 + con
        } else if (job == "Thief") {
            moveset.push_back("Sneaky Stab!");
            moveset.push_back("Stealth.");
            moveset.push_back("~"); //
        } else {
            moveset.push_back("Attack!");
            moveset.push_back("Block."); //2/3 of dmg
            moveset.push_back("DmgD~"); //Dmg down to party 
            moveset.push_back("DmgU~"); //Dmg up to boss
        }
        return moveset;

    }

};



// comparators
bool compareLootByName(Loot* arg1, Loot* arg2) {
    bool answer = (arg1->name < arg2->name);
    return answer;
}

bool compareLootByValue(Loot* arg1, Loot* arg2) {
    bool answer = (arg1->value > arg2->value);
    return answer;
}

// character stat generator functions

int rollDie(void) {
    return 1 + rand() % 6;
}

int generateStat(void) {
    return rollDie() + rollDie() + rollDie();
}

int jobSort(string job) {  // this returns the ASCII value of a character minus 97
    if (job == "Fighter")
        return 0;
    else if (job == "Mage")
        return 1;
    else if (job == "Cleric")
        return 2;
    else // Thief
        return 3;
}

bool compareLevel(PlayerChar* arg1, PlayerChar* arg2) {
    bool answer = (arg1->level < arg2->level);
    return answer;
}



Loot* randomLoot(list<PlayerChar*>::iterator charItr, int argRand) {
    if (argRand == 1) { // Weapons
        if ((*charItr)->job == "Fighter")
            return (new Weapon("Sword of Sharpness", 100, 10, 30, "Sharp"));
        else if ((*charItr)->job == "Mage")
            return (new Weapon("Staff of Destruction", 100, 10, 30, "Blunt"));
        else if ((*charItr)->job == "Cleric")
            return (new Weapon("Club of Destruction", 100, 10, 30, "Blunt"));
        else
            return (new Weapon("Dagger of Sharpness", 100, 10, 30, "Sharp"));
    }
    if (argRand == 2) { // Helm
        if ((*charItr)->job == "Fighter")
            return (new HeadWear("Helmet of Hardness", 100, "Hard"));
        else if ((*charItr)->job == "Mage")
            return (new HeadWear("Circlet of Hardness", 100, "Hard"));
        else if ((*charItr)->job == "Cleric")
            return (new HeadWear("Helm of Hardness", 100, "Hard"));
        else
            return (new HeadWear("Cowl of Hardness", 100, "Hard"));
    }
    if (argRand == 3) { // Armor
        if ((*charItr)->job == "Fighter")
            return (new Armor("Armor of Toughness", 100, "Tough"));
        else if ((*charItr)->job == "Mage")
            return (new Armor("Robe of Toughness", 100, "Tough"));
        else if ((*charItr)->job == "Cleric")
            return (new Armor("Armor of Toughness", 100, "Tough"));
        else
            return (new Armor("Cloak of Toughness", 100, "Tough"));
    }
    if (argRand == 4) { // HandWear
        if ((*charItr)->job == "Fighter")
            return (new HandWear("Gauntlets of Strength", 100, "Increase Strength"));
        else if ((*charItr)->job == "Mage")
            return (new HandWear("Gloves of Mana Regen", 100, "Mana Regen"));
        else if ((*charItr)->job == "Cleric")
            return (new HandWear("Bracers of Toughness", 100, "Tough"));
        else
            return (new HandWear("Gloves of Nimbleness", 100, "Nimble"));
    }
    if (argRand == 5) { // Boots
        if ((*charItr)->job == "Fighter")
            return (new Boots("Boots of Swiftness", 100, "Swift"));
        else if ((*charItr)->job == "Mage")
            return (new Boots("Boots of Swiftness", 100, "Swift"));
        else if ((*charItr)->job == "Cleric")
            return (new Boots("Boots of Swiftness", 100, "Swift"));
        else
            return (new Boots("Boots of Swiftness", 100, "Swift"));
    }
    if (argRand == 6) { // MagicRing
        if ((*charItr)->job == "Fighter")
            return (new MagicRing("Ring of Endurance", 100, "Increases Constitution"));
        else if ((*charItr)->job == "Mage")
            return (new MagicRing("Band of Intelligance", 100, "Increases Intelligence"));
        else if ((*charItr)->job == "Cleric")
            return (new MagicRing("Band of Wisdom", 100, "Increases Wisdom"));
        else
            return (new MagicRing("Ring of Dexterity", 100, "Increases Dexterity"));
    }
}

void doMove(string move) {
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



int main(void) {
    srand(time(0));

    list<Loot*> loot;

    list<PlayerChar*> myCharList;
    list<PlayerChar*>::iterator listItr;

    list<PlayerChar*> myJobHash[4];
    list<PlayerChar*>::iterator hashItr;


    // need to think about if random level is nessessary
    myCharList.push_back(new PlayerChar("Tibalt Velo", 1 + rand() % 20, "Fighter", loot));
    myCharList.push_back(new PlayerChar("Ohr Sormuzhik", 1 + rand() % 20, "Fighter", loot));
    myCharList.push_back(new PlayerChar("Levi", 1 + rand() % 20, "Fighter", loot));
    myCharList.push_back(new PlayerChar("Kezda Goldenfield", 1 + rand() % 20, "Mage", loot));
    myCharList.push_back(new PlayerChar("Aetcius Kroft", 1 + rand() % 20, "Mage", loot));
    myCharList.push_back(new PlayerChar("Levi", 1 + rand() % 20, "Mage", loot));
    myCharList.push_back(new PlayerChar("Kasma Walnir", 1 + rand() % 20, "Cleric", loot));
    myCharList.push_back(new PlayerChar("Lumisashi Lualrur", 1 + rand() % 20, "Cleric", loot));
    myCharList.push_back(new PlayerChar("Levi", 1 + rand() % 20, "Cleric", loot));
    myCharList.push_back(new PlayerChar("Talindra Deryth", 1 + rand() % 20, "Thief", loot));
    myCharList.push_back(new PlayerChar("Tibalt Velo", 1 + rand() % 20, "Thief", loot));
    myCharList.push_back(new PlayerChar("Levi", 1 + rand() % 20, "Thief", loot));

    for (listItr = myCharList.begin(); listItr != myCharList.end(); listItr++) {
        (*listItr)->strength = generateStat();
        (*listItr)->dexterity = generateStat();
        (*listItr)->constitution = generateStat();
        (*listItr)->intelligence = generateStat();
        (*listItr)->wisdom = generateStat();
        (*listItr)->charisma = generateStat();
        // They get random loot
        (*listItr)->gear.push_back(randomLoot(listItr, 1 + rand() % 6));
        (*listItr)->gear.push_back(randomLoot(listItr, 1 + rand() % 6));
        (*listItr)->gear.push_back(randomLoot(listItr, 1 + rand() % 6));
        // they get trait
        if ((*listItr)->job == "Fighter")
            (*listItr)->charTraits = "Strong";
        else if ((*listItr)->job == "Mage")
            (*listItr)->charTraits = "Intelligent";
        else if ((*listItr)->job == "Cleric")
            (*listItr)->charTraits = "Charismatic";
        else // Thief
            (*listItr)->charTraits = "Stealthy";
    }

    while(!myCharList.empty()) { 
        myJobHash[jobSort(myCharList.front()->job)].push_back(myCharList.front());
        myCharList.pop_front();
    }
    
    for (int i = 0; i < 4; i++) {
        if (!myJobHash[i].empty()) {
            cout << "\n\n\tList of " << myJobHash[i].front()->job << endl;
            cout << "----------------------------------" << endl << endl;
            myJobHash[i].sort(compareLevel);
            while (!myJobHash[i].empty()) {
                myJobHash[i].front()->printCharInfo();
                myJobHash[i].pop_front();
            }
            cout << endl << endl;
        }
    }




    



    cout << endl << endl << endl << endl;
    cout << "Now in this portion, This will my attempt on a turn-based games" << endl;


    int userInput;
    PlayerChar* Boss;
    vector<PlayerChar*> myBossVec;
    myBossVec.push_back(new PlayerChar("Dragon", 20, "Boss", loot));
    myBossVec.push_back(new PlayerChar("Jefe, Destroyer of Worlds", 20, "Boss", loot)); // thought about putting Eater of Worlds
    myBossVec.push_back(new PlayerChar("PadaJuan", 20, "Boss", loot));
    


    /*do {*/

    cout << "Here is the list of Bosses to choose from. To pick one, simply type the number of their Index" << endl << endl;

    for (int i = 0; i < myBossVec.size(); i++) {
            cout << "\t Index " << i + 1 << ": " << myBossVec[i]->name << endl;
    }

    cout << "\nWhich one will you choose: ";
    cin >> userInput;

    while (userInput < 1 || userInput > 3) {
            cout << "\n\nThis number is not from the given index: 1, 2, 3" << endl;
            cout << "Please try again: ";
            cin >> userInput;
    }

    Boss = myBossVec[userInput - 1];


    // The user's ragtag boss team
    myCharList.push_back(new PlayerChar("Jackie Chan", 20, "Fighter", loot));
    myCharList.push_back(new PlayerChar("Gandalf",  20, "Mage", loot));
    myCharList.push_back(new PlayerChar("Follower of Shrek",  20, "Cleric", loot)); // cause ig Shrek is God
    myCharList.push_back(new PlayerChar("Jack Sparrow",  20, "Thief", loot));


    cout << "\n\n\n\t   Your Party"<< endl;
    cout << "----------------------------------" << endl << endl;
    for (listItr = myCharList.begin(); listItr != myCharList.end(); listItr++) {
        (*listItr)->strength = generateStat();
        (*listItr)->dexterity = generateStat();
        (*listItr)->constitution = generateStat();
        (*listItr)->intelligence = generateStat();
        (*listItr)->wisdom = generateStat();
        (*listItr)->charisma = generateStat();
        (*listItr)->health = 7 * (*listItr)->level + 3 + (((*listItr)->constitution - 10) / 2);
        // This will be for when they are hitting the boss for their turn
        //if ((*listItr)->job == "Fighter") {
        //    (*listItr)->damage = 10 + rollDie() + (((*listItr)->strength - 10) % 2);
        //}
        //else if ((*listItr)->job == "Mage") {
        //    (*listItr)->damage = 10 + rollDie() + (((*listItr)->intelligence - 10) % 2);
        //}
        //else if ((*listItr)->job == "Cleric") {
        //    (*listItr)->damage = 10 + rollDie() + (((*listItr)->charisma - 10) % 2);
        //}
        //else { // Thief
        //    (*listItr)->damage = 10 + rollDie() + (((*listItr)->dexterity - 10) % 2);
        //}
        (*listItr)->printCharInfo();
    }

    string[] chosenMoves = new string[5];
    do {
        int turn = 0;
        //players
        for (listItr = myCharList.begin(); listItr != myCharList.end(); listItr++) {
            vector<string> moves = (*listItr)->getMoveset();
            cout << "Choose move for " << (*listItr)->name << " (1-3):\n";
            for (int i = 0; i < 3; i++) {
                cout << moves[i] << "\t";
            }
            cout << endl;
            int choice = 0;
            do {
                cin >> choice;
                if (choice > 0 && choice < 4) {
                    cout << "Enter a number 1-3:\n";
                }
            } while (choice <= 0 && choice >= 4)
            chosenMoves[turn] = moves;
            turn++;
        }
        //boss stuff
        int bossIndex = rand() % 4;
        string bossMove = Boss->getMoveset()[bossIndex];
        chosenMoves[4] = bossMove;
        doMove(bossMove);











    } while (Boss->health <= 0 || myCharList.empty());

    if (Boss->health <= 0)
        cout << "\n\n\t The Boss is Defeated, You Win" << endl;
    else // User loses
        cout << "\n\n\t Womp Womp, You Lose" << endl;
























    /*} while (userResp = do it again)*/
    





    return 0;
}
