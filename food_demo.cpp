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

void deleteFood();
void readFood();
void createFood();

void printAllFoods();

int main() {
    return 0;
}

void deleteFood() {
    printAllFoods();

    int choice;
    cout << "Which food would you like to delete (Enter #): ";
    cin >> choice;

    char confirmation;
    cout << "Are you sure you want to delete " << foods.at(choice).name << "? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y') {
        foods.erase(foods.begin() + choice);
    }

    printAllFoods();
}

void createFood() {
    string fname;
    cout << "Enter a food name: ";
    getline(cin, fname);

    double fprice;
    cout << "Enter the price: ";
    cin >> fprice;

    double frating;
    cout << "Enter the rating (out of 5): ";
    cin >> frating;

    cin.ignore();

    string forigin;
    cout << "Enter the origin: ";
    getline(cin, forigin);

    Food newFood = {fname, fprice, frating, forigin}; // init list
    /*newFood.name = fname;
    newFood.price = fprice;
    ...*/

    foods.push_back(newFood);
    printAllFoods();
}

void readFood() {
    string fname;
    cout << "Enter a food: ";
    getline(cin, fname);
    bool exists = false;

    // loops through all existing food
    for (int i = 0; i < foods.size(); i++){
        if (fname == foods.at(i).name) {
            exists = true;
            Food f = foods.at(i);
            cout << f.name << "\t";
            cout << f.price << "\t";
            cout << f.rating << "\t";
            cout << f.origin << endl;
            cout << f.description << endl;
        }
    } 
    if (exists == false) {
        cout << fname << " does not exist. " << endl;
    }
    
}

void printAllFoods(){
  for (int i = 0; i < foods.size(); i++){
    cout << i << ". \t" << foods.at(i).name << "\t";
    cout << foods.at(i).price << "\t";
    cout << foods.at(i).rating << "\t";
    cout << foods.at(i).origin << "\t"; 
    cout << endl;
  }
}