// 统计以某个单词开头的句子有哪些
Map<String, List<Integer>> map = new HashMap<>();
public List<String> beforeAndAfterPuzzles(String[] phrases) {
    // 循环每个句子
    for(int i=0;i<phrases.length;i++){
        // 将句子以空格分割
        String[] arr = phrases[i].split(" ");
        // 得到句子首单词，并将本句子加入以该首单词开始的句子集合中
        List<Integer> list=map.getOrDefault(arr[0],new ArrayList<>());
        list.add(i);
        map.put(arr[0],list);
    }
    // 再次循环每个句子
    for(int i=0;i<phrases.length;i++){
        // 查找能与当前句子合并的句子
        find(phrases,i);
    }
    // 返回结果
    List<String> res = new ArrayList<>(set);
    // 按照字典顺序排序
    Collections.sort(res);
    return res;
}
Set<String> set = new HashSet<>();
// 查找能与当前句子合并的句子
void find(String[] phrases, int index){
    // 将当前句子以空格分割
    String[] arr = phrases[index].split(" ");
    // 当前句子尾单词
    String key = arr[arr.length-1];
    // 如果map中不存在以当前尾单词开头的句子，退出
    if(!map.containsKey(key)) return;
    // 找到所有以当前尾单词开头的句子
    for(int i : map.get(key)){
        // 注意不能与自身合并
        if(i!=index){
            // 合并两个句子
            String str=phrases[index]+phrases[i].substring(key.length());
            set.add(str);
        }
    }
}
