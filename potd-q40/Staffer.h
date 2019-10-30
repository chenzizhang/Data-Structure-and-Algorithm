#pragma once

#include <algorithm>
#include <cmath>
#include <string>

class Staffer {
    public:
        Staffer(std::string favQuestion, int startingEnergy);

        int getEnergyLevel();//return energy

        int answerQuestion(std::string questionType, int anticipatedTime); //return time used

    private:
        int energyLevel;
        std::string favoriteType;
};
