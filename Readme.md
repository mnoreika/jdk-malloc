
JDK 15 Hotspot VM Malloc Interface
===================

Modified HotSpot VM 15 to support manual memory management outside of the garbage collected heap. The goal of this project is to enable novel compile-time memory management strategies for JVM languages.

### Features

Supports allocation/deallocation of:

* objects
* object arrays
* primitive int arrays
* primitive double arrays  

Objects are allocated using malloc.

### Limitations 

* Compatible only with EpsilonGC
* No support for pointer compression 

## Usage 

* Build the JVM (for instructions see [building.md](doc/.buildingmd)) 
* Compile source with javac
    ```
    .../jdk/bin/javac Source.java
    ```
* Run with command:
    ```
    .../jdk/bin/java -XX:+UnlockExperimentalVMOptions -XX:+UseEpsilonGC -XX:-UseCompressedOops -XX:-UseCompressedClassPointers Source
    ```

## API


```
/**
 * Allocates object in native memory.
 * @param clazz Class of the object to be allocated.
 * @return an allocated uninitialised object.
 */
public native static Object alloc(Class<?> clazz);

/**
 * Allocates object array in native memory.
 * @param clazz Class of the object array to be allocated.
 * @param length The length of the array.
 * @return an allocated object array.
 */
public native static Object[] allocObjArray(Class<?> clazz, int length);

/**
 * Allocates primitive int array in native memory.
 * @param length The length of the array.
 * @return an allocated primitive array.
 */
public native static int[] allocIntArray(int length);

/**
 * Allocates primitive double array in native memory.
 * @param length The length of the array.
 * @return an allocated primitive array.
 */
public native static double[] allocDoubleArray(int length);

/**
 * Frees object allocated in native memory.
 * @param obj object to be freed.
 */
public native static void free(Object obj);

/**
 * Frees object array allocated in native memory.
 * @param objArray object array to be freed.
 */
public native static void freeObjArray(Object[] objArray);
```

## Examples


```
Foo obj = (Foo) Runtime.alloc(Foo.class);
obj.a = 42;
System.out.println(obj.a);
Runtime.free(obj);
```
See [here](examples) for more examples.
