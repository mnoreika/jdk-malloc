#include "iterator.inline.hpp"
#include "oops/compressedOops.inline.hpp"
#include <stdlib.h>
#include "logging/log.hpp"
#include "utilities/stack.inline.hpp"
#include <set>

typedef Stack<oop, mtGC> ObjectStack;
typedef std::set<oop> Set;

class FreeOopClosure: public BasicOopIterateClosure {
private:
    ObjectStack* const _stack;

    template <class T>
    void do_oop_work(T* p);

public:
    FreeOopClosure(ObjectStack* stack): _stack(stack) {}
    virtual void do_oop(oop* p) {do_oop_work(p);}
    virtual void do_oop(narrowOop* p) {}
    virtual bool should_verify_oops() { return false; }
};

class NativeAllocator {
public:
    virtual void free(oop p);
};
