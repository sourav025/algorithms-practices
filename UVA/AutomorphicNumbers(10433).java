import java.io.*;
import java.math.BigInteger;

public class AutomorphicNumbers {
    public static void main(String[] args) throws Exception{
        BufferedReader inp=new BufferedReader(new InputStreamReader(System.in));
        String s;
        while((s=inp.readLine())!=null){
            Auto ob=new Auto(s);
            System.out.println(ob.getSolution()?("Automorphic number of "+s.length()+"-digit."):("Not an Automorphic number."));
        }
    }
}


class Auto{
    String str;
    Auto(String s){
        str=s;
    }
    boolean getSolution(){
        BigInteger num=new BigInteger(str);
        return num.multiply(num).toString().endsWith(str);
    }
}