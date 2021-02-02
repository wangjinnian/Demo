#ifndef ABSTRACTBASE_HPP
#define ABSTRACTBASE_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <list>
#include <queue>
#include <algorithm>
#include <chrono>
#include <iomanip>

#include "DateRecv.hpp"

using namespace std;
using namespace std::chrono;
class SubJect;

class ObServer{
public:
    ObServer(){

    }
    virtual void UpDate(DataMode::DataMode &data,system_clock::time_point &now_time,
                        int timr_jian,system_clock::time_point &dao_time)=0;
    //{
        //cout<<"here"<<endl;
    //}
private:

};

struct UpDate{
    DataMode::DataMode m_data;
    time_point<system_clock> m_time;
    UpDate(DataMode::DataMode &data){
        m_data=data;
    }
    void operator()(shared_ptr<ObServer> &ps){
        m_time=system_clock::now();
        duration<int,std::milli> jiange{m_data.len/m_data.speed};
        system_clock::time_point dao_time = m_time+jiange;
        ps.get()->UpDate(m_data,m_time,jiange.count(),dao_time);
    }
};
class SubJect{
public:
    SubJect(){

    }

    void AddTach(const shared_ptr<ObServer> &add){
        m_list.push_back(add);
    }
    void delTach(const shared_ptr<ObServer> &sub)
    {
        const auto&& pos=find(m_list.begin(),m_list.end(),sub);
        if(pos!=m_list.end()){
            m_list.erase(pos);
        }
    }
    void Notify(DataMode::DataMode &data){
        for_each(m_list.begin(),m_list.end(),UpDate(data));
    }
protected:
    thread m_th{};
    list<shared_ptr<ObServer>> m_list;
private:
    queue<DataMode::DataMode> m_buffer;
};

#endif
