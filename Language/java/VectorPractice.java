import java.util.Vector;

public class VectorPractice {
    public void oneDimensionalVector() {
        Vector<Integer> v = new Vector<>();
        v.add(34);v.add(76);

        for (int i = 0; i < v.size(); i++) {
            System.out.printf("%d ", v.get(i));
        }
        System.out.printf("\n");
    }

    public void twoDimensionalVector() {
        Vector<Vector<Integer>> row = new Vector<>();
        Vector<Integer>col = new Vector<>();
        col.add(45);col.add(76);row.add(col);

        for (int i = 0 ; i < row.size(); i++) {
            for (int j = 0; j < row.get(i).size(); j++) {
                System.out.printf("%d ", row.get(i).get(j));
            }
        }
    }

    public static void main(String[] args) {
       VectorPractice v = new VectorPractice();
       v.oneDimensionalVector();
       v.twoDimensionalVector();
    }
}
