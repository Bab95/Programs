package interfaces;

public class ShapeFactory {
    public Shape getshape(String shape){
        if(shape==null){
            return null;
        }else if(shape.equalsIgnoreCase("CIRCLE")){
            return new Circle();
        }else if(shape.equalsIgnoreCase("SQUARE")){
            return new Square();
        }else if(shape.equalsIgnoreCase("TRIANGLE")){
            return new Triangle();
        }
        return null;
    }
}
