#include <iostream>
#include <string>

using namespace std;

class Animal { // class declaration
  // ACCESS SPECIFIERS
  private:
    // everything in here is 'hidden'
    string ownerName; // member data
    string ownerAddress;
  
  public:
    // everything in here is 'accessible'
    string scientificName;
    string petName;
    int id;

    // CONSTRUCTORS -- function overloading
    Animal() { //default
      ownerName = "";
      ownerAddress = "Exists in the wild.";
      scientificName = "Unknown";
      petName = "None";
      id = -1;
    }
    Animal(string pName, string sName, int identifier){ // parameterized constructor
      ownerName = "";
      ownerAddress = "";
      scientificName = sName;
      petName = pName;
      id = identifier;
    }
    Animal(string oName, string oAddress){
      ownerName = oName; 
      ownerAddress = oAddress;
      id = -200;
      // define other variables...
    }

    // COPY CONSTRUCTOR -- only one allowed
    Animal(Animal& original){
      scientificName = original.scientificName;
      petName = original.petName;
      id = original.id;
      ownerName = original.ownerName;
      ownerAddress = original.ownerAddress;
    }

    // DESTRUCTOR -- only one allowed
    ~Animal(){
      cout << "Destructor called for animal with id = " << id << endl;
    }

    // Member Functions -- GETTERS/ACCESSOR
    string getPetName(){ return petName; }
    string getSciName(){ return scientificName; }
    string getOwner(){ return ownerName; }
    string getAddress(){ return ownerAddress; }
    int getId() {return id; }

    // More Member Functions -- SETTERS/MODIFIERS
    void setOwner(string name) { // change a private var's value
      ownerName = name;
    }
    void setPetName(string name){
      petName = name;
    }
};

int main(){
  Animal thing2("Kitty", "Felis catus", 123); // instantiate - 3
  cout << "Thing2's pet name is: " << thing2.getPetName() << endl;
  cout << "Thing2's owner name is: " << thing2.getOwner() << endl;

  Animal thing3; // instantiate another object -- 2
  thing3.setPetName("Dorothy");
  cout << "Thing3's pet name is: " << thing3.getPetName() << endl;
  cout << "Thing3's owner name is: " << thing3.getOwner() << endl;

  Animal thing1; // instantiated an object -- 1
  thing1.petName = "Roofus";
  thing1.id = 100;
  thing1.scientificName = "Canis lupus familiaris";
  thing1.setOwner("Justin");
  cout << "Thing1's owner is : " << thing1.getOwner() << endl;
  return 0;
}

string sayHello(){
  sayHello();
  return "Hello";
}