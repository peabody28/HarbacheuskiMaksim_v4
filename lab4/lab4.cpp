// number 6
#include <iostream>

enum EngineType
{
	Diesel,
	Petrol,
	Electric
};

enum CarCreater
{
	Opel,
	Mercedes,
	Tesla
};

std::ostream& operator<<(std::ostream& out, const EngineType value) {

	switch (value) {
	case 0:
		return out << "Diesel";
		break;
	case 1:
		return out << "Petrol";
		break;
	case 2:
		return out << "Electric";
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const CarCreater value) {

	switch (value) {
	case 0:
		return out << "Opel";
		break;
	case 1:
		return out << "Mercedes";
		break;
	case 2:
		return out << "Tesla";
		break;
	}
}

class Transport
{
protected:
	EngineType engineType;
public:
	Transport(EngineType _engineType) 
	{
		engineType = _engineType;
	}

	virtual double Cost() = 0;

	virtual void Print() = 0;

	virtual ~Transport() = default;
};

class Car : public Transport
{
protected:
	CarCreater creater;
public:
	Car(CarCreater _creater, EngineType _engineType) : Transport(_engineType) 
	{
		creater = _creater;
	}

	double Cost() override
	{
		return -1;
	}

	void Print() override
	{
		std::cout << "Car engine type:" << engineType << std::endl;
		std::cout << "Car creater:" << creater << std::endl;
	}

	~Car() {}
};

class ElectricCar : public Car
{
private:
	int expenditure;
public:
	ElectricCar(int _expenditure, CarCreater _creater, EngineType _engineType) : Car(_creater, _engineType)
	{
		expenditure = _expenditure;
	}

	double Cost() override
	{
		return 70000;
	}

	void Print() override
	{
		Car::Print();
		std::cout << "Electric car expenditure(kW):" <<expenditure << std::endl;
	}

	~ElectricCar() {}
};

class Plane : public Transport
{
private:
	int maxHeight;
public:
	Plane(int _maxHeight, EngineType _engineType) : Transport(_engineType)
	{
		maxHeight = _maxHeight;
	}

	double Cost() override
	{
		return 1000000;
	}

	void Print() override
	{
		std::cout << "Plane engine type:" << engineType << std::endl;
		std::cout << "Plane max height:" << maxHeight << std::endl << std::endl;
	}

	~Plane() {}
};


int main()
{
	Transport** ts = new Transport* [3];
	ts[0] = new Car(Mercedes, Petrol);
	ts[1] = new ElectricCar(1, Tesla, Electric);
	ts[2] = new Plane(10000, Diesel);

	for (int i = 0; i < 3; i++)
	{
		std::cout << "Cost:"<<ts[i]->Cost()<<std::endl;
		ts[i]->Print();
		delete ts[i];
	}

	return 0;
}
