package com.company.Models;

import com.company.Interfaces.AbstractFactory;
import com.company.Interfaces.Shape;

public class ShapeFactory extends AbstractFactory {
    @Override
    public Shape getShape(String shapeType){
        if(shapeType==null) {
            return null;
        }else if(shapeType.equalsIgnoreCase("rectangle")){
            return new Rectangle();
        }else if(shapeType.equalsIgnoreCase("square")){
            return new Square();
        }
        return null;
    }
}
