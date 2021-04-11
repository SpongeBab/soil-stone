class Solution:
    """
    @param number: A 3-digit number.
    @return: Reversed number.
    """
    def reverseInteger(self, number):
        self.__init__()
        # 999
        i = number % 100
        k = i // 10
        j = number // 100
        return number % 10 * 100 + k * 10 + j


if __name__ == '__main__':
    demo = Solution()
    print(demo.reverseInteger(int(input())))
