#include "ThreadGuard.h"

Thread_guard::Thread_guard(std::thread &t_) //: t(t_)
{
    this->t = &t_;
}

Thread_guard::~Thread_guard()
{
    if (this->t->joinable())
        this->t->join();
}