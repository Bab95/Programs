package com.company;

public class Context {
    private state State;
    public Context(){
        State = null;
    }
    public void setState(state State){
        this.State = State;
    }
    public state getState(){
        return this.State;
    }
}
