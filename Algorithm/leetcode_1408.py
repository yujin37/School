class Solution:
    def stringMatching(self, words: list[str]) -> list[str]:
        result=[]
        for i in range(len(words)):
            for j in range(i+1,len(words)): 
                words_i=list(words[i])
                words_j=list(words[j])
                fix=0
                find=''
                if len(words_i)<len(words_j):
                    
                    now=0
                    for k in range(len(words_j)):
                        if words_j[k]==words_i[now]:
                            find+=words_j[k]
                            now+=1
                            if now == len(words_i):
                                break
                        else:
                            if now>0:
                                if words_i[now]!=words_j[k]:
                                    now-=1
                                    find=find[:-1]
                                    if words_i[now]==words_j[k]:
                                        find+=words_i[now]
                                    
                                        now+=1
                    if find == words[i]:
                        if not find in result:
                            result.append(find)
                elif len(words_i)>=len(words_j):
                    now=0
                    for k in range(len(words_i)):
                        if words_i[k]==words_j[now]:
                            find+=words_i[k]
                            now+=1
                            if now == len(words_j):
                                break
                        else:
                            if now>0:
                                if words_i[k]!=words_j[now]:
                                    now-=1
                                    find=find[:-1]
                                    if words_i[k]==words_j[now]:
                                        find+=words_i[k]
                                        now+=1 
                    if find == words[j]:
                        if not find in result:
                            result.append(find)
         
        return result