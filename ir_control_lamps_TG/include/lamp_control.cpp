#include "lamp_control.h"

long LampControl :: get_signal(unsigned int par)
{
    switch (par)
    {
    case 1:
        return LIGHT_TURN;
    case 2:
        return RGB_TURN;
    case 3:
        return BRIGHTNESS_UP;
    case 4:
        return BRIGHTNESS_DOWN;
    case 5:
        return WARM_OR_RGB_CHANGE;
    case 6:
        return COLD_OR_RGB;
    case 7:
        return CHANGING;
    case 8:
        return CRESCENT_MOON;
    case 9:
        return HALF_OF_WARM;
    case 10: 
        return HALF_OF_COLD;
    }
}