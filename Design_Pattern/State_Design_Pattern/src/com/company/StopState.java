package com.company;

public class StopState implements state {
    @Override
    public void doAction(Context context) {
        System.out.println("Player is in Stop State");
        context.setState(this);
    }

    @Override
    public String toString() {
        return "Stop_State";
    }
}
