#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
//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
struct Cat{
  enum {MAX_CHAR_SIZE = 100};
  char catName[MAX_CHAR_SIZE];
  int minLifeSpan;
  int maxLifeSpan;
  int minWeight;
  int maxWeight;
  string temperment;
  string origin;
  bool validEntry;

  Cat();
};

Cat::Cat(){
    for (int index = 0; index < MAX_CHAR_SIZE; index++) {
  minLifeSpan = 0;
  maxLifeSpan = 0;
  minWeight = 0;
  maxWeight = 0;
  temperment = "";
  origin = "";
  validEntry = false;
}
  }
  const int MAX_CATS = 67;
  Cat readCat(ifstream & inFile){
    Cat cat;
    inFile.get(cat.catName, Cat::MAX_CHAR_SIZE, ';');
    inFile.ignore(100,';');

    inFile >> cat.minLifeSpan;
    inFile.ignore(100,';');

    inFile >> cat.maxLifeSpan;
    inFile.ignore(100,';');

    inFile >> cat.minWeight;
    inFile.ignore(100,';');

    inFile >> cat.maxWeight;
    inFile.ignore(100,';');

    inFile >> cat.temperment;
    inFile.ignore(100,';');

    inFile >> cat.origin;

    cat.validEntry = !inFile.eof();
    return cat;
  }
// readCatData reads the cat data from the file
int readCatData(Cat cat[]){
  ifstream catFile("cats.txt");
  int numCats = 0;
while(catFile.peek() != EOF && numCats < MAX_CATS){
  
  cat[numCats] = readCat(catFile);
  numCats++;
}
  return numCats;
}
// printCats prints all the information for a cat
void printCats(ostream &out, Cat cat){
    out << cat.catName << ",";
    out << "Minimun Lifespan: " << cat.minLifeSpan << ",";
    out << "Maximum Lifespan: " << cat.maxLifeSpan << ",";
    out << "Minimum weight: " << cat.minWeight << ",";
    out << "Maximum weight: " << cat.maxWeight << ",";
    out << "Temperment: " << cat.temperment << " ";
    out << "Country of origin: " << cat.origin << endl;
    out << endl;
}
// printArrayToScreen prints the cat from the file to the screen
void printArrayToScreen(Cat cat[], int numCats) {
    for (int index = 0; index < numCats; index++) {
        cout << "Index " << index << ": ";
        printCats(cout, cat[index]);
    }
}
// printArrayToFile takes the information type by the user and puts it into the file
void printArrayToFile(const char fileName[], Cat cat[], int numCats) {
    ofstream outFile(fileName);
    for (int index = 0; index < numCats; index++) {
        printCats(outFile, cat[index]);
    }
}
// readInt reads the user input and validates it
int readInt(const char prompt[]){
    int temp = 0;
    cout << prompt;
    cin >> temp;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << prompt;
        cin >> temp;
    }
    return temp;
}
// removeCat removes a cat from the array
void removeCat(Cat cat[]){
  int numRemove = -1;
  while((numRemove < 0) || (numRemove > 57)){
  numRemove = readInt("Enter a number between 0 and 57: ");
  }
 for(int index = numRemove; index < 56; index++){
   cat[index] = cat[index + 1];
 }
}
//addCat adds a cat to the array
void addCat(Cat cat[], int index){
    cout << "Enter a cat name: ";
    cin >> cat[index].catName;

    cat[index].minLifeSpan = readInt("Enter minimum life span: ");
    cat[index].maxLifeSpan = readInt("Enter max life span: ");
    cat[index].minWeight = readInt("Enter minimum weight: ");
    cat[index].maxWeight = readInt("Enter max weight: ");
  cout << ("Enter temperment: ");
    cin >> cat[index].temperment;
  cout << ("Enter country of origin: ");
    cin >> cat[index].origin;
  
    cat[index].validEntry = true;
    }
// searchData searches a cat by weight
void searchData(Cat cat[]){
  int option ;
    cout << "Enter a number to search by cat weight: "; 
  cin >> option;
  
for(int i = 0; i < MAX_CATS; i++){
 if(cat[i].minWeight == option){
   printCats(cout, cat[i]);
   
}
}
}

// displayMenu displays all the options the user can choose
void displayMenu(Cat cat[], int numCats){
  char option;
  while(option != 'q'){
    cout << "Press 'l' to list, 'r' or 'a' to remove or add or remove a cat, 's' to search database, 'f' to save to file, 'd' to discard any changes,  or 'q' to quit: ";
    cin >> option;
{
if(option == 'r'){
  removeCat(cat);
  numCats -= 1;
}
if(option == 'a'){
  addCat(cat, numCats);
  numCats += 1;
}
if(option == 'l'){
  printArrayToScreen(cat, numCats);
}
if(option == 's'){
  searchData(cat);
}
if(option == 'f'){
  printArrayToFile("example.txt", cat, numCats);
}
if(option == 'd'){
  numCats = readCatData(cat);
}
  }
}
  } 
//calls the functions
int main() {
    Cat cat[MAX_CATS];
int numCats = readCatData(cat);
  displayMenu(cat, numCats);
 
}
