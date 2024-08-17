#include <iostream>
#include <thread>

void call_from(int tid){
    std::cout << "Lauched by thread " << tid << std::endl;
}

int main() {
    std::thread t[10];

    for (int i = 0; i < 10; i++){
        t[i].start();
    }

    for ( int i = 0; i < 10; i++){
        t[i] = std::thread(call_from, i);
    }

    std::cout << "Launched from main" << std::endl;

    for (int i = 0; i < 10; i++){
        t[i].join();
    }
}
