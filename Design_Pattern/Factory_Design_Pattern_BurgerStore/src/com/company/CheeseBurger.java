package com.company;

public class CheeseBurger implements Burger {
    @Override
    public void cook() {
        System.out.println("Cooking CheeseBurger");
    }

    @Override
    public void prepare() {
        System.out.println("Preparing CheeseBurger");
    }

    @Override
    public void box() {
        System.out.println("boxing CheeseBurger");
    }
}
