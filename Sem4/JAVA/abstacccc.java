abstract class shape { //It is a class that cannot have it's own objects.
	public int x,y;
	public abstract void printArea();
}

class rectangle extends shape
{
	public void printArea()
	{
		System.out.println("The area is: "+x*y);
	}
}


class triangle extends shape
{
	public void printArea()
	{
		System.out.println("The area is: "+(x*y)/2);
	}
}


class circle extends shape
{
	public void printArea()
	{
		System.out.println("The area is: "+3.14*x*x);
	}
}


public class abstacccc {

	public static void main(String[] args) {
		rectangle r = new rectangle();
		r.x = 10;
		r.y = 20;
		r.printArea();
		System.out.println("-------------------------------------");
		triangle t = new triangle();
		t.x = 30;
		t.y = 35;
		t.printArea();
		System.out.println("-------------------------------------");
		circle c = new circle();
		c.x = 2;
		c.printArea();
		System.out.println("-------------------------------------");

	}

}
