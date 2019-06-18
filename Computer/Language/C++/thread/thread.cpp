#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <functional>
#include <atomic>
#include <time.h>
#include <unistd.h>

int func1 (int arg) {
    int sum = 0;
    for (int i = 0; i <= arg; i++) {
        sum += i;
    }
    std::cout << sum << std::endl;
    while (1);
    return sum;
}

void pause_thread(int n) {
    std::this_thread::sleep_for (std::chrono::seconds(n));
    std::cout << "pause of " << n << " seconds ended\n";
}

int main() {
    std::thread* t1 = new std::thread(&func1, 10000);
    auto start = std::chrono::high_resolution_clock::now();
    //std::this_thread::sleep_for(2s);
    std::thread::id t1_id = t1->get_id();
    std::cout << "t1's id: " << t1_id << '\n';
    sleep(3);
    auto end = std::chrono::high_resolution_clock::now();
    pause_thread(3);
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Waited " << elapsed.count() << " ms\n";
    pthread_t handler = t1->native_handle();
    t1->detach();
    //t1->join();
    //delete t1;
    //t1.join();
    return 0;
}
