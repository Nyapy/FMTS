package javaStudy;

public class day210110 {
	
	public class Car{
		String name;
		int currentGear;
		final static int AA =5;
		static final int AB =5;
		
		public int sum() {
			int a;
			a = 3;
			return a ;
		};
		public int sum(int num1, int num2){
		    System.out.println(num1+num2);
		    return num1 + num2;
		}

		
		void changeGear(int gear) {
			System.out.println("기어를 " + gear + "단으로 변경");
			currentGear = gear;
		}
		
		String getCurrentState() {
			return name + "의 현재 기어 : " + currentGear;
		}
	}
	public class Taxi extends Car{
		int fare;
		boolean passengerYn;
	}
	
	
	public static void main(String[] args) {
		
		class AA {
			int ia = 1;
		}
		
		class AB extends AA{
			int j = 2;
		}
		
		AB name = new AB();
		
		System.out.println(name.ia);
		System.out.println(name.j);
		
		class human{
			String name;
			int age;

			public human(String name, int age){
			    this.name = name;
			    this.age = age;
			}
		}
		
		human OSB = new human("오세봉", 28);
		
		System.out.println(OSB.name);
		System.out.println(OSB);

	}

}
