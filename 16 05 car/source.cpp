#include <iostream>
#include <string>

using namespace std;

class Component {
public:
    virtual Component* clone() const = 0;
    virtual void info() const = 0;
    virtual ~Component() {}
};

class Engine : public Component {
private:
    string volume;
    string power;
public:
    Engine(const string& vol, const string& pow) : volume(vol), power(pow) {}
    Component* clone() const override { return new Engine(*this); }
    void info() const override {
        cout << "Engine: " << volume << " " << power << "\n";
    }
};

class Transmission : public Component {
private:
    string type;
public:
    Transmission(const string& t) : type(t) {}
    Component* clone() const override { return new Transmission(*this); }
    void info() const override {
        cout << "Transmission: " << type << "\n";
    }
};

class Manufacturer : public Component {
private:
    string name;
    int year;
    string fuelType;
    string country;
public:
    Manufacturer(const string& n, int y, const string& fuel, const string& c) : name(n), year(y), fuelType(fuel), country(c) {}
    Component* clone() const override { return new Manufacturer(*this); }
    void info() const override {
        cout << "Year of issue: " << name << " (" << year << ")\n";
        cout << "Fuel Type: " << fuelType << "\n";
        cout << "Country: " << country << "\n";
    }
};

class Car {
private:
    Engine* engine;
    Transmission* transmission;
    Manufacturer* manufacturer;
    string model;
    string bodyType;
    string driveType;
    string color;
public:
    Car(const string& mdl, Engine* eng, Transmission* trans, Manufacturer* manu,
        const string& body, const string& drive, const string& col)
        : model(mdl), engine(eng), transmission(trans), manufacturer(manu),
        bodyType(body), driveType(drive), color(col) {}
    Car(const Car& other)
        : model(other.model), bodyType(other.bodyType), driveType(other.driveType),
        color(other.color) {
        engine = dynamic_cast<Engine*>(other.engine->clone());
        transmission = dynamic_cast<Transmission*>(other.transmission->clone());
        manufacturer = dynamic_cast<Manufacturer*>(other.manufacturer->clone());
    }
    ~Car() {
        delete engine;
        delete transmission;
        delete manufacturer;
    }
    void info() const {
        cout << "Model: " << model << "\n";
        engine->info();
        transmission->info();
        manufacturer->info();
        cout << "Body Type: " << bodyType << "\n";
        cout << "Drive Type: " << driveType << "\n";
        cout << "Color: " << color << "\n";
        cout << "\n";
    }
};

int main() {
    system("chcp 1251");

    Engine bmwEngine("4.4 liters", ",600 horsepower");
    Transmission bmwTransmission("Automatic");
    Manufacturer bmwManufacturer("BMW", 2020, "Gasoline", "Germany");

    Engine vwEngine("2 liters", ",200 horsepower");
    Transmission vwTransmission("Mechanik");
    Manufacturer vwManufacturer("Volkswagen", 2013, "Diesel", "Germany");

    Engine teslaEngine("100 kW", ",600 horsepower");
    Transmission teslaTransmission("Automatic");
    Manufacturer teslaManufacturer("Tesla", 2017, "Electricity", "America");

    Engine toyotaEngine("3.5 liters", ",270 horsepower");
    Transmission toyotaTransmission("Automatic");
    Manufacturer toyotaManufacturer("Toyota Camry", 2010, "Gasoline", "Japan");

    Engine audiEngine("4 liters", ",650 horsepower");
    Transmission audiTransmission("Automatic");
    Manufacturer audiManufacturer("Audi", 2024, "Gasoline", "Germany");

    Engine mercedesEngine("4 liters", ",900 horsepower");
    Transmission mercedesTransmission("Automatic");
    Manufacturer mercedesManufacturer("Mercedes Benz W213", 2019, "Gasoline", "Germany");

    Engine subaruEngine("2 liters", ",450 horsepower");
    Transmission subaruTransmission("Mechanik");
    Manufacturer subaruManufacturer("Subaru", 2004, "Gasoline", "Japan");

    Car bmw("BMW M5 F90", &bmwEngine, &bmwTransmission, &bmwManufacturer,
        "Sedan", "AWD", "Black");
    Car vw("Volkswagen Passat B7", &vwEngine, &vwTransmission, &vwManufacturer,
        "Universal", "FWD", "White");
    Car tesla("Tesla Model X", &teslaEngine, &teslaTransmission, &teslaManufacturer,
        "Liftback", "AWD", "Red");
    Car toyota("Toyota Camry", &toyotaEngine, &toyotaTransmission, &toyotaManufacturer,
        "Sedan", "FWD", "Black");
    Car audi("Audi RS6", &audiEngine, &audiTransmission, &audiManufacturer,
        "Universal", "AWD", "Gray");
    Car mercedes("Mercedes Benz W213", &mercedesEngine, &mercedesTransmission, &mercedesManufacturer,
        "Sedan", "AWD", "Dark Blue");
    Car subaru("Subaru Impreza WRX STI", &subaruEngine, &subaruTransmission, &subaruManufacturer,
        "Sedan", "AWD", "Black-red");

    string userInput;
    cout << "Введите марку автомобиля (BMW, Volkswagen, Tesla, Toyota, Audi, Mercedes Benz или Subaru): ";
    cin >> userInput;

    if (userInput == "BMW") {
        bmw.info();
    }
    else if (userInput == "Volkswagen") {
        vw.info();
    }
    else if (userInput == "Tesla") {
        tesla.info();
    }
    else if (userInput == "Toyota") {
        toyota.info();
    }
    else if (userInput == "Audi") {
        audi.info();
    }
    else if (userInput == "Mercedes") {
        mercedes.info();
    }
    else if (userInput == "Subaru") {
        subaru.info();
    }
    else {
        cout << "Марка автомобиля не распознана.\n";
    }

    return 0;
}
