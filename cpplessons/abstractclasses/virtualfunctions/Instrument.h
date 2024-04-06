#ifndef INSTRUMENT_H
#define INSTRUMENT_H 

class Instrument { // abstract class
public:
    virtual void MakeSound() = 0; // force implementation to all classes
};

class Cello : public Instrument { // create inherited class Cello
public:
    void MakeSound();
};

class Piano: public Instrument {
    void MakeSound();
};



#endif