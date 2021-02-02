///**udp**///

#ifndef DATERECV_HPP
#define DATERECV_HPP

#include <memory>
#include "DataMode.h"
using namespace std;

class DateRecv{
public:
    DateRecv(){

    }
    void OnHander(){

    }
};

shared_ptr<DateRecv> m_data_recv=make_shared<DateRecv>();
#endif
