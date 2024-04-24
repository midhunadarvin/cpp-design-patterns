## Simple Scheduler in C++

### Interface 

```
IScheduler {
    function addTask // add task to the scheduler
    function start // start the scheduler
    function stop // stop the scheduler
}
```

### Build

Use the following command to build and run the executable target.

```bash
g++ -o main.exe --std=c++17 main.cpp SimpleScheduler.cpp
```

### Run

```
./main.exe
```

