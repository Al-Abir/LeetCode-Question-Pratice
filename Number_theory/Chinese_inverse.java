package Number_theory;

public class Chinese_inverse {
    static int inv(int a , int m){
        int m0=m, t,q;
        int x0=0,x1=1;
        if(m==1){
            return 0;
        }
        while(a>1){
            q= a/m;
            t = m;
            m = a%m;
            a= t;
            t=x0;
            x0 = x1-q*x0;
            x1= t;

        }
        if(x1<0){
            x1+=m0;
        }
        return x1;
    }
    static int findmax(int num[], int rem[], int k){
        int M = 1;
        for(int i=0; i<k; i++){
            M *=num[i];
        }
        int result =0;
        for(int i =0; i<k; i++){
            int m = M/num[i]; // m1, m2, m3
            result += rem[i]*m*inv(m,num[i]);
        }
        return result % M;
    }
    public static void main(String[] args) {
        
        int num[]= {3,4,5};
        int rem[]= {2,3,1};
        int k= num.length;
        System.out.println("X is "+ findmax(num, rem,k));

    }
}
