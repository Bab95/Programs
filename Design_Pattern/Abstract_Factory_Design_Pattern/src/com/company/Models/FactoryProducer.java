package com.company.Models;

import com.company.Interfaces.AbstractFactory;

public class FactoryProducer {
    public static AbstractFactory getFactory(boolean rounded){
        if(rounded){
            return new RoundedShapeFactory();
        }else {
            return new ShapeFactory();
        }
    }
}
