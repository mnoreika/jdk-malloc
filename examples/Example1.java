
class Example1 {
    class Foo {
        int a;
    }

    public static void main(String[] args) {
        Foo obj = (Foo) Runtime.alloc(Foo.class);
        obj.a = 42;
        System.out.println(obj.a);
        Runtime.free(obj);
    }
}