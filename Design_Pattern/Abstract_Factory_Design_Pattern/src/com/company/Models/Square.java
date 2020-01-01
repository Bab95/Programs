package com.company.Models;

import com.company.Interfaces.Shape;

public class Square implements Shape {
    @Override
    public void draw() {
        System.out.println("Drawing Square");
    }
}
