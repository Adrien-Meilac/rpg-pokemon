#ifndef PKMN_WEATHER_H_INCLUDED
#define PKMN_WEATHER_H_INCLUDED

#include "../Pokemon/Move.h"
#include "../Pokemon/Type.h"

#include <string>

#define WEATHER_CLEAR           "CLEAR SKIES"
#define WEATHER_HARSH_SUNLIGHT  "HARSH SUNLIGHT"
#define WEATHER_RAIN            "RAIN"
#define WEATHER_SANDSTORM       "SANDSTORM"
#define WEATHER_HAIL            "HAIL" /// Snow

namespace PKMN
{
    class Weather;
}

class PKMN::Weather
{
public :

    Weather();
    Weather(std::string weather);

    Weather(Weather const& other);
        /** \brief Copy constructor
         *
         * \param other Move const& : other Move to copy
         *
         */

    Weather& operator=(Weather const& other);
        /** \brief to simplify assignment of Move objects
         *
         * \param other Move const& : other Move to copy
         * \return Move& : *this
         *
         */

    ~Weather();

    void setWeather(std::string weather);

    std::string getInternalName() const;

    std::string startMessage(const Move& mv);
    std::string endMessage() const;
    std::string turnMessage() const;

    double weatherEffect(const Type& type) const;

private:

    std::string m_InternalName;

};

namespace PKMN
{

bool operator==(Weather weather1, Weather weather2);
bool operator==(Weather weather1, std::string weatherInternalName);

}

#endif // PKMN_WEATHER_H_INCLUDED
