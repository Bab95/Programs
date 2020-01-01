package com.company;

public class CPU {
    public void freeze(){
        System.out.println("Computer Freezing");
    }
    public void execute(){
        System.out.println("Executing the commands");
    }
    public void jump(long position){
        System.out.println("Jumping to the position..."+position);
    }
}
