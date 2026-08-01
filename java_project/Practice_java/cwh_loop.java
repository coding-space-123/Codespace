//break and continue 

// loop

public class cwh_loop {
    public static void main(String[] args){
        int i=1;
        // while loop
        System.out.println("while loop");
        while(i<=3){
            System.out.println("i = " + i);
            i++;
        }
        // do -  while loop
        System.out.println("do while loop"); 
        int a=5;
        do{
            System.out.println("a = " + a);
            a--;
        }while(a>1);
        // for loop
        System.out.println("for loop ");
        for(int j=1;j<=10;j++){
            //System.out.println("j = " +j);
            if(j==5)
            {
                System.out.println("ending the loop ");
                //break;
                continue;
            }
            System.out.println("j = " + j);
        }

        for (int z = 1; z <= 10; z++) {
            System.out.println("z = " +z);
            if (z == 5) {
                System.out.println("ending the loop ");
                break;
            }
            
        }
            
    }
}
