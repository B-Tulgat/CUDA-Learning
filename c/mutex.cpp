#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void call_from (int tid){
    mtx.lock();
    std::cout << "Launched by thread " << tid << std::endl;
    mtx.unlock();
}

int main(){
    std::thread t[10];

    for (int i = 0; i< 10; i++){
        t[i] = std::thread(call_from,i);
    }


    mtx.lock();
    std::cout << "Launched from main" << std::endl;
    mtx.unlock();

    for (int i = 0; i<10; i++){
        t[i].join();
    }
}
