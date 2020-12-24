#ifndef MISC_H
#define MISC_H

#include "stdint.h"

#define DOUBLE_SIGN_OFFSET  63
#define DOUBLE_EXP_OFFSET   52
#define DOUBLE_MAN_OFFSET   0

#define DOUBLE_SIGN_MASK    0x8000000000000000
#define DOUBLE_EXP_MASK     0x7ff0000000000000
#define DOUBLE_MAN_MASK     0x000fffffffffffff

#define FLOAT_SIGN_OFFSET  31
#define FLOAT_EXP_OFFSET   23
#define FLOAT_MAN_OFFSET   0

#define FLOAT_SIGN_MASK     0x80000000
#define FLOAT_EXP_MASK      0x7f800000
#define FLOAT_MAN_MASK      0x007fffff

typedef union {
    double _double;
    uint8_t _char[sizeof (double)];
    uint64_t _long_long;
} do_ch_t;

typedef union {
    float _float;
    uint8_t _char[sizeof (float)];
    uint32_t _long;
} fl_ch_t;

typedef enum {
    POSITIVE,
    NEGATIVE
} sign_t;

class Misc
{

public:
    static uint64_t getMantiss(double val);
    static uint64_t getMantiss(float val);
    static uint16_t getExponent(double val);
    static uint8_t getExponent(float val);
    static sign_t getSign(double val);
    static sign_t getSign(float val);
    static uint64_t getDoubleLongLong(double val);
};

#endif // MISC_H
