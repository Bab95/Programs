package com.company;
import interfaces.Shape;
import interfaces.ShapeFactory;

public class Main {

    public static void main(String[] args) {
	// write your code here
        ShapeFactory shapeFacory = new ShapeFactory();
        Shape shape = shapeFacory.getshape("circle");
        shape.draw();
        shape = null;
        shape = shapeFacory.getshape("triangle");
        shape.draw();
        shape = null;
        shape = shapeFacory.getshape("square");
        shape.draw();
        shape = null;
    }
}
