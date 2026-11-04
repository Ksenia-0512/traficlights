#include"TrafficLight.h"
#include <iostream>
#include <chrono>

std::ostream& operator<<(std::ostream& os, TrafficLightsState state)
{
    switch (state)
    {
    case RED:    os << "Красный"; break;
    case YELLOW: os << "Желтый";  break;
    case GREEN:  os << "Зеленый"; break;
    }
    return os;
}

TrafficLight::TrafficLight(std::string street, std::string city, std::string country, double latitude, double longitude)
{
    this->street = street;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

TrafficLightsState TrafficLight::GetCurrentState() {
   
    // Фиксируем время
    auto now = std::chrono::system_clock::now();

    // Приводим до секунд
    auto now_sec = std::chrono::floor<std::chrono::seconds>(now).time_since_epoch();

    // Получаем остаток от деления - секунды текущей минуты, и обращаем в число

    int seconds = (now_sec).count();

    seconds = seconds % 60;

    if (seconds >= 0 && seconds <= 5) // в промежутке от нуля до пяти секунд
    {
        return TrafficLightsState::YELLOW; // будет гореть желтый свет
    }

    if (seconds > 5 && seconds <= 35) // в промежутке от нуля до пяти секунд
    {
        return TrafficLightsState::RED; // будет гореть желтый свет
    }

    if (seconds > 35 && seconds <= 60) // в промежутке от нуля до пяти секунд
    {
        return TrafficLightsState::GREEN; // будет гореть желтый свет
    }
}

void TrafficLight::GetInfo() {

    std::cout << " " << GetCurrentState() << " Светофор: " << country << ", " << city << ", " << street << std::endl;

}