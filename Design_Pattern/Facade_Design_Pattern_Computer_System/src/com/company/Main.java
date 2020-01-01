package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        CPU cpu = new CPU();
        Memory memory = new Memory();
        HardDrive hdd = new HardDrive();
        ComputerFacade computer = new ComputerFacade(cpu,memory,hdd);
        computer.start();
    }
}
