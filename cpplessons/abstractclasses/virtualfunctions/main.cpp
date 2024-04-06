#include "Instrument.cpp"
#include <iostream>

int main() {

Instrument* i1 = new Cello(); 
Instrument* i2 = new Piano();
// i2->MakeSound(); 

// i1->MakeSound();

Instrument* instruments[2] = { i1, i2 };

for (int i = 0; i < 2; i++)
    instruments[i]->MakeSound();


}
