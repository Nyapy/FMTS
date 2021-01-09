package javaStudy;

public class day210109 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int s = 4;
		/*
		 * for (int i = s; i <10 ; i ++) { System.out.println(i); }
		 */
		
		outer : for (int i = 0; i <4; i ++ ) {
			for (int j = 0; j <3; j++) {
				if (i == 2) break outer;
				System.out.println("i= " + i + " j = " + j);
			}
		
		}
		
		System.out.println("메인 메서드 스타트 ㄱㄱ");
		name();
		System.out.println("메인 메서드 끝 ㄱㄱ");
		
		int[] scoreList = {10,20,50,71,5,17,98};
		double avgScore = calcAvg(scoreList);
		System.out.println("평균점수 :" + avgScore);
	}
	
	private static void name() {
		System.out.println("name 메서드 start...");
		for (int i = 0; i <5; i++) {
			if(i == 3) {
				return;
			}
			System.out.println(i);
		}
	}
	
	private static double calcAvg(int[] scoreList) {
		
		int sum = 0;
		for (int i= 0; i< scoreList.length; i++) {
			sum = sum + scoreList[i];
			System.out.println(i);
		}
		return (double)sum/scoreList.length;
	}

}
