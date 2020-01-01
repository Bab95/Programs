package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        MyClass myClass = MyClass.getInstance();
        myClass.name = "Class";
        System.out.println(myClass);
        MyClass secondclassinstance = MyClass.getInstance();
        System.out.println(secondclassinstance);
        Singleton singleton = Singleton.getInstance();
        System.out.println(singleton);
    }
}
