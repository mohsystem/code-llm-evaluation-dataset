import java.util.List;
import java.util.ArrayList;

public class Task22_GEMINI_gemini_1_5_pro_001 {
  public static List<Object> filterList(final List<Object> list) {
    List<Object> result = new ArrayList<>();
    for(Object element : list){
      if(element instanceof Integer){
        result.add(element);
      }
    }
    return result;
  }
}