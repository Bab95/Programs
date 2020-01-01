package com.company;

public class SingleObject {
    private static SingleObject instance = new SingleObject();
    private SingleObject(){
        System.out.println("singleObject Class Constructor");
    }
    public void showMsg(){
        System.out.println("Hello Speaking from Single Object Class");
    }
    public static SingleObject getInstance(){
        return instance;
    }
}
