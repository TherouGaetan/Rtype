#ifndef Thread_IMutex_h
#define Thread_IMutex_h

namespace Thread {

class IMutex {
public:
    virtual ~IMutex() { }

 public:
    virtual void lock()  = 0;
    virtual void try_lock()  = 0;
    virtual void unlock()  = 0;
};

}

#endif // Thread_IMutex_h
