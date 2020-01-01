package com.company;

public class StartState implements state {
    @Override
    public void doAction(Context context) {
        System.out.println("Player is in start state");
        context.setState(this);
    }
    public String toString(){
        return "Start_State";
    }
}
