// Создать класс «Автомобиль» со следующими данными: id – уникальный номер, name – ФИО владельца, mileage –
// пробег.Создать дружественный класс «СТО», в котором реализовать метод установки пробега автомобиля.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car
{
private:
    int id;
    string name;
    int mileage;
public:
    void static SetId(Car& car, int _id)
    {
        car.id = _id;
    }

    friend class Sto;

    Car(string _name, int _mileage)
    {
        name = _name;
        mileage = _mileage;
    }

    ~Car()
    {

    }
};

class Sto
{
public:
    int ComputeMileAge(Car& car)
    {
        return car.mileage;
    }

    Sto()
    {

    }

    ~Sto()
    {

    }
};

int main()
{
    Car car = Car("Mercedes", 150000);
    Car::SetId(car, 1);

    Car car2 = Car("BMW", 30000);
    Car::SetId(car2, 2);

    Sto sto = Sto();

    cout << sto.ComputeMileAge(car) << endl;
    cout << sto.ComputeMileAge(car2) << endl;

    vector<Car> cars;

    cars.push_back(car);
    cars.push_back(car2);

    for (int i = 0; i < cars.size(); i++)
        cout << sto.ComputeMileAge(cars[i]) << endl;

    return 0;
}