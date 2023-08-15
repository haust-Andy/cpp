#include "Thread.h"


#include <sstream>

using namespace std;


Thread::Thread(Thread::ThreadFunc func, const string &name)
    : _func(func), _started(false), _joined(false), _name(name)
{
    if (name == "")
    {
        setDefaultName();
    }
}

Thread::~Thread()
{
    if (_started && !_joined)
    {
        _thread.detach();
    }
}

void Thread::start()
{
    assert(!_started);
    _started = true;
    _thread = thread(_func);
}

void Thread::join()
{
    assert(_started && !_joined);
    _joined = true;
    _thread.join();
}

void Thread::setDefaultName()
{
    stringstream sos;
    sos << this_thread::get_id() << "-->" << _thread.get_id();
    _name = sos.str();
}