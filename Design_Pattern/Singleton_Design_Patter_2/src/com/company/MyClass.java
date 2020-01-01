package com.company;

public class MyClass {
    String name;
    private static MyClass uniqueInstance = new MyClass();
    private MyClass(){

    }
    public static /*synchronized*/ MyClass getInstance(){
        //Synchronized keyword makes our singleton thread safe.....
        /*if(uniqueInstance==null){
            uniqueInstance = new MyClass();
        }*/
        return uniqueInstance;
    }
}
