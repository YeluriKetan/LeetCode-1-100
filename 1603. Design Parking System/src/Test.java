public class Test {
    public static void main(String[] args) {
        ParkingSystem park = new ParkingSystem(1,1,0);
        System.out.println(park.addCar(1));
        System.out.println(park.addCar(1));
        System.out.println(park.addCar(2));
        System.out.println(park.addCar(3));
    }
}
