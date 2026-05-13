// associativity : left to right or right to left 
// precedence : plus has more precednec than minus operator


public class associativity
{
    public static void main(String[] args){
        int a = 6*5-34/2;
        /*
        highest precedence goes to * and / .
        they are evaluated on the basis of left to right associativity
        =30-34/2
        =30-17
        =13
        */
       System.out.println("a = " +  a);
    }
}