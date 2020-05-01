Set<String> res = new HashSet<>(); // 返回结果
public List<String> crawl(String startUrl, HtmlParser htmlParser) {
    String host = getUrl(startUrl); // 取得域名
    Queue<String> q = new LinkedList<>(); // bfs用的queue
    res.add(startUrl); // 添加startUrl至返回结果
    q.offer(startUrl); // 添加startUrl至bfs的Queue
    while(q.size()>0){
        String url = q.poll(); // 取得一个url
        // 查看当前url包含的所有链接
        List<String> urls = htmlParser.getUrls(url);
        for(String u : urls){ // 循环每一个链接
            // 如果该链接已经爬过或者不属于当前域名，跳过
            if(res.contains(u)||!getUrl(u).equals(host)){
                continue;
            }
            res.add(u); // 添加该链接至返回结果
            q.offer(u); // 添加该链接至bfs的Queue
        }
    }
    return new ArrayList<>(res);
}
