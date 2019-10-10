class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        bank = set(bank)
        if end not in bank:
            return -1
        
        q = [(start, 0)] # start, now step
        change = {'A':'TCG', 'T': 'ACG', 'C':'ATG', 'G':'ATC'}
        while q:
            node, step = q.pop(0)
            if node == end: # achieve
                return step
            for i, v in enumerate(node):
                for j in change[v]:
                    new = node[:i] + j + node[i+1:]
                    if new in bank:
                        q.append((new, step + 1))
                        bank.remove(new)
        return -1

'''
这是一题典型的 BFS 
可以作为 Python 的 BFS 模板
'''
