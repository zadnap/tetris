#include "../include/utils.h"
#include <raylib.h>

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