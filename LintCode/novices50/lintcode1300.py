class Solution:
    """
    @param n: an integer
    @return: whether you can win the game given the number of stones in the heap
    """

    def canWinBash(self, n):
        # Write your code here
        self.__init__()
        if n % 4 == 0:
            return print("False")
        else:
            return print("true")


if __name__ == '__main__':
    demo = Solution()
    demo.canWinBash(4)
