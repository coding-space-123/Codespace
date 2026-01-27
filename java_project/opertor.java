// operator in java....
// operators are used to operate or perform operators on variables and values .
//types of operator 
//1. arithmetic operator --> + , - , * , / , %
//2. assignment operator --> = , += , -= , *= , /= , %=
//3. comparison operator --> == , != , > , < , >= , <=
//4. logical operator --> && , || , !
//5. bitwise operator ->> & , | , ^ , ~ , << , >>
// works on bits


// arithmetic operator can not work on booleans 
// % operator can work on float and doubles .

// precedence of operator  : the operators are applied and evaluated 
// based on precedence . 
// eg. (+,-) . hence * & / are evaluated first then + and - are evaluated .




public class opertor {
    public static void main(String[] args) {
        int a=4;
        int x=2;
        int b= 6+ a;
        int c= 6 % a;  //modulo op.
        System.out.println(b);  // 10
        System.out.println(c);  // 2
        System.out.println(a==b); // false
        System.out.println(x==c); //true
        System.out.println( (a>b) && (a<c) ); // false && true --> false
        System.out.println(a>b || b >c );
        System.out.println(2 & 3);
        // 10
        // 11
        // and : 10 = 2
}
}

