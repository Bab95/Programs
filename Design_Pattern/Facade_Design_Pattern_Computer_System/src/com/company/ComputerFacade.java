package com.company;

public class ComputerFacade {
    private CPU processor;
    private Memory ram;
    private HardDrive hdd;

    public ComputerFacade(CPU processor, Memory ram, HardDrive hdd) {
        this.processor = processor;
        this.ram = ram;
        this.hdd = hdd;
    }
    public void start(){
        processor.freeze();
        ram.load(132,hdd.read(3456,89));
        processor.jump(132);
        processor.execute();
    }
}
