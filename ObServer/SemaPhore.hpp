#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <mutex>
#include <condition_variable>
using namespace std;
class SemaPhore{
public:
    SemaPhore(int i=1):value(i)
    {

    }
    ~SemaPhore()=default;
    SemaPhore(SemaPhore &other)=delete;
    SemaPhore(SemaPhore&& other)=delete;
    void operator=(SemaPhore &other)=delete;
    void wait()
    {
        unique_lock<mutex> m_unique_lock(m_mutex);
        while(value<1) {
            m_cond_var.wait(m_unique_lock);
        }
        value--;
    }
    bool try_wait()
    {
        unique_lock<mutex> m_unique_lock(m_mutex);
        while(value<1) {
            return false;
        }
        value--;
        return true;
    }
    void post()
    {
        {
            unique_lock<mutex> m_unique_lock(m_mutex);
            value++;
        }
        m_cond_var.notify_one();
    }
private:
    mutex m_mutex;
    condition_variable m_cond_var;
    int value{0};

};

#endif