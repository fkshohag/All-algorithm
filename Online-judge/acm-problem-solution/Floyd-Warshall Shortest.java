/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package floye.worshall;

/**
 *
 * @author mdshohag
 */
public class FloyeWorshall {
   public static   int inf=9999999;
   public static   int vertice=5;
    public static void main(String[] args) {
        int[][]data=new int[5][5];
        for(int i=0;i<vertice;i++)
            for(int j=0;j<vertice;j++)
                data[i][j]=inf;
        for(int i=0;i<vertice;i++)
            data[i][i]=0;
    data[0][1]=20;
    data[0][2]=10;
    data[0][4]=5;
    data[2][3]=10;
    data[3][1]=3;
    data[4][2]=2;
    data[4][3]=4;
    for(int k=0;k<vertice;k++)
        for(int i=0;i<vertice;i++)
            for(int j=0;j<vertice;j++)
                if(data[i][j]>data[i][k]+data[k][j])
                data[i][j]=data[i][k]+data[k][j];
    for(int i=0;i<vertice;i++)
    {
        for(int j=0;j<vertice;j++)
        {
            System.out.printf("%d ",data[i][j]);
        }
        System.out.println();
    }
    }
}
