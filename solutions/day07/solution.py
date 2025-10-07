from collections import deque

class Solution:
    def avoidFlood(self, rains: list[int]) -> list[int]:
        last = {}
        q = deque()
        res = []

        for i, lake in enumerate(rains):
            if lake != 0:
                if lake in last:
                    found = False
                    temp = deque()
                    while q:
                        j = q.popleft()
                        if not found and j > last[lake]:
                            res[j] = lake
                            found = True
                        else:
                            temp.append(j)
                    if not found:
                        return []
                    q = temp
                res.append(-1)
                last[lake] = i
            else:
                res.append(1)
                q.append(i)

        return res
