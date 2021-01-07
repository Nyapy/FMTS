import java.util.Arrays;

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
		//에러 System.out.println(0101 && 0101);
		int s1 = 10;
		int s2 = 10;
		System.out.println(s1==s2);
		
		int a = 2;
		int b = 5;
		int c = a|b;
		int d = a&b;
		int e = a^b;
		int i, j;
		i = a <<2 ;
		j = b >> 2;
		System.out.println("a = "+ a);
		System.out.println("b = "+ b);
		System.out.println("a|b = " + c);
		System.out.println("a&b= " + d);
		System.out.println("a ^ b = " + e);
		System.out.println("a << 2 = " + i);
		System.out.println("b >> 2 = " + j );
				
		System.out.println("-2 >> 2 = " + (-5>>2) );
		String a1 = "aaa";
		String a2 = "aaa";
		if (a1==a2) {
			System.out.println("저거 두개 같음");
		}
		else {
			System.out.println("아냐 다름");
		}
		
		int scoreList[] ;
		scoreList = new int[10];
		
		scoreList[0] = 100;
		scoreList[1] = 80;
		scoreList[2] = 90;
		scoreList[3] = 70;
		scoreList[4] = 85;
		System.out.println(scoreList.length);
		System.out.println(scoreList[9]);
		
		int AA[] = {45, 10, 80, 100, 60};
		System.out.println(AA[3]);
		
		int[][] ABC = {{1,2,3}, {2,4}, {3,5,5,5}};
		System.out.println(Arrays.deepToString(ABC));
	}

}
