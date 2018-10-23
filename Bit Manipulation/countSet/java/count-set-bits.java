public class countSet {
    public static void main(String[] args) {
        int n;
        try{
            n = Integer.parseInt(args[0]);
            System.out.println("Number is : " + n);
            System.out.println("Number of bits = " + Integer.bitCount(n));
        } catch (NumberFormatException e) {
            System.out.println("Given input is not a valid integer.");
            System.exit(1);
        }
    }
}