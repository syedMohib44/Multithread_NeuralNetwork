#include <thread>

class Thread_guard
{

public:
    explicit Thread_guard(std::thread &t);
    ~Thread_guard();
    Thread_guard(Thread_guard const &) = delete;
    Thread_guard &operator=(Thread_guard const &) = delete;

private:
    std::thread *t;
};