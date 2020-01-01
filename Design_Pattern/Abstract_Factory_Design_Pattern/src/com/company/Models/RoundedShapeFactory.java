package com.company.Models;

import com.company.Interfaces.AbstractFactory;
import com.company.Interfaces.Shape;

public class RoundedShapeFactory extends AbstractFactory {
    @Override
    public Shape getShape(String shapeType) {
        if(shapeType==null){
            return null;
        }else if(shapeType.equalsIgnoreCase("rectangle")){
            return new roundedRectangle();
        }else if(shapeType.equalsIgnoreCase("square")){
            return new roundedSquare();
        }
        return null;
    }
}
