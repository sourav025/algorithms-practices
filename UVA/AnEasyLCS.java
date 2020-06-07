import java.io.*;
import java.util.*;

public class AnEasyLCS{
	public static void main(String... args) throws Exception{
		BufferedReader inp=new BufferedReader(new InputStreamReader(System.in));
		
		int t=Integer.parseInt(inp.readLine().trim());
		for(int cas=1;cas<=t;cas++){
			inp.readLine();
			String str1=inp.readLine().trim();
			String str2=inp.readLine().trim();
			
			Solution ob=new Solution(str1,str2);
			
			System.out.print("Case "+cas+": ");
			
			if(ob.lcs(str1.length()-1,str2.length()-1)>0){
				System.out.println(ob.getRes());
			}
			else System.out.println(":(");
			
		}		
	}
}


class Solution{
	private String str1,str2;
	static String res[][];
	static int dp[][];
	static{
		res=new String[110][110];
		dp=new int[110][110];
	}
	Solution(String s1,String s2){
		str1=s1;str2=s2;
		
		for(int i=0;i<110;i++){
			Arrays.fill(dp[i],-1);
			Arrays.fill(res[i],"");
		}
	}
	
	public String getRes(){
		return res[str1.length()-1][str2.length()-1];
	}
	
	int lcs(int l1,int l2)
	{
		if(l1<0||l2<0)
			return 0;
		
		if(dp[l1][l2] != -1)
			return dp[l1][l2];
		
		if(str1.charAt(l1)==str2.charAt(l2)){
			dp[l1][l2]=1+lcs(l1-1,l2-1);
			
			if( l1>0 && l2>0 ){
				res[l1][l2]=res[l1-1][l2-1];
			}
			res[l1][l2]+=str1.charAt(l1);
			return dp[l1][l2];
		}
		int a=lcs(l1-1,l2);
		int b=lcs(l1,l2-1);
		
		if(a==b){
			if(l1>0&&l2>0){
				
				if(res[l1-1][l2].compareTo(res[l1][l2-1])<0)
					res[l1][l2]=res[l1-1][l2];
				else
					res[l1][l2]=res[l1][l2-1];
			}
		}
		else if(a>b)
			res[l1][l2]=res[l1-1][l2];
		else if(a<b)
			res[l1][l2]=res[l1][l2-1];
		
		dp[l1][l2]=a;
		if(dp[l1][l2]<b) dp[l1][l2]=b;
		
		return dp[l1][l2];
	}
	
}
/*

3

ab
ba

zxcvbn
hjgasbznxbzmx

you
kjhs
*/