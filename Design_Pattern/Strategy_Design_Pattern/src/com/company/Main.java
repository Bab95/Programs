package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Context context = new Context(new addOPeration());
        int num1 = 34;
        int num2 = 2;
        System.out.println(context.executeStrategy(num1,num2));
        context = null;
        context = new Context(new subtractOperation());
        System.out.println(context.executeStrategy(num1,num2));
        context = null;
        context = new Context(new multiplyOperation());
        System.out.println(context.executeStrategy(num1,num2));

    }
}
