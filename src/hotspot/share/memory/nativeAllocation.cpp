#include "memory/nativeAllocation.hpp"

void NativeAllocator::free(oop p) {
  std::free(p);
  return;

  // ObjectStack stack;
  // FreeOopClosure cl = FreeOopClosure(&stack);

  // stack.push(p);

  // while(!stack.is_empty()) {
  //   oop obj = stack.pop();

  //   if (obj != NULL) {
  //     obj->print();
  //     obj->oop_iterate(&cl);

  //     if (!obj->is_array()) {
  //         std::free(obj);
  //     }
  //   }
  // }
}

template <class T>
void FreeOopClosure::do_oop_work(T* p) {
    T o = RawAccess<>::oop_load(p);
    oop obj = (oop) o;

    _stack->push(obj);
}
