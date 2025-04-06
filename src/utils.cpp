#include "../include/utils.h"

bool hasElapsedTime(double interval, double &lastUpdateTime)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int generateRandomNumber(int min, int max)
{
    std::srand(static_cast<unsigned int>(GetTime() * 1000));
    return min + std::rand() % (max - min + 1);
}