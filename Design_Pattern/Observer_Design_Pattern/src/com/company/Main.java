package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Subject subject = new Subject();
        new HexaObserver(subject);
        new OctalObserver(subject);
        new BinaryObserver(subject);
        System.out.println("First state change: 15");
        subject.setState(15);
        System.out.println("Second State change");
        subject.setState(10);

    }
}
