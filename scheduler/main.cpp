/**
 * g++ main.cpp SimpleScheduler.cpp -o main.exe --std=c++17
 */
#include "SimpleScheduler.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  /* code */
  SimpleScheduler scheduler;

  // Example tasks
  scheduler.addTask("Task 1",
                    std::chrono::system_clock::now() + std::chrono::seconds(5),
                    []() { std::cout << "Task 1 executed!" << std::endl; });

  scheduler.addTask("Task 2",
                    std::chrono::system_clock::now() + std::chrono::seconds(10),
                    []() { std::cout << "Task 2 executed!" << std::endl; });

  // Start the scheduler
  std::thread schedulerThread(&SimpleScheduler::start, &scheduler);

  // Let the scheduler run for some time
  std::this_thread::sleep_for(std::chrono::seconds(20));

  // Stop the scheduler
  scheduler.stop();
  schedulerThread.join();

  return 0;
  return 0;
}
