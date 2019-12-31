package com.company;

public class McAloo implements Burger {
    @Override
    public void cook() {
        System.out.println("Cooking McAloo Burger");
    }

    @Override
    public void prepare() {
        System.out.println("Preparing McAloo Burger");
    }

    @Override
    public void box() {
        System.out.println("Bosing McAloo Burger");
    }
}
