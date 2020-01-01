package com.company;

import com.company.Interfaces.AbstractFactory;
import com.company.Interfaces.Shape;
import com.company.Models.FactoryProducer;

public class Main {

    public static void main(String[] args) {
	// write your code here
        AbstractFactory shapeFactory = FactoryProducer.getFactory(false);
        Shape shape1 = shapeFactory.getShape("rectangle");
        shape1.draw();
        Shape shape2 = shapeFactory.getShape("square");
        shape2.draw();
        AbstractFactory shapeFactoryRounded = FactoryProducer.getFactory(true);
        Shape shape3 = shapeFactoryRounded.getShape("rectangle");
        shape3.draw();
        Shape shape4 = shapeFactoryRounded.getShape("square");
        shape4.draw();

    }
}
