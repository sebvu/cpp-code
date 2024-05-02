#ifndef EXCEPTION_H
#define EXCEPTION_H

    class BadValue {
    private:
        float value;
    public:
        BadValue(float value) : value(value) {}
        float GetValue() { return value; }
    };
    class ZeroValue{};

#endif