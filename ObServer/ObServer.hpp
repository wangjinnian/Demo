///**guan cha zhe**///

#ifndef OBSERVER_HPP
#define OBSERVER_HPP
#include <iostream>

#include "AbstractBase.hpp"
//bei tong tongzhi zhe jilei
using namespace std;
class XXXOb:public ObServer{
    void UpDate(DataMode::DataMode &data,system_clock::time_point &now_time,
                int timr_jian,system_clock::time_point &dao_time) final {
        cout<<data.type<<endl;
        std::time_t now_time_t=system_clock::to_time_t(now_time);
        std::time_t dao_time_t=system_clock::to_time_t(dao_time);
        cout<<"now time"<<std::put_time(std::localtime(&now_time_t), "%F %T")<<endl;
        cout<<"%d mill后到达"<<timr_jian<<endl;
        cout<<"dao da time"<<std::put_time(std::localtime(&dao_time_t), "%F %T")<<endl;
    }
};

#endif
