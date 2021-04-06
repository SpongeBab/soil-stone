# class Solution:
#     """
#     @param nums: A list of integers
#     @return: An integer indicate the value of maximum difference between two substrings
#     """
import math


def maxDiffSubArrays():
    # write your code here
    array1 = [1, 2, -3, 1]
    print(len(array1))
    array2 = []
    sub_array1 = []
    sub_array2 = []
    sum1, sum2 = 0, 0
    i, t, j = 0, 0, 0
    # if len(array1)%2 is not None:
    #     p
    for i in range(len(array1)):
        if i < (len(array1) / 2):
            print("sss", len(array1) / 2)
            sub_array1.append(array1[i])
            print(sub_array1)
            sum1 += sub_array1[i]
            print(sum1)
        else:
            for j in range(int(len(sub_array1) / 2)):
                if sub_array1[j] != array1[i]:
                    sub_array2.append(array1[i])
                    print(sub_array2)
                    sum2 += sub_array2[j]

        output = sum1 - sum2
        print("ooo", output)


maxDiffSubArrays()
# if __name__ == '__main__':
#     maxDiffSubArrays()
