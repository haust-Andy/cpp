

#ifndef BASE_THREAD_H
#define BASE_THREAD_H


#include <functional>
#include <thread>

class Thread
{
public:
    using ThreadFunc = std::function<void()>;

    explicit Thread(ThreadFunc func, const string &name = string());
    ~Thread();

    void start();
    void join();

    const string &name() const { return _name; }
    bool started() const { return _started; }

private:
    void setDefaultName();

private:
    bool _started;
    bool _joined;
    std::thread _thread;
    ThreadFunc _func;
    string _name;
};



#endif // !BASE_THREAD_H