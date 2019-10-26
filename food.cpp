#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Food {
    string name;
    double price;
    double rating;
    string origin;
    string description;
};

vector<Food> foods = {
    {"Pasta salad", 6.99, 4.3, "Italy", "Organic wheat pasta with creamy alfredo sauce"},
    {"Pizza pie", 4.99, 4.6, "Italy", "Non-GMO cheese sprinkled around toasted pita bread"},
    {"Cheeseburger", 4.75, 3.5, "USA", "The classic American chicken burger with Smashburger's secret sauce"},
    {"Butter popcorn", 1.99, 3.5, "USA", "The classic American movie-time snack"},
    {"Masala dosa", 2.99, 4.5, "India", "A crispy, rice-batter crepe encases a spicy mix of mashed potato"},
    {"Potato chips", 0.99, 3.5, "UK", "One of the world's most child-friendly and best foods"},
    {"Seafood paella", 6.99, 4.8, "Spain", "Shrimp, lobster, mussels and cuttlefish combine with white rice and various herbs, oil and salt in this Valencian dish"},
    {"Chicken rice", 3.99, 3.75, "Singapore", "Steamed or boiled chicken is served atop fragrant oily rice, with sliced cucumber as the token vegetable"},
    {"Marzipan", 2.55, 3.75, "Germany", "Ground almonds coated with sugar"},
    {"Chicken parm", 6.75, 4.75, "Australia", "Melted Parmesan and mozzarella cheese, and a peppery, garlicky tomato sauce drizzled over the top of a chicken fillet"},
    {"Ankimo fish", 7.75, 4.95, "Japan", "Chunk of monkfish liver with a little grated daikon on the side"},
    {"Goi cuon", 0.75, 4.95, "Vietnam", "This snack made from pork, shrimp, herbs, rice vermicelli and other ingredients wrapped in rice paper is served at room temperature"},
};

void printFood(Food f);
void printStars(int num);
void printAllFood();
void showMenu();

void createFood();
void readFood();
void updateFood();
void deleteFood();

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    int choice;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "           GLOBAL FOODS DATABASE               " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "1. Create and add a new food." << endl;
    cout << "2. Read information about a food." << endl;
    cout << "3. Update an existing food." << endl;
    cout << "4. Delete an existing food from history." << endl;
    cout << "5. Show all foods." << endl;
    cout << "6. Exit database." << endl;

    cin >> choice;
    cin.clear();

    bool cont = true;
    switch(choice) {
        case 1:
            createFood();
            break;
        case 2: 
            readFood();
            break;
        case 3: 
            updateFood();
            break;
        case 4:
            deleteFood();
            break;
        case 5:
            printAllFood();
            break;
        case 6:
            cont = false;
    }
    if (cont == true){
        showMenu();
        
    }
}

void deleteFood(){
    printAllFood();
    int num;
    cout << "Which food would you like to delete? (Enter #): ";
    cin >> num;
    cin.ignore();

    char confirm;
    cout << "Are you sure you want to delete " << foods.at(num).name << "? (Y/N): ";
    cin >> confirm;
    if (tolower(confirm) == 'y') {
        foods.erase(foods.begin() + num);
    }
    cin.ignore();
}

void updateFood(Food& f, int attribute, string value){
    switch(attribute){
        case 1: 
            f.name = value;
            break;
        case 2: 
            f.price = stod(value);
            break;
        case 3: 
            f.rating = stod(value);
            break;
        case 4: 
            f.origin = value;
            break;
        case 5: 
            f.description = value;
            break;
    }
}

void updateFood(){
    printAllFood();
    int num;
    cout << "Which food would you like to update? (Enter #): ";
    cin >> num;

    cout << "1. Name " << endl;
    cout << "2. Price " << endl;
    cout << "3. Rating " << endl;
    cout << "4. Origin " << endl;
    cout << "5. Description " << endl;

    int attribute;
    cout << "Which attribute would you like to update? (Enter #): ";
    cin >> attribute;
    cin.ignore();

    string value; 
    cout << "What is the value of the new attribute? " << endl;
    getline(cin, value);

    updateFood(foods.at(num), attribute, value);
    cout << foods.at(num).name << " has been successfully updated in the Global Foods Database. " << endl;
}


void readFood(){
    string fname;
    cin.ignore();
    cout << "Enter the name of a food: ";
    getline(cin, fname);

    for (int i = 0; i < foods.size(); i++){
        if (fname == foods.at(i).name){
            printFood(foods.at(i));
            cout << foods.at(i).description;
        }
    }
}

void createFood(){
    string n, o, d;
    double p, r;

    cin.ignore();

    cout << endl;
    cout << "Enter the name: ";
    getline(cin, n);

    cout << "Enter the origin: ";
    getline(cin, o);

    cout << "Enter the price (US $): ";
    cin >> p;

    cout << "Enter the rating (out of 5): ";
    cin >> r;

    cin.ignore();
    cout << "Enter a description ";
    getline(cin, d);
    

    Food f = {n, p, r, o, d};
    foods.push_back(f);
}

void printStars(double num){
    int i = 1;
    while (i <= num) {
        cout << "*";
        i++;
    }
    if (i - 1 < num) {
        cout << "'";
    }
}
void printFood(Food f){
    cout << f.name << "\t";
    cout << "$: " << f.price << "\t\t";
    cout << "Rating: "; printStars(f.rating); cout << "\t";
    cout << "Origin: " << f.origin << "\t"; 
    cout << endl;
}

void printAllFood(){
    for (int i = 0; i < foods.size(); i++){
        cout << i << ". \t";
        printFood(foods.at(i));
    }
}