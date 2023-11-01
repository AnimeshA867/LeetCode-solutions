import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
}

class solution {
    Map<Integer, Integer> frequency = new HashMap<Integer, Integer>(10, 1);

    int maxCount = 0;

    public int[] findMode(TreeNode root) {
        List<Integer> modes = new ArrayList();

        traversal(root, modes);
        int[] result = new int[modes.size()];
        for (int i = 0; i < modes.size(); i++) {
            result[i] = modes.get(i);
        }

        return result;
    }

    public void traversal(TreeNode node, List<Integer> modes) {
        if (node == null) {
            return;
        }
        traversal(node.left, modes);
        frequency.put(node.val, frequency.getOrDefault(node.val, 0) + 1);
        int count = frequency.get(node.val);
        if (count > maxCount) {
            maxCount = count;
            modes.clear();
            modes.add(node.val);
        } else if (count == maxCount) {
            modes.add(node.val);
        }
        traversal(node.right, modes);
    }

}

public static void main(String[] args){
    //Same as before. I'm too lazy to write the main function. YOu won't really need it anyways. 
}
