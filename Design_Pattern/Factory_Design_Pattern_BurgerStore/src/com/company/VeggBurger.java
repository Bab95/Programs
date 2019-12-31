package com.company;

public class VeggBurger implements Burger {
    @Override
    public void cook() {
        System.out.println("Cooking Veggie Burger");
    }

    @Override
    public void prepare() {
        System.out.println("Preparing Veggie Burger");
    }

    @Override
    public void box() {
        System.out.println("Boxing Veggie Burger");
    }
}
