/**
 * @(#)leapYear.java
 *
 *
 * @author 
 * @version 1.00 2012/7/30
 */

import java.math.*;
import java.util.*;
public class leapYear {
	public static void main (String[] args) {
		BigInteger a=new BigInteger("4");
		BigInteger b=new BigInteger("100");
		BigInteger c=new BigInteger("400");
		BigInteger d=new BigInteger("15");
		BigInteger e=new BigInteger("55");
		BigInteger f=new BigInteger("0");
		BigInteger n=new BigInteger("0");
		Scanner in=new Scanner(System.in);
		int k=0,Or,p=0;
		while(in.hasNext())
		{
			if(p>0)System.out.println("");
			n=in.nextBigInteger();
			k=0;
			Or=1;
			if(((n.mod(a)).equals(f)&&(n.mod(b)).compareTo(f)!=0)||((n.mod(c)).equals(f)))
			{
				System.out.println("This is leap year.");
				if((n.mod(e)).equals(f)) k=1;
				Or=0;
			}
			if((n.mod(d)).equals(f))
			{
				System.out.println("This is huluculu festival year.");
				Or=0;
			}
			if(Or==1)
				System.out.println("This is an ordinary year.");
			if(k==1) System.out.println("This is bulukulu festival year.");
			p++;
			
		}
	}       
}