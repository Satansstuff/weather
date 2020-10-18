#include <iostream>
#include "httplib.h"
#include "json.hpp"
using json = nlohmann::json;
int main(int argc, char **argv)
{
    std::string city = "karlskrona";
    if(argc > 1)
    {
        city = argv[2];
    }
    httplib::Client cli("http://api.weatherstack.com");
    auto res = cli.Get((std::string("/current?access_key=XXXXXXXXXXXXX&query=") + city).c_str());

    if(res->status == 200)
    {
        auto j = json::parse(res->body);
        try 
        {
            unsigned temp = j.at("current").at("temperature");
            std::string city = j.at("location").at("name");
            std::string weather = j.at("current").at("weather_descriptions").at(0);
            unsigned feels = j.at("current").at("feelslike");
            std::string time = j.at("location").at("localtime");
            time.erase(0, 11);
            std::string wind_dir = j.at("current").at("wind_dir");
            double wind_speed = j.at("current").at("wind_speed");
            std::cout << "Observation time: " << time << std::endl; // Technically cheating
            std::cout << "Temperature: " << temp << "c" << std::endl;
            std::cout << "Feels-like: " << feels << "c" <<std::endl; 
            std::cout << "Weather: " << weather << std::endl;
            std::cout << "Wind: " << wind_speed * 0.3048 << " m/s, " << wind_dir << std::endl;
            std::cout << "Location: " << city << std::endl;
        } catch (const std::exception& e) 
        {
            std::cout << "Time: " << "N/A" << std::endl;
            std::cout << "Temperature: " << "N/A" << "c" << std::endl;
            std::cout << "Feels-like: " << "N/A" << "c" <<std::endl; 
            std::cout << "Weather: " << "N/A" << std::endl;
            std::cout << "Wind: " << "N/A " << "m/s" << std::endl;
            std::cout << "Location: " << "N/A" << std::endl;
            return EXIT_FAILURE;
        }
    }
    else
    {
        std::cout << "Time: " << "N/A" << std::endl;
        std::cout << "Temperature: " << "N/A" << "c" << std::endl;
        std::cout << "Feels-like: " << "N/A" << "c" <<std::endl; 
        std::cout << "Weather: " << "N/A" << std::endl;
        std::cout << "Wind: " << "N/A " << "m/s" << std::endl;
        std::cout << "Location: " << "N/A" << std::endl;
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
