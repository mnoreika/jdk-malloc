
class Example1 {
    public static void main(String[] args) {
        String a = (String) Runtime.alloc(String.class);
        Runtime.free(a);
    }
}

