#ifndef DATAMODE_H
#define DATAMODE_H

#include <array>
using namespace std;
namespace DataMode{
    typedef struct DATA_MODE{
        int type;
        unsigned int len;
        unsigned int speed;
        array<char,40> name;
    }DataMode;
}

#endif
