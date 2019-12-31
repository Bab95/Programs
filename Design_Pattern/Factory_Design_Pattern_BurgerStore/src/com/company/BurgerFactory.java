package com.company;

public class BurgerFactory {
    public Burger getBurger(String type){
        if(type==null){
            return null;
        }else if(type.equalsIgnoreCase("Cheese")) {
            return new CheeseBurger();
        }else if(type.equalsIgnoreCase("Veggie")){
            return new VeggBurger();
        }else if(type.equalsIgnoreCase("McAloo")){
            return new McAloo();
        }
        return null;
    }
}
