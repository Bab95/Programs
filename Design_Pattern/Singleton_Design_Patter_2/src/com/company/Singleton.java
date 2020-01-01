//Double Checked Locking Method of Creating Singleton Class
package com.company;

public class Singleton {
    //private static Singleton uniqueInstance;
    private volatile static Singleton uniqueInstance;
    String name;
    private Singleton(){

    }
    public static Singleton getInstance(){
        if(uniqueInstance==null){
            synchronized (Singleton.class){
                if(uniqueInstance==null){
                    uniqueInstance = new Singleton();
                }
            }
        }
        return uniqueInstance;
    }
}
