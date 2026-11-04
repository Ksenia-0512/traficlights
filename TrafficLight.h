#include <string>

enum TrafficLightsState { RED, YELLOW, GREEN };

class TrafficLight {

protected:
	
	std::string street;
	std::string city;
	std::string country;
	double latitude;
	double longitude;

public:

	//конструктор
	TrafficLight(std::string street, std::string city, std::string country, double latitude, double longitude);

	// методы
	TrafficLightsState GetCurrentState(); //получить статус о цвете светофора
	void GetInfo(); //вывести информацию о текущем цвете и адресе  светофора 
	//..
};