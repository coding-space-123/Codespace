// lecture 1 : Introduction to Java Programming Language
// lecture 1 to 3

class Hello {
    // This is the main method, which is the entry point of the Java application.{
    public static void main(String[] args) {
        System.out.println("Java is ready.");
    }
}
// This is a simple Java program that prints a message to the console.
// It serves as a basic example of how to write and run a Java application.
// To run this program, save it in a file named Hello.java and use the command:
// javac Hello.java to compile it, followed by java Hello to execute it.
// The output will be: Java is ready.
// This code is a part of a larger project that demonstrates basic Java syntax
// and structure.
// It is intended for educational purposes to help beginners understand how to
// set up and run a Java

// Anatomy of java program
// 1. Class Declaration: The program starts with the declaration of a class
// named Hello.
// 2. Main Method: Inside the class, there is a main method which is the entry
// point of the application.
// 3. Print Statement: The main method contains a print statement that outputs
// text to the console.
// 4. Comments: The program includes comments that explain various parts of the
// code.
// 5. Execution Instructions: Instructions are provided on how to compile and
// run the program.
// 6. Output: The expected output of the program is also mentioned in the
// comments. application.

// documentation :
// This program is documented with comments to explain its purpose and
// functionality. ----> suggested documentation style.

// package declaration :
// In this example, there is no package declaration. However, in larger
// projects, classes are often organized into packages. ----> optional package
// declaration style.

// import statements : --->optional import statements style.

// interface statement : --->optional interface statement style.

// class defination : ---->optional class definition style.

// Main method Class. --->eseential part of java program.
// {
// Main method Definition
// }

// Naming Conventions in Java:
// 1. Class Names: Should be in PascalCase.
// Example: HelloWorld, MyFirstClass
// 2. Method Names /function names: Should be in camelCase.
// Example: printMessage(), calculateSum()
// 3. Variable Names: Should also be in camelCase.
// Example: userName, totalAmount
// 4. Constants: Should be in UPPER_SNAKE_CASE.
// Example: MAX_VALUE, DEFAULT_TIMEOUT
// Examples:
// HelloWorld ----> pascal naming convention.
// printMessage ----> camel naming convention.
// userName ----> camel naming convention.
// MAX_VALUE ----> upper snake naming convention.

// package com.example.helloworld;
// import java.util.Scanner;

// variables. --> contain data values used in the program.
// rules for declaring variables:
// 1. A variable name must start with a letter (A-Z or a-z), dollar sign ($), or
// underscore (_).
// whitespace not allowed.
// not start with digit.

// 2. Subsequent characters can be letters, digits (0-9), dollar signs, or
// underscores.
// 3. Variable names are case-sensitive (e.g., myVar and myvar are different).
// 4. Variable names cannot be a Java keyword (e.g., int, class, public).
// 5. Variable names should be meaningful and descriptive of the data they hold.
// Examples of valid variable names:
// int userAge;
// String userName;
// double accountBalance;
// boolean isActive;

// data types. --> specify the type of data a variable can hold, such as int,
// String, boolean, etc.
// 1. primitives data types : int , char ,boolean ,float ,double ,byte ,short
// ,long
// byte: 1 byte. ---> 8 bits , range: -128 to 127. i.e -2^7 to 2^7-1. ---->
// (2^8)/2 to (2^8)/2-1, default value: 0
// short: 2 bytes. ---> 16 bits , range: -32,768 to 32,767. i.e -2^15 to 2^15-1
// , default value: 0
// byte and short are mainly used to save memory in large arrays where the
// memory savings is significant.
// They can also be used to represent raw binary data or to work with low-level
// data structures.

// int: 4 bytes ---> 32 bits , range: -2,147,483,648 to 2,147,483,647. i.e -2^31
// to 2^31-1 , default value: 0
// int is the most commonly used data type for integer values in Java. It is
// used for
// arithmetic operations, loops, array indexing, and general-purpose counting.

// long: 8 bytes ---> 64 bits , range: -9,223,372,036,854,775,808 to
// 9,223,372,036,854,775,807. i.e -2^63 to 2^63-1 , default value: 0L
// long is used when a wider range than int is needed. It is often used for
// large

// float: 4 bytes. ---> 32 bits , range: approximately ±3.40282347E+38F (6-7
// significant decimal digits) , default value: 0.0f
// float is used for saving memory in large arrays of floating-point numbers.

// double: 8 bytes. ---> 64 bits , range: approximately
// ±1.79769313486231570E+308 (15 significant decimal digits) , default value:
// 0.0d
// double is the default data type for decimal values in Java. It is used for
// high-precision calculations, scientific computations, and when a wider range
// is needed.

// char: 2 bytes ---> 16 bits , range: 0 to 65,535 (unsigned) , default value:
// '\u0000' because it uses Unicode ,
// char is used to store single characters, such as letters, digits, and
// symbols.

// boolean: 1 bit (true or false) ---> default value: false
// size depend on JVM implementation.
// boolean is used for simple flags that track true/false conditions.

// 2. non-primitives data types (derived from primitives data types): String ,
// Arrays , Classes , Interfaces
