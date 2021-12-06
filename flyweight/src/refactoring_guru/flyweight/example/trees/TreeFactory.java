package refactoring_guru.flyweight.example.trees;

import java.awt.*;
import java.util.HashMap;
import java.util.Map;

public class TreeFactory {
    static Map<String, TreeType> treeTypes = new HashMap<>();
    
    public static Tree getTree(int x, int y, String name, Color color, String otherTreeData) {
        TreeType type = getTreeType(name, color, otherTreeData);
        Tree tree = new Tree(x, y, type);
        return tree;
    }

    private static TreeType getTreeType(String name, Color color, String otherTreeData) {
        TreeType result = treeTypes.get(name);
        if (result == null) {
            result = new TreeType(name, color, otherTreeData);
            treeTypes.put(name, result);
        }
        return result;
    }
  
}
