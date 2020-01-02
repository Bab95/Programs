package com.company.models;

import com.company.Interfaces.Iterator;

public class DevStoreIterator implements Iterator {
    Product[] catalog;
    int index = 0;

    public DevStoreIterator(Product[] products){
        this.catalog = products;
    }

    @Override
    public boolean hasnext() {
        if(index>=catalog.length||catalog[index]==null){
            return false;
        }
        return true;
    }

    @Override
    public Object next() {
        if(this.hasnext()){
            Product product = catalog[index];
            index++;
            return product;
        }
        return null;
    }
}
