package Java;

public class Point {
    private double x,y;

    public Point (){

    }
    public Point (double x, double y){
        this.x = x;
        this.y = y;
    }

    public void print () {
        System.out.println(this.x);
        System.out.println(this.y);
    }
    public double getX() {
        return x;
    }

    public void setX(double x) {
        this.x = x;
    }

    public double getY() {
        return y;
    }

    public void setY(double y) {
        this.y = y;
    }
}
