package com.company;

import com.company.models.DevStoreCatalog;
import com.company.models.GeekyStoreCatalog;
import com.company.models.Product;
import com.company.models.Seller;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here
        DevStoreCatalog devStoreCatalog = new DevStoreCatalog();
        //Product[] devCatalog = devStoreCatalog.getCatalog();

        GeekyStoreCatalog geekyStoreCatalog = new GeekyStoreCatalog();
        //ArrayList<Product> geekyCatalog = geekyStoreCatalog.getCatalog();

        /*for(int i=0;i<devCatalog.length;i++){
            Product product = devCatalog[i];
            System.out.print(product.getName()+" ");
            System.out.print(product.getDescription()+" ");
            System.out.println(product.getPrice());

        }
        System.out.println("----------------");

        for(int i=0;i<geekyCatalog.size();i++){
            Product product = (Product)geekyCatalog.get(i);
            System.out.print(product.getName()+" ");
            System.out.print(product.getDescription()+" ");
            System.out.println(product.getPrice());

        }*/

        Seller seller = new Seller(geekyStoreCatalog,devStoreCatalog);
        seller.printCatalog();
    }
}
