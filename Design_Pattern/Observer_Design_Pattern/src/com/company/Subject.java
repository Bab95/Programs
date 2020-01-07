package com.company;

import java.util.ArrayList;
import java.util.List;

public class Subject {
    protected List<Observer> observers = new ArrayList<Observer>();
    private int state;
    public void attach(Observer observer){
        this.observers.add(observer);
    }
    public void setState(int state) {
        this.state = state;
        notifyAllObserver();
    }
    public int getState() {
        return state;
    }
    public void notifyAllObserver(){
        for(Observer observer:observers){
            observer.update();
        }
    }
}
