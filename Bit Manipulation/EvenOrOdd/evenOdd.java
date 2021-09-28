class EvenOddJava {

    static boolean Even(int x) {

        if ((x ^ 1) == x + 1)
            return true;
        else
            return false;
    }

    public static void main(String[] args) {
        int n = 100;
        System.out.print(Even(n) == true ? "Even" : "Odd");
    }
}