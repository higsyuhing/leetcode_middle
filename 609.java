class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        // for follow-up questions: just read the first 1kb content and construct hash
        // later comparing the remaining.. 
        
        HashMap < String, List < String >> map = new HashMap < > ();
        for (String path: paths) {
            String[] values = path.split(" ");
            for (int i = 1; i < values.length; i++) {
                String[] name_cont = values[i].split("\\(");
                name_cont[1] = name_cont[1].replace(")", "");
                List < String > list = map.getOrDefault(name_cont[1], new ArrayList < String > ());
                list.add(values[0] + "/" + name_cont[0]);
                map.put(name_cont[1], list);
            }
        }
        List < List < String >> res = new ArrayList < > ();
        for (String key: map.keySet()) {
            if (map.get(key).size() > 1)
                res.add(map.get(key));
        }
        return res;
    }
}

/*

class Solution {
    public List<List<String>> findDuplicate(String[] paths) {
        Map<String, List<String>> map = new HashMap<>();
        for (String path: paths) {
            addToMap(map, path);
        }
        List<List<String>> dup = new ArrayList<>();
        for (List<String> dups : map.values()) {
            if (dups.size() > 1) {
                dup.add(dups);
            }
        }
        return dup;
    }
    
    private void addToMap(Map<String, List<String>> map, String path) {
        String[] files = path.split(" ");
        for (int i = 1; i < files.length; i++) {
            int index = files[i].indexOf('(');
            String fileName = files[i].substring(0, index);
            String fileContent = files[i].substring(index + 1, files[i].length() - 1);
            String longName = files[0] + "/" + fileName;
            List<String> dups = map.getOrDefault(fileContent, new ArrayList<>());
            dups.add(longName);
            map.put(fileContent, dups);
        }
    }    
}

*/
