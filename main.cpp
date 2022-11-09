#include <iostream>
#include <boost/version.hpp>
#include<boost/noncopyable.hpp>
#include<mutex>
#include<vector>
#include<pthread.h>
#include <boost/thread/with_lock_guard.hpp>
using namespace std;

class count : boost::noncopyable{
private:
    int value;
    mutable mutex mu;
public:
    count(int v):value(v){

    }
    int getvalue()const{
        lock_guard<mutex> guard(mu);
        sleep(1);
        return value;
    }
    void increase(){
        lock_guard<mutex> gurad(mu);
        sleep(1);
        value++;
    }


};
count c(1);
void * start(void* args){
    for(int i=0; i<5; i++){
        int val = c.getvalue();
        cout<<"this pthread 1 "<<val<< endl;
        c.increase();
        sleep(1);
    }

}
void * start2(void* args){
    for(int i=0; i<5; i++){

        int val = c.getvalue();
        cout<<"this pthread 2 "<<val<< endl;
        sleep(1);
        c.increase();
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << "Boost版本：" << BOOST_VERSION << endl;
    vector<pthread_t> mem;
    mem.resize(5);
    pthread_create(&mem[0], nullptr, start, nullptr);
    pthread_create(&mem[1], nullptr, start2, nullptr);

    pthread_join(mem[0], nullptr);
    pthread_join(mem[1], nullptr);
    cout<<"thi"<<endl;

    return 0;
}
