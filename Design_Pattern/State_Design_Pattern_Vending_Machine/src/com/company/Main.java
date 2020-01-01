package com.company;

import com.company.model.SodaVendingMachine;

public class Main {

    public static void main(String[] args) {
	// write your code here
        SodaVendingMachine sodaVendingMachine = new SodaVendingMachine(10);
        System.out.println(sodaVendingMachine);
        sodaVendingMachine.insertMoney();
        sodaVendingMachine.selectSoda();

        System.out.println(sodaVendingMachine);

        sodaVendingMachine.insertMoney();
        sodaVendingMachine.selectSoda();

        sodaVendingMachine.insertMoney();
        sodaVendingMachine.selectSoda();
        System.out.println(sodaVendingMachine);
    }
}
