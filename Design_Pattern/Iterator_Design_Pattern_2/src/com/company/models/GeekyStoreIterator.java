package com.company.models;

import com.company.Interfaces.Iterator;

import java.util.ArrayList;

public class GeekyStoreIterator implements Iterator {
    ArrayList<Product> catalog;

    public GeekyStoreIterator(ArrayList<Product> catalog) {
        this.catalog = catalog;
    }

    int index;
    @Override
    public boolean hasnext() {
        if(index>=catalog.size()||catalog.get(index)==null){
            return false;

        }
        return true;
    }

    @Override
    public Object next() {
        if(this.hasnext()){
            Product product = catalog.get(index);
            index++;
            return product;
        }
        return null;
    }
}
