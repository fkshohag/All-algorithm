import java.util.HashMap;
import java.util.Map;

public class ObjectDic {
    public static void main(String[] args) {
        HashMap<String, String> my_dict = new HashMap<>();
        my_dict.put("name", "shohag");
        my_dict.put("address", "Kishoreganj");
        // Key retrieve
        for (String key: my_dict.keySet()) {
            System.out.printf("%s ", key);
        }
        System.out.println("\n");
        // Value retrieve
        for (String value: my_dict.values()) {
            System.out.println(value);
        }
        // Key and value retrieve
        for(Map.Entry<String, String>entity: my_dict.entrySet()) {
            System.out.printf("key: %s value: %s\n", entity.getKey(), entity.getValue());
        }
    }
}
