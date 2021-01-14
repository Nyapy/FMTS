package javaStudy;

public class day210114 {
	

	public static void main(String[] args) {
		
		Employee kim = new Employee("a", 1, 5, "a", "d", "e" );

	}
	
	class Employee{
		String name;
		int number;
		int age;
		String title;
		String dept;
		String grade;
		
		private Employee(String n1, int n2, int a, String t, String d, String g) {
			name = n1;
			number = n2;
			age = a;
			title = t;
			dept = d;
			grade = g;
		}
	}
	

}


