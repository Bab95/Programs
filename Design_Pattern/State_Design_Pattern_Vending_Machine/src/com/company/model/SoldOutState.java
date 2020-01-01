package com.company.model;

public class SoldOutState implements State {
    SodaVendingMachine sodaVendingMachine;

    public SoldOutState(SodaVendingMachine sodaVendingMachine) {
        this.sodaVendingMachine = sodaVendingMachine;
    }

    @Override
    public void insertMoney() {
        System.out.println("Machine sold out");
    }

    @Override
    public void ejectMoney() {
        System.out.println("Insert Money first before ejecting");
    }

    @Override
    public void select() {
        System.out.println("No soda Available");
    }

    @Override
    public void dispense() {
        System.out.println("No soda available");
    }

    @Override
    public String toString() {
        return "Sold Out!";
    }
}
