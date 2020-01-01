package com.company.model;

public class SodaVendingMachine {
    State soldOutState;
    State noMoneyState;
    State soldState;
    State hasMoneyState;

    State state = soldOutState;
    int count = 0;
    public SodaVendingMachine(int noOfSodas){
        this.count = noOfSodas;
        soldOutState = new SoldOutState(this);
        noMoneyState = new NoMoneyState(this);
        soldState = new SoldState(this);
        hasMoneyState = new HasMoneyState(this);

        if(noOfSodas>0){
            state = noMoneyState; //if more than 0 sodas we set the state to no money state....
        }
    }

    //Actions
    public void insertMoney(){
        state.insertMoney();
    }

    public void ejectMoney(){
        state.ejectMoney();
    }

    public void selectSoda(){
        state.select();
    }

    public void dispense(){
        state.dispense();
    }

    public int getCount(){
        return this.count;
    }

    public void setSoldOutState(State soldOutState) {
        this.soldOutState = soldOutState;
    }

    public void setNoMoneyState(State noMoneyState) {
        this.noMoneyState = noMoneyState;
    }

    public void setSoldState(State soldState) {
        this.soldState = soldState;
    }

    public void setHasMoneyState(State hasMoneyState) {
        this.hasMoneyState = hasMoneyState;
    }

    public void setState(State state) {
        this.state = state;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public State getSoldOutState() {
        return soldOutState;
    }

    public State getNoMoneyState() {
        return noMoneyState;
    }

    public State getSoldState() {
        return soldState;
    }

    public State getHasMoneyState() {
        return hasMoneyState;
    }

    public State getState() {
        return state;
    }

    @Override
    public String toString() {
        StringBuffer result = new StringBuffer();
        result.append("\nThe SodaMachine Co.");
        result.append("\nInventory Count "+count+"soda");
        if(count!=1){
            result.append("s");
        }
        result.append("\n");
        result.append("Soda Vending Machine is "+state+"\n");
        return result.toString();
    }
}
