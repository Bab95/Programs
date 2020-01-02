package com.company.models;

public class DevStoreCatalog {
    private static final int MAX_ITEMS = 4;
    private int noProducts = 0;
    Product[] catalog;
    public DevStoreCatalog(){
        catalog = new Product[MAX_ITEMS];
        addItem("C++ is not dead","T-shirt",34.99);
        addItem("Java Sucks!","silky mouse pad",45.99);
        addItem("Java Design Pattern","Book",189.89);
        addItem("WebDev","Cook Book",178.00);
    }
    public void addItem(String name,String description,double price){
        Product product = new Product(name,description,price);
        if(noProducts>=MAX_ITEMS){
            System.out.println("Catalog is full----");
        }else{
            catalog[noProducts] = product;
            noProducts++;
        }
    }

    /*public Product[] getCatalog(){
        return catalog;
    }*/

    public DevStoreIterator createIterator(){
        return new DevStoreIterator(catalog);
    }
}
