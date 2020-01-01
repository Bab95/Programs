package com.company.Models;

import com.company.Interfaces.Shape;

public class Rectangle implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Rectangle");
    }
}
