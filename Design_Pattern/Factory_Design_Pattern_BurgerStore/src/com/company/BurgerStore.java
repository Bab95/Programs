package com.company;

public class BurgerStore {
    BurgerFactory factory;
    BurgerStore(BurgerFactory factory){
        this.factory = factory;
    }
    public Burger OrderBugrger(String type){
        Burger burger = factory.getBurger(type);
        burger.prepare();
        burger.cook();
        burger.box();
        return burger;
    }
}
