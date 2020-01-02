package com.company;

import java.security.spec.NamedParameterSpec;

public class Main {

    public static void main(String[] args) {
	// write your code here
        NameRepository repository = new NameRepository();
        for(Iterator itr=repository.getIterator();itr.hasnext();){
            String name = (String)itr.next();
            System.out.println("Name is: "+name);
        }
    }
}
