
class Example3 {
    public static void main(String[] args) {
        int[] arr1 = Runtime.allocIntArray(2);
        double[] arr2 = Runtime.allocDoubleArray(2);

        arr1[0] = 10;
        arr1[1] = 20;
        arr2[0] = -5.0;
        arr2[1] = 12.0;

        double sum = arr1[0] + arr1[1] + arr2[0] + arr2[1];
        System.out.println(sum);

        Runtime.free(arr1);
        Runtime.free(arr2);
    }
}