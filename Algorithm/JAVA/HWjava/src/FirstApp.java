
public class FirstApp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("첫 번째. Hello, World");
		if (true){
			int x = 5;
			
			System.out.println(x);
		}
		int age = 25;
		double avgAge = (double)age;
		System.out.println(avgAge);
		
//		byte b1 = 127;
//		char c1 = '가';
//		int i1;
//		double d1;
//		System.out.println("자동 형변환 결과");
//		i1 = b1;
//		System.out.println("i1 = b1의 형변환 " + i1);
//		i1 = c1;
//		System.out.println("i1 = c1의 형변환 " + i1);
//		d1 = i1;
//		System.out.println("d1 = i1의 형변환 " + d1);
//		
//		int sum = 128;
//		byte data = (byte)sum;
//		System.out.println(data);
		byte b1 = 127;
		char c1;
		int i1 = 128;
		int i2 = 97;
		double d1 = 3.14;
		System.out.println("명시적 형변환 결과");
		b1 = (byte)i1;
// 인트 데이터는 바이트형으로 형변환했을때 바이트는 128을 표현할 수 없으므려 전혀다른값 -128을 저장
		System.out.println("b1 = i1의 형변환 " + b1);
		c1 = (char)i2;
// 97이라는 인트 데이터를 char 형으로 형변환 했을 때 97을 유니코드로 하는 문자인 소문자 a가 c1에 저장
		System.out.println("c1 = i2의 형변환 " + c1);
		i1= (int)d1;
// int double 데이터를 int 데이터로 명시적 형변환하여 3.15 소수점 아래를 제외한 정수 부분만을 i1 변수에 저장
		System.out.println("d1 = i1의 형변환 " + i1);
		
	
		
	}

}
