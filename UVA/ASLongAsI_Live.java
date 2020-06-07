import java.io.*;
import java.util.*;

public class Main {
    public static void main(String... args) throws Exception {
        BufferedReader inp= new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(inp.readLine().trim());
        for(int cas=1;cas<=t;cas++){
            inp.readLine();
            StringTokenizer tokens=new StringTokenizer(inp.readLine());
            AsLong ob=new AsLong(Integer.parseInt(tokens.nextToken()),Integer.parseInt(tokens.nextToken()));
            ob.getCostsAndEdges(inp);
            System.out.print("Case "+cas+": ");
            ob.showRes();
        }
    }
}

class AsLong{
    List<Integer> Edge[];
    int cost[];
    int n,m;
    AsLong(int n,int m){
        this.n=n;
        this.m=m;
        Edge=new List[n+1];        
        cost=new int[n+1];
    }
    void getCostsAndEdges(BufferedReader inp) throws Exception{
        StringTokenizer tokens=new StringTokenizer(inp.readLine());
        for(int i=0;i<n;i++){
            Edge[i]=new ArrayList<Integer>();
            cost[i]=Integer.parseInt(tokens.nextToken());
        }
        for(int i=0;i<m;i++){
            tokens=new StringTokenizer(inp.readLine());
            Edge[Integer.parseInt(tokens.nextToken())].add(Integer.parseInt(tokens.nextToken()));
        }
    }
    void showRes(){
        int ind=0,id,sum=0,mx=0;
        for(int i=0;Edge[i].size()>0;){
            mx=0;
            ind=0;
            for(int j=0;j<Edge[i].size();j++){
                if(mx<cost[Edge[i].get(j)]){
                    mx=cost[Edge[i].get(j)];
                    ind=Edge[i].get(j);
                }
            }
            sum+=mx;
            i=ind;
        }
        System.out.println(sum+" "+ind);
    }
    
}