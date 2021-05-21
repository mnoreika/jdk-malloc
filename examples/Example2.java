
class Example2 {
    class Foo {
        int a;
    }

    public static void main(String[] args) {
        Foo[] objs = (Foo[]) Runtime.allocObjArray(Foo.class, 10);
        Foo obj = (Foo) Runtime.alloc(Foo.class);

        obj.a = 42;
        objs[5] = obj;
        System.out.println(objs[5].a);

        Runtime.free(obj);
        Runtime.free(objs);
    }
}