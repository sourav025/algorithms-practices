import java.io.*;
import java.util.*;

public class SpecialMenu{	
	
	static int T;
	static long dp[][];
	static int vis[][],len;
	static String str;
	
	public static void main(String... args) throws Exception {
		T=1;
		
		dp=new long[65][65];
		vis=new int[65][65];
		
		BufferedReader inp=new BufferedReader(new InputStreamReader(System.in));
		int t=Integer.parseInt(inp.readLine().trim());
		for(int cas=1;cas<=t;cas++){
			T++;
			str=inp.readLine().trim();
			len=str.length()-1;
			System.out.println("Case "+cas+": "+back(0,len));
		}
	}
	
	static long back(int l1,int l2){		
		if(l1>l2) return 0;
		if(l1==l2) return 1;
		if(vis[l1][l2]==T) return dp[l1][l2];
		vis[l1][l2]=T;
		dp[l1][l2]=0;
		if(str.charAt(l1)==str.charAt(l2)) dp[l1][l2]+=1+back(l1+1,l2-1);
		dp[l1][l2]+=(back(l1+1,l2)+back(l1,l2-1)-back(l1+1,l2-1));
		return dp[l1][l2];		
	}
}