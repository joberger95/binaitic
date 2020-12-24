#include "misc.h"
#include "math.h"


uint64_t Misc::getMantiss(double val)
{
    do_ch_t temp;
    temp._double = val;
    temp._long_long &= DOUBLE_MAN_MASK;
    return temp._long_long;
}

uint64_t Misc::getMantiss(float val)
{
    fl_ch_t temp;
    temp._float = val;
    temp._long &= FLOAT_MAN_MASK;
    return temp._long;
}

uint16_t Misc::getExponent(double val)
{
    do_ch_t temp;
    temp._double = val;

    temp._long_long &= DOUBLE_EXP_MASK;
    uint16_t temp_2 = temp._long_long>>DOUBLE_EXP_OFFSET;
    return temp_2;

}

uint8_t Misc::getExponent(float val)
{
    fl_ch_t temp;
    temp._float = val;

    temp._long &= FLOAT_EXP_MASK;
    uint8_t temp_2 = uint8_t(temp._long>>FLOAT_EXP_OFFSET);
    return temp_2;
}

sign_t Misc::getSign(double val)
{
    do_ch_t temp;
    temp._double = val;

    if(temp._long_long&DOUBLE_SIGN_MASK)
        return NEGATIVE;
    else
        return POSITIVE;
}

sign_t Misc::getSign(float val)
{
    fl_ch_t temp;
    temp._float = val;

    if(temp._long&FLOAT_SIGN_MASK)
        return NEGATIVE;
    else
        return POSITIVE;
}

uint64_t Misc::getDoubleLongLong(double val)
{
    do_ch_t temp;
    temp._double = val;
    return temp._long_long;
}



