#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <conio.h>  // reads keyboard input

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;

const int x = 10;
const int y = 15;
char grid[x][y];
char displayGrid[x][y];

struct Move {
    string name;
    int powerPoints;
    int power;
    double accuracy;
    string type;
};

struct Pokemon {
    string name;
    int id;
    int pokedexNo;
    int health;    
    string type;
    vector<Move> moves;
};

// game's complete Pokedex
vector<Pokemon> pokedex = {
    {"Bulbasaur", 4, 1, 55, "grass" },
    {"Squirtle", 2, 2, 25, "water" },
    {"Pikachu", 4, 3, 40, "electric" },
};

// all known Pokemon moves
vector<Move> grassMoves = {
    {"Bullet Seed", 30, 25, 1.00, "grass"},
    {"Energy Ball", 10, 90, 1.00, "grass"},
    {"Frenzy Plant", 5, 150, 0.9, "grass"},
};
vector<Move> waterMoves = {
    {"Dive", 10, 80, 1.00, "water"},
    {"Clamp", 10, 35, 0.85, "water"},
    {"Brine", 10, 65, 1.00, "water"},
};
vector<Move> fireMoves = {
    {"Ember", 25, 40, 1.00, "fire"},
    {"Fire Punch", 15, 75, 1.00, "fire"},
    {"Fire Spin", 15, 35, 0.85, "fire"},
};
vector<Move> electricMoves = {
    {"Thunderbolt", 10, 110, 0.7, "electric"},
    {"Thunder Fang", 15, 65, 0.95, "electric"},
    {"Bolt Strike", 5, 130, 0.85, "electric"},
};

// grid-related functions
void initializeGrid();
void printGrid();
void placePokemon(int num);                         // place Pokemon on the grid
void listenKey(int& row, int& col);                 // waits for keyboard input

// battle-related functions
bool checkPosition(int row, int col);               // checks if special cell on grid -- contains wild pokemon?
Pokemon getPokemon();                               // spawns a randomly selected Pokemon from your Pokedex -- the wild Pokemon
vector<Move> determineMoves(vector<string> m);      // assigns moves to a wild Pokemon
bool pokemonBattle(Pokemon& p, Pokemon e);          // launches battles between two Pokemon
void displayMoves(Pokemon p);                       // displays your possible move choices
bool useMove(Pokemon& p, Pokemon& e, int m);        // uses a Pokemon move, checks if valid

// helper functions
void readPokedex();                                 // prints full Pokedex
void readPokemon(Pokemon p);                        // prints data about a given Pokemon

int pokemonMet = 0;     // how many Pokemon have you met?
int howMany = 5;        // how many Pokemon are on the grid?

int main() {
    // your starter Pokemon
    Pokemon yours;
    yours.name = "Snorlax";
    yours.id = 0;
    yours.pokedexNo = 0;
    yours.type = "Normal";
    yours.moves = determineMoves({"electric", "fire", "water", "grass"});
    yours.health = 50;
    
    // initializing the grid
    srand(time(0));
    initializeGrid();
    placePokemon(howMany);
    
    // the player's location
    int row = x - 1;
    int col = 0;
    displayGrid[row][col] = 'O';
    
    bool lost = false;
    
    cout << "-------------------- POKEMON CPP -----------------------" << endl;
    cout << "Welcome to the world of Pokemon! I am Pokemon Professor Cpp! " << endl;
    cout << "Your goal is to meet all " << howMany << " pokemon on this field. Ready?" << endl;
    cout << "--------------------------------- -----------------------" << endl;
    cout << "(Press any key to continue)" << endl;

    while (pokemonMet < howMany) { // while the player hasn't seen 'em all...
        listenKey(row, col);
        if (checkPosition(row, col)) { // is there a wild pokemon here? 
            if (pokemonBattle(yours, getPokemon())) { // did you win the battle?
                cout << "The wild pokemon fainted! Press any key to continue." << endl;
            } else {
                lost = true;
                break; // exit while loop
            }
        } else {
            displayGrid[row][col] = 'O'; // reset the player's location
            printGrid(); // re-print the grid
        }
    }

    if (lost) {
        cout << "Oh no! Your Pokemon fainted. Rushing to the nearest Pokemon center... " << endl;
    } else if (pokemonMet >= howMany) {
        cout << "You've beaten all the Pokemon! Congratulations, you have completed Pokemon CPP!" << endl;
    }

    return 0;
}

void listenKey(int& row, int& col){
    int c = 0;
    displayGrid[row][col] = '.';
    switch((c = getch())) {
        case KEY_UP:
            if (row - 1 < x && row - 1 >= 0) {
                row--;
            }
            break;
        case KEY_DOWN:
            if (row + 1 < x && row + 1 >= 0) {
                row++;
            }
            break;
        case KEY_LEFT:
            if (col - 1 < y && col - 1 >= 0) {
                col--;
            }
            break;
        case KEY_RIGHT:
            if (col + 1 < y && col + 1 >= 0) {
                col++;
            }
            break;
    }
}

bool pokemonBattle(Pokemon& p, Pokemon e) {
    cout << "A wild " << e.name << " appeared!" << endl;
    cout << "What will " << p.name << " do?" << endl;
    while (e.health > 0 && p.health > 0){ 
        displayMoves(p);
        readPokemon(p);
        readPokemon(e);
        int moveSelection;
        cin >> moveSelection;
        while (!useMove(p, e, moveSelection - 1)){
            cout << "Invalid move. Try again: " << endl;
            cin.clear();
            cin >> moveSelection;
        }
        if (e.health > 0) {
            int randEnemyMove = rand() % e.moves.size();
            while(e.moves.at(randEnemyMove).powerPoints <= 0){
                randEnemyMove = rand() % e.moves.size();
                cout << "Recalculating" << endl;
            }
            useMove(e, p, randEnemyMove);
            cout << e.name << " used " << e.moves.at(randEnemyMove).name << "!" << endl;
        }
    }
    if (p.health > 0) {
        pokemonMet++;
        return true;
    } return false;
}

bool useMove(Pokemon& p, Pokemon& e, int m){
    if (m < 4 && p.moves.at(m).powerPoints > 0) {
        p.moves.at(m).powerPoints--;
        e.health -= p.moves.at(m).power;
        return true;
    }
    return false;
}

bool checkPosition(int row, int col) {
    if (displayGrid[row][col] == 'X') {
        cout << "Pokemon Battle!" << endl;
        displayGrid[row][col] == '.';
        return true;
    } else {
        return false;
    }
}

void initializeGrid() {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            displayGrid[i][j] = '.';
        }
    }
}

void printGrid() {
    cout << endl;
    cout << "-----------------------------" << endl;
    cout << "CPP TOWN      Battles: " << pokemonMet << " / " << howMany << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << displayGrid[i][j] << " ";
        }
        cout << endl;
    }
}

void readPokemon(Pokemon p) {
    cout << "Name: " << p.name << "\t";
    cout << "Pokedex No.: " << p.pokedexNo << "\t";
    cout << "Type: " << p.type << "\t";
    cout << "HP: " << p.health << "\t"; cout << endl;
}

void readPokedex() {
    for (int i = 0; i < pokedex.size(); i++) {
        readPokemon(pokedex.at(i));
    }
}

Pokemon getPokemon() {
    int randomPokedexNo = rand() % pokedex.size();
    Pokemon p;
    p.name = pokedex.at(randomPokedexNo).name;
    p.id = pokedex.at(randomPokedexNo).id;
    p.pokedexNo = pokedex.at(randomPokedexNo).pokedexNo;
    p.type = pokedex.at(randomPokedexNo).type;
    p.health = pokedex.at(randomPokedexNo).health;
    p.moves = determineMoves({p.type, p.type, "water", "fire"});
    return p;
}

void placePokemon(int num) {
    for (int i = 0; i < num; i++){
        int xPos = rand() % x;
        int yPos = rand() % y;
        displayGrid[xPos][yPos] = 'X';
    }
}

void displayMoves(Pokemon p) {
    for (int i = 0; i < p.moves.size(); i++){
        cout << (i + 1) << ". " << p.moves.at(i).name << " (" << p.moves.at(i).powerPoints << " left; " << p.moves.at(i).power << " HP)" << endl;
    }
}

vector<Move> determineMoves(vector<string> m) {
    vector<Move> moves;
    for (int i = 0; i < m.size(); i++) {
        if (m.at(i) == "electric") {
            moves.push_back(electricMoves.at(rand() % electricMoves.size()));
        } else if (m.at(i) == "fire") {
            moves.push_back(fireMoves.at(rand() % fireMoves.size()));
        } else if (m.at(i) == "water") {
            moves.push_back(waterMoves.at(rand() % waterMoves.size()));
        } else if (m.at(i) == "grass") {
            moves.push_back(grassMoves.at(rand() % grassMoves.size()));
        }
    }
    return moves;
}