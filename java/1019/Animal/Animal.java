class AnimalClass {
  enum AnimalType { dog, cat, horse, chicken, pig };
  AnimalType type;
}

public class Animal {
  public static void main(String[] args) {
    AnimalClass newAnimal = new AnimalClass();
    newAnimal.type= AnimalClass.AnimalType.dog;
    System.out.println("new animal is " + newAnimal.type);
  }
}
