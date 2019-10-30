# coding=utf-8


class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        m = {'}': '{', ']': '[', ')': '('}
        for i in s:
            if i not in m:
                stack.append(i)
            elif not stack or stack.pop() != m[i]:
                return False

        return not stack


if __name__ == '__main__':
    s = '{[]}'
    print(Solution().isValid(s))
