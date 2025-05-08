
#include <iostream>
#include <string>
using namespace std;

// 父類別：Car
class Car {
protected:
    string m_brand;
    int m_MaxSeating;
    int m_price;
    string m_DriveMode;

public:
    Car(string brand, int seating, string driveMode)
        : m_brand(brand), m_MaxSeating(seating), m_DriveMode(driveMode) {
        m_price = m_MaxSeating * 500000;
    }

    string get_Brand() {
        return m_brand;
    }

    int get_MaxSeating() {
        return m_MaxSeating;
    }

    int get_Price() {
        return m_price;
    }

    string get_DriveMode() {
        return m_DriveMode;
    }
};

// 子類別：BMW_Car
class BMW_Car : public Car {
public:
    BMW_Car() : Car("BMW", 5, "Rear-wheel") {}
};

// 子類別：AUDI_Car
class AUDI_Car : public Car {
public:
    AUDI_Car() : Car("AUDI", 5, "Front-wheel") {}
};

// 子類別：BENZ_Car
class BENZ_Car : public Car {
public:
    BENZ_Car() : Car("BENZ", 5, "Front-wheel") {}
};

int main() {
    BMW_Car bmw;
    AUDI_Car audi;
    BENZ_Car benz;

    cout << "Brand: " << bmw.get_Brand() << ", Seating: " << bmw.get_MaxSeating()
         << ", Price: " << bmw.get_Price() << ", DriveMode: " << bmw.get_DriveMode() << endl;

    cout << "Brand: " << audi.get_Brand() << ", Seating: " << audi.get_MaxSeating()
         << ", Price: " << audi.get_Price() << ", DriveMode: " << audi.get_DriveMode() << endl;

    cout << "Brand: " << benz.get_Brand() << ", Seating: " << benz.get_MaxSeating()
         << ", Price: " << benz.get_Price() << ", DriveMode: " << benz.get_DriveMode() << endl;

    return 0;
}
