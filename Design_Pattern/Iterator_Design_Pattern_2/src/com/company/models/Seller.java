package com.company.models;

public class Seller {
    GeekyStoreCatalog geekyStoreCatalog;
    DevStoreCatalog devStoreCatalog;
    public Seller(GeekyStoreCatalog geekyStoreCatalog,DevStoreCatalog devStoreCatalog) {
        this.geekyStoreCatalog = geekyStoreCatalog;
        this.devStoreCatalog = devStoreCatalog;
    }

    public void printCatalog(){
        GeekyStoreIterator geekyStoreIterator = geekyStoreCatalog.createIterator();
        DevStoreIterator devStoreIterator = devStoreCatalog.createIterator();
        System.out.println("Printing Geeky Catalog.....");
        printCatalog(geekyStoreIterator);

        System.out.println("\nPrinting Dev Catalog------");
        printCatalog(devStoreIterator );
    }

    private void printCatalog(GeekyStoreIterator iterator){
        while(iterator.hasnext()){
            Product product = (Product)iterator.next();
            System.out.print(product.getName()+" ");
            System.out.print(product.getDescription()+" ");
            System.out.println(product.getPrice());
        }
    }

    private void printCatalog(DevStoreIterator iterator){
        while(iterator.hasnext()){
            Product product = (Product)iterator.next();
            System.out.print(product.getName()+" ");
            System.out.print(product.getDescription()+" ");
            System.out.println(product.getPrice());
        }
    }
}
