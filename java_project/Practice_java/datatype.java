// b -> byte  .
// s -> short .
// i -> integer. 
// l -> long 
// f -> float 
// d -> double 
// c -> char

// b + s -> int 
// s + i -> int 
// l + f -> float
// c + i -> int 
// c + s -> int 
// l + d -> double
// f + d -> double

import java.util.Scanner;
public class datatype {
    public static void main (String[] args) {
        byte x = 5;
        int y = 6;
        short z = 8;
        int a = y + z;
        float b = 6.54f + x;
        System.out.println("output:");
        System.out.println(b);
        System.out.println(x);
        System.out.println(y);
        System.out.println(a);
        System.out.println(z);

        //increment and decrement operator 
    int i = 16;
    System.out.println(i++);
    System.out.println(++i);
    // quiz 
    int xx= 7;
    System.out.println("value = " + ++xx * 8);
    char ch = 'a';
    System.out.println("value = " + ++ch);
    System.out.println("value = " + ch++);
    System.out.println(6 > xx);
    System.out.println(2 > i);
    // set 2 
    Scanner sc = new Scanner (System.in);
    System.out.println("enter value :");
    int p = sc.nextInt();






    
    System.out.println(p > 3);
    }
}

/*
output:
11.54
5
6
14
8
16
18
value = 64
value = b
value = b
false
false
enter value :
56
true
*/



