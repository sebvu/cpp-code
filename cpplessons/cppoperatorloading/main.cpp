#include <iostream>
#include <string>
#include <list>

struct Person {
    std::string Name;
    int Age; 
    int id;

    Person(std::string Name, int Age, int id)
        : Name(Name), Age(Age), id(id) {}

    bool operator == (const Person& PERSON) const {
        return this->id == PERSON.id; // compared reference id to called id for true or false

    }
};

struct MyFavorites {
    std::list<Person>myFavoritePeople;

    void operator += (Person& PERSON) {
        this->myFavoritePeople.push_back(PERSON);
    }

    void operator -= (Person& PERSON) {
        this->myFavoritePeople.remove(PERSON);
    } 
    
    /* interesting error with the definition of remove!

    will need to overload == operator due to definition of remove
    looking for if PERSON equals the object in myFavoritePerson
    look at Person struture for == operator!

    */
};

std::ostream& operator << (std::ostream& COUT, Person& PERSON) {
    COUT << "Name: " << PERSON.Name << std::endl;
    COUT << "Subscribers: " << PERSON.Age << std::endl;
    return COUT;
}

std::ostream& operator << (std::ostream& COUT, MyFavorites& FAVORITES) {
    for (Person PERSON : FAVORITES.myFavoritePeople) // for every PERSON in FAVORITES.myFavoritePeople
        COUT << PERSON << std::endl; // insert PERSON to COUT
    return COUT;
}

int main() {

    std::cout << "Printing out individual objects: " << std::endl;

    Person Jackson = Person("Jackson Mcgee", 32, 5592);
    Person Albert = Person("Albert Hanson", 26, 6694);
    std::cout << Jackson << Albert << std::endl;

    std::cout << "Printing out favorite people list: " << std::endl;

    MyFavorites myFavorites;
    myFavorites += Jackson;
    myFavorites += Albert;
    myFavorites -= Jackson; // removing Jackson
    std::cout << myFavorites;

}