#include <iostream>
#include <memory>
#include "ObServer.hpp"
#include "Subject.hpp"
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    XXXSubJect xiaofang;
    shared_ptr<XXXOb> wang=make_shared<XXXOb>();
    shared_ptr<XXXOb> li=make_shared<XXXOb>();
    xiaofang.AddTach(wang);
    xiaofang.AddTach(li);
    DataMode::DataMode data;
    data.type=1;
    data.len=100000;
    data.speed=5;
    xiaofang.Notify(data);
    return 0;
}
