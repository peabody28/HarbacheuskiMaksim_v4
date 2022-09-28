#include <iostream>


enum EngineType
{
	Diesel,
	Petrol
};

enum PlaneType
{
	Passenger,
	Military
};

enum TransportCreater
{
	Opel,
	AirJet
};


std::ostream& operator<<(std::ostream& out, const PlaneType value) {

	switch (value)
	{
	case 0:
		return out << "Passenger";
		break;
	case 1:
		return out << "Military";
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const EngineType value) {

	switch (value) {
	case 0:
		return out << "Diesel";
		break;
	case 1:
		return out << "Petrol";
		break;
	}
}

std::ostream& operator<<(std::ostream& out, const TransportCreater value) {

	switch (value) {
	case 0:
		return out << "Opel";
		break;
	case 1:
		return out << "AirJet";
		break;
	}
}


class Transport
{
protected:
	TransportCreater Creater;

public:
	Transport()
	{

	}

	Transport(TransportCreater _creater)
	{
		Creater = _creater;
	}

	virtual void PrintData()
	{
		std::cout << Creater << std::endl;
	}

	~Transport() {}
};

class Car : public virtual Transport
{
protected:
	virtual EngineType GetEngineType() = 0;

public:

	Car()
	{

	}

	Car(TransportCreater _creater)
	{
		Creater = _creater;
	}

	void PrintData() override
	{
		std::cout << Creater << std::endl;
		std::cout <<  GetEngineType() << std::endl;
	}

	~Car() {}
};

class Plane : public virtual Transport {
protected:
	PlaneType type;

public:
	Plane(PlaneType _type, TransportCreater _creater)
	{
		type = _type;
		Creater = _creater;
	}

	void PrintData() override
	{
		std::cout << Creater << std::endl;
		std::cout << type << std::endl;
	}

	~Plane() {}
};

class OpelAstra : public Car
{
private:
	unsigned short mileage;

	EngineType GetEngineType() override { return Diesel; }

public:
	OpelAstra(unsigned short _mileage) : Car(Opel)
	{
		mileage = _mileage;
	}

	void PrintData() override
	{
		std::cout << Creater << std::endl;
		std::cout << GetEngineType() << std::endl;
		std::cout << mileage << std::endl;
	}

	~OpelAstra()
	{

	}
};

class Jet : public Plane
{
private:
	unsigned int maxHeight;

public:
	Jet(unsigned int _maxHeight = 20000) : Plane(Military, AirJet)
	{
		maxHeight = _maxHeight;
	}

	void PrintData() override
	{
		std::cout << Creater << std::endl;
		std::cout << type << std::endl;
		std::cout << maxHeight << std::endl;
	}

	~Jet()
	{

	}
};


class AirCar : public Plane, public Car
{
private:
	int maxSpeed;

	EngineType GetEngineType() override { return Petrol; }

public:
	AirCar(unsigned short _maxSpeed = 300) : Plane(Passenger, AirJet)
	{
		maxSpeed = _maxSpeed;
	}

	void PrintData() override
	{
		std::cout << Creater << std::endl;
		std::cout << GetEngineType() << std::endl;
		std::cout << type << std::endl;
		std::cout << maxSpeed << std::endl;
	}

	~AirCar()
	{

	}
};


int main()
{
	OpelAstra cc(20);
	AirCar aircar(200);

	aircar.PrintData();
	
	return 0;
}

