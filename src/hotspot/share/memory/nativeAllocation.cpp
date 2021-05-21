#include "memory/nativeAllocation.hpp"

void NativeAllocator::free(oop p) {
  std::free(p);
  return;
}

template <class T>
void FreeOopClosure::do_oop_work(T* p) {
    T o = RawAccess<>::oop_load(p);
    oop obj = (oop) o;

    _stack->push(obj);
}
