
public class day210104 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int count = 1;
		int total1 = ++count;
		int total2 = count++;
		System.out.println(total1);
		System.out.println(total2);
		System.out.println(count);
		
		int num1 = 3;
		int num2 = 20;
		int num3,num4,num5,num6,num7;
		num3 = num2+num1;
		num4 = num2 -num1;
		num5 = num2 *num1;
		num6 = num2 /num1;
		num7 = num2 % num1;
		System.out.println("20+3 = " +num3);
		System.out.println("20-3 = " +num4);
		System.out.println("20*3 = " +num5);
		System.out.println("20/3 = " +num6);
		System.out.println("20%3 = " +num7);
		
		System.out.println(0x11 & 0x10);
		System.out.println(0011 & 1010);
		System.out.println(0010);
		//¿¡·¯ System.out.println(0101 && 0101);
				
	}

}
