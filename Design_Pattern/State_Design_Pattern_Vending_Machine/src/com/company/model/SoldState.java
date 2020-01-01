package com.company.model;

public class SoldState implements State {

    SodaVendingMachine sodaVendingMachine;

    public SoldState(SodaVendingMachine sodaVendingMachine) {
        this.sodaVendingMachine = sodaVendingMachine;
    }

    @Override
    public void insertMoney() {
        System.out.println("Give a second... soda coming right up");
    }

    @Override
    public void ejectMoney() {
        System.out.println("sorry!....soda is coming");
    }

    @Override
    public void select() {
        System.out.println("Nope... you can't eject moeny if you already have soda");
    }

    @Override
    public void dispense() {
        System.out.println("Stop trying to get second soda for free!");
        if(sodaVendingMachine.getCount()>0){
            sodaVendingMachine.setState(sodaVendingMachine.noMoneyState);
        }else{
            System.out.println("Sorry out of Sodas....!");
            sodaVendingMachine.setState(sodaVendingMachine.getSoldOutState());
        }
    }

    @Override
    public String toString() {
        return "Dispensing soda....";
    }

}
