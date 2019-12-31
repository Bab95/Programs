package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        /*BurgerFactory burgerFactory = new BurgerFactory();
        Burger cheeseBurger =  burgerFactory.getBurger("cheese");
        cheeseBurger.prepare();
        cheeseBurger.cook();
        cheeseBurger.box();

        Burger burger = burgerFactory.getBurger("Veggie");
        burger.prepare();
        burger.cook();
        burger.box();*/
        BurgerFactory factory = new BurgerFactory();
        BurgerStore store = new BurgerStore(factory);
        Burger burger = store.OrderBugrger("cheese");
        burger = store.OrderBugrger("McAloo");
        burger = store.OrderBugrger("Veggie");
    }
}
