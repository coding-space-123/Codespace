class String6 {
    public static void main(String args[]) {
        String s = "  Java Programming  ";
        String s1 = "";
        String s2 = "   ";

        System.out.println("Original String : '" + s + "'");

        System.out.println("Uppercase : " + s.toUpperCase());

        System.out.println("Lowercase : " + s.toLowerCase());

        System.out.println("After trim() : '" + s.trim() + "'");

        System.out.println("isEmpty() on s1 : " + s1.isEmpty());

        System.out.println("isBlank() on s2 : " + s2.isBlank());
    }






}