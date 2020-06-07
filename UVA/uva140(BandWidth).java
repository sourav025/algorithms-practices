import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 *
 * @author DewDrops
 */
public class Main {
    public static void main(String... args) throws Exception{
        
        String str=null;
        BufferedReader inp=new BufferedReader(new InputStreamReader(System.in));
        
        while(true)
        {
            str=inp.readLine();
            
            if(str.equals("#")){
                break;
            }
            
            Uva140 ob=new Uva140(str);
            ob.extractNodes();
            ob.doCalculationAndSave();
            ob.printOrder();
        }
    }
}

class Uva140{
    private String edges;
    private boolean edge[][],vis[];
    private int nodes[],node[],order[];
    private int n;
    private int min;
    
    public Uva140(String edges){
        this.edges=edges;
        edge=new boolean[30][30];
        vis=new boolean[30];
        nodes=new int[30];
        node=new int[30];
        order=new int[30];
        min=(1<<29);
        
        for(int i=0;i<30;i++){
            vis[i]=false;
            nodes[i]=0;
            node[i]=0;
            for(int j=0;j<30;j++)
                edge[i][j]=false;
        }        
    }
    
    public void extractNodes(){
        StringTokenizer tokens=new StringTokenizer(edges,";");
        while(tokens.hasMoreTokens()){
            String str=tokens.nextToken();
            
            int u=str.charAt(0)-'A';
            
            for(int i=2;i<str.length();i++){
                int v=str.charAt(i)-'A';
                edge[u][v]=true;
                edge[v][u]=true;
                
                nodes[u]=1;
                nodes[v]=1;
            }
        }
        n=0;
        for(int i=0;i<30;i++)
            if(nodes[i]==1) {
//                System.out.print((char)('A'+i)+" ");
                node[n++]=i;
            }
//        System.out.println("\n");
    }

    public void doCalculationAndSave() {
        int res[]=new int[30];
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                vis[i]=true;
                res[0]=i;
                doPermute(i,1,res);
                res[0]=-1;
                vis[i]=false;
            }
        }
    }
    
    public void doPermute(int id,int len,int[] res){
        
        if(len==n){
            int mx=0;
            for(int i=0;i<n;i++){
                int u=node[res[i]];
                for(int j=i+1;j<n;j++){
                    int v=node[res[j]];
                    if(edge[u][v]==true){
                        mx=Math.max(mx, j-i);
                    }
                }
            }
            if(min>mx){
                min=mx;
                for(int i=0;i<n;i++){
                    order[i]=res[i];
                }
            }
//            System.out.println(min);
        }
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=true;
                res[len]=i;
                doPermute(i,len+1,res);
                res[len]=-1;
                vis[i]=false;
            }
        }
    }

    void printOrder() {
        for(int i=0;i<n;i++){
            System.out.print((char)('A'+node[order[i]]) +" ");
        }
        System.out.println("-> "+min);
    }
    
}