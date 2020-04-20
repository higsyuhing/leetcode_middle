from collections import defaultdict
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        # this is really good.. see some hardness of leetcode! 

        if endWord not in wordList or not endWord or not beginWord or not wordList:
            return 0

        # Since all words are of same length.
        L = len(beginWord)

        # Dictionary to hold combination of words that can be formed,
        # from any given word. By changing one letter at a time.
        all_combo_dict = defaultdict(list)
        for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)


        # Queue for BFS
        queue = collections.deque([(beginWord, 1)])
        # Visited to make sure we don't repeat processing same word.
        visited = {beginWord: True}
        while queue:
            current_word, level = queue.popleft()      
            for i in range(L):
                # Intermediate words for current word
                intermediate_word = current_word[:i] + "*" + current_word[i+1:]

                # Next states are all the words which share the same intermediate state.
                for word in all_combo_dict[intermediate_word]:
                    # If at any point if we find what we are looking for
                    # i.e. the end word - we can return with the answer.
                    if word == endWord:
                        return level + 1
                    # Otherwise, add it to the BFS Queue. Also mark it visited
                    if word not in visited:
                        visited[word] = True
                        queue.append((word, level + 1))
                all_combo_dict[intermediate_word] = []
        return 0
        
        
'''

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // bfs, then once find a solution, problem solved.. 
        // 1. transform wordlkst to map, for quick search. 
        // 2. queue, tempWord: change each letter, check existance in map, insert
        // 2.1 add counter, then insert "EOF" label into queue
        
        if(beginWord.size() != endWord.size()) return 0; 
        if(beginWord.size() == 0) return 0; 
        
        set<string> dict; 
        int i; 
        for(i = 0; i < wordList.size(); i++){
            dict.insert(wordList[i]); 
        }
        if(dict.find(endWord) == dict.end()) return 0; 
        
        queue<string> bfsqueue; 
        bfsqueue.push(beginWord); 
        bfsqueue.push(""); 
        string temp, tempm; 
        int p, q; 
        for(i = 0; i < wordList.size(); i++){
            while(1){
                temp = bfsqueue.front(); 
                bfsqueue.pop(); 
                // cout << i << ": " << temp << endl; 
                if(temp == ""){
                    bfsqueue.push(temp); 
                    break;
                }
                if(temp == endWord) return (i+1); 
                
                for(p = 0; p < beginWord.size(); p++){
                    for(q = 0; q < 26; q++){
                        if(temp[p] == ('a'+q)) continue; //same letter
                        tempm = temp; 
                        tempm[p] = 'a'+q; 
                        if(dict.find(tempm) != dict.end()) bfsqueue.push(tempm); 
                    }
                }
            }
            
        }
        
        return 0; 
    }
};


'''
