package com.company.models;

import java.util.ArrayList;

public class GeekyStoreCatalog {
    private ArrayList<Product> catalog;
    public GeekyStoreCatalog(){
        catalog = new ArrayList<>();
        addItem("SUperMan-Comic","The best in the town",89.95);
        addItem("Batman Comic","Good comic",11.78);
        addItem("Star Wars","Very old and very good",89.45);
        addItem("Jedi-Tshirt","should have it",29.99);

    }
    public void addItem(String name,String description,double price){
        Product product = new Product(name,description,price);
        catalog.add(product);
    }

    /*public ArrayList<Product> getCatalog(){
        return catalog;
    }
    */
    public GeekyStoreIterator createIterator(){
        return new GeekyStoreIterator(catalog);
    }
}
